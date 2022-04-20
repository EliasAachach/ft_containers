#ifndef RBTREENODE_HPP
# define RBTREENODE_HPP

# define RED 0
# define BLACK 1

namespace ft
{
	template <typename	T>
	class node
	{
		public:

		/********************************/
		/*			TYPEDEF				*/
		/********************************/
			typedef T	value_type;

		protected:

		/********************************/
		/*		PRIVATE MEMBERS			*/
		/********************************/
			value_type	_value;
			node		*_parent;
			node		*_left;
			node		*_right;
			int			_color;
		
		public:
		/********************************/
		/*			CONSTRUCTOR			*/
		/********************************/
		/*default*/
		node():	_value(T), _color(RED), _parent(NULL), _left(NULL), _right(NULL)
		{
		}
		/*value*/
		node(value_type value):	_value(value), _color(RED), _parent(NULL), _left(NULL), _right(NULL)
		{
		}
	};
};

#endif