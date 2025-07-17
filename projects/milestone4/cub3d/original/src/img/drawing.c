/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:08:01 by marvin            #+#    #+#             */
/*   Updated: 2024/06/05 18:08:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
	{
		dst = img->addr + (y * img->line_length + \
				x * (img->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	img_draw_chunk(t_data *data, t_img *img, ssize_t h, ssize_t w)
{
	ssize_t	h_c;
	ssize_t	w_c;
	int		chunk_size;

	chunk_size = data->win->chunk_size;
	h_c = (h * chunk_size + data->win->offset_y);
	while (h_c < (h * chunk_size + data->win->offset_y) + chunk_size - 1)
	{
		w_c = w * chunk_size + data->win->offset_x;
		while (w_c < (w * chunk_size + data->win->offset_x) + chunk_size - 1)
		{
			if (h_c >= 0 && h_c < img->height && w_c >= 0 && w_c < img->width)
			{
				if (data->map->chunks[h][w].type == CHUNK_EMPTY || \
					data->map->chunks[h][w].type == CHUNK_PLAYER)
					my_mlx_pixel_put(img, w_c, h_c, 0x3B444B);
				else if (data->map->chunks[h][w].type == CHUNK_WALL)
					my_mlx_pixel_put(img, w_c, h_c, 0x515251);
			}
			w_c++;
		}
		h_c++;
	}
}

void	img_draw_player(t_data *data, t_img *img, int size)
{
	int	x;
	int	y;
	int	start_x;
	int	start_y;

	x = (data->player->x * data->win->chunk_size) + data->win->offset_x;
	y = (data->player->y * data->win->chunk_size) + data->win->offset_y;
	start_y = y - (size / 2);
	while (start_y < (y + 1) + (size / 2))
	{
		start_x = x - (size / 2);
		while (start_x < (x + 1) + (size / 2))
			if (data->win->map_view)
				my_mlx_pixel_put(img, start_x++, start_y, 0xF5B932);
		start_y++;
	}
}

void	img_draw_map(t_data *data, t_img *img)
{
	ssize_t	h;
	ssize_t	w;

	h = -1;
	data->win->offset_x = (data->config->r_w - \
		(data->map->l * data->win->chunk_size)) / 2;
	data->win->offset_y = (data->config->r_h - \
		(data->map->h * data->win->chunk_size)) / 2;
	while (++h < data->map->h)
	{
		w = -1;
		while (++w < data->map->l)
			img_draw_chunk(data, img, h, w);
	}
	img_draw_player(data, img, data->win->chunk_size / 3);
}
