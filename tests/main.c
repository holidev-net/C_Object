#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <string.h>

struct monObj {
	int a;
	void (*print)(void);
	int	printSize;
};

void print(struct monObj *obj)
{
	printf("%d\n", obj->a);
}

void test()
{
        void (*ptr)(void*) = (void*) 0x1234567899876;
        ptr((void*) 0x98765432112345);
}

struct monObj	*init()
{
	struct monObj *b = malloc(sizeof(struct monObj));
	unsigned char  buf[] = {
		0x48, 0xb8,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x48, 0xbf,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0xff, 0xe0,
	};
	b->printSize = sizeof(buf);
	void *virtualCodeAddress = mmap(
       		NULL,
		sizeof(buf),
		PROT_READ | PROT_WRITE | PROT_EXEC,
		MAP_ANONYMOUS | MAP_PRIVATE,
		0,
		0);
	*((void **) (buf + 2)) = &print;
	*((void **) (buf + 12)) = b;
	memcpy(virtualCodeAddress, buf, sizeof(buf));
	b->print = virtualCodeAddress;
	return b;
}

void	delete(struct monObj *obj)
{
	munmap((void*) (obj->print), obj->printSize);
	free(obj);
}

int main()
{
	struct monObj *b = init();
	struct monObj *b2 = init();

	b->a = 64;
	b2->a = 22;
	b->print();
	b2->print();

	delete(b);
	delete(b2);
	return (0);
}