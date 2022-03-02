#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
# include <memory>

namespace ft
{
template < typename T, class Alloc = std::allocator<T> >
	class Vector
	{

		public:

			Vector();
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
			iterator
			const_iterator
			reverse_iterator
			const_reverse_iterator
			difference_type
			size_type

		private:

	};
};

#endif /* ********************************************************** VECTOR_H */