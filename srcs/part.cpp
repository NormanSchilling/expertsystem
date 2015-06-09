/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 13:37:50 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/09 16:19:36 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <part.hpp>

/*
** CONSTRUCT & DESTRUCT
*/
Part::Part( void )
{
	return ;
}

Part::Part( Part const & cpy )
{
	*this = cpy;
}

Part::~Part( void )
{
	return ;
}

/*
** OPERATOR
*/
Part &	Part::operator=( Part const & cpy )
{
	if ( this == &cpy )
		return ( *this );

	// this->weight = cpy.getWeight();
	return ( *this );
}