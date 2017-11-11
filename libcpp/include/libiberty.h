#pragma once

#define XNEW(T) (T*)malloc(sizeof(T))
#define XCNEW(T) (T*)calloc(1, sizeof(T))
#define XNEWVEC(T,n) (T*)malloc(sizeof(T)*(n))
#define XCNEWVEC(T,n) (T*)calloc((n), sizeof(T))
#define XRESIZEVEC(T, P, N) ((T*)realloc ((void *) (P), sizeof (T) * (N)))
#define XDELETE(P)      free ((void*) (P))

#define XNEWVAR(T,S) (T*)malloc(S)
#define XCNEWVAR(T, S)      ((T *) calloc (1, (S)))
#define XDELETEVEC(P)       free ((void*) (P))

#define ARRAY_SIZE(x) (sizeof(x)/sizeof((x)[0]))



#define XOBNEW(O, T)        ((T *) obstack_alloc ((O), sizeof (T)))
#define XOBNEWVEC(O, T, N)  ((T *) obstack_alloc ((O), sizeof (T) * (N)))
#define XOBNEWVAR(O, T, S)  ((T *) obstack_alloc ((O), (S)))
#define XOBFINISH(O, T)         ((T) obstack_finish ((O)))


inline void * xmemdup(const void * inp, size_t cp, size_t all)
{
	return memcpy(calloc(1,all), inp, cp);
}

extern char *lrealpath (const char *);
extern const char *lbasename (const char *);
extern const unsigned char hex_value(unsigned char);



#define _hex_array_size 256
#define _hex_bad    99
extern const unsigned char _hex_value[_hex_array_size];
extern void hex_init (void);
#define hex_p(c)    (hex_value (c) != _hex_bad)
