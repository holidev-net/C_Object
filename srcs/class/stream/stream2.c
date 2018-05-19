/*
** EPITECH PROJECT, 2017
** PSU_myftp_2017
** File description:
** stream2.c
*/

#include <stdio.h>

#include "cobject.h"
#include "private_stream.h"
#include "stream.h"

stream_t *write_endl(stream_t *this)
{
	fprintf(this->stream, "\n");
	fflush(this->stream);
	return (this);
}

FILE *write_src(FILE *target, stream_t *this)
{
	if (target)
		this->stream = target;
	return (this->stream);
}