#ifndef PAIR_HPP
# define PAIR_HPP

# include <iostream>

namespace ft
{
	template <class T1, class T2>
	struct pair
	{
	/** ************************************************************************** */
	/**                                MEMBER TYPE                                 */
	/** ************************************************************************** */
		typedef T1		first_type;
		typedef	T2		second_type;

	/** ************************************************************************** */
	/**                             MEMBER VARIABLES                               */
	/** ************************************************************************** */
		first_type		first;
		second_type		second;

	/** ************************************************************************** */
	/**                                CONSTRUCTORS                                */
	/** ************************************************************************** */
		pair () :
			first(T1()),
			second(T2())
		{}

		template <class U, class V>
		pair ( const pair<U,V> &pr ) :
			first(pr.first),
			second(pr.second)
		{}

		pair (const first_type& a, const second_type& b) :
			first(a),
			second(b)
		{}

		~pair()
		{}

	/** ************************************************************************** */
	/**                                 OPERATORS                                  */
	/** ************************************************************************** */
		pair	&operator= ( const pair& pr )
		{
			if (*this != pr)
			{
				this->first = pr.first;
				this->second = pr.second;
			}
			return (*this);
		}
	};

	/** ************************************************************************** */
	/**                           COMPARAISON OPERATORS                            */
	/** ************************************************************************** */

	template <class T1, class T2>
	bool operator== ( const pair<T1, T2>& lhs, const pair<T1, T2>& rhs )
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class T1, class T2>
	bool operator!= ( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator<  ( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second ));
	}

	template <class T1, class T2>
	bool operator<= ( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{
		return !(rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>  ( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{
		return (rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>= ( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{
		return !(lhs < rhs);
	}

	template <class T1, class T2>
	pair<T1, T2> make_pair ( T1 x, T2 y )
	{
		return (pair<T1, T2>(x, y));
	}
};

template <typename T, typename U>
std::ostream &operator<<(std::ostream &os, const ft::pair<T, U> &pair)
{
	os << "[" << pair.first << "]=\"" << pair.second << "\"";
	return os;
}
template <typename T, typename U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &pair)
{
	os << "[" << pair.first << "]=\"" << pair.second << "\"";
	return os;
}



#endif
