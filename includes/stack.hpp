#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{
	template < typename T, typename Container = ft::vector<T>>
	class stack
	{
		public:
		/********************************/
		/*			TYPEDEFS			*/
		/********************************/
			typedef				Container				container_type;
			typedef typename	Container::value_type	value_type;
			typedef typename	Container::size_type	size_type;
		
		protected:
		/********************************/
		/*		PRIVATE MEMBER			*/
		/********************************/
			container_type	_c;
		
		public:
		/********************************/
		/*			CONSTRUCTOR			*/
		/********************************/
		explicit stack (const container_type& ctnr = container_type()) : _c(ctnr)
		{
		}

		/********************************/
		/*		MEMBER FUNCTIONS		*/
		/********************************/
		bool	empty() const
		{
			return(this->_c.empty());
		}
		
		size_type	size() const
		{
			return (this->_c.size());
		}

		value_type &	top()
		{
			return(this->_c.back());
		}
		const	value_type &	top()
		{
			return(this->_c.back());
		}

		void	push(const value_type &val)
		{
			this->_c.push_back(val);
		}
		void	push()
		{
			this->_c.pop_back();
		}
	};
}

#endif