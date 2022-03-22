/*
** EPITECH PROJECT, 2021
** proto.h
** File description:
** proto
*/

#ifndef PROTO_H_
    #define PROTO_H_

    #include <SFML/System/Export.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Graphics/Texture.h>
    #include <SFML/Graphics/Sprite.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <SFML/Window/Export.h>
    #include <SFML/Window/Joystick.h>
    #include <SFML/Window/Keyboard.h>
    #include <SFML/Window/Mouse.h>
    #include <SFML/Window/Sensor.h>
    #include <SFML/Audio/Sound.h>
    #include <math.h>

    #define RIGHT 1
    #define LEFT -1
    #define UP 2
    #define COLUMN 32
    #define LINE 18
    #define DOWN -2
    #define SIZE 60
    #define NB_MOB 10
    #define DIALOG_BOX_SIZE 869

typedef struct coord_s {
    int x;
    int y;
} coord_t;

typedef enum game_type_s {
    mob_type,
    error,
    ok,
    null,
    block_type,
    tower_type,
    end,
    bot_left,
    top_left,
    bot_right,
    top_right,
    horizontal,
    vertical,
} game_type_t;

typedef enum direction_s {
    up,
    down,
    right,
    left,
} direction_t;

typedef struct checkpoint_s {
    sfVector2f *point_pos;
    int count;
    int tmp;
} checkpoint_t;

typedef enum shot_s {
    is_shot,
    not_shot,
} shot_t;

typedef enum life_s {
    dead,
    alive,
} life_t;

typedef enum tower_type_s {
    normal,
    laser,
    slower,
    sniper,
    none,
} tower_type_t;

typedef struct mob_s {
    int count;
    int id;
    float life;
    float speed;
    float speed_save;
    sfSprite *mob_sprite;
    checkpoint_t *checkpoint;
    game_type_t type;
    life_t life_state;
    direction_t direction;
    sfVector2f position;
    sfRectangleShape *red;
    sfRectangleShape *green;
} mob_t;

typedef struct block_s {
    sfVector2f position;
    sfFloatRect hitbox;
    sfSprite *block_sprite;
    game_type_t type;
    int count;
    int tmp;
} block_t;

typedef struct map_s {
    int count;
    int tmp;
    float *mob_path_x;
    float *mob_path_y;
    char **map;
    int state;
    game_type_t type;
    sfVector2f end;
    sfVector2f start;
    sfSprite *sheet;
    int nb_tower;
    int nb_mob;
} map_t;

typedef struct delta_s {
    sfTime cur;
    sfTime old;
    float time;
    float count;
    float count2;
    sfClock *clock;
} delta_t;

typedef struct audio_s {
    sfMusic *ost;
    sfMusic *game;
    sfSound *btn_click;
    sfSound *place;
    sfSoundBuffer *buff_clk;
    sfSoundBuffer *place_snd;
} audio_t;

typedef struct tower_s {
    sfVector2f position;
    sfVector2f circle_pos;
    sfVector2f circle_center;
    sfFloatRect hitbox;
    int radius;
    sfCircleShape *circle;
    sfSprite *tower;
    sfSprite *block_sprite;
    game_type_t type;
    int count;
    int tmp;
    int focus;
    tower_type_t tower_type;
} tower_t;

typedef struct game_s {
    int nb_mob;
    mob_t **mob;
    tower_t **tower;
    block_t **path;
    sfSprite *bg;
    sfSprite *dialog;
    sfFont *font;
    sfText *info;
    sfSprite *game_bar;
    sfSprite *end_screen;
    sfSprite *snd_vis;
    sfText *money_text;
    game_type_t type;
    audio_t sfx;
    sfRectangleShape *filter;
    sfIntRect *sound_rect;
    sfIntRect win;
    sfIntRect lose;
    int money;
    char *str_money;
    int fps_state;
    int sound_volume;
    int score;
    sfText *score_text;
    char *str_score;
} game_t;

typedef enum gamestate_e {
    in_menu,
    in_game,
    is_paused,
    settings,
    end_game,
    restart,
} state_t;

typedef enum btn_type_e {
    start,
    options,
    quit,
    menu,
    resume,
    turret_sp,
    laser_sp,
    slow_sp,
    snp_sp,
    low,
    high,
    fps,
    howtoplay,
    onpause,
    idle
} type_t;

typedef struct mouse_s {
    tower_type_t type;
    sfVector2i position;
} mouse_t;

typedef struct win_s {
    sfRenderWindow *window;
    sfEvent event;
    mouse_t mouse;
    delta_t dt;
    state_t state;
    int base_life;
} win_t;

typedef struct button_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect idle;
    sfIntRect hover;
    sfIntRect click;
    type_t type;
    sfBool clicked;
} button_t;

typedef struct scene_s {
    mob_t mobs;
    button_t *buttons;
} scene_t;

char *get_map(char *filepath);
int max_size(int j, int count);
int column_size(char **map);
int size_map(char **map);
int condition_connected(char **map, coord_t *path, int y, int x);
int is_linked(char **map, coord_t *path);
int is_connected(char **map, coord_t *path);
int is_path(coord_t *path, char **map);
int check_path(char **map);
int check_spawn(map_t *map);
int check_castle(map_t *map);
int good_map_condition(char c);
int correct_map(char **map);
char **str_to_array(char *str, char c, char t);
void free_array(char **array);
map_t gestion_map(char *filepath);
int game_window(map_t map);
void window_event(win_t *window, game_t *game);
sfRenderWindow *create_video(void);
block_t *return_bot_left(float x, float y, sfSprite *sheet);
block_t *return_bot_right(float x, float y, sfSprite *sheet);
block_t *return_top_right(float x, float y, sfSprite *sheet);
block_t *return_top_left(float x, float y, sfSprite *sheet);
block_t *return_vertical(float x, float y, sfSprite *sheet);
block_t *return_horizontal(float x, float y, sfSprite *sheet);
sfSprite *create_sprite(char *filepath);
int is_right(map_t map, int tmp);
int is_left(map_t map, int tmp);
int is_up(map_t map, int tmp);
int is_down(map_t map, int tmp);
sfSprite *create_sprite(char *filepath);
sfVector2f create_vector(float x, float y);
void init_time(delta_t *dt);
void update_time(delta_t *dt);
int condition_nb_pos(char c1, int count, char c2);
int return_nb_pos(char **map, char c);
int is_a_path(map_t *map, int y, int x, coord_t *path);
int check_path_pos(map_t *map, coord_t *path);
void return_mob_path(map_t *map);
void create_mob_path(map_t *map);
block_t *check_angle_right(map_t *map, int tmp);
block_t *check_angle_left(map_t *map, int tmp);
block_t *check_angle_up(map_t *map, int tmp);
block_t *check_angle_down(map_t *map, int tmp);
block_t *return_path(map_t *map, int tmp);
block_t **create_path(map_t map);
void destroy_all_mob(block_t **mob_path, int value);
void destroy_all(game_t *game, map_t map, win_t *window, scene_t *scene);
void destroy_all2(delta_t *dt, sfSprite *bg);
block_t *create_block(int x, int y);
tower_t **create_map(map_t *map);
mob_t *create_mob(map_t map, block_t **path, int value);
mob_t **create_all_mob(map_t map, block_t **path);
void place_tower(map_t *map);
void fill_map(char **map);
sfIntRect create_rect(int top, int left, int width, int height);
sfSprite *create_background(map_t map);
void display_window
(win_t window, tower_t **tower, sfSprite *bg, block_t **path);
void display_all_mob(win_t *window, mob_t **mob, block_t **path, map_t map);
game_t create_game(map_t *map);
scene_t *create_button(sfSprite *sheet);
win_t create_window(void);
void display_scene(win_t *window, scene_t *scene, int button_nbr,
game_t *game);
int condition_checkpoint(int tmp, sfVector2f *checkpoint, block_t *block);
sfVector2f create_checkpoint(block_t *block);
int count_checkpoint(block_t **path);
checkpoint_t *create_all_checkpoint(block_t **path, map_t map);
int count_checkpoint(block_t **path);
sfVector2f create_checkpoint(block_t *block);
checkpoint_t *create_all_checkpoint(block_t **path, map_t map);
void display_game(scene_t *scene, win_t *window, game_t *game, map_t map);
void init_game(win_t *window, game_t *game, map_t map);
void rotate_sprite_right
(mob_t *mob, block_t *path, game_type_t type, direction_t direction);
void rotate_sprite_up
(mob_t *mob, block_t *path, game_type_t type, direction_t direction);
void rotate_sprite_left
(mob_t *mob, block_t *path, game_type_t type, direction_t direction);
void rotate_sprite_down
(mob_t *mob, block_t *path, game_type_t type, direction_t direction);
void display_rotate_mob(block_t **path, mob_t **mob);
int my_vectcmp(sfVector2f pos1, sfVector2f pos2);
void display_game(scene_t *scene, win_t *window, game_t *game, map_t map);
sfVector2f copy_vector(sfVector2f pos);
void move_mob(mob_t **mob, win_t *window, map_t map);
void destroy_copy_sprite(block_t **tower);
void destroy_sound(game_t *game);
void destroy_scene(scene_t *scene);
void destroy_game_info(game_t *game);
sfVector2f copy_vector_size(sfVector2f pos);
void put_tower_normal(map_t map, tower_t *tower, sfSound *place);
void put_tower_laser(map_t map, tower_t *tower, sfSound *place);
void put_tower_slower(map_t map, tower_t *tower, sfSound *place);
void put_tower_sniper(map_t map, tower_t *tower, sfSound *place);
void check_put_tower(map_t map, win_t *window, tower_t *tower, game_t *game);
void check_pose_tower(win_t *window, game_t *game, map_t map);
int check_inside_rect(sfVector2f rect, sfVector2i mouse, int size);
int tower_shot(tower_t *tower, mob_t *mob);
void int_char(game_t *game);
void destroy_mob(mob_t **mob, int value);
void restart_all(game_t *game, map_t map, scene_t *scene);
void check_tower_attack(game_t *game, win_t *window);
void mob_state(mob_t *mob, game_t *game, float damage);
void cast_tower_focus(mob_t *mob, tower_t *tower);
int tower_shot(tower_t *tower, mob_t *mob);

#endif
