
#include "../inc/so_long.h"

int check_around(t_data *data, int i, int j)
{
    printf("data->map[%d][%d]: %c\n", i, j, data->map[i][j]);
    if (data->map[i][j + 1] && data->map[i][j - 1])
    {
        if (data->map[i - 1][j] == data->content.wall &&
            data->map[i + 1][j] == data->content.wall &&
            data->map[i][j - 1] == data->content.wall &&
            data->map[i][j + 1] == data->content.wall)
            return (ft_error_int("Error!\nCollectcents or Player or Exit not reachable.\n"));
    }
    if (!data->map[i][j - 1])
    {
        if (data->map[i - 1][j] == data->content.wall &&
            data->map[i + 1][j] == data->content.wall &&
            data->map[i][j + 1] == data->content.wall)
            return (ft_error_int("Error!\nCollectcents or Player or Exit not reachable.\n"));
    }
    if (!data->map[i][j + 1])
    {
        if (data->map[i - 1][j] == data->content.wall &&
            data->map[i + 1][j] == data->content.wall &&
            data->map[i][j - 1] == data->content.wall)
            return (ft_error_int("Error!\nCollectcents or Player or Exit not reachable.\n"));
    }
    return (1);
}