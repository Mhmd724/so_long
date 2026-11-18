
#include "../inc/so_long.h"

void render_background(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == data->content.wall)
                print_img(data, data->img.img_wall, j, i);
            else if (data->map[i][j] == data->content.ground)
                print_img(data, data->img.img_ground, j, i);
            j++;
        }
        i++;
    }
}

void render_others(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == data->content.exit)
                print_img(data, data->img.img_exit, j, i);
            if (data->map[i][j] == data->content.collect)
                print_img(data, data->img.img_collect, j, i);
            if (data->map[i][j] == data->content.player)
            {
                data->pos.x = data->img.width * j;
                data->pos.y = data->img.height * i;
                print_img(data, data->img.img_player, j, i);
            }
            j++;
        }
        i++;
    }
}

void render(t_data *data)
{
    render_background(data);
    render_others(data);
}

void handle_rendering(t_data *data)
{
    data->mlx_win = mlx_new_window(data->mlx_ptr,
                                   (data->img.width * data->width), (data->img.height * data->height),
                                   "So_Long");
    if (!data->mlx_win)
        return;
    render(data);
    mlx_hook(data->mlx_win, KeyPress, KeyPressMask, &keypress, data);
    mlx_hook(data->mlx_win, 17, 0, &end, data);
    mlx_loop(data->mlx_ptr);
    end(data);
}

void print_img(t_data *data, void *img, int x, int y)
{
    mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img,
                            data->img.width * x, data->img.height * y);
}