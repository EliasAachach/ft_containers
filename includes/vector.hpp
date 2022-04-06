#ifndef vector_HPP
# define vector_HPP

# include <memory>
# include <stdexcept>
# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"
# include "Utils.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "operator_utils.hpp"

namespace ft
{
template < typename T, class Alloc = std::allocator<T> >
	class vector
	{
		public:

		/********************************/
		/*			TYPEDEFS			*/
		/********************************/
			typedef				T		value_type;
			typedef				Alloc	allocator_type;
			typedef typename	allocator_type::reference		reference;
			typedef typename	allocator_type::const_reference	const_reference;
			typedef typename	allocator_type::pointer		pointer;
			typedef typename	allocator_type::const_pointer	const_pointer;
			typedef				ft::random_access_iterator<value_type>	iterator;
			typedef				ft::random_access_iterator<const value_type>	const_iterator;
			typedef				ft::reverse_iterator<iterator>	reverse_iterator;
			typedef				ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef typename	allocator_type::size_type						size_type;
			typedef typename	ft::iterator_traits<iterator>::difference_type	difference_type;

		private:

			allocator_type	_alloc;
			pointer			_start;
			pointer			_end;
			pointer			_end_capacity;

			const size_type	computeCapacity( size_type __n )
			{
				if (this->capacity() > (this->size() + __n))
					return (this->capacity());
				const size_type __len = size() + std::max(size(), __n);
				return (__len < size() || __len > max_size()) ? max_size() : __len;
			}

		public:

		/********************************/
		/*			CONSTRUCTOR			*/
		/********************************/
				/*	Default	*/
			explicit vector(const allocator_type& alloc = allocator_type()) :
					_alloc(alloc),
					_start(0),
					_end(0),
					_end_capacity(0){}
				/*	Fill	*/
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
					_alloc(alloc)
			{
				this->_start = this->_alloc.allocate(n);
				this->_end_capacity = this->_start + n;
				this->_end = this->_start;
				while(n--)
				{
					this->_alloc.construct(this->_end, val);
					this->_end++;
				}
			}

				/*	Range	*/
			template <class InputIterator>
         	vector (InputIterator first, InputIterator last, 
				const allocator_type& alloc = allocator_type(),
				typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) 
				: _alloc(alloc) {
				difference_type n = last - first;
				this->_start = this->_alloc.allocate(n);
				this->_end_capacity = this->_start + n;
				this->_end = this->_start;
				while (n--) {
						this->_alloc.construct(this->_end, *first);
						this->_end++;
						first++;
					}
			}
				/*	Copy	*/
			vector	(const vector& x):
				_alloc(x.get_allocator())
			{
				this->_start = this->_alloc.allocate(x.size());
				this->_end_capacity = this->_start + x.size();
				this->_end = this->_start;
				this->assign(x.begin(), x.end());
			}
			~vector()
			{
				this->clear();
				this->_alloc.deallocate(this->_start, this->capacity());
			}

			vector &		operator=( vector const & rhs )
			{
				if (*this != rhs)
				{
					this->clear();
					this->assign(rhs.begin(), rhs.end());
				}
				return (*this);
			}

		/********************************/
		/*			ITERATORS			*/
		/********************************/

		iterator	begin()
		{
			return (this->_start);
		}
		const_iterator	begin() const
		{
			return (this->_start);
		}
		iterator	end()
		{
			return (this->_end);
		}
		const_iterator	end() const
		{
			return (this->_end);
		}
		reverse_iterator	rbegin()
		{
			return (reverse_iterator(this->_end));
		}
		const_reverse_iterator	rbegin() const
		{
			return (reverse_iterator(this->_end));
		}
		reverse_iterator	rend()
		{
			return (reverse_iterator(this->_start));
		}
		const_reverse_iterator	rend() const
		{
			return (reverse_iterator(this->_start));
		}

		/********************************/
		/*			MODIFIERS			*/
		/********************************/
		
		/*single element*/
		iterator	insert(iterator position, const value_type& val)
		{
			size_type	index = ft::distance(this->begin(), position);
			this->reserve(computeCapacity(1));
			iterator	new_pos = this->begin() + index;
			iterator	it = this->end();
			size_type	size = this->size();
			while (it != new_pos)
			{
				_alloc.construct(this->_start + size, this->_start[size - 1]);
				_alloc.destroy(this->_start + size - 1);
				size--;
				it--;
			}
			_alloc.construct(this->_start + size, val);
			this->_end++;
			return (iterator(this->_start + index));
		}
		/*fill*/
		void	insert(iterator position, size_type n, const value_type &val)
		{
			if (n == 0)
				return;
			size_type new_size = this->size() + n;
			size_type insert_idx = ft::distance(this->begin(), position);
			ptrdiff_t i = this->size() - 1;
			size_type j;
			this->reserve(computeCapacity(n));
			while (i >= static_cast<ptrdiff_t>(insert_idx))
			{
				this->_alloc.construct(this->_start + n + i, this->_start[i]);
				this->_alloc.destroy(this->_start + i);
				i--;
			}
			j = 0;
			while (j < n)
			{
				this->_alloc.construct(this->_start + insert_idx + j, val);
				j++;
			}
			this->_end = this->_start + new_size;
		}
		/*range*/
		template <class InputIterator>
		void	insert(iterator position, InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = 0)
		{
			size_type dist = ft::distance(first, last);
			if (dist == 0)
				return;
			size_type new_size = this->size() + dist;
			size_type insert_idx = ft::distance(this->begin(), position);
			ptrdiff_t i = this->size() - 1;
			InputIterator tmp;
			this->reserve(computeCapacity(dist));
			while (i >= static_cast<ptrdiff_t>(insert_idx))
			{
				this->_alloc.construct(this->_start + dist + i, this->_start[i]);
				this->_alloc.destroy(this->_start + i);
				i--;
			}
			tmp = first;
			i = 0;
			while (tmp != last)
			{
				this->_alloc.construct(this->_start + insert_idx + i, *tmp);
				tmp++;
				i++;
			}
			this->_end = this->_start + new_size;
		}

		/*range*/
		template <class InputIterator>
		void	assign(InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = 0)
		{
			size_type dist = ft::distance(first, last);
			this->clear();
			if (this->capacity() >= dist)
			{
				for (; first != last; first++, this->_end++)
				{
					this->_alloc.construct(this->_end, *first);
				}
			}
			else
			{
				this->reserve(dist);
				this->assign(first, last);
			}
		}
		/*fill*/
		void	assign(size_type n, const value_type &val)
		{
			this->clear();
			if (n == 0)
				return;
			this->reserve(n);
			while (n--)
			{
				this->_alloc.construct(this->_end, val);
				this->_end++;
			}
		}

		void	push_back(const value_type &val)
		{
			if (this->_end == this->_end_capacity)
			{
				this->reserve(computeCapacity(1));
			}
			this->_alloc.construct(this->_end, val);
			this->_end++;
		}
		void	pop_back(void)
		{
			--this->_end;
			this->_alloc.destroy((this->_end));
		}

		iterator	erase(iterator position)
		{
			return (erase(position, position + 1));
		}
		iterator	erase(iterator first, iterator last)
		{
			if (first != this->end() && first != last)
			{
				pointer p_first = &(*first);
				for (; &(*first) != &(*last); first++)
					_alloc.destroy(&(*first));
				for (int i = 0; i < _end - &(*last); i++)
				{
					_alloc.construct(p_first + i, *(&(*last) + i));
					_alloc.destroy(&(*last) + i);
				}
				_end -= (&(*last) - p_first);
				return (iterator(p_first));
			}
			return (first);
		}

		void	swap(vector &x)
		{
			std::swap(this->_start, x._start);
			std::swap(this->_end, x._end);
			std::swap(this->_end_capacity, x._end_capacity);
		}

		void clear(void)
		{
			this->erase(this->begin(), this->end());
		}
		/********************************/
		/*			CAPACITY			*/
		/********************************/

		size_type	size() const
		{
			return (this->_end - this->_start);
		}
		
		size_type	capacity ( void ) const
		{
			return (size_type(const_iterator(this->_end_capacity) - this->begin()));
		}

		
		size_type	max_size()const
		{
			return (allocator_type().max_size());
		}

		void	reserve(size_type n)
		{
			if (n > this->max_size())
				throw std::length_error("vector::reserve");
			if (this->capacity() < n)
			{
				const size_type old_size = this->size();
				pointer tmp = this->_alloc.allocate(n, this->_start);
				for (size_type i = 0; i < this->size(); i++)
				{
					this->_alloc.construct(tmp + i, this->_start[i]);
					this->_alloc.destroy(&(this->_start[i]));
				}
				this->_alloc.deallocate(this->_start, this->capacity());
				this->_start = tmp;
				this->_end = tmp + old_size;
				this->_end_capacity = this->_start + n;
			}
		}

		void	resize(size_type n, value_type val = value_type())
		{
			if (n > max_size())
				throw std::length_error("vector::resize");
			else if (n < this->size())
			{
				while (this->size() > n)
				{
					--this->_end;
					this->_alloc.destroy(this->_end);
				}
			}
			else
			{
				this->reserve(n);
				this->insert(this->end(), (n - this->size()), val);
			}
		}

		bool	empty() const
		{
			return (this->start == this->end);
		}

		/********************************/
		/*			ELEMENT	ACCESS		*/
		/********************************/

		reference		operator[] (size_type n)
		{
			return (static_cast<reference>(*(this->_start + n)));
		}
		const_reference	operator[] (size_type n) const
		{
			return (static_cast<const_reference>(*(this->_start + n)));
		}
		
		reference		at(size_type n)
		{
			if (n >= this->size())
			{
				std::string error("vector::at: n (wich is ");
				error += ft::to_string(n);
				error += std::string(") >= this->size() (wich is ");
				error += ft::to_string(this->size());
				error += std::string(")");
				throw(std::out_of_range(error));
			}
			return (this->operator[](n));
		}
		const_reference	at(size_type n) const
		{
			if (n >= this->size())
			{
				std::string error("vector::at: n (wich is ");
				error += ft::to_string(n);
				error += std::string(") >= this->size() (wich is ");
				error += ft::to_string(this->size());
				error += std::string(")");
				throw(std::out_of_range(error));
			}
			return (this->operator[](n));
		}
		reference		front()
		{
			return (*(this->_start));
		}

		const_reference	front() const
		{
			return (*(this->_start));
		}
		reference		back(void)
		{
			return (*(this->_end - 1));
		}

		const_reference	back(void) const
		{
			return (*(this->_end - 1));
		}

		/********************************/
		/*			ALLOCATOR			*/
		/********************************/

		allocator_type	get_allocator(void) const
		{
			return (this->_alloc);
		}
	};

	/********************************/
	/*			  SWAP				*/
	/********************************/

	template <class T, class Alloc>
	void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
	{
		x.swap(y);
	}

	/********************************/
	/*		RELATIONAL OPERATORS	*/
	/********************************/
	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (!(rhs < lhs));
	}

	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (!(lhs < rhs));
	}
};

#endif