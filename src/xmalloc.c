/*
 * Copyright (c) 2012-2013, BohuTANG <overred.shuttler at gmail dot com>
 * All rights reserved.
 * Code is licensed with GPL. See COPYING.GPL file.
 *
 */

#include "debug.h"
#include "xmalloc.h"

void _check_memory(void *p, size_t s)
{
	if (p == 0)
		__PANIC("memory allocation failed -- exiting, malloc-size#%d",
				s);
}

void *xmalloc(size_t s)
{
	void *p = 0;

	p = (void*)malloc(s);
	_check_memory(p, s);

	return p;
}

void *xcalloc(size_t n, size_t s)
{
	void *p = 0;

	p = (void*)calloc(n, s);
	_check_memory(p, s);

	return p;
}

void *xrealloc(void *p, size_t s)
{
	p = (void*)realloc(p, s);
	_check_memory(p, s);

	return p;
}

void xfree(void *p)
{
	if (p)
		free(p);
}
