
#include "../inc/so_long.h"

void set_img(t_data *data)
{
    data->img.width = 80;
    data->img.height = 80;
	data->img.ground = "./assets/floor.xpm";
	data->img.wall = "./assets/wall.xpm";
	data->img.collect = "./assets/collectors.xpm";
	data->img.player = "./assets/dragon.xpm";
	data->img.exit = "./assets/exit.xpm";
    data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr, data->img.wall,
                                               &(data->img.width), &(data->img.height));
    data->img.img_ground = mlx_xpm_file_to_image(data->mlx_ptr, data->img.ground,
                                                 &(data->img.width), &(data->img.height));
    data->img.img_exit = mlx_xpm_file_to_image(data->mlx_ptr, data->img.exit,
                                               &(data->img.width), &(data->img.height));
    data->img.img_collect = mlx_xpm_file_to_image(data->mlx_ptr, data->img.collect,
                                                  &(data->img.width), &(data->img.height));
    data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr, data->img.player,
                                                 &(data->img.width), &(data->img.height));
}

void set_contents(t_cnt *content)
{
    content->wall = '1';
    content->exit = 'E';
    content->collect = 'C';
    content->ground = '0';
    content->player = 'P';
    content->count_c = 0;
    content->count_e = 0;
    content->count_p = 0;
}