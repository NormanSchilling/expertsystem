/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 13:40:26 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/16 16:54:19 by nschilli         ###   ########.fr       */
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
		void			count_truefact(std::string operation, std::vector<Fact*> *init_fact);
		std::string		getRule(void);
		int				getSet(void);
		Part 			*getOperation(void);
		Part 			*getResult(void);
		float			getRatio(void);
		int				getNumberFact(void);

		/*
		** SETTER
		*/
		void			setSet(int value);

	private:
		std::string			rule;
		std::string			sign;
		float				number_truefact;
		float				number_fact;
		float				ratio;
		Part				*operation;
		Part				*result;
		int					set;
		std::vector<Fact*>	fact_left;
		std::vector<Fact*>	fact_right;
};

#endif