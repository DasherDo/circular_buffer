#include "cb_lib.h";

circular_buffer_t cb_init(int size)
{
	int arr[size];

	// Initialize arr to 0
	for (int i = 0; i < size; i++)
	{
		arr[i] = 0;
	}

	circular_buffer_t cb;
	cb.buffer = arr;
	cb.max_len = size;
	cb.head = arr[0];
	cb.tail = arr[0];
	cb.is_full = false;
	cb.is_empty = true;

	return cb;
}