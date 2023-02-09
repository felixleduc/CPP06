# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fleduc <fleduc@student.42quebec.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 09:51:09 by fleduc            #+#    #+#              #
#    Updated: 2023/02/09 09:24:38 by fleduc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serialize

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -g
CC = g++
RM = rm -rf

SRCS = serialize.cpp
OBJS = $(SRCS:.cpp=.o)

all = $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re