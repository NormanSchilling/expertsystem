/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 13:37:50 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/11 16:56:34 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rule.hpp>

/*
** CONSTRUCT & DESTRUCT
*/
Rule::Rule( void )
{
	return ;
}

Rule::Rule( std::string rule, std::vector<Fact*> *init_fact ) : rule(rule)
{
	std::string				operation;
	std::string				sign;
	std::string				result;
	std::smatch				m;
	std::regex				e( "<=>|=>" );

	this->set = 0;
	std::regex_search( this->rule, m, e );
	operation = this->rule.substr(0, m.position(0) );
	operation.erase(std::remove(operation.begin(), operation.end(), ' '), operation.end());
	sign = this->rule.substr(m.position(0), 3 );
	sign.erase(std::remove(sign.begin(), sign.end(), ' '), sign.end());
	result = this->rule.substr(m.position(0) + 3, m.position(1) );
	result.erase(std::remove(result.begin(), result.end(), ' '), result.end());

	this->operation = Part( operation, init_fact );

	return ;
}


Rule::Rule( Rule const & cpy )
{
	*this = cpy;
}

Rule::~Rule( void )
{
	return ;
}

/*
** OPERATOR
*/
Rule &	Rule::operator=( Rule const & cpy )
{
	if ( this == &cpy )
		return ( *this );

	return ( *this );
}

/*
** GETTER
*/
std::string	Rule::getRule(void)
{
	return (this->rule);
}