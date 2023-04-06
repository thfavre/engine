#include "engine.h"

int on_keypressed(int keycode, bool *key_pressed)
{
	// printf("Key pressed: %d\n", keycode);
	if (keycode < MAX_KEYS)
	{
		key_pressed[keycode] = true;
		// printf("Key pressed: %d\n", keycode);
	}
	// else
		// printf("Key: %d error (%d >= %d)\n", keycode, keycode, MAX_KEYS);
	return (0);
}

