#ifndef cb_lib_h
#define cb_lib_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct
{
	int size;
	int *header;
	int *tail;
	int *current;

	bool is_full;

} circular_buffer_t;

#endif