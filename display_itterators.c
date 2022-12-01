/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_itterators.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:30:30 by znichola          #+#    #+#             */
/*   Updated: 2022/12/01 18:40:40 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_itterations(t_app *p)
{
	t_complex	z;
	t_complex	c;
	int			i;

	i = 1;
	p->points[0] = rworld_to_screen(p, fpoint(0.0, 0.0));
	while (i < MAXPOINTS)
	{
		z = ftc(rscreen_to_world(p, p->points[i - 1]));
		c = ftc(rscreen_to_world(p, p->mouse_down));
		p->points[i] = rworld_to_screen(p, ctf(c_addition(c_power2(z), c)));
		put_circle_fast(&p->img, 2, p->points[i], colour_lerp(1, MAXPOINTS, i));
		i++;
	}
	return (0);
}

// return (mandelbrot_like(test, ftc(a->world_mouse_right), depth));
int	julia_itterations(t_app *p)
{
	t_complex	z;
	t_complex	c;
	int			i;
	t_fpoint	test;

	i = 1;
	test = rscreen_to_world(p, p->mouse_down);
	p->points[0] = rworld_to_screen(p, test);
	while (i < MAXPOINTS)
	{
		z = ftc(rscreen_to_world(p, p->points[i - 1]));
		c = ftc(p->world_mouse_right);
		p->points[i] = rworld_to_screen(p, ctf(c_addition(c_power2(z), c)));
		put_circle_fast(&p->img, 2, p->points[i], colour_lerp(1, MAXPOINTS, i));
		i++;
	}
	return (0);
}

int	burningship_itterations(t_app *p)
{
	t_complex	z;
	t_complex	c;
	int			i;

	i = 1;
	p->points[0] = rworld_to_screen(p, fpoint(0.0, 0.0));
	while (i < MAXPOINTS)
	{
		z = ftc(rscreen_to_world(p, p->points[i - 1]));
		c = ftc(rscreen_to_world(p, p->mouse_down));
		p->points[i] = rworld_to_screen(p,
				ctf(c_abs(c_addition(c_power2(z), c))));
		put_circle_fast(&p->img, 2, p->points[i], colour_lerp(1, MAXPOINTS, i));
		i++;
	}
	return (0);
}

int	burningjulia_itterations(t_app *p)
{
	t_complex	z;
	t_complex	c;
	int			i;
	t_fpoint	test;

	i = 1;
	test = rscreen_to_world(p, p->mouse_down);
	p->points[0] = rworld_to_screen(p, test);
	while (i < MAXPOINTS)
	{
		z = ftc(rscreen_to_world(p, p->points[i - 1]));
		c = ftc(p->world_mouse_right);
		p->points[i] = rworld_to_screen(p,
				ctf(c_abs(c_addition(c_power2(z), c))));
		put_circle_fast(&p->img, 2, p->points[i], colour_lerp(1, MAXPOINTS, i));
		i++;
	}
	return (0);
}

int	display_itterations(t_app *p)
{
	if (p->fractal_select == MANDELBROT)
		mandelbrot_itterations(p);
	else if (p->fractal_select == BURNINGSHIP)
		burningship_itterations(p);
	else if (p->fractal_select == JULIA)
		julia_itterations(p);
	else if (p->fractal_select == NONAME)
		burningjulia_itterations(p);
	return (0);
}
