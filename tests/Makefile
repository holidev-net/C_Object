SRCS	=	main2.c		\
		class/test.c	\
		class/string.c	\
		class/stream.c	\

all:
	make -C .. re
	gcc -I ../includes/ $(SRCS) -O3 -L.. -lstatic_cobject -g
