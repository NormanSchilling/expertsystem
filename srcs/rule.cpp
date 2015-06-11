/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgil <jgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 13:37:50 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/11 14:52:00 by jgil             ###   ########.fr       */
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

Rule::Rule( std::string rule ) : rule(rule)
{
	std::string				operation;
	std::string				sign;
	std::string				result;
	std::smatch				m;
	std::regex				e( "<=>|=>" );

	std::regex_search( this->rule, m, e );
	operation = this->rule.substr(0, m.position(0) );
	operation.erase(std::remove(operation.begin(), operation.end(), ' '), operation.end());
	sign = this->rule.substr(m.position(0), 3 );
	sign.erase(std::remove(sign.begin(), sign.end(), ' '), sign.end());
	result = this->rule.substr(m.position(0) + 3, m.position(1) );
	result.erase(std::remove(result.begin(), result.end(), ' '), result.end());
	std::cout << operation << std::endl;
	this->operation = Part( operation );
	std::cout << sign << std::endl;
	std::cout << result << std::endl;
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