# so_long

A small top-down 2D game written in C with the [MiniLibX](https://github.com/42Paris/minilibx-linux) graphics library, built as part of the 42 Beirut curriculum.

The player walks through a map loaded from a `.ber` file, picks up every collectible, and then reaches the exit. Every move is counted and printed to the terminal.

## Build

Requirements: Linux, `gcc`, `make`, and the X11 development headers.

```bash
sudo apt-get install gcc make xorg libxext-dev libbsd-dev   # Debian/Ubuntu
make
```

`make` builds `libft`, MiniLibX (both included in this repo), and then the `so_long` binary.

| Rule          | What it does                                  |
|---------------|-----------------------------------------------|
| `make`        | Build everything                              |
| `make clean`  | Remove object files                           |
| `make fclean` | Remove object files and the `so_long` binary  |
| `make re`     | Rebuild from scratch                          |

## Run

```bash
./so_long maps/map_correct.ber
```

Run it from the project folder: the sprites are loaded from `./assets/`.

## Controls

| Key                 | Action    |
|---------------------|-----------|
| `W` / `↑`           | Move up   |
| `A` / `←`           | Move left |
| `S` / `↓`           | Move down |
| `D` / `→`           | Move right|
| `Esc` / close window| Quit      |

The exit only opens once every collectible has been picked up.

## Maps

Maps are plain-text `.ber` files made of these characters:

| Char | Meaning     |
|------|-------------|
| `1`  | Wall        |
| `0`  | Floor       |
| `P`  | Player start|
| `E`  | Exit        |
| `C`  | Collectible |

Example:

```
1111111111111111111111
10P10000010000000000C1
1010000001000000100001
1000000000000001C00001
1000000001000000100001
1010000001000101000001
10E1000C0000010C000001
1010000001000101000001
1000000001000101000001
1111111111111111111111
```

The `maps/` folder has two valid maps (`map_correct.ber`, `map_correct_maze.ber`) and a set of invalid ones (`map_not_correct_*.ber`, `empty_map.ber`), one for each error case below.

## Error handling

On any error the program prints `Error` followed by an explicit message on stderr, then exits with code `1`:

```
Error
Collectibles or Exit not reachable.
```

It fails when:

- it isn't given exactly one map argument
- the map file doesn't have the `.ber` extension, or can't be opened
- the map is empty, or contains an empty line
- the map isn't rectangular
- the map isn't fully enclosed by walls
- there isn't exactly one player and one exit, or there are no collectibles
- the map contains a character other than `1`, `0`, `P`, `E`, `C`
- a collectible or the exit can't be reached from the player
- there is no display, the sprites can't be loaded, or the window can't be opened

Reachability is checked with a flood fill from the player. The exit stops the fill, since the player can't walk onto it before collecting everything.

## How it works

1. **Parse** – the `.ber` file is read into a buffer, checked for empty lines, split into rows, and validated (shape, walls, contents, reachability). A bad map is rejected before any window is opened.
2. **Init** – `mlx_init` connects to the X server.
3. **Setup** – the XPM sprites in `assets/` are loaded.
4. **Render** – the background (walls and floor) is drawn first, then the player, exit and collectibles.
5. **Loop** – `mlx_hook` handles key presses and the window close button, and `mlx_loop` keeps the game running.

## Project structure

```
.
├── assets/          # XPM sprites (wall, floor, player, exit, collectible)
├── inc/so_long.h    # Structs and prototypes
├── libft/           # My libft (+ ft_printf, get_next_line)
├── maps/            # Valid and invalid test maps
├── minilibx-linux/  # MiniLibX graphics library
├── srcs/            # Game source code
└── Makefile
```

## Author

**Mohamad Harajly** – [@Mhmd724](https://github.com/Mhmd724)

## License

This project is licensed under the MIT License – see [LICENSE](LICENSE). MiniLibX keeps its own license in `minilibx-linux/LICENSE`.
