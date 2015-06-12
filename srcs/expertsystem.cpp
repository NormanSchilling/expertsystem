/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expertsystem.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgil <jgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 13:37:50 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/12 12:40:40 by jgil             ###   ########.fr       */
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
	for (unsigned long i = 0; i < this->rules.size(); i++)
	{
		std::string		numeric;

		numeric = numerize(this->rules[i]->getOperation()->getPart());
		if (numeric.size() > 0)
		{
			std::cout << this->rules[i]->getOperation()->getPart() << std::endl;
			std::cout << numeric << std::endl;
		// get_bracket(this->rules[i]);
		// std::cout << "TEST : " << this->rules[i]->getOperation()->getPart() << std::endl;
		}
	}
}

std::string		ExpertSystem::numerize(std::string part)
{
	int				j;
	int 			k = 0;
	int				state;
	std::string		numeric(part.size(), 0);

	for (int i = 0; part[i]; i++)
	{
		if (part[i] == '!' && part[i + 1] && part[i + 1] >= 'A' && part[i + 1] <= 'Z')
			i++;
		if (part[i] >= 'A' && part[i] <= 'Z')
		{
			j = 0;
			while (this->init_fact[j]->getValue() != part[i])
				j++;
			state = this->init_fact[j]->getState();

			if (state == -1)
				part[i] = '2';
			else if (i == 0 || part[i - 1] != '!')
			{
				if (state == 0 || state == -2)
					part[i] = '0';
				else if (state == 1)
					part[i] = '1';
			}
			else
			{
				if (state == 0 || state == -2)
					part[i] = '1';
				else if (state == 1)
					part[i] = '0';
			}
		}
		numeric[k] = part[i];
		k++;
	}
	return (numeric);
}

void			ExpertSystem::get_bracket(Rule rule)
{
	(void)rule;
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