#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include "Utils.hpp"

namespace	ft
{
	template <class Iterator>
	class iterator_traits
	{
	public:

		typedef typename	Iterator::value_type			value_type;
		typedef typename	Iterator::difference_type		difference_type;
		typedef typename	Iterator::pointer				pointer;
		typedef typename	Iterator::reference				reference;
		typedef typename	Iterator::iterator_category		iterator_category;

	};

	template <class T>
	class iterator_traits<T*>
	{
	public:

		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef ft::random_access_iterator_tag	iterator_category;

	};

	template <class T>
	class iterator_traits<const T>
	{
	public:

		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef const T*						pointer;
		typedef const T&						reference;
		typedef ft::random_access_iterator_tag	iterator_category;

	};

	template <typename Iterator>
	typename ft::iterator_traits<Iterator>::difference_type
	distance (Iterator first, Iterator last)
	{
		return (__distance(first, last, typename ft::iterator_traits<Iterator>::iterator_category()));
	}

	template  <typename RandomAccessIterator>
	typename	ft::iterator_traits<RandomAccessIterator>::difference_type
	__distance(RandomAccessIterator first, RandomAccessIterator last, ft::random_access_iterator_tag)
	{
		return (last - first);
	}
	template <typename InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type
	__distance(InputIterator	first, InputIterator last, ft::input_iterator_tag)
	{
		typename ft::iterator_traits<InputIterator>::difference_type	diff;
		for(diff = 0; first != last; ++first, ++diff){}
		return (diff);
	}
	
};

#endif