
CC	=	gcc

CFLAGS	=	-W -Wall -Wextra -fPIC -O2 -I ./includes/

SRCS	=	init_member.c

OBJS	=	$(addprefix objs/, $(SRCS:.c=.o))

NAME	=	cobject

DYNAME	=	lib$(NAME).so

STNAME	=	libstatic_$(NAME).a

all		:	$(DYNAME) $(STNAME)

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