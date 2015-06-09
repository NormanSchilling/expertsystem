/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 16:11:25 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/09 16:15:14 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <operation.hpp>

/*
** CONSTRUCT & DESTRUCT
*/
Operation::Operation( void )
{
	return ;
}

Operation::Operation( Operation const & cpy )
{
	*this = cpy;
}

Operation::~Operation( void )
{
	return ;
}

/*
** OPERATOR
*/
Operation &	Operation::operator=( Operation const & cpy )
{
	if ( this == &cpy )
		return ( *this );

	return ( *this );
}

/*
** METHOD
*/
