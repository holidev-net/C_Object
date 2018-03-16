all:
	make -C .. re
	gcc main2.c -I ../includes/ class/test.c class/string.c class/stream.c -O3 -Bstatic -L.. -lstatic_cobject -g
