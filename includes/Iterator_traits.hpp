#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include "Utils.hpp"

namespace	ft
{
	template <class Iterator>
	class Iterator_traits
	{
	public:

		typedef Iteraor::value_type			value_type;
		typedef Iteraor::distance			difference_type;
		typedef Iteraor::pointer				pointer;
		typedef Iteraor::reference			reference;
		typedef Iteraor::iterator_category	iterator_category;

	};

	template <class T>
	class Iterator_traits<T*>
	{
	public:

		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef ft::random_access_iterator_tag	iterator_category;

	};

	template <class T>
	class Iterator_traits<const T>
	{
	public:

		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef const T*						pointer;
		typedef const T&						reference;
		typedef ft::random_access_iterator_tag	iterator_category;

	};
	
};

#endif