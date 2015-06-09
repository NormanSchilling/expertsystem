/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 13:37:50 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/09 16:19:27 by nschilli         ###   ########.fr       */
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

	// this->weight = cpy.getWeight();
	return ( *this );
}