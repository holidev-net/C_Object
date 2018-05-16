#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cobject.h"

struct test_s {
	int a;
};

int fct(int a, struct test_s *b)
{
	printf("%d\n", a + b->a);
}

#define N 25000

int main()
{
	struct test_s b;
	void	*tmp[N];
	int	idxs[N];

	srand(time(NULL));
	b.a = 32;
	for (int i = 0; i < N; i++) {
		tmp[i] = create_caller(&b, &fct, 1);
		idxs[i] = i;
	}
	for (int i = 0; i < N; i++) {
		idxs[i] = idxs[rand() % N];
		printf("%d\n", idxs[i]);
	}
	for (int i = 0; i < N; i++) {
		free_caller(tmp[i]);
	}
	return (0);
}