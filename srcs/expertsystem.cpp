/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expertsystem.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 13:37:50 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/08 15:04:29 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ExpertSystem.hpp>

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
void			ExpertSystem::fetch

void	 		ExpertSystem::parsing_init_fact(std::string line)
{
	std::smatch				m;
	std::regex				e( "#" );

	if ( line[0] == '=' )
	{
		std::regex_search( line, m, e );
		this->init_fact = line.substr( 0, m.position(0) );
		this->init_fact.erase(std::remove(this->init_fact.begin(), this->init_fact.end(),' '), this->init_fact.end());
	}
}

void	 		ExpertSystem::parsing_init_queries(std::string line)
{
	std::smatch				m;
	std::regex				e( "#" );

	if ( line[0] == '?' )
	{
		std::regex_search( line, m, e );
		this->init_queries = line.substr( 0, m.position(0) );
		this->init_queries.erase(std::remove(this->init_queries.begin(), this->init_queries.end(),' '), this->init_queries.end());
	}
}