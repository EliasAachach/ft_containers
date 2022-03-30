#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <stdexcept>
# include "Random_access_iterator.hpp"
# include "Reverse_iterator.hpp"
# include "Utils.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "operator_utils.hpp"

namespace ft
{
template < typename T, class Alloc = std::allocator<T> >
	class Vector
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
			typedef				ft::Random_access_iterator<value_type>	iterator;
			typedef				ft::Random_access_iterator<const value_type>	const_iterator;
			typedef				ft::Reverse_iterator<iterator>	reverse;
			typedef				ft::Reverse_iterator<const_iterator>	const_reverse;
			typedef typename	allocator_type::size_type						size_type;
			typedef typename	ft::Iterator_traits<iterator>::difference_type	difference_type;

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
			explicit Vector(const allocator_type& alloc = allocator_type()) :
					_alloc(alloc),
					_start(0),
					_end(0),
					_end_capacity(0){}
				/*	Fill	*/
			explicit Vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
					_alloc(alloc)
			{
				this->_start = this->_alloc.allocate(n);
				this->_end_capacity = this->_start + n;
				this->end = this->_start;
				while(n--)
				{
					this->_alloc.construct(this->_end, val);
					this->end++;
				}
			}

				/*	Range	*/
		template <class InputIterator>
		Vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) :
					_alloc(alloc)
			{
				difference_type	n = ft::distance(first, last);
				this->_start = this->_alloc.allocate(n);
				this->_end_capacity = this->_start + n;
				this->end = this->_start;
				while(n--)
				{
					this->push_back(*first++);
				}
			}
				/*	Copy	*/
			Vector	(const Vector& x):
				_alloc(x.get_allocator())
			{
				this->_start = this->_alloc.allocate(x.size());
				this->_end_capacity = this->_start + x.size();
				this->_end = this->_start;
				this->assign(x.begin(), x.end());
			}
			~Vector()
			{
				this->clear();
				this->_alloc.deallocate(this->_start, this->capacity());
			}

			Vector &		operator=( Vector const & rhs )
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
		reverse	rbegin()
		{
			return (reverse_iterator(this->_end));
		}
		const_reverse	rbegin() const
		{
			return (reverse_iterator(this->_end));
		}
		reverse	rend()
		{
			return (reverse_iterator(this->_start));
		}
		const_reverse	rend() const
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
		/********************************/
		/*			CAPACITY			*/
		/********************************/

		size_type	size()
		{
			return (this->_end - this->_start);
		}
		size_type	capacity()	const
		{
			return (size_type(this->_end_capacity - this->begin()));
		}
		size_type	max_size()const
		{
			return (allocator_type().max_size());
		}
		void	reserve (size_type n)
		{
			if (n > this->max_size())
			{
				throw (std::length_error("vector::reserve"));
			}
			if (n > this->capacity())
			{
				pointer	new_start = NULL;
				new_start = this->_alloc.allocate(n);
				pointer	new_end = new_start;
				for (size_type i = 0; i < this->size(); i++)
				{
					this->_alloc.construct(new_start + i, this->_start[i]);
					this->_alloc.destroy(this->_start[i]);
					new_end++;
				}
				this->_alloc.deallocate(this->_start, this->capacity());
				this->_start = new_start;
				this->_end = new_end;
				this->_end_capacity = this->_start + n;
			}
		}
	};
};

#endif /* ********************************************************** VECTOR_H */