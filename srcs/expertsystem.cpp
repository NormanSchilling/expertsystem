/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expertsystem.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 13:37:50 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/12 14:30:26 by nschilli         ###   ########.fr       */
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

	return ( *this );
}

/*
** METHOD
*/
void			ExpertSystem::expert()
{

	// for (unsigned long i = 0; i < this->rules.size(); i++)
	// {
		std::string numeric = "1+(1+1+1)|(0|1)";
		std::cout << count_first_bracket(numeric) << std::endl;
		for (int j = 0; j < count_first_bracket(numeric); j++ )
		{
			get_bracket(numeric);
		}
	// }
}

std::string		ExpertSystem::resolve_and(std::string numeric)
{
	std::string		resolved(numeric.size(), 0);
	int				k = 0;

	for (int i = 0; numeric[i] != '\0'; i++)
	{
		if (numeric[i] == '+')
		{
			k--;
			if (numeric[i - 1] == '1' && numeric[i + 1] == '1')
				resolved[k] = '1';
			else
				resolved[k] = '0';
		}
		resolved[k] = numeric[i];
		k++;
	}
	return (resolved);
}

std::string		ExpertSystem::resolve_or(std::string numeric)
{
	// (void)numeric;
	return (numeric);
}

std::string		ExpertSystem::resolve_xor(std::string numeric)
{
	// (void)numeric;
	return (numeric);
}

void			ExpertSystem::get_bracket(std::string numeric)
{
	std::string		bracket(numeric.size(), 0);

	for (int i = 0; numeric[i] != '\0'; i++)
	{
		if (numeric[i] == '(')
		{
			bracket = simplification_bracket(bracket, i);
			break ;
		}
	}
}

std::string		ExpertSystem::simplification_bracket(std::string numeric, int c)
{
	std::string		tmp(numeric.size(), 0);
	int				j;

	j = 0;
	c++;
	for (int i = c; numeric[i] != ')'; i++)
	{
		tmp[j] = numeric[i];
		j++;
	}
	return (tmp);
}

std::string		ExpertSystem::resolve_bracket(std::string bracket)
{
	std::string		numeric;

	numeric = resolve_and(bracket);
	std::cout << numeric << std::endl;
	return (numeric);
}



void			ExpertSystem::fetch_init_fact()
{
	for (unsigned long i = 0; i < this->init_fact.size(); i++)
	{
		std::cout << this->init_fact[i]->getValue() << std::endl;
		std::cout << this->init_fact[i]->getState() << std::endl;
	}
}

void			ExpertSystem::fetch_init_queries()
{
	for (unsigned long i = 0; i < this->init_queries.size(); i++)
	{
		std::cout << this->init_queries[i]->getValue() << std::endl;
		std::cout << this->init_queries[i]->getState() << std::endl;
	}
}

void			ExpertSystem::fetch_rules()
{
	for (unsigned long i = 0; i < this->rules.size(); i++)
	{
		std::cout << this->rules[i]->getRule() << std::endl;
	}
}

int				ExpertSystem::check_syntax_rule(std::string line)
{
	std::string				tmp;
	std::smatch				m;
	std::regex				e( "#" );
	std::regex				c( "([\\s]{0,1}[(]{0,1}[!]{0,1}[A-Z]{1,1}[)]{0,1}[\\s]{0,1}[+^|]{0,1}[\\s]{0,1})*[<]{0,1}[=]{1,1}[>]{1,1}([\\s]{0,1}[!]{0,1}[A-Z]{1,1}[\\s]{0,1}[+^|]{0,1}[\\s]{0,1})*" );

	if ( line[0] != '\n' && line[0] != '\0' && line[0] != '=' && line[0] != '?')
	{
		std::regex_search( line, m, e );
		tmp = line.substr( 0, m.position(0) );
		if (std::regex_match (tmp, c))
		{
			if (this->count_first_bracket(tmp) == this->count_second_bracket(tmp))
				this->rules.push_back( new Rule( tmp, &(this->init_fact) ) );
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
				this->init_queries.push_back( new Fact( tmp[i], -2 ) );
			}
		}
	}
}