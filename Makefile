# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmiranda <marvin@42quebec.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 00:20:42 by jmiranda          #+#    #+#              #
#    Updated: 2022/10/26 15:25:34 by jmiranda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME   = libftprintf.a

SRCS   = ft_printf.c \

OBJS   = ${SRCS:.c=.o}

CC     = gcc

CFLAGS = -Wall -Wextra -Werror

all    : ${NAME}

${NAME}: ${OBJS}
				 @ar -rcs ${NAME} ${OBJS}
				 @echo Printf Is Complete!

clean  :
				 @rm -f ${OBJS}

fclean : clean
				 @rm -f ${NAME}

re     : fclean all

.PHONY : all clean fclean re
