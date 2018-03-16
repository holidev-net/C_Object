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
	stream_t *_stdout = new(stream);
	stream_t *_stderr = new(stream, stderr);

	_stdout->str("stdout: ")->i(42)->str(" char")->endl();
	_stderr->str("stderr: ")->i(42)->str(" char")->endl();

	delete(stream, _stdout);
	delete(stream, _stderr);
}
