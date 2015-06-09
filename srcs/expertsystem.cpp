/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expertsystem.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 13:37:50 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/09 17:04:48 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expertsystem.hpp>

/*
** CONSTRUCT & DESTRUCT
*/
ExpertSystem::ExpertSystem( void )
{
	return ;
}

ExpertSystem::ExpertSystem( ExpertSystem const & cpy )
{
	*this = cpy;
}

ExpertSystem::~ExpertSystem( void )
{
	return ;
}

/*
** OPERATOR
*/
ExpertSystem &	ExpertSystem::operator=( ExpertSystem const & cpy )
{
	if ( this == &cpy )
		return ( *this );

	// this->weight = cpy.getWeight();
	return ( *this );
}

/*
** METHOD
*/
void			ExpertSystem::fetch_init_fact()
{
	for (unsigned long i = 0; i < this->init_fact.size(); i++)
	{
		std::cout << this->init_fact[i]->getValue() << std::endl;
		std::cout << this->init_fact[i]->getState() << std::endl;
	}
}

void	 		ExpertSystem::parsing_init_fact(std::string line)
{
	std::string				tmp;
	std::smatch				m;
	std::regex				e( "#" );

	if ( line[0] == '=' )
	{
		std::regex_search( line, m, e );
		tmp = line.substr( 0, m.position(0) );
		for (int i = 1; tmp[i]; i++)
		{
			if ( tmp[i] >= 'A' && tmp[i] <= 'Z')
			{
				this->init_fact.push_back( new Fact( tmp[i], -2 ) );
			}
		}
	}
}

// void	 		ExpertSystem::parsing_init_queries(std::string line)
// {
// 	std::smatch				m;
// 	std::regex				e( "#" );

// 	if ( line[0] == '?' )
// 	{
// 		std::regex_search( line, m, e );
// 		this->init_queries = line.substr( 0, m.position(0) );
// 		this->init_queries.erase(std::remove(this->init_queries.begin(), this->init_queries.end(),' '), this->init_queries.end());
// 	}
// }