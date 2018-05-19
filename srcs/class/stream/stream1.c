/*
** EPITECH PROJECT, 2017
** PSU_myftp_2017
** File description:
** stream1.c
*/

#include <stdio.h>

#include "cobject.h"
#include "private_stream.h"
#include "stream.h"

stream_t *write_str(char *str, stream_t *this)
{
	fprintf(this->stream, "%s", str);
	return (this);
}

stream_t *write_c(char c, stream_t *this)
{
	fprintf(this->stream, "%c", c);
	return (this);
}

stream_t *write_i(int i, stream_t *this)
{
	fprintf(this->stream, "%i", i);
	return (this);
}

stream_t *write_ld(long i, stream_t *this)
{
	fprintf(this->stream, "%ld", i);
	return (this);
}