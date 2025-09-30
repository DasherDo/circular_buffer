#include "cb_lib.h"

static circular_buffer_t *cb = NULL;

circular_buffer_t cb_init(int size)
{
	int *arr = malloc(sizeof(int) * size);

	// Initialize arr to 0
	for (int i = 0; i < size; i++)
	{
		arr[i] = 0;
	}

	circular_buffer_t cb_init;
	cb_init.buffer = arr;
	cb_init.max_len = size;
	cb_init.head = 0;
	cb_init.tail = 0;
	cb_init.is_full = false;
	cb_init.is_empty = true;
	cb = &cb_init;

	return cb_init;
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
}
