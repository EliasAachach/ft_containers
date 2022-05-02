#ifndef RBTREENODE_HPP
#define RBTREENODE_HPP

#define RED 0
#define BLACK 1

namespace ft
{
	template <typename T>
	class node
	{
	public:
		/********************************/
		/*			TYPEDEF				*/
		/********************************/
		typedef T value_type;

	protected:
		/********************************/
		/*		PRIVATE MEMBERS			*/
		/********************************/
		value_type _value;
		node *_parent;
		node *_left;
		node *_right;
		int _color;

	public:
		/********************************/
		/*			CONSTRUCTOR			*/
		/********************************/
		/*default*/
		node() : _value(T()), _parent(NULL), _left(NULL), _right(NULL), _color(BLACK)
		{
		}
		node(node *parent, node *left = 0, node *right = 0, int color = BLACK) : _value(T()),
																						  _parent(parent),
																						  _left(left),
																						  _right(right),
																						  _color(color)
		{
		}

		node(const value_type &val, node *parent = 0, node *left = 0, node *right = 0,
			 int color = BLACK) : _value(val),
								  _parent(parent),
								  _left(left),
								  _right(right),
								  _color(color)
		{
		}

		node(const node &node) : _value(node._value),
									_parent(node.parent),
									_left(node.left),
									_right(node.right),
									_color(node.color)
		{
		}

		~node(void)
		{
		}
	};
};

#endif