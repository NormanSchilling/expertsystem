/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgil <jgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 13:37:50 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/11 13:38:28 by jgil             ###   ########.fr       */
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
	std::string		tmp;
	std::smatch		m;
	std::regex		r( "[<]{0,1}=>" );

	std::regex_search(this->rule, m, r);
	tmp = this->rule.substr(m.position(0), 3);
	tmp.erase(std::remove(tmp.begin(), tmp.end(), ' '), tmp.end());
	this->sign = tmp;
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