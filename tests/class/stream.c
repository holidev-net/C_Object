/*
** EPITECH PROJECT, 2017
** stream.c for C_Object
** File description:
** description
*/

#define PRIVATE_STREAM

#include "stream.h"

stream_t *write_str(char *str, stream_t *);
stream_t *write_c(char c, stream_t *);
stream_t *write_i(int i, stream_t *);
stream_t *write_ld(long l, stream_t *);
stream_t *write_endl(stream_t *);

stream_t	*init_stream();
void		delete_stream(stream_t *);
