SRCS	=	test_vector.c

LIST	=	test_list.c
VECTOR	=	test_vector.c
EVENT	=	test_event.c

all:
	make -C .. re
	gcc -I ../includes/ $(SRCS) -O3 -L.. -lstatic_cobject -g

test:
	gcc -I ../includes/ $(SRCS) -O3 -L.. -lstatic_cobject -g

list:
	gcc -I ../includes/ $(LIST) -O3 -L.. -lstatic_cobject -g

vector:
	gcc -I ../includes/ $(VECTOR) -O3 -L.. -lstatic_cobject -g

event:
	gcc -I ../includes/ $(EVENT) -O3 -L.. -lstatic_cobject -g