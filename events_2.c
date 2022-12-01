/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 00:40:16 by znichola          #+#    #+#             */
/*   Updated: 2022/12/01 15:19:42 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	key_board_nums(t_app *a, int key)
{
	if (key == 18)
		a->pallet_index = 0;
	else if (key == 19)
		a->pallet_index = 1;
	else if (key == 20)
		a->pallet_index = 2;
	else if (key == 21)
		a->pallet_index = 3;
	else if (key == 23)
		a->pallet_index = 4;
	else if (key == 22)
		a->pallet_index = 5;
	else if (key == 26)
		a->pallet_index = 6;
	else if (key == 28)
		a->pallet_index = 7;
	else if (key == 25)
		a->pallet_index = 8;
	else if (key == 29)
		a->pallet_index = 9;
}

static void	fractal_select(t_app *a, int key)
{
	if (key == KEY_M)
		a->fractal_select = MANDELBROT;
	else if (key == KEY_J)
		a->fractal_select = JULIA;
	else if (key == KEY_B)
		a->fractal_select = BURNINGSHIP;
	else if (key == KEY_N)
		a->fractal_select = NONAME;
}

int	key_press(int keycode, t_app *a)
{
	if (keycode == KEY_ESC)
		destroy(&a->vars);
	else if (keycode == KEY_UP || keycode == KEY_W)
		a->offset.y += 10 / a->scale.y;
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		a->offset.y -= 10 / a->scale.y;
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		a->offset.x -= 2 / a->scale.x;
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		a->offset.x += 2 / a->scale.x;
	else if (keycode == KEY_PLUS)
		zoom(a, 1);
	else if (keycode == KEY_MINUS)
		zoom(a, -1);
	else if (keycode == KEY_SPACE)
		a->render = toggle(a->render);
	else
	{
		key_board_nums(a, keycode);
		fractal_select(a, keycode);
	}
	return (0);
}
	// printf("\nkeycode:[%d]\n", keycode);
		// printf("fractal selected is:%d\n", a->fractal_select);
