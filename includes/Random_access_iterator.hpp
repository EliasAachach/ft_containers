#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include <iostream>
# include <string>
# include "Utils.hpp"

namespace ft
{
	template <typename T>
	class Random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T>
	{

		public:

			typedef	ft::iterator<ft::random_access_iterator_tag, T>::pointer	pointer;
			Random_access_iterator();
			Random_access_iterator( Random_access_iterator const & src );
			~Random_access_iterator();

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

			Random_access_iterator &		operator=( Random_access_iterator const & rhs )
			{
                if (this == &rhs)
		            return (*this);
                this->_elem = rhs._elem;
                return (*this);
			}
			Random_access_iterator			operator+(difference_type nbr)
			{
				return (this->_elem + nbr);
			}
			Random_access_iterator			operator+(Random_access_iterator const & rhs)
			{
				return (this->_elem + rhs.base());
			}
			Random_access_iterator			operator-(difference_type nbr)
			{
				return (this->_elem - nbr);
			}
			Random_access_iterator			operator-(Random_access_iterator const & rhs)
			{
				return (this->_elem - rhs.base());
			}
			Random_access_iterator &		operator+=(difference_type nbr)
			{
				_elem += nbr;
				return (*this);
			}
			Random_access_iterator &		operator+=(Random_access_iterator const & rhs)
			{
				_elem += rhs.base();
				return (*this);
			}
			Random_access_iterator &		operator-=(difference_type nbr)
			{
				_elem -= nbr;
				return (*this);
			}
			Random_access_iterator &		operator-=(Random_access_iterator const & rhs)
			{
				_elem -= rhs.base();
				return (*this);
			}
			Random_access_iterator			operator*(void)
			{
				return (*_elem);
			} 
	/********************************/
	/*	Incrementation Operators	*/
	/********************************/
			Random_access_iterator &		operator++()
			{
				_elem++;
				return (this);
			}
			Random_access_iterator &		operator++(int)
			{
				Random_access_iterator	ret(*this);
				_elem++;
				return (ret);
			}
			Random_access_iterator &		operator--()
			{
				_elem--;
				return (this);
			}
			Random_access_iterator &		operator--(int)
			{
				Random_access_iterator	ret(*this);
				_elem--;
				return (ret);
			}
			reference operator[](difference_type n) 
			{
				return (*(operator+(n)));
			}

		private:
			pointer	_elem;

	};

	/********************************/
	/*		Comparison Operators	*/
	/********************************/

	template <typename T>
	bool		operator<(ft::Random_access_iterator<T> const lhs, ft::Random_access_iterator<T> const rhs)
	{
		return (lhs->base() < rhs->base());
	}
	template <typename T_L, typename T_R>
	bool		operator<(ft::Random_access_iterator<T_L> const lhs, ft::Random_access_iterator<T_R> const rhs)
	{
		return (lhs->base() < rhs->base());
	}

	template <typename T>
	bool		operator>(ft::Random_access_iterator<T> const lhs, ft::Random_access_iterator<T> const rhs)
	{
		return (lhs->base() > rhs->base());
	}
	template <typename T_L, typename T_R>
	bool		operator>(ft::Random_access_iterator<T_L> const lhs, ft::Random_access_iterator<T_R> const rhs)
	{
		return (lhs->base() > rhs->base());
	}

	template <typename T>
	bool		operator<=(ft::Random_access_iterator<T> const lhs, ft::Random_access_iterator<T> const rhs)
	{
		return (lhs->base() <= rhs->base());
	}
	template <typename T_L, typename T_R>
	bool		operator<=(ft::Random_access_iterator<T_L> const lhs, ft::Random_access_iterator<T_R> const rhs)
	{
		return (lhs->base() <= rhs->base());
	}

	template <typename T>
	bool		operator>=(ft::Random_access_iterator<T> const lhs, ft::Random_access_iterator<T> const rhs)
	{
		return (lhs->base() >= rhs->base());
	}
	template <typename T_L, typename T_R>
	bool		operator>=(ft::Random_access_iterator<T_L> const lhs, ft::Random_access_iterator<T_R> const rhs)
	{
		return (lhs->base() >= rhs->base());
	}

	template <typename T>
	bool		operator==(ft::Random_access_iterator<T> const lhs, ft::Random_access_iterator<T> const rhs)
	{
		return (lhs->base() == rhs->base());
	}
	template <typename T_L, typename T_R>
	bool		operator==(ft::Random_access_iterator<T_L> const lhs, ft::Random_access_iterator<T_R> const rhs)
	{
		return (lhs->base() == rhs->base());
	}

	template <typename T>
	bool		operator!=(ft::Random_access_iterator<T> const lhs, ft::Random_access_iterator<T> const rhs)
	{
		return (lhs->base() != rhs->base());
	}
	template <typename T_L, typename T_R>
	bool		operator!=(ft::Random_access_iterator<T_L> const lhs, ft::Random_access_iterator<T_R> const rhs)
	{
		return (lhs->base() != rhs->base());
	}

	template<typename T>
    ft::Random_access_iterator<T> operator+(typename ft::Random_access_iterator<T>::difference_type n, typename ft::Random_access_iterator<T>& rai)
    {
		return (&(*rai) + n);
    }
	template<typename T>
    ft::Random_access_iterator<T> operator-(typename ft::Random_access_iterator<T>::difference_type n, typename ft::Random_access_iterator<T>& rai)
    {
		return (&(*rai) - n);
    }
	template <typename T>
    typename ft::Random_access_iterator<T>::difference_type	operator-(const ft::Random_access_iterator<T> lhs, const ft::Random_access_iterator<T> rhs)
    {
        return (lhs.base() - rhs.base());
    }
    template<typename T_L, typename T_R>
    typename ft::Random_access_iterator<T_L>::difference_type	operator-(const ft::Random_access_iterator<T_L> lhs, const ft::Random_access_iterator<T_R> rhs)
    {
        return (lhs.base() - rhs.base());
    }
};

#endif /* ****************************************** RANDOM_ACCESS_ITERATOR_H */