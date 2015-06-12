/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 13:40:26 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/12 11:17:56 by nschilli         ###   ########.fr       */
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
#include <part.hpp>

class Rule
{
	public:

		/*
		** CONSTRUCT & DESTRUCT
		*/
		Rule( void );
		Rule(std::string line, std::vector<Fact*> *init_fact);
		Rule( Rule const & cpy );
		~Rule( void );

		/*
		** OPERATOR
		*/
		Rule &	operator=( Rule const & cpy );

		/*
		** GETTER
		*/
		std::string		getRule(void);
		Part 			*getOperation(void);

	private:
		std::string		rule;
		std::string		sign;
		Part			*operation;
		// Part			*result;
		int				set;

};

#endif