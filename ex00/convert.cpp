/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 09:41:34 by fleduc            #+#    #+#             */
/*   Updated: 2023/02/08 12:48:03 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>

const std::string	find_value(std::string value)
{
	if (value.back() == '.' && value.length() > 1)
		return ("none");
	if ((value[0] == '-' && value[1] >= '0' && value[1] <= '9') || (value[0] >= '0' && value[0] <= '9'))
	{
		int	i = 0;
		while (value[++i])
			if (value[i] < '0' || value[i] > '9')
				break ;
		if ((int)value.length() == i)
		{
			try
			{
				std::stoi(value);
			}
			catch(const std::exception& e)
			{
				return ("none");
			}
			return ("int");
		}
	}
	if (value.length() == 1)
		return ("char");
	if (value.back() == 'f')
	{
		int	i = -1;
		int	dot_count = 0;
		while (value[++i])
		{
			if (value[i] == '.')
				dot_count++;
			if (value[i] != '.' && (value[i] < '0' || value[i] > '9'))
				break ;
		}
		i++;
		if (dot_count == 1 && (int)value.length() == i)
		{
			try
			{
				std::stof(value);
			}
			catch(const std::exception& e)
			{
				return ("none");
			}
			return ("float");
		}
	}
	int		i = -1;
	bool	has_dot = false;
	while (value[++i])
	{
		if (value[i] == '.')
		{
			if (has_dot == false)
				has_dot = true;
			else
				break ;
		}
		if (value[i] != '.' && (value[i] < '0' || value[i] > '9'))
			break ;
	}
	if (has_dot == true && (int)value.length() == i)
	{
		try
		{
			std::stod(value);
		}
		catch(const std::exception& e)
		{
			return ("none");
		}
		return ("double");
	}
	if (value.compare("nanf") == 0 || value.compare("+inff") == 0 || value.compare("-inff") == 0)
		return ("float");
	if (value.compare("nan") == 0 || value.compare("+inf") == 0 || value.compare("-inf") == 0)
		return ("double");
	return ("none");		
}

double	cast_value(std::string const &value, std::string const type)
{
	double	value_cast = 0;
	if (type.compare("int") == 0)
		value_cast = std::stoi(value);
	else if (type.compare("float") == 0)
		value_cast = std::stof(value);
	else if (type.compare("double") == 0)
		value_cast = std::stod(value);
	return (value_cast);
}

void	conv_char(std::string value, std::string const type)
{
	double value_cast = 0;
	
	if (type.compare("char") == 0)
	{
		char	ret;
		ret = static_cast<char>(value[0]);
		if (ret < 0 || ret > 127)
			std::cout << "impossible";
		else if (ret < 32 && ret >= 0)
			std::cout << "non displayable";
		else
			std::cout << ret;
	}
	else
	{
		value_cast = cast_value(value, type);
		if (static_cast<int>(value_cast) != value_cast || value_cast < 0 || value_cast > 127)
			std::cout << "impossible";
		else if (value_cast < 32 && value_cast >= 0)
			std::cout << "non displayable";
		else
			std::cout << (char)value_cast;
	}
}

void	conv_int(std::string value, std::string const type)
{
	double value_cast = 0;
	
	if (type.compare("char") == 0)
		std::cout << static_cast<int>(value[0]);
	else
	{
		value_cast = cast_value(value, type);
		if (value.compare("nan") == 0 || value.compare("nanf") == 0
			|| value_cast > std::numeric_limits<int>::max()
			|| value_cast < std::numeric_limits<int>::min())
			std::cout << "impossible";
		else
			std::cout << (int)value_cast;
	}
}

void	conv_float(std::string value, std::string const type)
{
	double value_cast = 0;
	
	if (type.compare("char") == 0)
		std::cout << static_cast<float>(value[0]) << ".0f";
	else
	{
		value_cast = cast_value(value, type);
		if (value_cast > std::numeric_limits<float>::max()
			|| value_cast < -std::numeric_limits<float>::max())
			std::cout << "impossible";
		else if (value_cast == static_cast<int>(value_cast))
			std::cout << static_cast<float>(value_cast) << ".0f";
		else
			std::cout << static_cast<float>(value_cast) << "f";
	}
}

void	conv_double(std::string value, std::string const type)
{
	double value_cast = 0;
	
	if (type.compare("char") == 0)
		std::cout << static_cast<double>(value[0]) << ".0";
	else
	{
		if (value.compare("nanf") == 0 || value.compare("+inff") == 0 || value.compare("-inff") == 0)
			value.pop_back();
		value_cast = cast_value(value, type);
		if (value_cast == static_cast<int>(value_cast))
			std::cout << static_cast<double>(value_cast) << ".0";
		std::cout << static_cast<double>(value_cast);
	}
}

void	cout_casts(std::string value)
{
	std::string	type = find_value(value);
	if (type.compare("none") == 0)
	{
		std::cout << "argument must be one of these literals: <char>, <int>, <float> or <double>" << std::endl;
		return ;
	}
	std::cout << "char: "; conv_char(value, type); std::cout << std::endl;
	std::cout << "int: "; conv_int(value, type); std::cout << std::endl;
	std::cout << "float: "; conv_float(value, type); std::cout << std::endl;
	std::cout << "double: "; conv_double(value, type); std::cout << std::endl;
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert <literal>" << std::endl;
		return (1);
	}
	cout_casts(argv[1]);
}
