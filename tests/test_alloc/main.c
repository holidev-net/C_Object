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

#define N 32

int main()
{
	vector_t	*tmp[N];

	srand(time(NULL));
	int 		nn = rand() % N;
	int		idxs[N + nn];
	vector_t	*tmp2[nn];

	for (int i = 0; i < N; i++) {
		tmp[i] = new(vector);
		tmp[i]->assign(10, (void*) ((intptr_t) i));
		idxs[i] = i;
	}
	for (int i = 0; i < N; i++) {
		idxs[i] = idxs[rand() % N];
	}
	for (int i = 0; i < nn; i++) {
		delete_vector(&(tmp[i]));
	}
	for (int i = 0; i < nn; i++) {
		tmp2[i] = new(vector);
		tmp2[i]->assign(10, (void*) ((intptr_t) i));
		idxs[N + i] = i;
	}
	for (int i = nn; i < N; i++) {
		delete_vector(&(tmp[i]));
	}
	for (int i = 0; i < nn; i++) {
		delete_vector(&(tmp2[i]));
	}
	return (0);
}