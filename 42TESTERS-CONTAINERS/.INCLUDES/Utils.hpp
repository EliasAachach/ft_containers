#ifndef UTILS_HPP
# define UTILS_HPP

# include <cstddef>
# include <string>
# include <sstream>
# include <typeinfo>
# include <iostream>
namespace ft
{
	template <typename T>
	std::string	to_string(T n)
	{
		std::ostringstream ss;
		ss << n;
		return (ss.str());
	}

	struct	random_access_iterator_tag {};
	struct	input_iterator_tag {};
	struct	output_iterator_tag {};
	struct	forward_iterator_tag : public input_iterator_tag {};
	struct	bidirectional_iterator_tag : public forward_iterator_tag {};

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