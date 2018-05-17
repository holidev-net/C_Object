/*
 * --------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <benjamin.viguier@epitech.eu> wrote this file. As long as you retain this 
 * notice you can do whatever you want with this stuff. If we meet some day,
 * and you think this stuff is worth it, you can buy me a beer in
 * return Benjamin Viguier
 * --------------------------------------------------------------------------
 */

#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <malloc.h>
#include "_alloc.h"

static _page_header_t	*last_page_g = NULL;
static size_t		page_size_g;
uint16_t		_total_available_caller_g = 0;

static inline int	_init_header_block(void *page)
{
	size_t		available = page_size_g / _alignedSize_g;
	_page_header_t	*h = page;

	memset(page, 0, page_size_g);
	h->available = available - ((sizeof(h) + available) / _alignedSize_g);
	h->off = _alignedSize_g * (available - h->available);
	if (_total_available_caller_g == 0) {
		_total_available_caller_g = h->available;
	}
	return (mprotect(page, page_size_g,
		PROT_READ | PROT_WRITE | PROT_EXEC));
}

static inline _page_header_t	*_get_page_with_available_caller_block(void)
{
	for (_page_header_t *page = last_page_g; page != NULL;
		page = page->prev) {
		if (page->available)
			return (page);
	}
	return (NULL);
}

void	*_get_allocated_page_memory()
{
	_page_header_t	*page;

	if (page_size_g == 0)
		page_size_g = getpagesize();
	if (last_page_g) {
		page = _get_page_with_available_caller_block();
		if (page) {
			return (page);
		}
	}
	page = last_page_g;
	if (posix_memalign((void**) &last_page_g, page_size_g, page_size_g))
		return (NULL);
	if (_init_header_block(last_page_g))
		return (NULL);
	if (page) {
		last_page_g->prev = page;
		page->next = last_page_g;
	}
	return (last_page_g);
}

void	*_get_caller_at(_page_header_t *page, int idx)
{
	void	*start = ((void*) page) + page->off;

	return (start + (_alignedSize_g * idx));
}

void	free_caller(void *caller)
{
	_page_header_t	*page = (void*) ((uintptr_t) caller & -page_size_g);
	void		*start = ((void*) page) + page->off;
	int		idx = ((uintptr_t) caller - (uintptr_t) start)
				/ _alignedSize_g;
	int		x = idx / 8;
	int		y = idx % 8;

	page->buf[x] &= ~(0x1 << y);
	page->available++;
	if (page->available == _total_available_caller_g) {
		if (page->prev)
			page->prev->next = page->next;
		if (page->next)
			page->next->prev = page->prev;
		if (page == last_page_g) {
			last_page_g = page->prev;
		}
		free(page);
	}
}