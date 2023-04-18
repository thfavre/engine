#include "engine.h"
/*
 * Initializes the key_pressed array by setting all elements to false
 *
 * @param key_pressed: pointer to the boolean array representing key states
*/
void	keys_init(bool *key_pressed)
{
	int	i;

	i = 0;
	while (i < MAX_KEYS)
		key_pressed[i++] = false;
	// TODO : ft_bzero(key_pressed, MAX_KEYS);
}
