
CC	=	gcc

CFLAGS	=	-W -Wall -Wextra -fPIC -O2 -I ./includes/

SRCS	=	init_member.c

OBJS	=	$(addprefix objs/, $(SRCS:.c=.o))

NAME	=	libcobject.so

all		:	$(NAME)

objs/%.o	:	srcs/%.c
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS)	-c -o $@ $<

$(NAME)		:	$(OBJS)
			$(CC) -shared -o $(NAME) $(OBJS)

clean		:
			rm -rf objs;

fclean		:	clean
			rm $(NAME)

re		:	fclean all