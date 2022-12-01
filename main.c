/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:57:33 by znichola          #+#    #+#             */
/*   Updated: 2022/12/01 20:15:08 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	valid_input_message(void)
{
	write(1, "\n~~ possible parametrs ~~\n", 27);
	write(1, "./fractol mandelbrot  or -m\n", 29);
	write(1, "./fractol julia  or -j\n", 29);
	write(1, "./fractol burningship  or -b\n", 29);
	write(1, "./fractol burningjulia  or -n\n", 31);
	write(1, "\noptional second parameter to define\n", 38);
	write(1, "the julia starting itteration\n", 31);
	write(1, "./fractol -j \"1.23 -1.23\" \n", 28);
	return (0);
}

int	welcome_message(void)
{
	write(1, "\n..ABAABABAABAABABAABABA\n", 26);
	write(1, "Welcome to the magical world of fractals,\n", 43);
	write(1, "explore the complex plane, itterate and selfrepeat\n", 52);
	write(1, "till all meaning is lost and you forget yourself.\n", 51);
	write(1, "\n      ~~ controle scheme ~~\n", 30);
	write(1, "   switch fractals : m j b n\n", 30);
	write(1, "    zoome to mouse : mouse_scroll\n", 35);
	write(1, "          movement : w a s d or arrow key\n", 43);
	write(1, "         re-center : r\n", 24);
	write(1, " spaw colour sheme : numbers 0 to 9\n", 37);
	write(1, "display itteration : mouse_left_click\n", 38);
	write(1, "select julia const : mouse_right_click\n", 39);
	write(1, "pause calculations : space_bar\n", 32);
	write(1, "      re-set depth : mouse_middle_click\n", 41);
	return (0);
}	

int	main(int ac, char **av)
{
	t_app	app;

	if (ac <= 1 || ac > 3)
		return (valid_input_message());
	welcome_message();
	(void)av;
	init_app(&app);
	mlx_hook(app.vars.win, ON_MOUSEMOVE, 0, mouse_move, &app);
	mlx_key_hook(app.vars.win, key_press, &app);
	mlx_mouse_hook(app.vars.win, mouse_hook, &app);
	mlx_hook(app.vars.win, ON_DESTROY, 0, destroy, &app.vars);
	mlx_loop_hook(app.vars.mlx, render_next_frame, &app);
	mlx_loop(app.vars.mlx);
}
