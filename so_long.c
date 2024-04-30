/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:08:03 by andreasgjer       #+#    #+#             */
/*   Updated: 2024/04/30 12:44:01 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>
#include <stdlib.h> 
#include <stdio.h>

int main(void)
{
    void *mlx;
    void *mlx_win;
    void *image;
    int image_width;
    int image_height;
    char *image_path = "./sprites/platforms.xpm";
    //int x;
    //int y;
    //int i;
    //y = 0;
    //x = 0;
    //i = 0;
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 800, 600, "so_long");
    image = mlx_xpm_file_to_image(mlx, image_path, &image_width, &image_height);
    printf("image address = %p\n", image);
    printf("width is %i\n", image_width);
    printf("height is %i\n", image_height);
    /*int gap = x / 64;
    int x_coord = (600 - x * 2) / 4 + (i *(x + gap));
    */
   mlx_put_image_to_window(mlx, mlx_win, image, (600 - image_width) / 4, (800 - image_height) / 4);
    mlx_loop(mlx);
}