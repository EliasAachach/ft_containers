#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "Utils.hpp"
# include "Iterator_traits.hpp"

namespace	ft
{
	template <class _Iterator>
	class reverse_iterator : public ft::iterator<typename ft::Iterator_traits<_Iterator>::iterator_category, 
				typename ft::Iterator_traits<_Iterator>::value_type>
	{

	public:

		typedef _Iterator												iterator_type;
		typedef typename Iterator_traits<_Iterator>::difference_type		difference_type;
		typedef typename Iterator_traits<_Iterator>::iterator_category	iterator_category;
		typedef typename Iterator_traits<_Iterator>::reference			reference;
		typedef typename Iterator_traits<_Iterator>::pointer				pointer;
	
	protected:

		iterator_type	_current;

	public:

	/********************************/
	/*			CONSTRUCTOR			*/
	/********************************/

		reverse_iterator(): _current(){};
		explicit reverse_iterator(iterator_type it): _current(it){};
		reverse_iterator (const reverse_iterator& other) :	_current(other._current){};
		template <class Iter>
  		reverse_iterator (const reverse_iterator<Iter>& rev_it): _current(rev_it.base()){};
		~reverse_iterator();

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
			reverse_iterator	tmp = this->_current;
			return(*--tmp);
		}

		/*	Pointer Operators	*/
		pointer		operator->(void) const
		{
			return (&(operator*()));
		}

		/*	Incrementation Operators	*/
		reverse_iterator &	operator++(void)
		{
			this->_current--;
			return (*this);
		}
		reverse_iterator	operator++(int)
		{
			reverse_iterator tmp = *this;
			++(*this);
			return (tmp);
		}
		reverse_iterator &	operator--(void)
		{
			this->_current++;
			return (*this);
		}
		reverse_iterator	operator--(int)
		{
			reverse_iterator tmp = *this;
			--(*this);
			return (tmp);
		}

		/*		Arithmetic Operators	*/

		reverse_iterator	operator+(difference_type n) const
		{
			return (reverse_iterator(this->_current - n));
		}
		reverse_iterator	operator-(difference_type n) const
		{
			return (reverse_iterator(this->_current + n));
		}

		reverse_iterator &	operator+=(difference_type n) const
		{
			this->_current -= n;
			return (*this);
		}
		reverse_iterator &	operator-=(difference_type n) const
		{
			this->_current += n;
			return (*this);
		}

		reference	operator[]( difference_type n ) const
		{
			return *(*this + n);
		}

	};
	/********************************/
	/*			OPERATORS			*/
	/********************************/

		/*		Arithmetic Operators	*/
		template <typename T_L, typename T_R>
		inline typename ft::reverse_iterator<T_L>::difference_type
		operator-(	const ft::reverse_iterator<T_L> lhs, const ft::reverse_iterator<T_R> rhs)
		{
			return ( lhs.base() - rhs.base() );
		}
		template<typename _Iterator>
		inline reverse_iterator<_Iterator>
		operator+(	typename reverse_iterator<_Iterator>::difference_type __n, const reverse_iterator<_Iterator>& __x)
		{
			return reverse_iterator<_Iterator>(__x.base() - __n);
		}

		/*		Relational operators	*/
		template<typename T_L, typename T_R>
		inline bool		operator==(const ft::reverse_iterator<T_L> lhs, const ft::reverse_iterator<T_R> rhs)
		{
			return (lhs.base() == rhs.base());
		}
		template<typename T_L, typename T_R>
		inline bool		operator!=(const ft::reverse_iterator<T_L> lhs, const ft::reverse_iterator<T_R> rhs)
		{
			return !(lhs == rhs);
		}
		template<typename T_L, typename T_R>
		inline bool		operator<(const ft::reverse_iterator<T_L> lhs, const ft::reverse_iterator<T_R> rhs)
		{
			return (rhs.base() < lhs.base());
		}
		template<typename T_L, typename T_R>
		inline bool		operator>(const ft::reverse_iterator<T_L> lhs, const ft::reverse_iterator<T_R> rhs)
		{
			return (rhs < lhs);
		}
		template<typename T_L, typename T_R>
		inline bool		operator<=(const ft::reverse_iterator<T_L> lhs, const ft::reverse_iterator<T_R> rhs)
		{
			return !(rhs < lhs);
		}
		template<typename T_L, typename T_R>
		inline bool		operator>=(const ft::reverse_iterator<T_L> lhs, const ft::reverse_iterator<T_R> rhs)
		{
			return !(lhs < rhs);
		}

};

#endif