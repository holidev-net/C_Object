/*
** EPITECH PROJECT, 2017
** stream.h for C_Object
** File description:
** description
*/

#pragma once

#include <stdio.h>

CLASS stream {
	struct stream *(*str)(char *str);
	struct stream *(*c)(char);
	struct stream *(*i)(int);
	struct stream *(*ld)(long);
	struct stream *(*endl)();
	FILE *(*src)(FILE*);
	void (*flush)();

	#ifdef __PRIVATE_STREAM__
	FILE *stream;
	#endif
}	stream_t;

void		stream_ctor(stream_t *);
stream_t	*init_stream0();
stream_t	*init_stream1(FILE *file);
void		delete_stream(stream_t **);

#define STREAM0	init_stream0
#define STREAM1	init_stream1

#define ctor_stream(_0, _1, FUNC, ...) FUNC
#define init_stream(arg...) ctor_stream(_0, ##arg, STREAM1, STREAM0)(arg)

#ifdef __PRIVATE_STREAM__
stream_t *write_str(char *str, stream_t *);
stream_t *write_c(char c, stream_t *);
stream_t *write_i(int i, stream_t *);
stream_t *write_ld(long l, stream_t *);
stream_t *write_endl(stream_t *);
void flush(stream_t *);
FILE *write_src(FILE *target, stream_t *);
#endif