/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** alloc_amd64.c
*/

#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include "internal_alloc.h"

#ifdef __amd64__

/* copy register to {rdi rsi rdx rcx r8 r9 r10 r11 rax rbx} (amd64) */
static const short _asmmov_g[] = {
	0xbf48, 0xbe48, 0xba48, 0xb948, 0xb849,
	0xb949, 0xba49, 0xbb49, 0xb848, 0xbb48
};

/* template caller (amd64) :
	move rax
	addr of func
	mov last arg
	addr obj
	jmp rax
*/
static const unsigned char  _caller_template_g[] = {
	0x48, 0xb8,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xff, 0xe0
};

const size_t  _alignedSize_g =
	sizeof(_caller_template_g) / ALIGN * ALIGN +
	!!(sizeof(_caller_template_g) % ALIGN) * ALIGN;

void	*create_capture(void *data_ptr, void *function_ptr, int arg_nbr)
{
	_page_header_t	*page = alloc_get_allocated_page_memory();
	void		*caller_block = alloc_get_caller_block(page);

	if (caller_block == NULL)
		return (caller_block);
	memset(caller_block, 0, _alignedSize_g);
	memcpy(caller_block, _caller_template_g, sizeof(_caller_template_g));
	*((void **) (caller_block + 2)) = function_ptr;
	*((short *) (caller_block + 10)) = _asmmov_g[arg_nbr];
	*((void **) (caller_block + 12)) = data_ptr;
	page->available--;

	return (caller_block);
}

void	*get_capture_data(void *caller)
{
	return *((void **) (caller + 12));
}

#endif