/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 08:30:37 by znichola          #+#    #+#             */
/*   Updated: 2022/11/30 22:43:18 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	destroy(t_vars *vars)
{
	// printf("lsdjkf %p\n", vars);
	mlx_destroy_window(vars->mlx, vars->win);
	// printf("lsdjkf %p\n", vars);
	exit(0);
	return (0);
}

void	zoom(t_app *a, int dir)
{
	t_fpoint	mouse_world_before_zoom;
	t_fpoint	mouse_world_after_zoom;
	
	mouse_world_before_zoom = rscreen_to_world(a, a->mouse);
	if (dir > 0)
	{
		a->scale.x *= 1.2;
		a->scale.y *= 1.2;
	}
	else if (dir < 0)
	{
		a->scale.x *= 0.8;
		a->scale.y *= 0.8;
	}
	else
		return ;
	mouse_world_after_zoom = rscreen_to_world(a, a->mouse);
	a->offset.x += (mouse_world_before_zoom.x - mouse_world_after_zoom.x);
	a->offset.y += (mouse_world_before_zoom.y - mouse_world_after_zoom.y);
	// printf("scale: "); pf(a->scale); printf("\n");
	// printf("offset: "); pf(a->offset); printf("\n");
	a->cf.depth = 1;
}

void	key_board_nums(t_app *a, int key)
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

int	key_press(int keycode, t_app *a)
{
	printf("\nkeycode:[%d]\n", keycode);
	if (keycode == KEY_ESC)
		destroy(&a->vars);
	else if (keycode == KEY_UP || keycode == KEY_W)
		a->offset.y += 4/a->scale.y;
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		a->offset.y -= 4/a->scale.y;
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		a->offset.x -= 4/a->scale.x;
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		a->offset.x += 4/a->scale.x;
	else if (keycode == KEY_PLUS)
		zoom(a, 1);
	else if (keycode == KEY_MINUS)
		zoom(a, -1);
	else if (keycode == KEY_SPACE)
		toggle(a->render);
	else
		key_board_nums(a, keycode);
	return (1);
}

int	mouse_hook(int action, int x, int y, t_app *a)
{
	a->mouse.x = x;
	a->mouse.y = y;
	// (void)a;
	if (action == MOUSE_LEFT)
	{
		printf("left click\n");
		// a->mouse_left.x = x;
		// a->mouse_left.y = y;
		// a->shapes.l_circle = rscreen_to_world(a, a->mouse_left);
		// printf("mouse position (%d, %d)\n", a->mouse_left.x, a->mouse_left.y);
	}
	else if (action == MOUSE_RIGHT)
	{
		printf("right click\n");
		// a->mouse_right.x = x;
		// a->mouse_right.y = y;
		// a->shapes.r_circle = rscreen_to_world(a, a->mouse_right);
		// printf("mouse position (%d, %d)\n", a->mouse_right.x, a->mouse_right.y);
	}
	else if (action == MOUSE_MIDDLE)
		printf("middle click\n");
	else if (action == MOUSE_SCROLL_UP)
		zoom(a, -1);
	else if (action == MOUSE_SCROLL_DOWN)
		zoom(a, 1);
	return (0);
}

int	mouse_move(int x, int y, t_app *a)
{
		a->mouse_down.x = x;
		a->mouse_down.y = y;
		return (1);
}