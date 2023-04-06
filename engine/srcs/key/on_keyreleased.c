#include "engine.h"

int on_keyreleased(int keycode, bool *key_pressed)
{
	if (keycode < MAX_KEYS && key_pressed[keycode])
	// {
		key_pressed[keycode] = false;
	// 	printf("Key released: %d\n", keycode);
	// }
	// else
	// 	printf("Key: %d error (%d >= %d)\n", keycode, keycode, MAX_KEYS);
	return (0);
}
