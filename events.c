/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 08:30:37 by znichola          #+#    #+#             */
/*   Updated: 2022/12/01 15:19:14 by znichola         ###   ########.fr       */
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
}
	// a->cf.depth = a->scale.x * 0.001;
	// a->cf.depth = a->scale.x * 0.001;
	// a->start_depth = a->scale.x;
	// printf("scale: "); pf(a->scale); printf("\n");
	// printf("offset: "); pf(a->offset); printf("\n");

int	mouse_hook(int action, int x, int y, t_app *a)
{
	a->mouse.x = x;
	a->mouse.y = y;
	if (action == MOUSE_LEFT)
		a->mouse_left_toggle = toggle(a->mouse_left_toggle);
	else if (action == MOUSE_RIGHT)
		a->world_mouse_right = rscreen_to_world(a, a->mouse);
	else if (action == MOUSE_MIDDLE)
	{	
		a->cf.depth = 1;
		a->render = 1;
	}
	else if (action == MOUSE_SCROLL_UP)
		zoom(a, -1);
	else if (action == MOUSE_SCROLL_DOWN)
		zoom(a, 1);
	return (0);
}
		// a->mouse_left.x = x;
		// a->mouse_left.y = y;
		// a->shapes.l_circle = rscreen_to_world(a, a->mouse_left);
		// printf("mouse position (%d, %d)\n",
		// a->mouse_left.x, a->mouse_left.y);

int	mouse_move(int x, int y, t_app *a)
{
	a->mouse_down.x = x;
	a->mouse_down.y = y;
	return (0);
}
