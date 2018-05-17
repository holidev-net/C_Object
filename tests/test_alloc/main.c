#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include "cobject.h"
#include "vector.h"

struct test_s {
	int a;
};

int fct(int a, struct test_s *b)
{
	printf("%d\n", a + b->a);
}

#define N 64000

int main()
{
	vector_t	*tmp[N];
	int		idxs[N];

	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		tmp[i] = new(vector);
		tmp[i]->assign(10, (void*) ((intptr_t) i));
		idxs[i] = i;
	}
	for (int i = 0; i < N; i++) {
		idxs[i] = idxs[rand() % N];
		printf("%lu\n", (intptr_t) tmp[idxs[i]]->front());
	}
	for (int i = 0; i < N; i++) {
		delete_vector(&(tmp[i]));
	}
	return (0);
}