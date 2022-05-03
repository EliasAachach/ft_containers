#ifndef rb_tree_iterator
# define rb_tree_iterator

# include "rbTreeNode.hpp"

namespace ft
{
	template <typename T>
	bool		__is_leaf(ft::node<T> *__x)
	{
		if (__x->_parent == 0 && __x->_left == 0 && __x->_right == 0)
			return (true);
		return (false);
	}

	template <typename T>
	static ft::node<T>	*_local_rb_tree_increment(ft::node<T> *__x)	throw()
	{
		if (__x->_right && __x->_parent != 0)
		{
			__x = __x->_right;
			while(__x->_left && __x->_left->_parent != 0)
				__x = __x->_left;
		}
		else
		{
			ft::node<T>	*__y = __x->_parent;
			while (__x == __y->_right)
			{
				__x = __y;
				__y = __y->_parent;
			}
			if (__x->_right != __y)
				__x = __y;
		}
		return (__x);
	}

	template <typename T>
	ft::node<T>		*_rb_tree_increment(ft::node<T>	*__x)	throw()
	{
		return(_local_rb_tree_increment(__x));
	}
	template <typename T>
	const ft::node<T>		*_rb_tree_increment(const ft::node<T>	*__x)	throw()
	{
		return(_local_rb_tree_increment(const_cast<ft::node<T>*>(__x)));
	}

	template <typename T>
	static	ft::node<T>		*_local_rb_tree_decrement(ft::node<T> *__x)	throw()
	{
		if (__x->_color = RED && __x->_parent->_parent == __x)
			__x = __x->_right;
		else if (__x->_left != 0 && !__is_leaf(__x->_left))
		{
			ft::node<T>	*__y = __x->_left;
			while(__y->_right != 0 && !__is_leaf(__y->_right))
				__y = __y->_right;
			__x =  __y;
		}
		return (__x);
	}

	template <typename T>
	ft::node<T>		*_rb_tree_decrement(ft::node<T>	*__x)	throw()
	{
		return(_local_rb_tree_decrement(__x));
	}
	template <typename T>
	const ft::node<T>		*_rb_tree_decrement(const ft::node<T>	*__x)	throw()
	{
		return(_local_rb_tree_decrement(const_cast<ft::node<T>*>(__x)));
	}
}

#endif