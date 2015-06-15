/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expertsystem.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 13:40:26 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/15 15:45:47 by nschilli         ###   ########.fr       */
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
		void			get_max_ratio(void);
		std::string		get_bracket(std::string numeric);
		std::string		simplification_bracket(std::string numeric, int c);
		char			resolve_bracket(std::string bracket);
		std::string		resolve_and(std::string numeric);
		std::string		resolve_or(std::string numeric);
		std::string		resolve_xor(std::string numeric);
		std::string		numerize(std::string part);
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
		int					max_ratio_nbr;
		float				max_ratio;

};

#endif