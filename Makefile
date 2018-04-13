##
## EPITECH PROJECT, 2017
## Makefile for C_Object
## File description:
## description
##

CC		=	gcc

CFLAGS		=	-W -Wall -Wextra -g -fPIC -O2 -I ./includes/

SRCS		=	init_member.c			\
			class/list/list.c		\
			class/list/list1.c		\
			class/list/list2.c		\
			class/list/list3.c		\
			class/list/list4.c		\
			class/list/list5.c		\
			class/list/list6.c		\
			class/list/list_errors.c	\
			class/string/string.c		\
			class/stream/stream.c		\

OBJS		=	$(addprefix objs/, $(SRCS:.c=.o))

NAME		=	cobject

DYNAME		=	lib$(NAME).so

STNAME		=	libstatic_$(NAME).a

all		:	dynamic static

dynamic		:	$(DYNAME)

static		:	$(STNAME)

objs/%.o	:	srcs/%.c
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS)	-c -o $@ $<

$(DYNAME)	:	$(OBJS)
			$(CC) -shared -o $(DYNAME) $(OBJS)

$(STNAME)	:	$(OBJS)
			ar rc $(STNAME) $(OBJS)
			ranlib $(STNAME)

clean		:
			rm -rf objs;

fclean		:	clean
			rm -f $(DYNAME)
			rm -f $(STNAME)

re		:	fclean all
