#ifndef FLAT_INCLUDES
#define FLAT_INCLUDES
#endif

#define link1_typedef(type,name)		\
    typedef struct link1_##name link1_##name;	\
    struct link1_##name {			\
	link1_##name * peer;			\
	type child;				\
    }						\

#define link1_funcdef(name)						\
    inline static void link1_##name##_insert(link1_##name ** list, link1_##name * link) \
    {									\
	link->peer = *list;						\
	*list = link;							\
    }									\
									\
    inline static void link1_##name##_remove(link1_##name ** list)	\
    {									\
	*list = (*list)->peer;						\
    }									\
									\
    inline static link1_##name * link1_##name##_pop(link1_##name ** list) \
    {									\
	link1_##name * retval = *list;					\
	*list = retval->peer;						\
	return retval;							\
    }									\

#define for_link1(iter, host)			\
    for(iter = &(host); iter; iter = (iter)->peer)
