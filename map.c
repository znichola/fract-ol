/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:45:12 by znichola          #+#    #+#             */
/*   Updated: 2022/10/27 20:37:10 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// map fuction takes screen input and maps it to the correct point the set
double	map(int val, int in_max, double out_min, double out_max)
{
	return (val * (out_max - out_min) / in_max + out_min);
}