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

static const short _asmmov_g[] = {
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

static const unsigned char  _caller_template_g[] = {
	0x48, 0xb8, // mov rax
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // addr of func
	0x00, 0x00, // mov last arg
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // addr obj
	0xff, 0xe0, // jmp rax
};

static const size_t  _alignedSize_g = (sizeof(_caller_template_g) % 16 == 0 
                        ? sizeof(_caller_template_g) 
                        : sizeof(_caller_template_g) + (sizeof(_caller_template_g) - (sizeof(_caller_template_g) % ALIGN)));

static inline int init_member_write_member_callers(
	void *obj, va_list vl, void *caller_address, int nb_functs)
{
	init_wrap_t     cur_wrapper;
	void		*cur = caller_address + ALIGN;

	*((size_t*) caller_address) = _alignedSize_g + ALIGN;
        while (nb_functs--) {
                cur_wrapper = va_arg(vl, init_wrap_t);
                memcpy(cur, _caller_template_g, sizeof(_caller_template_g));
                *((void **) (cur + 2)) = cur_wrapper.target;
                *((short *) (cur + 10)) = _asmmov_g[cur_wrapper.nb_args];
                *((void **) (cur + 12)) = obj;
                *(cur_wrapper.funct) = cur;
                cur += _alignedSize_g;
        }
	va_end(vl);
	return (mprotect(caller_address, ALIGN + _alignedSize_g, PROT_EXEC));
}

int init_members(void *obj, int nb_functs, ...)
{
        va_list         vl;
	void    *caller_address = mmap(NULL, _alignedSize_g + ALIGN,
		        PROT_READ | PROT_WRITE,
		        MAP_ANONYMOUS | MAP_PRIVATE, 0, 0);

        if (caller_address == (void*) -1)
                return (-1);
        va_start(vl, nb_functs);
	return (init_member_write_member_callers(
		obj, vl, caller_address, nb_functs));
}

void delete_members(void *first_member)
{
	munmap(first_member, *((size_t*) (first_member - ALIGN)));
}
