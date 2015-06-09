/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 16:01:56 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/09 16:13:52 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_HPP
# define OPERATION_HPP

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <fact.hpp>
#include <operator.hpp>

class Operation
{
	public:

		/*
		** CONSTRUCT & DESTRUCT
		*/
		Operation( void );
		Operation( Operation const & cpy );
		~Operation( void );

		/*
		** OPERATOR
		*/
		Operation &	operator=( Operation const & cpy );

		/*
		** METHOD
		*/

		/*
		** GETTER
		*/

	private:
		Operator	ope;
		Fact		left;
		Fact		right;

};

#endif