/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:24:37 by thomas            #+#    #+#             */
/*   Updated: 2023/04/13 12:48:03 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODES_H
# define KEYCODES_H

# ifdef __gnu_linux__
#  define MAX_KEYS 69000
#  define K_SPACE 32
#  define K_EXCLAIM 33
#  define K_QUOTEDBL 34
#  define K_HASH 35
#  define K_DOLLAR 36
#  define K_PERCENT 37
#  define K_AMPERSAND 38
#  define K_QUOTE 39
#  define K_LEFTPAREN 40
#  define K_RIGHTPAREN 41
#  define K_ASTERISK 42
#  define K_PLUS 43
#  define K_COMMA 44
#  define K_MINUS 45
#  define K_PERIOD 46
#  define K_SLASH 47
#  define K_0 48
#  define K_1 49
#  define K_2 50
#  define K_3 51
#  define K_4 52
#  define K_5 53
#  define K_6 54
#  define K_7 55
#  define K_8 56
#  define K_9 57
#  define K_COLON 58
#  define K_SEMICOLON 59
#  define K_LESS 60
#  define K_EQUALS 61
#  define K_GREATER 62
#  define K_QUESTION 63
#  define K_AT 64
#  define K_LEFTBRACKET 91
#  define K_BACKSLASH 92
#  define K_RIGHTBRACKET 93
#  define K_CARET 94
#  define K_UNDERSCORE 95
#  define K_BACKQUOTE 96
#  define K_A 97
#  define K_B 98
#  define K_C 99
#  define K_D 100
#  define K_E 101
#  define K_F 102
#  define K_G 103
#  define K_H 104
#  define K_I 105
#  define K_J 106
#  define K_K 107
#  define K_L 108
#  define K_M 109
#  define K_N 110
#  define K_O 111
#  define K_P 112
#  define K_Q 113
#  define K_R 114
#  define K_S 115
#  define K_T 116
#  define K_U 117
#  define K_V 118
#  define K_W 119
#  define K_X 120
#  define K_Y 121
#  define K_Z 122
# define K_BACKSPACE 65288
# define K_TAB 65289
# define K_ENTER 65293
# define K_RETURN K_ENTER
# define K_SHIFT 65505
# define K_CTRL 65507
# define K_ALT 65513
# define K_PAUSE 65299
# define K_CAPSLOCK 65509
# define K_ESCAPE 65307
# define K_ESC K_ESCAPE
# define K_PAGEUP 65365
# define K_PAGEDOWN 65366
# define K_END 65367
# define K_HOME 65360
# define K_LEFT 65361
# define K_UP 65362
# define K_RIGHT 65363
# define K_DOWN 65364
# define K_PRINTSCREEN 65377
# define K_INSERT 65379
# define K_DELETE 65535
# define K_0_NUM 65456
# define K_1_NUM 65457
# define K_2_NUM 65458
# define K_3_NUM 65459
# define K_4_NUM 65460
# define K_5_NUM 65461
# define K_6_NUM 65462
# define K_7_NUM 65463
# define K_8_NUM 65464
# define K_9_NUM 65465
# define K_MULTIPLY 65450
# define K_ADD 65451
# define K_SUBTRACT 65453
# define K_DECIMAL 65454
# define K_DIVIDE 65455
# define K_F1 65470
# define K_F2 65471
# define K_F3 65472
# define K_F4 65473
# define K_F5 65474
# define K_F6 65475
# define K_F7 65476
# define K_F8 65477
# define K_F9 65478


# elif __APPLE__
#  define MAX_KEYS 500
# define K_BACKSPACE 8
# define K_TAB 9
# define K_ENTER 13
# define K_RETURN K_ENTER
# define K_ESCAPE 53
# define K_ESC K_ESCAPE
# define K_LEFT 123
# define K_RIGHT 124
# define K_DOWN 125
# define K_UP 126
#  define K_A 0
#  define K_W 13
#  define K_S 1
#  define K_D 2

// TODO


# endif

#endif
