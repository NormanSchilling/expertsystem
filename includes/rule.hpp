/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 13:40:26 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/08 14:50:15 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RULE_HPP
# define RULE_HPP

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>

class Rule
{
	public:

		/*
		** CONSTRUCT & DESTRUCT
		*/
		Rule( void );
		Rule( Rule const & cpy );
		~Rule( void );

		/*
		** OPERATOR
		*/
		Rule &	operator=( Rule const & cpy );

	private:
		std::string		rule;
		std::string		sign;
		Part			operaton;
		Part			result;

};

#endif