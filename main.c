/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:57:33 by znichola          #+#    #+#             */
/*   Updated: 2022/11/28 23:42:55 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


// formula used to calculate the 

int	main(void)
{
	t_app app;
	
	init_app(&app);
	
	// mlx_hook(app.vars.mlx, ON_MOUSEMOVE, 0, mouse_action, &app.vars);
	mlx_key_hook(app.vars.win, key_press, &app.vars);
	mlx_mouse_hook(app.vars.win, mouse_hook, &app);

	mlx_hook(app.vars.win, ON_DESTROY, 0, destroy, &app.vars);
	mlx_loop_hook(app.vars.mlx, render_next_frame, &app);
	mlx_loop(app.vars.mlx);
}