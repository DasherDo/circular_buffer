#include "main.h"
#include "cb_lib.h"

void main()
{

	// Initializes cb buffer, single static cb createds
	cb_init(20);
	for (int i = 0; i < 10; i++)
	{
		cb_push(i);
	}
	cb_print();
}