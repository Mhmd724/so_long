
#include "../inc/so_long.h"

void ft_count_content(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == data->content.collect)
                data->content.count_c += 1;
            if (data->map[i][j] == data->content.player)
                data->content.count_p += 1;
            if (data->map[i][j] == data->content.exit)
                data->content.count_e += 1;
            j++;
        }
        i++;
    }
}

int ft_check_format(char **map)
{
    int i;
    int j;
    int get_width;

    get_width = 0;
    while (map[0][get_width])
        get_width++;
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
            j++;
        if (j != get_width)
            return (ft_error_int("Error!\nMap must be rectangular or square.\n"));
        i++;
    }
    return (1);
}

int ft_check_line(char *map_line, t_data *data)
{
    int i;

    i = 0;
    while (map_line[i])
    {
        if (map_line[i] != data->content.wall)
            return (ft_error_int("Error!\nMap line not closed.\n"));
        i++;
    }
    return (1);
}

int ft_check_col(char *map_line, char wall, t_data *data)
{
    int i;

    i = 0;
    while (map_line[i])
        i++;
    if (map_line[0] != wall || map_line[i - 1] != wall)
        return (ft_error_int("Error!\nMap column not closed.\n"));
    data->width = i;
    return (1);
}

int ft_check_other(t_data *data, t_cnt *content, int i)
{
    int j;

    j = 0;
    while (data->map[i][j])
    {
        if (content->count_e > 1 || content->count_p > 1)
            return (ft_error_int("Error!\nWrong number of players or exit.\n"));
        if (data->map[i][j] != content->wall && data->map[i][j] != content->ground && data->map[i][j] != content->exit && data->map[i][j] != content->player && data->map[i][j] != content->collect)
            return (ft_error_int("Error!\nUnknown symbol(s) in map.\n"));
        if (data->map[i][j] == content->collect ||
            data->map[i][j] == content->player ||
            data->map[i][j] == content->exit)
            if (!check_around(data, i, j))
                return (0);
        j++;
    }
    return (1);
}