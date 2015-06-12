/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expertsystem.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgil <jgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 13:40:26 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/12 11:42:13 by jgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPERTSYSTEM_HPP
# define EXPERTSYSTEM_HPP

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <fact.hpp>
#include <rule.hpp>

class ExpertSystem
{
	public:

		/*
		** CONSTRUCT & DESTRUCT
		*/
		ExpertSystem( void );
		ExpertSystem( ExpertSystem const & cpy );
		~ExpertSystem( void );

		/*
		** OPERATOR
		*/
		ExpertSystem &	operator=( ExpertSystem const & cpy );

		/*
		** METHOD
		*/
		void			expert(void);
		std::string		numerize(std::string part);
		void			get_bracket(Rule rule);

		void			fetch_init_fact(void);
		void			fetch_init_queries(void);
		void			fetch_rules(void);
		int				check_syntax_rule(std::string line);
		int				count_first_bracket(std::string tmp);
		int				count_second_bracket(std::string tmp);
		void			parsing_init_fact(std::string line);
		void			parsing_init_queries(std::string line);

		/*
		** GETTER
		*/


	private:
		std::vector<Rule*>	rules;
		std::vector<Fact*>	init_fact;
		std::vector<Fact*>	init_queries;

};

#endif