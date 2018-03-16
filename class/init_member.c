/*
** EPITECH PROJECT, 2017
** init_member.c for C_Object
** File description:
** description
*/

#include <sys/mman.h>
#include <stdlib.h>
#include <string.h>

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

void *init_member(void *obj, void *func, int nb_args)
{
	unsigned char  buf[] = {
		0x48, 0xb8, // mov rax
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // addr of func
		0x00, 0x00, // mov last arg
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // addr obj
		0xff, 0xe0, // call rax
	};
	void *virtualCodeAddress = mmap(NULL, sizeof(buf) + ALIGN,
		PROT_READ | PROT_WRITE | PROT_EXEC,
		MAP_ANONYMOUS | MAP_PRIVATE, 0, 0);
	*((size_t*) virtualCodeAddress) = sizeof(buf);
	virtualCodeAddress += ALIGN;
	*((void **) (buf + 2)) = func;
	*((short *) (buf + 10)) = asmmov_g[nb_args];
	*((void **) (buf + 12)) = obj;
	memcpy(virtualCodeAddress, buf, sizeof(buf));
	return (virtualCodeAddress);
}

void delete_member(void *member)
{
	munmap(member, *((size_t*) (member - ALIGN)));
}
