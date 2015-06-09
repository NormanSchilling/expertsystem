/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fact.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 15:57:19 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/09 16:17:41 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fact.hpp>

/*
** CONSTRUCT & DESTRUCT
*/
Fact::Fact( void )
{
	return ;
}

Fact::Fact( Fact const & cpy )
{
	*this = cpy;
}

Fact::~Fact( void )
{
	return ;
}

/*
** OPERATOR
*/
Fact &	Fact::operator=( Fact const & cpy )
{
	if ( this == &cpy )
		return ( *this );

	// this->weight = cpy.getWeight();
	return ( *this );
}

/*
** METHOD
*/