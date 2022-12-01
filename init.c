/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 00:29:49 by znichola          #+#    #+#             */
/*   Updated: 2022/12/01 01:16:32 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_app(t_app *p)
{
	p->vars.mlx = mlx_init();
	p->img.width = WIDTH;
	p->img.hight = HIGHT;
	p->vars.win = mlx_new_window(p->vars.mlx, p->img.width, p->img.hight,
			"Hello Fractal!");
	p->img.img = mlx_new_image(p->vars.mlx, p->img.width, p->img.hight);
	p->img.addr = mlx_get_data_addr(p->img.img,
			&p->img.bits_per_pixel,
			&p->img.line_length,
			&p->img.endian);
	p->scale = fpoint(p->img.width * 0.2, p->img.hight * 0.2);
	p->offset = fpoint(0, 0);
	p->offset = rscreen_to_world(p,
			ipoint(p->img.width / -2, p->img.hight / -2));
	init_pallets(&p->pallets);
	p->pallet_index = 0;
}
	// printf("screen center: "); 
	// pi(ipoint(p->img.width/2, p->img.hight/2)); printf("\n");
	// printf("world corrds: "); 
	// pf(rscreen_to_world(p, ipoint(-p->img.width/2, -p->img.hight/2))); 
	// printf("\n");

t_pallet	get_pallet(t_app *a, int i)
{
	return (a->pallets.p[i]);
}
