/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:57:33 by znichola          #+#    #+#             */
/*   Updated: 2022/10/26 22:05:29 by znichola         ###   ########.fr       */
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


// xend = x + r cos(angle) and yend = y + r sin(angle)
// void put_circle(t_data *data, int radius, int x, int y)
// {
// 	for (int i = x; i < x+radius*2; i++)
// 		for (int e = y; e < y+radius*2; e++)
// 		{
// 			if ()
// 			{
// 				my_mlx_pixel_put(data, i, e, 0x00FF0000);
// 			}
// 		}
// }

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

	// neede to intialise the display engine
	mlx = mlx_init();
	
	// initialises a new windoes and places it inside thie pointer
	mlx_win = mlx_new_window(mlx, WIDTH, HIGHT, "Hello world!");

	// retraving the temporary buffer frame on wich we write before writing,
	//	to fill with the image we want to display
	//	it's only been initialised here.
	img.img = mlx_new_image(mlx, WIDTH, HIGHT);
	
	
	/*
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/
	// now we need to populate the image parameters using the function.
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	
	// fuction that put's a particular pixel to the display buffer
	
	// make a square, centred on the top right.
	
	// put_circle(&img, 100, WIDTH/2, HIGHT/2);
	DrawCircle(&img, (HIGHT/2)-50, WIDTH/2, HIGHT/2);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}