/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:45:12 by znichola          #+#    #+#             */
/*   Updated: 2022/12/01 01:19:38 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Convert coordinates from World Space --> Screen Space
t_ipoint	rworld_to_screen(t_app *a, t_fpoint w)
{
	t_ipoint	s;

	s.x = (int)((w.x - a->offset.x) * a->scale.x);
	s.y = (int)((w.y - a->offset.y) * a->scale.y);
	return (s);
}
	// printf("offset: "); pf(a->offset); 
	// printf(" scale: "); pf(a->scale); printf("\n");
	// printf("world to screeen: ");
	// pf(w); printf(" -> "); pi(s); printf("\n");

// Convert coordinates from Screen Space --> World Space
t_fpoint	rscreen_to_world(t_app *a, t_ipoint s)
{
	t_fpoint	w;

	w.x = (float)(((float)s.x / a->scale.x) + a->offset.x);
	w.y = (float)(((float)s.y / a->scale.y) + a->offset.y);
	return (w);
}
	// printf("offset: "); pf(a->offset);
	// printf(" scale: "); pf(a->scale); printf("\n");
	// printf("screen to world: "); pi(s); printf(" -> "); pf(w); printf("\n");
