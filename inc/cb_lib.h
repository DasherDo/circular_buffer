#ifndef cb_lib_h
#define cb_lib_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct
{
	int *buffer;
	int max_len;
	int head;
	int tail;

	bool is_full;
	bool is_empty;

} circular_buffer_t;

// Returns an empty circular_buffer_t struct when give a size
void cb_init(int size);

// Attempts to push val into the cb, return true if successful and false if it fails (buffer is full)
bool cb_push(int val);

// Removes the value at *head from cb, returns the value. Returns -1 if there is no value
int cb_pop();

// Returns the value at *head
int cb_peek();

// True if the cb has no values
bool cb_is_empty();

// True if the cb is full
bool cb_is_full();

// Prints the circular buffer to stdout
void cb_print();
#endif