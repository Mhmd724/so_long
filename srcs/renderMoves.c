
#include "../inc/so_long.h"

void render_left(t_data *data)
{
    int pos_i;
    int pos_j;

    pos_i = data->pos.y / data->img.height;
    pos_j = data->pos.x / data->img.width;
    if (data->map[pos_i][pos_j - 1] != data->content.wall)
    {
        if (!(data->map[pos_i][pos_j - 1] == data->content.exit))
        {
            data->map[pos_i][pos_j - 1] = data->content.player;
            data->map[pos_i][pos_j] = data->content.ground;
            render(data);
            data->count += 1;
            printf("Count = %d\n", data->count);
        }
        else
        {
            if (check_collects(data) == 0)
            {
                printf("Congratulations, you have won the game in %d moves.\n", data->count);
                end(data);
            }
        }
    }
}

void render_right(t_data *data)
{
    int pos_i;
    int pos_j;

    pos_i = data->pos.y / data->img.height;
    pos_j = data->pos.x / data->img.width;
    if (data->map[pos_i][pos_j + 1] != data->content.wall)
    {
        if (!(data->map[pos_i][pos_j + 1] == data->content.exit))
        {
            data->map[pos_i][pos_j + 1] = data->content.player;
            data->map[pos_i][pos_j] = data->content.ground;
            render(data);
            data->count += 1;
            printf("Count = %d\n", data->count);
        }
        else
        {
            if (check_collects(data) == 0)
            {
                printf("Congratulations, you have won the game in %d moves.\n", data->count);
                end(data);
            }
        }
    }
}

void render_top(t_data *data)
{
    int pos_i;
    int pos_j;

    pos_i = data->pos.y / data->img.height;
    pos_j = data->pos.x / data->img.width;
    if (data->map[pos_i - 1][pos_j] != data->content.wall)
    {
        if (!(data->map[pos_i - 1][pos_j] == data->content.exit))
        {
            data->map[pos_i - 1][pos_j] = data->content.player;
            data->map[pos_i][pos_j] = data->content.ground;
            render(data);
            data->count += 1;
            printf("Count = %d\n", data->count);
        }
        else
        {
            if (check_collects(data) == 0)
            {
                printf("Congratulations, you have won the game in %d moves.\n", data->count);
                end(data);
            }
        }
    }
}

void render_down(t_data *data)
{
    int pos_i;
    int pos_j;

    pos_i = data->pos.y / data->img.height;
    pos_j = data->pos.x / data->img.width;
    if (data->map[pos_i + 1][pos_j] != data->content.wall)
    {
        if (!(data->map[pos_i + 1][pos_j] == data->content.exit))
        {
            data->map[pos_i + 1][pos_j] = data->content.player;
            data->map[pos_i][pos_j] = data->content.ground;
            render(data);
            data->count += 1;
            printf("Count = %d\n", data->count);
        }
        else
        {
            if (check_collects(data) == 0)
            {
                printf("Congratulations, you have won the game in %d moves.\n", data->count);
                end(data);
            }
        }
    }
}