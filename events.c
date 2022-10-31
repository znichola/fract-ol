/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 08:30:37 by znichola          #+#    #+#             */
/*   Updated: 2022/10/30 13:00:48 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	e_close(int keycode, t_vars *vars)
{
	printf("\nkeycode:[%d]\n", keycode);
	if (keycode == 53)
		destroy(vars);
	return(1);
}

int	destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	mouse_hook(int action, int *foo)
{
	(void)foo;
	// ap->cf.scale = 1;
	if (action == 5)
	{
		printf("zoome out");
		// ap->cf.scale += 0.1;
	}
	else if (action == 4)
	{
		printf("zoom in/n");
		// ap->cf.scale -= 0.1;
	}
	printf("mouse action done %d\n", action);
	return (0);
}