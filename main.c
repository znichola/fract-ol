/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:57:33 by znichola          #+#    #+#             */
/*   Updated: 2022/10/30 12:54:12 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


// formula used to calculate the 

int	main(void)
{
	t_app app;
	
	// t_data	img;
	// t_vars	vars;

	
	// t_complex	z;
	// z.a = 0.0;
	// z.b = 0.0;

	// t_complex	c;
	// c.a = 0.0;
	// c.b = 0.0;

	// vars.mlx = mlx_init();
	// vars.win = mlx_new_window(vars.mlx, WIDTH, HIGHT, "Hello world!");
	// img.img = mlx_new_image(vars.mlx, WIDTH, HIGHT);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);
	
	// mandelbrot set
	//	f(z) = z^2 + C
	// z is a complex variable
	// C in a complex constant
	//
	//	first we start with z = 0;
	//	z1 = f(0)
	//	z2 = f(z1)
	//	z3 = f(z2)
	//	...
	//	if this sequence is bounded, that C is solid, part of the mandelbrot set
	//	ie if the one of the first numbers is bigger than 2, we started with this
	
	// #FFF9F9
	// #FFFAF3
	// #FFFDF0
	// 0xFFFFFFFFFFFFFF06
	
	/* the complex number filed fitted to the screenspace */
	// t_cmpx_fld cf;
	// calc_complex_field(&cf, 500, 500, 1);
	
	// generate_madelbrot(&cf,&img);
	
	// mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);

	int foo = 0;
	init_app(&app);
	mlx_mouse_hook(app.vars.win, mouse_hook, &foo);//, p);
	mlx_loop_hook(app.vars.mlx, render_next_frame, &app);

	mlx_key_hook(app.vars.win, e_close, &app.vars);
	mlx_hook(app.vars.win, 17, 0, destroy, &app.vars);
	
	mlx_loop(app.vars.mlx);
}