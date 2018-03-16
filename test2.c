/*
** EPITECH PROJECT, 2017
** test2.c for C_Object
** File description:
** description
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct a {
	struct a *(*str)(struct a *, char *str);
	struct a *(*c)(struct a *, char);
	struct a *(*i)(struct a *, int);
	struct a *(*ld)(struct a *, long);
	struct a *(*endl)(struct a *);

	FILE *stream;
}	a_t;

a_t *w_str(a_t *this, char *str)
{
	fprintf(this->stream, "%s", str);
	return this;
}
a_t *w_c(a_t *this, char c)
{
	fprintf(this->stream, "%c", c);
	return this;
}
a_t *w_i(a_t *this, int i)
{
	fprintf(this->stream, "%i", i);
	return this;
}
a_t *w_ld(a_t *this, long l)
{
	fprintf(this->stream, "%ld", l);
	return this;
}
a_t *w_endl(a_t *this)
{
	fprintf(this->stream, "\n");
	fflush(this->stream);
	return this;
}

int main()
{
	a_t *a = malloc(sizeof(a_t));

	a->str = w_str;
	a->c = w_c;
	a->i = w_i;
	a->ld = w_ld;
	a->endl = w_endl;
	a->stream = stdout;

	a->str(a, "time: ")->i(a, 12)->c(a, 's')->endl(a);
}
