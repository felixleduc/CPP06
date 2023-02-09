/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:51:07 by fleduc            #+#    #+#             */
/*   Updated: 2023/02/09 09:24:41 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

typedef struct s_data
{
	int			id;
	std::string	message;
}	Data;

uintptr_t   serialize(Data* ptr)
{
	std::cout << "before serialization: " << std::endl;
	std::cout << "id: " << ptr->id << std::endl;
	std::cout << "message: " << ptr->message << std::endl << std::endl;
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data    *deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int main(void)
{
	Data	*tmp = new Data;

	tmp->id = 1;
	tmp->message = "Hey dude";

	Data	*newData = deserialize(serialize(tmp));
	std::cout << "after serialization: " << std::endl;
	std::cout << "id: " << newData->id << std::endl;
	std::cout << "message: " << newData->message << std::endl;
	delete	tmp;
}
