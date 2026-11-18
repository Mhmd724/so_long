
#include "../inc/so_long.h"

static void free_copy(char **copy)
{
    int i;

    i = 0;
    while (copy[i])
    {
        free(copy[i]);
        i++;
    }
    free(copy);
}

static char **copy_map(t_data *data)
{
    char **copy;
    int i;

    copy = malloc(sizeof(char *) * (data->height + 1));
    if (!copy)
        return (NULL);
    i = 0;
    while (i < data->height)
    {
        copy[i] = ft_strdup(data->map[i]);
        if (!copy[i])
        {
            free_copy(copy);
            return (NULL);
        }
        i++;
    }
    copy[i] = NULL;
    return (copy);
}

/*
** Marks every tile the player can walk to with 'V'.
** The exit is marked when reached but not walked through,
** because the player can't step onto it before collecting everything.
*/
static void flood_fill(char **map, int i, int j, t_data *data)
{
    if (map[i][j] == data->content.wall || map[i][j] == 'V')
        return ;
    if (map[i][j] == data->content.exit)
    {
        map[i][j] = 'V';
        return ;
    }
    map[i][j] = 'V';
    flood_fill(map, i + 1, j, data);
    flood_fill(map, i - 1, j, data);
    flood_fill(map, i, j + 1, data);
    flood_fill(map, i, j - 1, data);
}

static int has_unreached(char **map, t_data *data)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == data->content.collect
                || map[i][j] == data->content.exit)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int check_path(t_data *data)
{
    char **copy;
    int i;
    int j;
    int unreached;

    copy = copy_map(data);
    if (!copy)
        return (ft_error_int("Error\nMemory allocation failed.\n"));
    i = 0;
    while (copy[i] && !ft_strchr(copy[i], data->content.player))
        i++;
    j = ft_strchr(copy[i], data->content.player) - copy[i];
    flood_fill(copy, i, j, data);
    unreached = has_unreached(copy, data);
    free_copy(copy);
    if (unreached)
        return (ft_error_int("Error\nCollectibles or Exit not reachable.\n"));
    return (1);
}