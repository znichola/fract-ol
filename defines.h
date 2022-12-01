/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:19:36 by znichola          #+#    #+#             */
/*   Updated: 2022/12/01 17:17:26 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define WIDTH 500
# define HIGHT 500
# define MAXDEPTH 120
# define MAXPOINTS 50

# define GREY 0XE2DED0
# define IVORY 0X4E4F50
# define BLACK 0X0
# define WHITE 0XFFFFFF

# define PI 3.1415926535

# define MANDELBROT 0
# define JULIA 1
# define BURNINGSHIP 2
# define NONAME 3

enum e_events
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_LEAVE = 8,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	ON_RESIZE = 25,
};

enum e_mouse_key
{
	MOUSE_LEFT = 1,
	MOUSE_RIGHT = 2,
	MOUSE_MIDDLE = 3,
	MOUSE_SCROLL_UP = 4,
	MOUSE_SCROLL_DOWN = 5,
};

enum e_key {
	KEY_ESC = 53,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_F = 3,
	KEY_UP = 126,
	KEY_DOWN = 125,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_PLUS = 69,
	KEY_MINUS = 78,
	KEY_SPACE = 49,
	KEY_J = 38,
	KEY_M = 46,
	KEY_B = 11,
	KEY_N = 45,
	KEY_R = 15,
};

#endif /* defines */