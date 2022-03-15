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

		/*	Dereference Operators	*/
		reference	operator*(void) const
		{
			Reverse_iterator	tmp = this->_current;
			return(*--tmp);
		}

		/*	Pointer Operators	*/
		pointer		operator->(void) const
		{
			return (&(operator*()));
		}

		/*	Incrementation Operators	*/
		Reverse_iterator &	operator++(void)
		{
			this->_current--;
			return (*this);
		}
		Reverse_iterator	operator++(int)
		{
			Reverse_iterator tmp = *this;
			++(*this);
			return (tmp);
		}
		Reverse_iterator &	operator--(void)
		{
			this->_current++;
			return (*this);
		}
		Reverse_iterator	operator--(int)
		{
			Reverse_iterator tmp = *this;
			--(*this);
			return (tmp);
		}

		/*		Arithmetic Operators	*/

		Reverse_iterator	operator+(diffrence_type n) const
		{
			return (Reverse_iterator(this->_current - n));
		}
		Reverse_iterator	operator-(diffrence_type n) const
		{
			return (Reverse_iterator(this->_current + n));
		}

		Reverse_iterator &	operator+=(diffrence_type n) const
		{
			this->_current -= n;
			return (*this);
		}
		Reverse_iterator &	operator-=(diffrence_type n) const
		{
			this->_current += n;
			return (*this);
		}

		reference	operator[]( difference_type n ) const
		{
			return *(*this + n);
		}

		operator reverse_iterator<const _Iterator> () const
		{
			return (reverse_iterator<const _Iterator>(this->_curr));
		}

	};
	/********************************/
	/*			OPERATORS			*/
	/********************************/

		/*		Arithmetic Operators	*/
		template <typename T_L, typename T_R>
		inline typename ft::Reverse_iterator<T_L>::difference_type
		operator-(	const ft::Reverse_iterator<T_L> lhs, const ft::Reverse_iterator<T_R> rhs)
		{
			return ( lhs.base() - rhs.base() );
		}
		template<typename _Iterator>
		inline Reverse_iterator<_Iterator>
		operator+(	typename Reverse_iterator<_Iterator>::difference_type __n, const Reverse_iterator<_Iterator>& __x)
		{
			return reverse_iterator<_Iterator>(__x.base() - __n);
		}

		/*		Relational operators	*/
		template<typename T_L, typename T_R>
		inline bool		operator==(const ft::Reverse_iterator<T_L> lhs, const ft::Reverse_iterator<T_R> rhs)
		{
			return (lhs.base() == rhs.base());
		}


};

#endif