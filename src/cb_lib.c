#include "cb_lib.h"

static circular_buffer_t *cb = NULL;

void cb_init(int size)
{

	cb = malloc(sizeof(circular_buffer_t));
	int *arr = malloc(sizeof(int) * size);

	// Initialize arr to 0
	for (int i = 0; i < size; i++)
	{
		arr[i] = 0;
	}

	cb->buffer = arr;
	cb->max_len = size;
	cb->head = 0;
	cb->tail = 0;
	cb->is_full = false;
	cb->is_empty = true;

	// return cb_init;
}

static void move_head()
{
	cb->head = (cb->head + 1) % cb->max_len;
	// If after advancing head the index = tails, then the cb is full
	cb->is_full = (cb->head) == (cb->tail);
	cb->is_empty = false;
}

static void move_tail()
{
	cb->tail = (cb->tail + 1) % cb->max_len;
	// If after advancing tail the index = head, then the cb is empty
	cb->is_empty = (cb->head) == (cb->tail);
	cb->is_full = false;
}

bool cb_push(int val)
{
	// Cannot push if there is no cb
	if (!cb)
	{
		return false;
	}
	// Cannot push if the cb is full
	if (cb->is_full)
	{
		return false;
	}
	cb->buffer[cb->head] = val;
	move_head();
	return true;
}

// Removes the value at tail and returns it, -1 if there is an error
int cb_pop()
{
	if (!cb)
	{
		return -1;
	}
	if (cb->is_empty)
	{
		return -1;
	}
	int val = cb->buffer[cb->tail];
	move_tail();
	return val;
}

// Returns the value at tail, returns -1 if there is an error
int cb_peek()
{
	if (!cb)
	{
		return -1;
	}
	if (cb->is_empty)
	{
		return -1;
	}
	int val = cb->buffer[cb->tail];
	return val;
}

// Prints the values of the cb between tail and head, excludes values popped
void cb_print()
{
	for (int i = cb->tail; i < cb->head; i++)
	{
		printf("%d\r\n", cb->buffer[i]);
	}
}

bool cb_is_empty()
{
	if (!cb)
	{
		return true;
	}
	return cb->is_empty;
}

bool cb_is_full()
{
	if (!cb)
	{
		return false;
	}
	return cb->is_full;
}