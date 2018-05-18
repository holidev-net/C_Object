/*
 * --------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <benjamin.viguier@epitech.eu> wrote this file. As long as you retain this 
 * notice you can do whatever you want with this stuff. If we meet some day,
 * and you think this stuff is worth it, you can buy me a beer in
 * return Benjamin Viguier
 * --------------------------------------------------------------------------
 */

#define LBD_1(ret, nb_args, body, av...) ({			\
	void	*lbd_result_;					\
	struct cap_s {						\
		typeof(_1(av)) _1(av);				\
	}	*shr = malloc(sizeof(struct cap_s));		\
	memmove(shr, &((struct cap_s) {				\
		_1(av)						\
	}), sizeof(struct cap_s));				\
	ret __lbd__ body;					\
	lbd_result_ = create_caller(shr, __lbd__, nb_args);	\
	lbd_result_;						\
});

#define LBD_2(ret, nb_args, body, av...) ({			\
	void	*lbd_result_;					\
	struct cap_s {						\
		typeof(_1(av)) _1(av);				\
		typeof(_2(av)) _2(av);				\
	}	*shr = malloc(sizeof(struct cap_s));		\
	memmove(shr, &((struct cap_s) {				\
		_1(av),						\
		_2(av)						\
	}), sizeof(struct cap_s));				\
	ret __lbd__ body;					\
	lbd_result_ = create_caller(shr, __lbd__, nb_args);	\
	lbd_result_;						\
});

static inline void	free_lambda(void *lbd)
{
	free(get_capture(lbd));
	free_caller(lbd);
}

static inline void	__free_lamdba(void *lbd)
{
	free_lambda(*((void**) lbd));
}