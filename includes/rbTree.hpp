#ifndef RBTREE_HPP
# define RBTREE_HPP

#include "rbTreeNode.hpp"
#include "rb_tree_iterator.hpp"
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

			this->_root = NULL;
			this->_emptyNode = this->_node_alloc.allocate(1);
			this->_node_alloc.construct(this->_emptyNode, tmp);
			this->_leftLeaf = this->_node_alloc.allocate(1);
			this->_node_alloc.construct(this->_leftLeaf, tmp);
			this->_rightLeaf = this->_node_alloc.allocate(1);
			this->_node_alloc.construct(this->_rightLeaf, tmp);

			it = src.begin();
			while (it != src.end())
			{
				insert(*it);
				it++;
			}
			this->_countNode = 0;
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
				if (this->_comp(newNode.data, x->data))
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
			else if (key_compare()(newNode.data.first, y->data.first))
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
				insert_pointer->color = BLACK;
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
	};
};

#endif