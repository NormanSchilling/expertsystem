/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fact.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 15:49:48 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/09 15:57:09 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACT_HPP
# define FACT_HPP

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>

class Fact
{
	public:

		/*
		** CONSTRUCT & DESTRUCT
		*/
		Fact( void );
		Fact( Fact const & cpy );
		~Fact( void );

		/*
		** OPERATOR
		*/
		Fact &	operator=( Fact const & cpy );

		/*
		** METHOD
		*/

		/*
		** GETTER
		*/

	private:
		std::string	value;
		int			state;

};

#endif