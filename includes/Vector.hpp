#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <stdexcept>
# include "Random_access_iterator.hpp"
# include "Utils.hpp"

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
			typedef typename	allocator_type::reference		reference
			typedef typename	allocator_type::const_reference	const_reference
			typedef typename	allocator_type::pointer		pointer
			typedef typename	allocator_type::const_pointer	const_pointer
			typedef typename 	Alloc::reference		reference;
			typedef typename 	Alloc::const_reference	const_reference;
			typedef typename 	Alloc::pointer			pointer;
			typedef typename 	Alloc::const_pointer	const_pointer;
			typedef				ft::Random_access_iterator<value_type>	iterator;
			typedef				ft::Random_access_iterator<const value_type>	const_iterator;
			typedef				ft::Reverse_iterator<iterator>	reverse;
			typedef				ft::Reverse_iterator<const_iterator>	const_reverse;
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
			~Vector();
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
	/*			METHODS				*/
	/********************************/
	
	/********************************/
	/*			CAPACITY			*/
	/********************************/

	size_type	size()
	{
		return (this->_end - this->_start);
	}

	};
};

#endif /* ********************************************************** VECTOR_H */