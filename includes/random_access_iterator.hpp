#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include <iostream>
# include <string>
# include <string>
# include "Utils.hpp"

namespace ft
{
	template <typename T>
	class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T>
	{

		public:

			typedef	typename	ft::iterator<ft::random_access_iterator_tag, T>::pointer			pointer;
			typedef typename	ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename	ft::iterator<ft::random_access_iterator_tag, T>::value_type			value_type;
			typedef typename	ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
			typedef typename	ft::iterator<ft::random_access_iterator_tag, T>::reference			reference;
		
		private:
			pointer	_elem;

		public:

			/*	default constructor	*/
			random_access_iterator(): _elem(0)
			{
			}

			/*	copy constructor	*/
			random_access_iterator( random_access_iterator const & src ): _elem(src.base())
			{
			}

			/*	constructor from a pointer	*/
			random_access_iterator(pointer elem): _elem(elem)
			{
			}

	/********************************/
	/*			ACCESSORS			*/
	/********************************/

			pointer	base() const
			{
				return (this->_elem);
			}

	/********************************/
	/*		Arithmetic Operators	*/
	/********************************/

			random_access_iterator &		operator=( random_access_iterator const & rhs )
			{
                if (this == &rhs)
		            return (*this);
                this->_elem = rhs._elem;
                return (*this);
			}
			random_access_iterator			operator+(difference_type nbr)
			{
				return (this->_elem + nbr);
			}
			random_access_iterator			operator+(random_access_iterator const & rhs)
			{
				return (this->_elem + rhs.base());
			}
			random_access_iterator			operator-(difference_type nbr)
			{
				return (this->_elem - nbr);
			}
			random_access_iterator &		operator+=(difference_type nbr)
			{
				_elem += nbr;
				return (*this);
			}
			random_access_iterator &		operator+=(random_access_iterator const & rhs)
			{
				_elem += rhs.base();
				return (*this);
			}
			random_access_iterator &		operator-=(difference_type nbr)
			{
				_elem -= nbr;
				return (*this);
			}
			random_access_iterator &		operator-=(random_access_iterator const & rhs)
			{
				_elem -= rhs.base();
				return (*this);
			}
			reference			operator*(void) const
			{
				return (*_elem);
			}
			pointer				operator->(void) const
			{
				return (&(this->_elem));
			}
	/********************************/
	/*	Incrementation Operators	*/
	/********************************/
			random_access_iterator &	operator++()
			{
				_elem++;
				return (*this);
			}
			random_access_iterator		operator++(int)
			{
				random_access_iterator	ret(*this);
				_elem++;
				return (ret);
			}
			random_access_iterator &	operator--()
			{
				_elem--;
				return (*this);
			}
			random_access_iterator		operator--(int)
			{
				random_access_iterator	ret(*this);
				_elem--;
				return (ret);
			}
			reference operator[](difference_type n) 
			{
				return (*(operator+(n)));
			}
			operator random_access_iterator<const T>() const
			{
				return (random_access_iterator<const T>(this->_elem));
			}
	};

	/********************************/
	/*		Comparison Operators	*/
	/********************************/

	template <typename T>
	bool		operator<(ft::random_access_iterator<T> const lhs, ft::random_access_iterator<T> const rhs)
	{
		return (lhs.base() < rhs.base());
	}
	template <typename T_L, typename T_R>
	bool		operator<(ft::random_access_iterator<T_L> const lhs, ft::random_access_iterator<T_R> const rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <typename T>
	bool		operator>(ft::random_access_iterator<T> const lhs, ft::random_access_iterator<T> const rhs)
	{
		return (lhs.base() > rhs.base());
	}
	template <typename T_L, typename T_R>
	bool		operator>(ft::random_access_iterator<T_L> const lhs, ft::random_access_iterator<T_R> const rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <typename T>
	bool		operator<=(ft::random_access_iterator<T> const lhs, ft::random_access_iterator<T> const rhs)
	{
		return (lhs.base() <= rhs.base());
	}
	template <typename T_L, typename T_R>
	bool		operator<=(ft::random_access_iterator<T_L> const lhs, ft::random_access_iterator<T_R> const rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <typename T>
	bool		operator>=(ft::random_access_iterator<T> const lhs, ft::random_access_iterator<T> const rhs)
	{
		return (lhs.base() >= rhs.base());
	}
	template <typename T_L, typename T_R>
	bool		operator>=(ft::random_access_iterator<T_L> const lhs, ft::random_access_iterator<T_R> const rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <typename T>
	bool		operator==(ft::random_access_iterator<T> const lhs, ft::random_access_iterator<T> const rhs)
	{
		return (lhs.base() == rhs.base());
	}
	template <typename T_L, typename T_R>
	bool		operator==(ft::random_access_iterator<T_L> const lhs, ft::random_access_iterator<T_R> const rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <typename T>
	bool		operator!=(ft::random_access_iterator<T> const lhs, ft::random_access_iterator<T> const rhs)
	{
		return (lhs.base() != rhs.base());
	}
	template <typename T_L, typename T_R>
	bool		operator!=(ft::random_access_iterator<T_L> const lhs, ft::random_access_iterator<T_R> const rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template<typename T>
    ft::random_access_iterator<T> operator+(typename ft::random_access_iterator<T>::difference_type n, typename ft::random_access_iterator<T>& rai)
    {
		return (&(*rai) + n);
    }
	template<typename T>
    ft::random_access_iterator<T> operator-(typename ft::random_access_iterator<T>::difference_type n, typename ft::random_access_iterator<T>& rai)
    {
		return (&(*rai) - n);
    }
	template <typename T>
    typename ft::random_access_iterator<T>::difference_type	operator-(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() - rhs.base());
    }
    template<typename T_L, typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type	operator-(const ft::random_access_iterator<T_L> lhs, const ft::random_access_iterator<T_R> rhs)
    {
        return (lhs.base() - rhs.base());
    }
};

#endif /* ****************************************** RANDOM_ACCESS_ITERATOR_H */