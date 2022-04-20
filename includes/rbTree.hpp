#ifndef RBTREE_HPP
# define RBTREE_HPP

#include "rbTreeNode.hpp"
#include <functional>

namespace ft
{
	template <class _Key, class T, class Compare = std::less<_Key>, class Alloc = std::allocator<T> >
	class	rbTree
	{
		public:

		/********************************/
		/*			TYPEDEF				*/
		/********************************/
		typedef _Key		key_type;
		typedef T			value_type;
		typedef Alloc		allocator_type;
		typedef _Key		key_type;
		typedef	ft::node<T>	node;
		typedef typename	allocator_type::template rebind<Node>::other	node_allocator;
		typedef typename	node_allocator::pointer							node_pointer;
		typedef typename	node_allocator::reference						node_reference;
		typedef				ft::rb_tree_iterator<T>							iterator;

		private:
		
		/********************************/
		/*		PRIVATE MEMBERS			*/
		/********************************/
		node_pointer	_root;
		node_allocator	_node_alloc;

		public:
		
		/********************************/
		/*		MEMBER	TYPE			*/
		/********************************/
					bool _comp(value_type a, value_type b, Compare cmp = Compare())
			{
				return cmp(a.first, b.first);
			}

			void	leftRotate ( node_pointer node )
			{
				node_pointer	tmp = node->right;

				node->right = tmp->left;
				if (tmp->left != NULL && tmp->left != this->_empty)
				{
					tmp->left->parent = node;
				}
				tmp->parent = node->parent;
				if (node->parent == NULL || node->parent == this->_empty)
				{
					this->_root = tmp;
				}
				else if (node == node->parent->left)
				{
					node->parent->left = tmp;
				}
				else
				{
					node->parent->right = tmp;
				}
				tmp->left = node;
				node->parent = tmp;
			}

			void	rightRotate ( node_pointer node )
			{
				node_pointer tmp = node->left;

				node->left = tmp->right;
				if (tmp->right != NULL && tmp->right != this->_empty)
				{
					tmp->right->parent = node;
				}
				tmp->parent = node->parent;
				if (node->parent == NULL || node->parent == this->_empty)
				{
					this->_root = tmp;
				}
				else if (node == node->parent->right)
				{
					node->parent->right = tmp;
				}
				else
				{
					node->parent->left = tmp;
				}
				tmp->right = node;
				node->parent = tmp;
			}

			void	insert_fix ( node_pointer node )
			{
				node_pointer	tmp;

				while (node->parent->color == 1)
				{
					if (node->parent == node->parent->parent->right)
					{
						tmp = node->parent->parent->left;
						if (tmp && tmp->color == 1)
						{
							tmp->color = 0;
							node->parent->color = 0;
							node->parent->parent->color = 1;
							node = node->parent->parent;
						}
						else
						{
							if (node == node->parent->left)
							{
								node = node->parent;
								rightRotate(node);
							}
							node->parent->color = 0;
							node->parent->parent->color = 1;
							leftRotate(node->parent->parent);
						}
					}
					else
					{
						tmp = node->parent->parent->right;

						if (tmp && tmp->color == 1)
						{
							tmp->color = 0;
							node->parent->color = 0;
							node->parent->parent->color = 1;
							node = node->parent->parent;
						}
						else
						{
							if (node == node->parent->right)
							{
								node = node->parent;
								leftRotate(node);
							}
							node->parent->color = 0;
							node->parent->parent->color = 1;
							rightRotate(node->parent->parent);
						}
					}
					if (node == this->_root) {
						break;
					}
				}
				this->_root->color = 0;
			}

			void	delete_fix ( node_pointer node )
			{
				node_pointer	tmp;

				while (node != this->_root && node->color == BLACK)
				{
					if (node == node->parent->left)
					{
						tmp = node->parent->right;
						if (tmp->color == RED)
						{
							tmp->color = BLACK;
							node->parent->color = RED;
							leftRotate(node->parent);
							tmp = node->parent->right;
						}
						if (tmp->left->color == BLACK && tmp->right->color == BLACK)
						{
							tmp->color = RED;
							node = node->parent;
						}
						else
						{
							if (tmp->right->color == BLACK)
							{
								tmp->left->color = BLACK;
								tmp->color = RED;
								rightRotate(tmp);
								tmp = node->parent->right;
							}
							tmp->color = node->parent->color;
							node->parent->color = BLACK;
							tmp->right->color = BLACK;
							leftRotate(node->parent);
							node = this->_root;
						}
					}
					else
					{
						tmp = node->parent->left;
						if (tmp->color == RED)
						{
							tmp->color = BLACK;
							node->parent->color = RED;
							rightRotate(node->parent);
							tmp = node->parent->left;
						}
						if (tmp->right->color == BLACK)
						{
							tmp->color = RED;
							node = node->parent;
						}
						else {
							if (tmp->left->color == BLACK)
							{
								tmp->right->color = BLACK;
								tmp->color = RED;
								leftRotate(tmp);
								tmp = node->parent->left;
							}
							tmp->color = node->parent->color;
							node->parent->color = BLACK;
							tmp->left->color = BLACK;
							rightRotate(node->parent);
							node = this->_root;
						}
					}
				}
				node->color = BLACK;
			}

			void	delete_tree ( node_pointer root )
			{
				if (root != NULL)
				{
					delete_tree(root->left);
					delete_tree(root->right);
				}
				if (root != this->_empty && root != NULL)
				{
					this->_node_alloc.destroy(root);
					this->_node_alloc.deallocate(root, 1);
				}
			}

			void	rbTransplant ( node_pointer x, node_pointer y )
			{
				if (x->parent == NULL)
				{
					this->_root = y;
				}
				else if (x == x->parent->left)
				{
					x->parent->left = y;
				}
				else
				{
					x->parent->right = y;
				}
				y->parent = x->parent;
			}

			node_pointer	maximum ( node_pointer node )
			{
				while (node->right != this->_empty)
				{
					node = node->right;
				}
				return (node);
			}

			node_pointer	minimum ( node_pointer node )
			{
				while (node->left != this->_empty)
				{
					node = node->left;
				}
				return (node);
			}

			void	printTreeHelper ( node_pointer node, std::string indent, bool side ) const
			{
				if (node != this->_empty)
				{
					std::cout << indent;
					if (side)
					{
						std::cout << "R----";
						indent += "   ";
					}
					else
					{
						std::cout << "L----";
						indent += "   ";
					}

					std::string sColor = node->color ? "🔴" : "⚫";
					std::cout << "(" << node->data << ") (" << sColor << ")" << std::endl;
					printTreeHelper(node->left, indent, false);
					printTreeHelper(node->right, indent, true);
				}
			}

			void	searchTreeHelper ( node_pointer node, value_type data ) const
			{
				if (node == this->_empty || *node == data)
				{
					return (node);
				}

				if (_comp(data, node->data))
				{
					return (searchTreeHelper(node, data));
				}
				return (searchTreeHelper(node, data));
			}
	};
};

#endif