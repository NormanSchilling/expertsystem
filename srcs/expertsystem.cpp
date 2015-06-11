/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expertsystem.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgil <jgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 13:37:50 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/11 12:17:05 by jgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expertsystem.hpp>

/*
** CONSTRUCT & DESTRUCT
*/
ExpertSystem::ExpertSystem( void )
{
	return ;
}

ExpertSystem::ExpertSystem( ExpertSystem const & cpy )
{
	*this = cpy;
}

ExpertSystem::~ExpertSystem( void )
{
	return ;
}

/*
** OPERATOR
*/
ExpertSystem &	ExpertSystem::operator=( ExpertSystem const & cpy )
{
	if ( this == &cpy )
		return ( *this );

	// this->weight = cpy.getWeight();
	return ( *this );
}

/*
** METHOD
*/
void			ExpertSystem::fetch_init_fact()
{
	for (unsigned long i = 0; i < this->init_fact.size(); i++)
	{
		// std::cout << this->init_fact[i]->getValue() << std::endl;
		// std::cout << this->init_fact[i]->getState() << std::endl;
	}
}

void			ExpertSystem::fetch_init_queries()
{
	for (unsigned long i = 0; i < this->init_queries.size(); i++)
	{
		// std::cout << this->init_queries[i]->getValue() << std::endl;
		// std::cout << this->init_queries[i]->getState() << std::endl;
	}
}

void			ExpertSystem::fetch_rules()
{
	for (unsigned long i = 0; i < this->rules.size(); i++)
	{
		// std::cout << this->rules[i]->getRule() << std::endl;
	}
}

int				ExpertSystem::check_syntax_rule(std::string line)
{
	std::string				tmp;
	std::smatch				m;
	std::regex				e( "#" );
	std::regex				r( "=>" );
	std::regex				c( "([\\s]{0,1}[(]{0,1}[!]{0,1}[A-Z]{1,1}[)]{0,1}[\\s]{0,1}[+^|]{0,1}[\\s]{0,1})*[<]{0,1}[=]{1,1}[>]{1,1}([\\s]{0,1}[!]{0,1}[A-Z]{1,1}[\\s]{0,1}[+^|]{0,1}[\\s]{0,1})*" );

	if ( line[0] != '\n' && line[0] != '\0' && line[0] != '=' && line[0] != '?')
	{
		std::regex_search( line, m, e );
		tmp = line.substr( 0, m.position(0) );
		if (std::regex_match (tmp, c))
		{
			if (this->count_first_bracket(tmp) == this->count_second_bracket(tmp))
				this->rules.push_back( new Rule( tmp ) );
			else
			{
				std::cout << "error syntax : " << tmp << std::endl;
				exit(-1);
			}
		}
		else
		{
			std::cout << "error syntax : " << tmp << std::endl;
			exit(-1);
		}
	}
	return (0);
}

int				ExpertSystem::count_first_bracket(std::string tmp)
{
	int		count = 0;

	for (int i = 0; tmp[i] != '\0'; i++)
	{
		if (tmp[i] == '(')
			count++;
	}
	return (count);
}

int				ExpertSystem::count_second_bracket(std::string tmp)
{
	int		count = 0;

	for (int i = 0; tmp[i] != '\0'; i++)
	{
		if (tmp[i] == ')')
			count++;
	}
	return (count);
}

void	 		ExpertSystem::parsing_init_fact(std::string line)
{
	std::string				tmp;
	std::smatch				m;
	std::regex				e( "#" );

	if ( line[0] == '=')
	{
		std::regex_search( line, m, e );
		tmp = line.substr( 0, m.position(0) );
		for (int i = 1; tmp[i]; i++)
		{
			if ( tmp[i] >= 'A' && tmp[i] <= 'Z')
			{
				this->init_fact.push_back( new Fact( tmp[i], 1 ) );
			}
		}
	}
}

void	 		ExpertSystem::parsing_init_queries(std::string line)
{
	std::string				tmp;
	std::smatch				m;
	std::regex				e( "#" );

	if ( line[0] == '?')
	{
		std::regex_search( line, m, e );
		tmp = line.substr( 0, m.position(0) );
		for (int i = 1; tmp[i]; i++)
		{
			if ( tmp[i] >= 'A' && tmp[i] <= 'Z')
			{
				this->init_fact.push_back( new Fact( tmp[i], -2 ) );
			}
		}
	}
}