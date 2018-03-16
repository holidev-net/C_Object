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
	stream_t *stdout = new(stream);
	stream_t *strerr = new(stream, stderr);

	stdout->str("stdout: ")->i(42)->str(" char")->endl();
	strerr->str("strerr: ")->i(42)->str(" char")->endl();

	delete(stream, stdout);
	delete(stream, strerr);
}
