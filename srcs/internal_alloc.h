/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** _alloc.h
*/

#pragma once

#include <unistd.h>
#include <stdint.h>
#include <sys/types.h>

#define ALIGN	16

typedef struct _page_header_s {
	struct _page_header_s	*prev;
	struct _page_header_s	*next;
	uint16_t		available;
	uint16_t		off;
	uint8_t			buf[];
}	_page_header_t;

extern uint16_t		_total_available_caller_g;
extern const size_t	_alignedSize_g;

void	*alloc_get_allocated_page_memory(void);
void	*alloc_get_caller_at(_page_header_t *page, int idx);

static inline uint8_t	alloc_get_byte_for_caller(_page_header_t *p,
							int *ii)
{
	int	i = 0;

	for (; i < _total_available_caller_g; i++) {
		if (~p->buf[i] & 0xFF) {
			*ii = i;
			return (~p->buf[i]);
		}
	}
	*ii = i;
	return (0);
}

static inline void	*alloc_get_caller_block(_page_header_t *page)
{
	uint8_t	byte;
	int	i;

	if (!page)
		return (NULL);
	byte = alloc_get_byte_for_caller(page, &i);
	if (i == _total_available_caller_g)
		return (NULL);
	for (int j = 7; j >= 0; j--) {
		if (byte & 0x1) {
			page->buf[i] |= 1 << (7 - j);
			return (alloc_get_caller_at(page, i * 8 + j));
		}
		byte = byte >> 1;
	}
	return (NULL);
}