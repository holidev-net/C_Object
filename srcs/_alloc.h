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

void	*_get_allocated_page_memory(void);
void	*_get_caller_at(_page_header_t *page, int idx);

static inline uint8_t	_get_byte_for_caller(_page_header_t *page, int *ii)
{
	int	i = 0;

	for (; i < _total_available_caller_g; i++) {
		if (~page->buf[i] & 0xFF) {
			*ii = i;
			return ~page->buf[i];
		}
	}
	*ii = i;
	return (0);
}

static inline void	*_get_caller_block(_page_header_t *page)
{
	uint8_t	byte;
	int	i;
	int	av = 7;

	if (!page)
		return (NULL);
	byte = _get_byte_for_caller(page, &i);
	if (i == _total_available_caller_g)
		return (NULL);
	if (i * 8 + av > _total_available_caller_g) {
		av -= _total_available_caller_g % 8;
	}
	for (int j = av; j >= 0; j--) {
		if (byte & 0x1) {
			page->buf[i] |= 1 << (av - j);
			return (_get_caller_at(page, i * 8 + j));
		}
		byte = byte >> 1;
	}
	return (NULL);
}