/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 00:29:49 by znichola          #+#    #+#             */
/*   Updated: 2022/12/01 17:14:37 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_scale_offset(t_app *p)
{
	p->scale = fpoint(p->img.width * 0.2 * ((double)HIGHT / WIDTH),
			p->img.hight * 0.2);
	p->offset = fpoint(0, 0);
	p->offset = rscreen_to_world(p,
			ipoint(p->img.width / -2, p->img.hight / -2));
}

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
	set_scale_offset(p);
	init_pallets(&p->pallets);
	p->pallet_index = 0;
	p->start_depth = 1;
	p->fractal_select = 0;
	p->mouse_left_toggle = 0;
}
	// printf("screen center: "); 
	// pi(ipoint(p->img.width/2, p->img.hight/2)); printf("\n");
	// printf("world corrds: "); 
	// pf(rscreen_to_world(p, ipoint(-p->img.width/2, -p->img.hight/2))); 
	// printf("\n");
