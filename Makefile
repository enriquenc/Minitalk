#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/20 01:00:57 by tmaslyan          #+#    #+#              #
#    Updated: 2018/05/20 01:00:59 by tmaslyan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

LIBFT = libft/libft.a

all: lib server client
server client : server.o client.o
	gcc -o server server.o $(LIBFT)
	gcc -o client client.o $(LIBFT)

lib:
	make -C libft

server.o: server.c
	gcc -c -o server.o server.c

client.o: client.c
	gcc -c -o client.o client.c

clean:
	rm -f server.o client.o
	make clean -C libft
fclean: clean
	rm -f server client
	make fclean -C libft
re: fclean all