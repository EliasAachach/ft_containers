#include "Utils.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Utils::Utils()
{
}

Utils::Utils( const Utils & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Utils::~Utils()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Utils &				Utils::operator=( Utils const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Utils const & i )
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