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
		typedef T 					value_type;
		typedef	T&					value_reference;
		typedef T*					value_pointer;

		typedef	node<T>				node_type;
		typedef node<T>&			node_reference;
		typedef node<T>*			node_pointer;

		typedef const T&			const_value_reference;
		typedef const T*			const_value_pointer;

		typedef const node<T>&		const_node_reference;
		typedef const node<T>*		const_node_pointer;

		typedef	std::allocator<node_type>	allocator_type;

		/********************************/
		/*		PRIVATE MEMBERS			*/
		/********************************/
		value_type _value;
		node *_parent;
		node *_left;
		node *_right;
		int _color;

		/********************************/
		/*			CONSTRUCTOR			*/
		/********************************/
		/*default*/
		node() : _value(T()), _parent(0), _left(0), _right(0), _color(BLACK)
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
									_parent(node._parent),
									_left(node._left),
									_right(node._right),
									_color(node._color)
		{
		}

		~node(void)
		{
		}
	};
};

#endif