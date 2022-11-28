/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:45:12 by znichola          #+#    #+#             */
/*   Updated: 2022/11/28 23:17:32 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// map fuction takes screen input and maps it to the correct point the set
double	map(int val, int in_max, double out_min, double out_max)
{
	return (val * (out_max - out_min) / in_max + out_min);
}

void	pi(t_ipoint p)
{
	printf("(%d, %d)", p.x, p.y);
}

void	pf(t_fpoint p)
{
	printf("(%.1f, %.1f)", p.x, p.y);
}

// Convert coordinates from World Space --> Screen Space
void	world_to_screen(t_app *a, t_fpoint w, t_ipoint *s)
{
	s->x = (int)((w.x - a->offset.x) * a->scale.x);
	s->y = (int)((w.y - a->offset.y) * a->scale.y);
}

// Convert coordinates from Screen Space --> World Space
void	screen_to_world(t_app *a, t_ipoint s, t_fpoint *w)
{
	w->x = (float)(((float)s.x / a->scale.x) + a->offset.x);
	w->y = (float)(((float)s.y / a->scale.y) + a->offset.y);
}

// Convert coordinates from World Space --> Screen Space
t_ipoint	rworld_to_screen(t_app *a, t_fpoint w)
{
	t_ipoint	s;

	s.x = (int)((w.x - a->offset.x) * a->scale.x);
	s.y = (int)((w.y - a->offset.y) * a->scale.y);
	// printf("offset: "); pf(a->offset); printf(" scale: "); pf(a->scale); printf("\n");
	// printf("world to screeen: "); pf(w); printf(" -> "); pi(s); printf("\n");
	return (s);
}

// Convert coordinates from Screen Space --> World Space
t_fpoint	rscreen_to_world(t_app *a, t_ipoint s)
{
	t_fpoint	w;
	
	w.x = (float)(((float)s.x / a->scale.x) + a->offset.x);
	w.y = (float)(((float)s.y / a->scale.y) + a->offset.y);
	printf("offset: "); pf(a->offset); printf(" scale: "); pf(a->scale); printf("\n");
	printf("screen to world: "); pi(s); printf(" -> "); pf(w); printf("\n");
	return (w);
}