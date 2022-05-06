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
		typedef	typename ft::rbTree<const key_type, value_type, _Compare, _Alloc>::node_pointer		node_pointer;

		class value_compare : std::binary_function<value_type, value_type, bool>
		{
			friend class ft::map<key_type, mapped_type, key_compare, allocator_type>;

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

		/********************************/
		/*			ITERATORS			*/
		/********************************/
		iterator	begin()
		{
			return (this->_rbTree.begin());
		}
		const_iterator	begin() const
		{
			return (this->_rbTree.begin());
		}
		
		iterator	end()
		{
			return (this->_rbTree.end());
		}
		const_iterator	end() const
		{
			return (this->_rbTree.end());
		}

		reverse_iterator	rbegin()
		{
			return (this->end());
		}
		const_reverse_iterator	rbegin() const
		{
			return (this->end());
		}
		
		reverse_iterator	rend()
		{
			return (this->begin());
		}
		const_reverse_iterator	rend() const
		{
			return (this->begin());
		}

		/********************************/
		/*			CAPACITY			*/
		/********************************/
		bool	empty() const
		{
			return (this->_rbTree.getSize() == 0);
		}

		size_type	size() const
		{
			return (this->_rbTree.getSize());
		}

		size_type	max_size() const
		{
			return (this->_rbTree.maxSize());
		}

		/********************************/
		/*		ELEMENT	ACCESS			*/
		/********************************/
		mapped_type	&operator[](const key_type &key)
		{
			iterator	pos = lower_bound(key);

			pos = insert(pos, value_type(key, mapped_type()));
			return ((*pos).second);
		}

		/********************************/
		/*			MODIFIERS			*/
		/********************************/
		ft::pair<iterator,bool> insert (const value_type& val)
		{
			iterator	tmp;

			tmp = this->_rbTree.search(val);
			if (tmp != this->end())
				return (ft::make_pair<iterator, bool>(tmp, false));
			else
			{
				tmp = this->_rbTree.insert(val);
				return (ft::make_pair<iterator, bool>(tmp, true));
			}
		}
		iterator insert (iterator position, const value_type& val)
		{
			iterator	tmp;
			
			(void)position;
			tmp = this->_rbTree.search(val);
			if (tmp == this->end())
				tmp = this->_rbTree.insert(val);
			return (tmp);
		}
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last)
		{
			while (first != last)
				insert(*first++);
		}

		void erase (iterator position)
		{
			this->_rbTree.deleteNode(position);
		}
		size_type erase (const key_type& key)
		{
			iterator	tmp = this->_rbTree.search(key);
			if (tmp == this->end())
				return (0);
			else
			{
				this->erase(tmp);
				return (1);
			}
		}
		void erase (iterator first, iterator last)
		{
			iterator tmp = first;
			while (first != last)
			{
				first++;
				this->erase(tmp);
				tmp = first;
			}
		}

		void	swap(map &rhs)
		{
			this->_rbTree.swap(rhs._rbTree);
		}

		void	clear()
		{
			this->_rbTree.clear();
		}

		/********************************/
		/*			OBSERVERS			*/
		/********************************/
		key_compare key_comp() const
		{
			return (key_compare());
		}
		value_compare value_comp() const
		{
			return (value_compare(key_comp()));
		}
		
		/********************************/
		/*			OPERATIONS			*/
		/********************************/
		iterator find (const key_type& key)
		{
			return (this->_rbTree.search(key));
		}
		const_iterator find (const key_type& key) const
		{
			return (this->_rbTree.search(key));
		}

		size_type count (const key_type& key) const
		{
			if (this->find(key) == this->end())
				return (0);
			return (1);
		}

		iterator lower_bound (const key_type& key)
		{
			iterator	lower = this->begin();
			while (lower != this->end() && key_compare()(lower->first, key))
				lower++;
			return (lower);
		}
		const_iterator lower_bound (const key_type& key) const
		{
			iterator	lower = this->begin();
			while (lower != this->end() && key_compare()(lower->first, key))
				lower++;
			return (lower);
		}

		iterator upper_bound (const key_type& key)
		{
			iterator	upper = this->begin();
			while (upper != this->end() && !key_compare()(upper->first, key))
				upper++;
			return (upper);
		}
		const_iterator upper_bound (const key_type& key) const
		{
			iterator	upper = this->begin();
			while (upper != this->end() && !key_compare()(upper->first, key))
				upper++;
			return (upper);
		}

		ft::pair<const_iterator, const_iterator>	equal_range (const key_type& key) const
		{
			ft::make_pair<iterator, iterator>(lower_bound(key), upper_bound(key));
		}
		ft::pair<iterator, iterator>	equal_range (const key_type& key)
		{
			ft::make_pair<iterator, iterator>(lower_bound(key), upper_bound(key));
		}

		/********************************/
		/*			ALLOCATOR			*/
		/********************************/
		allocator_type get_allocator() const
		{
			return (this->_alloc);
		}

		/********************************/
		/*		FRIEND	OPERATORS		*/
		/********************************/
		template<typename _K1, typename _T1, typename _C1, typename _A1>
		friend bool	operator== (	const map<_K1, _T1, _C1, _A1>&,
									const map<_K1, _T1, _C1, _A1>& );
		template<typename _K1, typename _T1, typename _C1, typename _A1>
		friend bool	operator< (	const map<_K1, _T1, _C1, _A1>&,
								const map<_K1, _T1, _C1, _A1>& );
	};

		/********************************/
		/*			OPERATORS			*/
		/********************************/
	template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
	inline bool	operator== (	const map<_Key, _Tp, _Compare, _Alloc>& __x,
								const map<_Key, _Tp, _Compare, _Alloc>& __y )
	{
		return (__x._rb_tree == __y._rb_tree);
	}

	template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
	inline bool	operator< (	const map<_Key, _Tp, _Compare, _Alloc>& __x,
							const map<_Key, _Tp, _Compare, _Alloc>& __y )
	{
		return (__x._rb_tree < __y._rb_tree);
	}

	template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
	inline bool	operator!= (	const map<_Key, _Tp, _Compare, _Alloc>& __x,
								const map<_Key, _Tp, _Compare, _Alloc>& __y )
	{
		return (!(__x == __y));
	}

	template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
	inline bool	operator> (	const map<_Key, _Tp, _Compare, _Alloc>& __x,
							const map<_Key, _Tp, _Compare, _Alloc>& __y )
	{
		return (__y < __x);
	}

	template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
	inline bool	operator<= (	const map<_Key, _Tp, _Compare, _Alloc>& __x,
								const map<_Key, _Tp, _Compare, _Alloc>& __y )
	{
		return (!(__y < __x));
	}

	template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
	inline bool	operator>= (	const map<_Key, _Tp, _Compare, _Alloc>& __x,
								const map<_Key, _Tp, _Compare, _Alloc>& __y )
	{
		return (!(__x < __y));
	}

	template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
	inline void	swap (	map<_Key, _Tp, _Compare, _Alloc>& __x,
						map<_Key, _Tp, _Compare, _Alloc>& __y)
	{
		__x.swap(__y);
	}
}

#endif