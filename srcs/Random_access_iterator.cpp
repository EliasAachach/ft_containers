#include "Random_access_iterator.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Random_access_iterator::Random_access_iterator()
{
}

Random_access_iterator::Random_access_iterator( const Random_access_iterator & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Random_access_iterator::~Random_access_iterator()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Random_access_iterator &				Random_access_iterator::operator=( Random_access_iterator const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Random_access_iterator const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */