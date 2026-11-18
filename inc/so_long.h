#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "../minilibx-linux/mlx.h"
#include "../libft/inc/libft.h"
#include "../libft/inc/ft_printf.h"
#include "../libft/inc/get_next_line.h"
#include <X11/keysym.h>
#include <X11/X.h>

typedef struct s_img
{
    void *img_wall;
    void *img_ground;
    void *img_exit;
    void *img_player;
    void *img_collect;
    int height;
    int width;
    char *player;
    char *exit;
    char *wall;
    char *ground;
    char *collect;
} t_img;

typedef struct s_pos
{
    int x;
    int y;
} t_pos;

typedef struct s_cnt
{
    char player;
    char exit;
    char collect;
    char wall;
    char ground;
    int count_p;
    int count_e;
    int count_c;
} t_cnt;

typedef struct s_data
{
    void *mlx_ptr;
    void *mlx_win;
    char **map;
    int width;
    int height;
    t_cnt content;
    t_img img;
    t_pos pos;
    int count;
} t_data;

/*Utils*/
// int ft_error(char *str);
void *ft_error(char *str);
int ft_error_int(char *str);
int ft_new_strchr(char *str, char *cmp);

/*Set*/
void set_contents(t_cnt *content);
int set_img(t_data *data);
void free_game(t_data *data);

/*Handle_map*/
char **handle_map(char **str, t_data *data);
char **parse_map(int fd, t_data *data);
char *get_map(int fd);
void *ft_free_map(t_data *data);

/*Map_checker*/
void ft_count_content(t_data *data);
int ft_check_format(char **map);
int ft_check_line(char *map_line, t_data *data);
int ft_check_col(char *map_line, char wall, t_data *data);
int ft_check_other(t_data *data, t_cnt *content, int i);

/*Handle Rendering*/
int handle_rendering(t_data *data);
void render(t_data *data);
void render_background(t_data *data);
void render_others(t_data *data);
void print_img(t_data *data, void *img, int x, int y);

/*RenderMoves*/
void render_left(t_data *data);
void render_right(t_data *data);
void render_top(t_data *data);
void render_down(t_data *data);

/*so_long*/
int check_collects(t_data *data);
int end(t_data *data);
int keypress(int keysym, t_data *data);

/*Collect_handling*/
int check_path(t_data *data);
#endif