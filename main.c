/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:57:33 by znichola          #+#    #+#             */
/*   Updated: 2022/10/28 00:22:42 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


// formula used to calculate the 

// int offset = (y * line_length + x * (bits_per_pixel / 8));
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	if (x < 0 || y < 0 || x > WIDTH || y > HIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void put_square(t_data *data, int w, int h, int x, int y)
{
	for (int i = x; i < x+w; i++)
	{
		for (int e = y; e < y+h; e++)
			my_mlx_pixel_put(data, i, e, 0x00FF0000);
	}
}

int	DrawCircle(t_data *data, int r, int x, int y)
{
	static const double PI = 3.1415926535;
	double i, angle, x1, y1;
 
	for(i = 0; i < 360; i += 0.1)
	{
		angle = i;
		x1 = r * cos(angle * PI / 180);
		y1 = r * sin(angle * PI / 180);
		my_mlx_pixel_put(data, x1 + x, y1 + y, 0x00FF0000);
	}
	return (1);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	t_complex	z;
	z.a = 0.0;
	z.b = 0.0;

	t_complex	c;
	c.a = 0.0;
	c.b = 0.0;

	double	a_min = -2.2;
	double	a_max = .8;
	double	b_min = fabs(a_min - a_max) * ((double)HIGHT / (double)WIDTH) / -2;
	double	b_max = fabs(a_min - a_max) * ((double)HIGHT / (double)WIDTH) / 2;

	// print_complex("power", set(z, c, 5));
	// printf ("found depth {%d}\n", fractal_set(z, c, 10));
	
	// printf("%f\n", map(WIDTH/2+10, WIDTH, -2, 2));

	// return (0);

	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HIGHT, "Hello world!");
	img.img = mlx_new_image(mlx, WIDTH, HIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	
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
	int	colour = 0XE2DED0;
	for (int h = 0; h < HIGHT; h++)
	{
		for (int w = 0; w < WIDTH; w++)
		{
			c.a = map(w, WIDTH, a_min, a_max);
			if (w == 0)
				c.b = map(h, HIGHT, b_min, b_max);
			int d = fractal_set(z, c, DEPTH);
			// printf("% 3d ", d);
			if (d == -1)
				colour = 0X4E4F50;
			else 
				colour = 0XE2DED0;
			my_mlx_pixel_put(&img, w, h, colour);
		}
		// printf("\n ----");
	}

	// my_mlx_pixel_put(&img, 50, 50, 0X4E4F50);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}