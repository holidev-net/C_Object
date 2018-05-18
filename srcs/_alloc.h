/*
 * --------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <benjamin.viguier@epitech.eu> wrote this file. As long as you retain this 
 * notice you can do whatever you want with this stuff. If we meet some day,
 * and you think this stuff is worth it, you can buy me a beer in
 * return Benjamin Viguier
 * --------------------------------------------------------------------------
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

static inline void	*_get_caller_block(_page_header_t *page)
{
	uint8_t	byte = 0;
	int	i = 0;
	int	av = 7;

	if (!page)
		return (NULL);
	for (; i < _total_available_caller_g; i++) {
		if (~page->buf[i] & 0xFF) {
			byte = ~page->buf[i];
			break;
		}
	}
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