
#include "../inc/so_long.h"

int check_collects(t_data *data)
{
    int i;
    int j;
    int count;

    i = 0;
    count = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == data->content.collect)
                count++;
            j++;
        }
        i++;
    }
    return (count);
}

int end(t_data *data)
{
    int i;

    i = 0;
    if (data->map)
    {
        while (data->map[i])
        {
            free(data->map[i]);
            i++;
        }
        free(data->map);
        mlx_destroy_image(data->mlx_ptr, data->img.img_wall);
        mlx_destroy_image(data->mlx_ptr, data->img.img_ground);
        mlx_destroy_image(data->mlx_ptr, data->img.img_exit);
        mlx_destroy_image(data->mlx_ptr, data->img.img_player);
        mlx_destroy_image(data->mlx_ptr, data->img.img_collect);
        mlx_destroy_window(data->mlx_ptr, data->mlx_win);
    }
    mlx_destroy_display(data->mlx_ptr);
    free(data->mlx_ptr);
    exit(0);
}

int keypress(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
        end(data);
    if (keysym == XK_a || keysym == 65361)
        render_left(data);
    if (keysym == XK_w || keysym == 65362)
        render_top(data);
    if (keysym == XK_d || keysym == 65363)
        render_right(data);
    if (keysym == XK_s || keysym == 65364)
        render_down(data);
    return (0);
}

int main(int argc, char **argv)
{
    t_data data;

    if (argc != 2)
        return (ft_error_int("Error!\nThis program takes 1 argument.\n"));
    else
    {
        data.count = 0;
        data.mlx_ptr = mlx_init();
        set_contents(&(data.content));
        data.map = handle_map(argv, &data);
        if (!data.map)
            end(&data);
        else
        {
            set_img(&data);
            handle_rendering(&data);
        }
    }
    return (1);
}