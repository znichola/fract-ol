/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 08:30:37 by znichola          #+#    #+#             */
/*   Updated: 2022/11/28 23:47:04 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
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
		a->scale.x *= 1.1;
		a->scale.y *= 1.1;
	}
	else if (dir < 0)
	{
		a->scale.x *= 0.9;
		a->scale.y *= 0.9;
	}
	else
		return ;
	mouse_world_after_zoom = rscreen_to_world(a, a->mouse);
	a->offset.x += (mouse_world_before_zoom.x - mouse_world_after_zoom.x);
	a->offset.y += (mouse_world_before_zoom.y - mouse_world_after_zoom.y);
}

int	key_press(int keycode, t_app *a)
{
	printf("\nkeycode:[%d]\n", keycode);
	if (keycode == KEY_ESC)
		destroy(&a->vars);
	else if (keycode == KEY_UP || keycode == KEY_W)
		a->offset.y += 10;
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		a->offset.y -= 10;
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		a->offset.x -= 10;
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		a->offset.x += 10;
	else if (keycode == KEY_PLUS)
		zoom(a, 1);
	else if (keycode == KEY_MINUS)
		zoom(a, -1);
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

int	mouse_action(int action, int x, int y, t_app *a)
{
		printf("\nmousecode:[%d] (%d, %d)\n", action, x, y);
		a->mouse_down.x = x;
		a->mouse_down.y = y;
		return (1);
}