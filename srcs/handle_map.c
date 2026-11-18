
#include "../inc/so_long.h"

char *get_map(int fd)
{
    char *buff;
    char *tmp;
    char *line;

    buff = NULL;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        if (buff == NULL)
            buff = ft_strdup(line);
        else
        {
            tmp = ft_strdup(buff);
            free(buff);
            buff = ft_strjoin(tmp, line);
            free(tmp);
        }
        free(line);
    }
    if (buff == NULL)
        return (ft_error("Error!\nThe map is empty.\n"));
    return (buff);
}

void *ft_free_map(t_data *data)
{
    int i;

    i = 0;
    while (data->map[i] != NULL)
    {
        free(data->map[i]);
        i++;
    }
    free(data->map);
    data->map = NULL;
    return (NULL);
}

char **parse_map(int fd, t_data *data)
{
    char *map;
    int i;

    map = get_map(fd);
    if (!map)
        return (NULL);
    data->map = ft_split(map, '\n');
    free(map);
    ft_count_content(data);
    if (!ft_check_format(data->map))
        return (ft_free_map(data));
    if (!ft_check_line(data->map[0], data))
        return (ft_free_map(data));
    i = 1;
    while (data->map[i])
    {
        if (!ft_check_col(data->map[i], data->content.wall, data))
            return (ft_free_map(data));
        else if (!ft_check_other(data, &(data->content), i))
            return (ft_free_map(data));
        i++;
    }
    data->height = i;
    if (!ft_check_line(data->map[i - 1], data))
        return (ft_free_map(data));
    return (data->map);
}

char **handle_map(char **str, t_data *data)
{
    int fd;

    fd = 0;
    data->map = NULL;
    if (!ft_new_strchr(str[1], ".ber"))
        return (ft_error("Error!\nWrong map format.\n"));
    fd = open(str[1], O_RDONLY);
    if (fd > 0)
        data->map = parse_map(fd, data);
    else
        return (ft_error("Error!\nFailed to open the File.\n"));
    if ((data->content.count_c == 0 || data->content.count_e != 1 || data->content.count_p != 1) && data->map != NULL)
    {
        ft_free_map(data);
        return (ft_error("Error!\nNeed 1 Player/Exit and at least 1 object.\n"));
    }
    if (data->map != NULL && !check_path(data))
        return (ft_free_map(data));
    return (data->map);
}