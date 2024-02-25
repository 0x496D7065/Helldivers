# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 12:46:17 by lpetit            #+#    #+#              #
#    Updated: 2024/02/25 16:58:13 by lpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= stratagem_training

INCLUDES = -L./includes

SRCS_DIR = ./srcs/

SRCS= 	$(SRCS_DIR)stratagem_training.c $(SRCS_DIR)helper.c \
	$(SRCS_DIR)key_parsing.c $(SRCS_DIR)ft_split.c

OBJS= $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -I./includes

.PHONY: all clean fclean re

all: $(NAME)
 
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)
 
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDES)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re: fclean all
