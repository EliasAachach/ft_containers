#ifndef MAP_HPP
# define MAP_HPP

# include "vector.hpp"
# include "rbTree.hpp"

namespace ft
{
	template <	class _Key, class _T, class _Compare = std::less<_Key>,
				class _Alloc = std::allocator<ft::pair<const _Key,_T> > >
	class map
	{
		/********************************/
		/*		MEMBER	TYPE			*/
		/********************************/
		typedef	_Key									key_type;
		typedef	_T										mapped_type;
		typedef	ft::pair<const key_type, mapped_type>	value_type;
		typedef	_Compare								key_compare;
		typedef	_Alloc									allocator_type;

		typedef	typename	allocator_type::reference		reference;
		typedef	typename	allocator_type::const_reference	const_reference;
		typedef	typename	allocator_type::pointer			pointer;
		typedef	typename	allocator_type::const_pointer	const_pointer;

		typedef				ft::rb_tree_iterator<value_type>		iterator;
		typedef				ft::rb_tree_const_iterator<value_type>	const_iterator;
		typedef				ft::reverse_iterator<iterator>			reverse_iterator;
		typedef				ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		typedef	typename	allocator_type::size_type						size_type;
		typedef	typename	ft::iterator_traits<iterator>::difference_type	difference_type;
		typedef	typename ft::RedBlackTree<const key_type, value_type, _Compare, _Alloc>::node_pointer		node_pointer;

		class value_compare : std::binary_function<value_type, value_type, bool>
		{
			friend class ft::map<key_type, mapped_type, key_compare, allocator_type>

			protected :

				_Compare	comp;

				value_compare(_Compare c) : comp(c){}
			
			public :
				
				typedef	bool		result_type;
				typedef value_type	first_argument_value;
				typedef value_type	second_argument_value;

			bool	operator()(const value_type & x, const value_type & y)  const
			{
				return (comp(x.first, y.first));
			}
		};
		
		/********************************/
		/*		PRIVATE	MEMBERS			*/
		/********************************/
		private :
			allocator_type	_alloc;
			_Compare		_comp;
			ft::rbTree<const key_type, mapped_type, key_compare, allocator_type>	_rbTree;
		
		/********************************/
		/*			CONSTRUCTORS		*/
		/********************************/
		public :

			/*default*/
			explicit	map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
						_alloc(alloc), _comp(comp), _rbTree()
			{
			}
			/*range*/
			template <typename InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
						_alloc(alloc), _comp(comp), _rbTree()
			{
				while (first != last)
				{
					this->insert(*first);
					first++;
				}
			}
			/*copy*/
			map(const map & x): _alloc(x._alloc), _comp(x._comp), _rbTree(x._rbTree)
			{
			}
			/*operator=*/
			map	&operator=(map & rhs)
			{
				if (&rhs == this)
					return (*this);
				this->clear();
				this->insert(rhs.begin(), rhs.end());
				return (*this);
			}
			/*destructor*/
			~map()
			{
			}
	};
}

#endif