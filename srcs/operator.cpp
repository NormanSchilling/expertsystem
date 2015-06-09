/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 16:15:58 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/09 16:16:20 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <operator.hpp>

/*
** CONSTRUCT & DESTRUCT
*/
Operator::Operator( void )
{
	return ;
}

Operator::Operator( Operation const & cpy )
{
	*this = cpy;
}

Operator::~Operator( void )
{
	return ;
}

/*
** OPERATOR
*/
Operator &	Operator::operator=( Operator const & cpy )
{
	if ( this == &cpy )
		return ( *this );

	return ( *this );
}

/*
** METHOD
*/
