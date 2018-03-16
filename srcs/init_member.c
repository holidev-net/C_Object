/*
** EPITECH PROJECT, 2017
** init_member.c for C_Object
** File description:
** description
*/

#include <sys/mman.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "init.h"

#define ALIGN   16

static const short asmmov_g[] = {
	0xbf48, // rdi
	0xbe48, // rsi
	0xba48, // rdx
	0xb948, // rcx
	0xb849, // r8
	0xb949, // r9
	0xba49, // r10
	0xbb49, // r11
	0xb848, // rax
	0xbb48, // rbx
};

static const unsigned char  buf[] = {
	0x48, 0xb8, // mov rax
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // addr of func
	0x00, 0x00, // mov last arg
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // addr obj
	0xff, 0xe0, // jmp rax
};

int init_members(void *obj, int nb_functs, ...)
{
	init_wrap_t     cur_wrapper;
	va_list         vl;
	const size_t  alignedSize = (sizeof(buf) % 16 == 0
			? sizeof(buf)
			: sizeof(buf) + (sizeof(buf) - (sizeof(buf) % ALIGN)));
	void    *virtualCodeAddress = mmap(NULL, alignedSize + ALIGN,
			PROT_READ | PROT_WRITE | PROT_EXEC,
			MAP_ANONYMOUS | MAP_PRIVATE, 0, 0);
	void    *cur = virtualCodeAddress + ALIGN;

	if (virtualCodeAddress == (void*) -1)
		return (-1);
	va_start(vl, nb_functs);
	*((size_t*) virtualCodeAddress) = alignedSize + ALIGN;
	virtualCodeAddress = cur;
	while (nb_functs--) {
		cur_wrapper = va_arg(vl, init_wrap_t);
		memcpy(cur, buf, sizeof(buf));
		*((void **) (cur + 2)) = cur_wrapper.target;
		*((short *) (cur + 10)) = asmmov_g[cur_wrapper.nb_args];
		*((void **) (cur + 12)) = obj;
		*(cur_wrapper.funct) = cur;
		cur += alignedSize;
	}
	return (0);
}

void delete_members(void *first_member)
{
	munmap(first_member, *((size_t*) (first_member - ALIGN)));
}
