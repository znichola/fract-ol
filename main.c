/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:57:33 by znichola          #+#    #+#             */
/*   Updated: 2022/12/02 23:25:02 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	valid_input_message(void)
{
	write(1, "ERROR: invalid input\n", 22);
	write(1, "\n~~ possible parametrs ~~\n", 27);
	write(1, "./fractol -m for mandelbrot\n", 29);
	write(1, "./fractol -j for julia\n", 24);
	write(1, "./fractol -b for burningship\n", 30);
	write(1, "./fractol -n for burningjulia\n", 31);
	return (0);
}

int	welcome_message(void)
{
	write(1, "\n..ABAABABAABAABABAABABA\n", 26);
	write(1, "Welcome to the magical world of fractals,\n", 43);
	write(1, "explore the complex plane, itterate and selfrepeat,\n", 53);
	write(1, "loose all meaning and forget yourself...\n", 42);
	write(1, "\n        ~~ controle scheme ~~\n", 32);
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

int	inputparce(int *fractal, char *opt)
{
	int	i;

	i = 0;
	while (opt[i])
		i++;
	if (i >= 3)
		return (1);
	if (opt[0] != '-')
		return (1);
	if (opt[1] == 'm')
		*fractal = MANDELBROT;
	else if (opt[1] == 'j')
		*fractal = JULIA;
	else if (opt[1] == 'b')
		*fractal = BURNINGSHIP;
	else if (opt[1] == 'n')
		*fractal = NONAME;
	else
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_app	app;
	int		fractal;

	if (ac != 2 || inputparce(&fractal, av[1]))
		return (valid_input_message());
	init_app(&app);
	app.fractal_select = fractal;
	welcome_message();
	mlx_hook(app.vars.win, ON_MOUSEMOVE, (1L << 0), mouse_move, &app);
	mlx_key_hook(app.vars.win, key_press, &app);
	mlx_mouse_hook(app.vars.win, mouse_hook, &app);
	mlx_hook(app.vars.win, ON_DESTROY, (1L << 0), destroy, &app.vars);
	mlx_loop_hook(app.vars.mlx, render_next_frame, &app);
	mlx_loop(app.vars.mlx);
	return (0);
}
