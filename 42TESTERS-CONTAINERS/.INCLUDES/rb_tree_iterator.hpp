#ifndef RB_TREE_ITERATOR
#define RB_TREE_ITERATOR

#include "Iterator_traits.hpp"
#include "rbTreeNode.hpp"
#include "rb_tree_iterator_base.hpp"
namespace ft
{
	template <typename T>
	struct rb_tree_iterator
	{
		/********************************/
		/*			TYPEDEF				*/
		/********************************/
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;

		typedef ft::bidirectional_iterator_tag iterator_category;
		typedef ptrdiff_t difference_type;
		typedef rb_tree_iterator<T> _Self;
		typedef typename node<T>::node_pointer _node_pointer;

		/********************************/
		/*			MEMBER				*/
		/********************************/
		_node_pointer _node_;

		/********************************/
		/*		   CONSTRUCTORS			*/
		/********************************/
		rb_tree_iterator() : _node_(0)
		{
		}

		explicit rb_tree_iterator(_node_pointer __x) : _node_(__x)
		{
		}

		/********************************/
		/*		 	OVERLOADS			*/
		/********************************/
		reference operator*() const
		{
			return (_node_->_value);
		}
		pointer operator->() const
		{
			return (&(_node_->_value));
		}
		_Self &operator++(void)
		{
			this->_node_ = ft::_rb_tree_increment(this->_node_);
			return (*this);
		}
		_Self operator++(int)
		{
			_Self __tmp = *this;

			this->_node_ = ft::_rb_tree_increment(this->_node_);
			return (__tmp);
		}
		_Self &operator--(void)
		{
			this->_node_ = ft::_rb_tree_decrement(this->_node_);
			return (*this);
		}
		_Self operator--(int)
		{
			_Self __tmp = *this;

			this->_node_ = ft::_rb_tree_decrement(this->_node_);
			return (__tmp);
		}
		bool operator==(const _Self &rhs)
		{
			return (this->_node_ == rhs._node_);
		}
		bool operator!=(const _Self &rhs)
		{
			return (this->_node_ != rhs._node_);
		}
	};

	template <typename T>
	struct rb_tree_const_iterator
	{
		/********************************/
		/*			TYPEDEF				*/
		/********************************/
		typedef T value_type;
		typedef const T *pointer;
		typedef const T &reference;

		typedef rb_tree_iterator<T> iterator;
		typedef ft::bidirectional_iterator_tag iterator_category;
		typedef ptrdiff_t difference_type;
		typedef rb_tree_const_iterator<T> _Self;
		typedef typename node<T>::const_node_pointer _node_pointer;

		/********************************/
		/*			MEMBER				*/
		/********************************/
		_node_pointer _node_;

		/********************************/
		/*		   CONSTRUCTORS			*/
		/********************************/
		rb_tree_const_iterator() : _node_(0)
		{
		}

		explicit rb_tree_const_iterator(_node_pointer __x) : _node_(__x)
		{
		}

		rb_tree_const_iterator(const iterator &it) : _node_(it._node_)
		{
		}

		/********************************/
		/*		 	OVERLOADS			*/
		/********************************/
		iterator _const_cast(void) const
		{
			return (iterator(const_cast<typename iterator::_node_pointer>(_node_)));
		}
		reference operator*() const
		{
			return (_node_->_value);
		}
		pointer operator->() const
		{
			return (&(_node_->_value));
		}
		_Self &operator++(void)
		{
			this->_node_ = ft::_rb_tree_increment(this->_node_);
			return (*this);
		}
		_Self operator++(int)
		{
			_Self __tmp = *this;

			this->_node_ = ft::_rb_tree_increment(this->_node_);
			return (__tmp);
		}
		_Self &operator--(void)
		{
			this->_node_ = ft::_rb_tree_decrement(this->_node_);
			return (*this);
		}
		_Self operator--(int)
		{
			_Self __tmp = *this;

			this->_node_ = ft::_rb_tree_decrement(this->_node_);
			return (__tmp);
		}
		bool operator==(const _Self &rhs)
		{
			return (this->_node_ == rhs._node_);
		}
		bool operator!=(const _Self &rhs)
		{
			return (this->_node_ != rhs._node_);
		}
	};
	template <typename T>
	inline bool operator==(const rb_tree_iterator<T> &lhs, const rb_tree_const_iterator<T> &rhs)
	{
		return (lhs._node_ == rhs._node_);
	}
	template <typename T>
	inline bool operator!=(const rb_tree_iterator<T> &lhs, const rb_tree_const_iterator<T> &rhs)
	{
		return (lhs._node_ != rhs._node_);
	}
}

#endif