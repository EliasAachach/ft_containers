#ifndef RBTREE_HPP
# define RBTREE_HPP

#include "rbTreeNode.hpp"
#include "rb_tree_iterator.hpp"
#include "operator_utils.hpp"
#include "pair.hpp"
#include <functional>
#include <memory>
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
		typedef	Compare		key_compare;
		typedef T			value_type;
		typedef Alloc		allocator_type;
		typedef	ft::node<T>	node;
		typedef typename	allocator_type::template rebind<node>::other	node_allocator;
		typedef typename	node_allocator::pointer							node_pointer;
		typedef typename	node_allocator::reference						node_reference;
		typedef				ft::rb_tree_iterator<T>							iterator;

		private:
		
		/********************************/
		/*		PRIVATE MEMBERS			*/
		/********************************/
		node_pointer	_root;
		node_pointer	_emptyNode;
		node_pointer	_leftLeaf;
		node_pointer	_rightLeaf;
		node_allocator	_node_alloc;
		size_t			_countNode;

		public:
		
		/********************************/
		/*		   CONSTRUCTORS			*/
		/********************************/
		
		/* default */
		rbTree(const node_allocator& node_alloc = node_allocator()) : _node_alloc(node_alloc)
		{
			node tmp;

			this->_root = NULL;
			this->_emptyNode = this->_node_alloc.allocate(1);
			this->_node_alloc.construct(this->_emptyNode, tmp);
			this->_leftLeaf = this->_node_alloc.allocate(1);
			this->_node_alloc.construct(this->_leftLeaf, tmp);
			this->_rightLeaf = this->_node_alloc.allocate(1);
			this->_node_alloc.construct(this->_rightLeaf, tmp);
			this->_countNode = 0;
		}

		/* copy */
		rbTree(const rbTree & src)
		{
			node 		tmp;
			iterator	it;

			this->_emptyNode = this->_node_alloc.allocate(1);
			this->_node_alloc.construct(this->_emptyNode, tmp);
			this->_leftLeaf = this->_node_alloc.allocate(1);
			this->_node_alloc.construct(this->_leftLeaf, tmp);
			this->_rightLeaf = this->_node_alloc.allocate(1);
			this->_node_alloc.construct(this->_rightLeaf, tmp);
			this->_root = NULL;
			this->_countNode = 0;

			it = src.begin();
			while (it != src.end())
			{
				insert(*it);
				it++;
			}
		}

		/* destructor */
		~rbTree()
		{
			delete_tree(this->_root);
			this->_node_alloc.destroy(this->_emptyNode);
			this->_node_alloc.deallocate(this->_emptyNode, 1);
			this->_node_alloc.destroy(this->_leftLeaf);
			this->_node_alloc.deallocate(this->_leftLeaf, 1);
			this->_node_alloc.destroy(this->_rightLeaf);
			this->_node_alloc.deallocate(this->_rightLeaf, 1);
		}
				
		/********************************/
		/*		 MEMBER	FUNCTIONS		*/
		/********************************/

		bool	_comp(value_type a, value_type b, Compare _cmp = Compare())
		{
			return (_cmp(a.first, b.first));
		}

		void	leftRotate ( node_pointer node )
		{
			node_pointer	tmp = node->_right;
	
			node->_right = tmp->_left;
			if (tmp->_left != NULL && tmp->_left != this->_emptyNode)
			{
				tmp->_left->_parent = node;
			}
			tmp->_parent = node->_parent;
			if (node->_parent == NULL || node->_parent == this->_emptyNode)
			{
				this->_root = tmp;
			}
			else if (node == node->_parent->_left)
			{
				node->_parent->_left = tmp;
			}
			else
			{
				node->_parent->_right = tmp;
			}
			tmp->_left = node;
			node->_parent = tmp;
		}

		void	rightRotate ( node_pointer node )
		{
			node_pointer tmp = node->_left;
	
			node->_left = tmp->_right;
			if (tmp->_right != NULL && tmp->_right != this->_emptyNode)
			{
				tmp->_right->_parent = node;
			}
			tmp->_parent = node->_parent;
			if (node->_parent == NULL || node->_parent == this->_emptyNode)
			{
				this->_root = tmp;
			}
			else if (node == node->_parent->_right)
			{
				node->_parent->_right = tmp;
			}
			else
			{
				node->_parent->_left = tmp;
			}
			tmp->_right = node;
			node->_parent = tmp;
		}

		void	insert_fix ( node_pointer node )
		{
			node_pointer	tmp;

			while (node->_parent->_color == RED)
			{
				if (node->_parent == node->_parent->_parent->_right)
				{
					tmp = node->_parent->_parent->_left;
					if (tmp && tmp->_color == RED)
					{
						tmp->_color = BLACK;
						node->_parent->_color = BLACK;
						node->_parent->_parent->_color = RED;
						node = node->_parent->_parent;
					}
					else
					{
						if (node == node->_parent->_left)
						{
							node = node->_parent;
							rightRotate(node);  
						}
						node->_parent->_color = BLACK;
						node->_parent->_parent->_color = RED;
						leftRotate(node->_parent->_parent);
					}
				}
				else
				{
					tmp = node->_parent->_parent->_right;
					if (tmp && tmp->_color == RED)
					{
						tmp->_color = BLACK;
						node->_parent->_color = BLACK;
						node->_parent->_parent->_color = RED;
						node = node->_parent->_parent;
					}
					else
					{
						if (node == node->_parent->_right)
						{
							node = node->_parent;
							leftRotate(node);
						}
						node->_parent->_color = BLACK;
						node->_parent->_parent->_color = RED;
						rightRotate(node->_parent->_parent);
					}
				}
				if (node == this->_root) {
					break;
				}
			}
			this->_root->_color = BLACK;
		}

		void	delete_fix(node_pointer	node)
		{
			node_pointer	tmp;
			while (node != this->_root && node->_color == BLACK)
			{
				if (node == node->_parent->_left)
				{
					tmp = node->_parent->_right;
					if (tmp->_color == RED)
					{
						tmp->_color = BLACK;
						node->_parent->_color = BLACK;
						leftRotate(node->_parent);
						tmp = node->_parent->_right;
					}
					if (tmp->_left->_color == BLACK && tmp->_right->_color == BLACK)
					{
						tmp->_color = RED;
						node = node->_parent;
					}
					else
					{
						if (tmp->_right->_color == BLACK)
						{
							tmp->_left->_color = BLACK;
							tmp->_color = RED;
							rightRotate(tmp);
							tmp = node->_parent->_right;
						}
						tmp->_color = node->_parent->_color;
						node->_parent->_color = BLACK;
						tmp->_right->_color = BLACK;
						leftRotate(node->_parent);
						node = this->_root;
					}
				}
				else
				{
					tmp = node->_parent->_left;
					if (tmp->_color == RED)
					{
						tmp->_color = BLACK;
						node->_parent->_color = RED;
						rightRotate(node->_parent);
						tmp = node->_parent->_left;
					}
					if (tmp->_right->_color == BLACK)
					{
						tmp->_color = RED;
						node = node->_parent;
					}
					else
					{
						if (tmp->_left->_color == BLACK)
						{
							tmp->_right->_color = BLACK;
							tmp->_color = RED;
							leftRotate(tmp);
							tmp = node->_parent->_left;
						}
						tmp->_color = node->_parent->_color;
						node->_parent->_color = BLACK;
						tmp->_left->_color = BLACK;
						rightRotate(node->_parent);
						node = this->_root;
					}
				}
			}
			node->_color = BLACK;
		}

		bool	isLeaf(node_pointer node) const
		{
			if (node->_left == NULL && node->_right == NULL && node->_parent == NULL)
				return (true);
			return (false);
		}

		void	delete_tree(node_pointer root)
		{
			if (root != NULL)
			{
				delete_tree(root->_left);
				delete_tree(root->_right);
			}
			if (root != this->_emptyNode && root != NULL && root != this->_leftLeaf && root != this->_rightLeaf)
			{
				this->_node_alloc.destroy(root);
				this->_node_alloc.deallocate(root, 1);
			}
		}

		void	rbTransplant(node_pointer x, node_pointer y)
		{
			if (x->_parent == NULL)
				this->_root = y;
			else if (x == x->_parent->_left)
				x->_parent->_left = y;
			else
				x->_parent->_right = y;
			y->_parent = x->_parent;
		}

		node_pointer	maximum(node_pointer node)
		{
			while (node->_right != this->_emptyNode)
				node = node->_right;
			return (node);
		}

		node_pointer	minimum(node_pointer node)
		{
			while (node->_left != this->_emptyNode)
				node = node->_left;
			return (node);
		}
		
		void	printTreeHelper ( node_pointer node, std::string indent, bool side ) const
		{
			if (node != this->_emptyNode)
			{
				std::cout << indent;
				if (node == this->_leftLeaf)
				{
					std::cout << "L----";
					std::cout << "Left leaf" << std::endl;
				}
				else if (node == this->_rightLeaf)
				{
					std::cout << "R----";
					std::cout << "r_leaf_right leaf" << std::endl;
				}
				else
				{
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
					std::string sColor = node->_color ? "⚫" : "🔴";
					std::cout << "(" << node->_value.first << ") (" << sColor << ")" << std::endl;
					printTreeHelper(node->_left, indent, false);
					printTreeHelper(node->_right, indent, true);
				}
			}
		}

		iterator	searchTreeHelper(node_pointer node, value_type value) const
		{
			if (node == NULL || isLeaf(node))
				return (this->end());
			if (!key_compare()(node->_value.first, value.first) && !key_compare()(value.first, node->_value.first))
				return (iterator(node));
			if (key_compare()(value.first, node->_value.first))
			{
				return (searchTreeHelper(node->_left, value));
			}
			return (searchTreeHelper(node->_right, value));
		}
		iterator	searchTreeHelper(node_pointer node, key_type key) const
		{
			if (node == NULL || isLeaf(node))
				return (this->end());
			if (!key_compare()(node->_value.first, key) && !key_compare()(key, node->_value.first))
				return (iterator(node));
			if (key_compare()(key, node->_value.first))
			{
				return (searchTreeHelper(node->_left, key));
			}
			return (searchTreeHelper(node->_right, key));
		}

		void	setHeader()
		{
			node_pointer	rightLeaf = this->maximum(this->_root);
			node_pointer	leftLeaf = this->minimum(this->_root);

			this->_rightLeaf->_parent = rightLeaf;
			this->_rightLeaf->_parent->_right = this->_rightLeaf;
			this->_leftLeaf->_parent = leftLeaf;
			this->_leftLeaf->_parent->_left = this->_leftLeaf;
			this->_emptyNode->_parent = 0;
		}
		
		void	unsetHeader()
		{
			if (this->_rightLeaf->_parent)
				this->_rightLeaf->_parent->_right = this->_emptyNode;
			if (this->_leftLeaf->_parent)
				this->_leftLeaf->_parent->_left = this->_emptyNode;
		}

		iterator	insert(value_type to_insert)
		{
			node			newNode(to_insert, NULL, this->_emptyNode, this->_emptyNode, RED);
			node_pointer	y = NULL;
			node_pointer	x = this->_root;
			node_pointer	insert_pointer = NULL;

			this->unsetHeader();
			while (x != NULL && x != this->_emptyNode)
			{
				y = x;
				if (this->_comp(newNode._value, x->_value))
					x = x->_left;
				else
					x =  x->_right;
			}
			newNode._parent = y;
			newNode._color = (newNode._parent == NULL) ? BLACK : RED;
			if (y == NULL)
			{
				this->_root = this->_node_alloc.allocate(1);
				insert_pointer = this->_root;
			}
			else if (key_compare()(newNode._value.first, y->_value.first))
			{
				y->_left = this->_node_alloc.allocate(1);
				insert_pointer = y->_left;
			}
			else
			{
				y->_right = this->_node_alloc.allocate(1);
				insert_pointer = y->_right;
			}
			this->_node_alloc.construct(insert_pointer, newNode);
			this->_countNode++;
			if (insert_pointer->_parent == NULL)
			{
				this->setHeader();
				insert_pointer->_color = BLACK;
				return(iterator(insert_pointer));
			}
			if (insert_pointer->_parent->_parent == NULL)
			{
				this->setHeader();
				return(iterator(insert_pointer));
			}
			insert_fix(insert_pointer);
			this->setHeader();
			return(iterator(insert_pointer));
		}


		void	deleteNode ( node_pointer to_delete )
			{
				node_pointer	tmp;
				node_pointer	new_root;
				int				original_color;

				this->unsetHeader();
				tmp = to_delete;
				original_color = tmp->_color;
				if (to_delete->_left == this->_emptyNode)
				{
					new_root = to_delete->_right;
					rbTransplant(to_delete, to_delete->_right);
				}
				else if (to_delete->_right == this->_emptyNode)
				{
					new_root = to_delete->_left;
					rbTransplant(to_delete, to_delete->_left);
				}
				else
				{
					tmp = minimum(to_delete->_right);
					original_color = tmp->_color;
					new_root = tmp->_right;
					if (tmp->_parent == to_delete)
					{
						new_root->_parent = tmp;
					}
					else
					{
						rbTransplant(tmp, tmp->_right);
						tmp->_right = to_delete->_right;
						tmp->_right->_parent = tmp;
					}
					rbTransplant(to_delete, tmp);
					tmp->_left = to_delete->_left;
					tmp->_left->_parent = tmp;
					tmp->_color = to_delete->_color;
				}
				this->_node_alloc.destroy(to_delete);
				this->_node_alloc.deallocate(to_delete, 1);
				this->_countNode--;
				if (original_color == BLACK)
				{
					delete_fix(new_root);
				}
				if (!isLeaf(this->_root))
					this->setHeader();
				else
				{
					this->_root = NULL;
				}
			}

		void	deleteNode(value_type value)
		{
			node_pointer	tmp(this->_root);

			while(tmp != this->_emptyNode)
			{
				if ((*tmp)._value == value)
					return (deleteNode(tmp));
				if (key_compare()(tmp->_value.first, value.first))
					tmp = tmp->_right;
				else
					tmp = tmp->_left;
			}
		}
		void	deleteNode(key_type key)
		{
			node_pointer	tmp;

			tmp = search(key);
			if (tmp != this->end())
				deleteNode(tmp);
		}

		void	clear()
		{
			delete_tree(this->_root);
			this->_root = NULL;
			this->_countNode = 0;
			this->_leftLeaf->_parent = NULL;
			this->_rightLeaf->_parent = NULL;
		}
		
		iterator	search(value_type value) const
		{
			if (this->_root != NULL)
				{
					return (searchTreeHelper(this->_root, value));
				}
				return (this->end());
		}
		iterator	search(key_type key) const
		{
			if (this->_root != NULL)
				return (searchTreeHelper(this->_root, key));
			return (this->end());
		}

		void	printTree() const
		{
			if (this->_root)
			{
				return (printTreeHelper(this->_root, "", true));
			}
		}

		node	getRoot() const
		{
			return (this->_root);
		}

		iterator	end() const
		{
			return(iterator(this->_rightLeaf));
		}

		iterator	begin() const
		{
			if (this->_root == NULL)
				return ((this->end()));
			return (iterator(this->_leftLeaf->_parent));
		}

		size_t	maxSize() const
		{
			return (node_allocator().max_size());
		}

		void	swap(rbTree & rhs)
		{
			rhs.unsetHeader();
			this->unsetHeader();
			std::swap(this->_root, rhs._root);
			std::swap(this->_leftLeaf, rhs._leftLeaf);
			std::swap(this->_rightLeaf, rhs._leftLeaf);
			std::swap(this->_emptyNode, rhs._emptyNode);
			std::swap(this->_countNode, rhs._countNode);
			if (this->_root)
				this->setHeader();
			if (rhs._root)
				rhs.setHeader();
			std::swap(this->_node_alloc, rhs._node_alloc);
		}

		size_t	getSize() const
		{
			return (this->_countNode);
		}

		template <class T1, class T2, class T3, class T4>
		friend inline bool operator==(const rbTree<T1, T2, T3, T4> &lhs, const rbTree<T1, T2, T3, T4> &rhs);

		template <class T1, class T2, class T3, class T4>
		friend inline bool operator<(const rbTree<T1, T2, T3, T4> &lhs, const rbTree<T1, T2, T3, T4> &rhs);
	};


	template <class _Key, class T, class Compare, class Alloc>
	inline bool	operator== (	const rbTree<_Key, T, Compare, Alloc> &__lhs,
								const rbTree<_Key, T, Compare, Alloc> &__rhs )
	{
		return (	__lhs._countNode == __rhs._countNode &&
					ft::equal(__lhs.begin(), __lhs.end(), __rhs.begin()));
	}

	template <class Key, class T, class Compare, class Alloc>
	inline bool	operator!=(const rbTree<Key, T, Compare, Alloc> & lhs, const rbTree<Key, T, Compare, Alloc> & rhs)
	{
		return (lhs != rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	inline bool	operator<(const rbTree<Key, T, Compare, Alloc> & lhs, const rbTree<Key, T, Compare, Alloc> & rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	inline bool	operator>(const rbTree<Key, T, Compare, Alloc> & lhs, const rbTree<Key, T, Compare, Alloc> & rhs)
	{
		return (lhs < rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	inline bool	operator<=(const rbTree<Key, T, Compare, Alloc> & lhs, const rbTree<Key, T, Compare, Alloc> & rhs)
	{
		return (!(lhs < rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	inline bool	operator>=(const rbTree<Key, T, Compare, Alloc> & lhs, const rbTree<Key, T, Compare, Alloc> & rhs)
	{
		return (!(rhs < lhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	inline void	swap(const rbTree<Key, T, Compare, Alloc> & lhs, const rbTree<Key, T, Compare, Alloc> & rhs)
	{
		rhs.swap(lhs);
	}
};

#endif