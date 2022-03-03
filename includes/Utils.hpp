#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <string>

namespace ft
{
	class	random_access_iterator_tag {};

	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};
};

#endif /* *********************************************************** UTILS_H */