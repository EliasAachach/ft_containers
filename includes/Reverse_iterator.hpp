#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "Utils.hpp"
# include "Iterator_traits.hpp"

namespace	ft
{
	template <class Iterator>
	class Reverse_iterator : public iterator< typename Iterator_traits<Iterator>::iterator_category,
			typename Iterator_traits<Iterator>::value_type,
			typename Iterator_traits<Iterator>::difference_type,
			typename Iterator_traits<Iterator>::pointer,
			typename Iterator_traits<Iterator>::reference> >
	{
	
	protected:

		Iterator	_current;

	public:

		typedef Iterator                        iterator_type;
		typedef typename iterator_traits<Iterator>::difference_type	difference_type;
		typedef typename iterator_traits<Iterator>::reference   reference;
		typedef typename iterator_traits<Iterator>::pointer     pointer;

	public:
		Reverse_iterator(): _current(){};
		~Reverse_iterator();
	};
};

#endif