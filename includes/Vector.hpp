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
			typedef				ft::Random_access_iterator<value_type>	iterator;
			typedef				ft::Random_access_iterator<const value_type>	const_iterator;
			typedef				ft::Reverse_iterator<iterator>	reverse;
			typedef				ft::Reverse_iterator<const_iterator>	const_reverse;

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

				/*	Copy	*/
			Vector( Vector const & src );
			~Vector();

			Vector &		operator=( Vector const & rhs );

				/*	methods	*/

			typedef	T		value_type;
			typedef Alloc	allocator_type;
			typedef typename Alloc::reference		reference;
			typedef typename Alloc::const_reference	const_reference;
			typedef typename Alloc::pointer			pointer;
			typedef typename Alloc::const_pointer	const_pointer;
			typedef typename iterator
			typedef typename const_iterator
			typedef typename reverse_iterator
			typedef typename const_reverse_iterator
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type
			typedef typename size_type

	};
};

#endif /* ********************************************************** VECTOR_H */