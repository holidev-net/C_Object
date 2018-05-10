SRCS	=	test_vector.c

LIST	=	test_list.c
VECTOR	=	test_vector.c
EVENT	=	test_event.c

all:
	make -C .. re
	gcc -g  -I../includes/ $(SRCS) -O3 -L.. -lstatic_cobject

test:
	gcc -g  -I../includes/ $(SRCS) -O3 -L.. -lstatic_cobject

list:
	gcc -g  -I../includes/ $(LIST) -O3 -L.. -lstatic_cobject

vector:
	gcc -g  -I../includes/ $(VECTOR) -O3 -L.. -lstatic_cobject

event:
	gcc -g  -I../includes/ $(EVENT) -O3 -L.. -lstatic_cobject