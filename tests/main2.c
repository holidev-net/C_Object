/*
** EPITECH PROJECT, 2017
** main2.c for C_Object
** File description:
** description
*/

#include <stdio.h>
#include "class/test.h"
#include <stdio.h>
#include "class/mystring.h"
#include "class/stream.h"
#include "init.h"

int main()
{
	FILE *f = fopen("blabla", "w");
	stream_t *stream1 = new(stream);
	stream_t *stream2 = new(stream, f);

	stream1->str("stream1: ")->i(42)->str(" char")->endl();
	stream2->str("stream2: ")->i(42)->str(" char")->endl();

	delete(stream, stream1);
	delete(stream, stream2);
	fclose(f);
}
