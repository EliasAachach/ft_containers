#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include <iostream>
# include <string>
# include "Utils.hpp"

namespace ft
{
	class Random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T>
	{

		public:

			Random_access_iterator();
			Random_access_iterator( Random_access_iterator const & src );
			~Random_access_iterator();

			Random_access_iterator &		operator=( Random_access_iterator const & rhs );

		private:

	};
};

#endif /* ****************************************** RANDOM_ACCESS_ITERATOR_H */