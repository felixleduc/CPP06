/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:09:37 by fleduc            #+#    #+#             */
/*   Updated: 2023/02/09 10:03:02 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

Base    *generate(void)
{
		Base  *ret = NULL;
		int nbr = rand() % 3;
	
		switch (nbr) {
				case 0:
					ret = new A;
					break;
				case 1:
					ret = new B;
					break;
				case 2:
					ret = new C;
					break;
				default:
					ret = NULL;
		}
		return (ret);
}

void	identify(Base *p)
{
		if (dynamic_cast<A*>(p) != NULL)
				std::cout << "A" << std::endl;
		else if (dynamic_cast<B*>(p) != NULL)
				std::cout << "B" << std::endl;
		else if (dynamic_cast<C*>(p) != NULL)
				std::cout << "C" << std::endl;
		
}

void	identify(Base &p)
{
		try
		{
			(void)dynamic_cast<A&>(p);
			std::cout << "A" << std::endl;
			return ;
		}
		catch(const std::exception& e)
		{}

		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
			return ;
		}
		catch(const std::exception& e)
		{}

		try
		{
			(void)dynamic_cast<C&>(p);
			std::cout << "C" << std::endl;
			return ;
		}
		catch(const std::exception& e)
		{}
}

int main(void)
{
		Base    *base;
		srand(time(NULL));
		
		base = generate();
		identify(base);
		identify(*base);
		delete	base;
}
