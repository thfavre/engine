#ifndef KEY_H
# define KEY_H

# include "keycodes.h"

void	keys_init(bool *key_pressed);
int		on_keypressed(int keycode, bool *key_pressed);
int		on_keyreleased(int keycode, bool *key_pressed);

#endif
