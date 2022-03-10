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

		typedef _Iterator												iterator_type;
		typedef typename iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename iterator_traits<Iterator>::reference			reference;
		typedef typename iterator_traits<Iterator>::pointer				pointer;

	public:

	/********************************/
	/*			CONSTRUCTOR			*/
	/********************************/

		Reverse_iterator(): _current(){};
		explicit Reverse_iterator(iterator_type it): _current(it){};
		reverse_iterator (const reverse_iterator& other) :	_current(other._current){};
		template <class Iter>
  		reverse_iterator (const reverse_iterator<Iter>& rev_it): _current(rev_it.base()){};
		~Reverse_iterator();

	/********************************/
	/*			ACCESSORS			*/
	/********************************/

		iterator_type	base() const
		{
			return (this->_curr);
		}
	/********************************/
	/*			OPERATORS			*/
	/********************************/
	
	};
};

#endif