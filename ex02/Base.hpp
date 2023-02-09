/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:09:34 by fleduc            #+#    #+#             */
/*   Updated: 2023/02/09 09:51:26 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>

//class Base
class Base
{
  public:
    virtual ~Base() {};
};

//class A
class A : public Base
{};

//class B
class B : public Base
{};

//class C
class C : public Base
{};

#endif
