#include "scene.h"

//ALLEGRO_FONT *font = NULL;
ALLEGRO_BITMAP *background = NULL;
ALLEGRO_BITMAP *background_game[5];

// function of menu
void menu_init()
{
    font = al_load_ttf_font("./font/pirulen.ttf", 14, 0);
    background = al_load_bitmap("./image/in.png");
}
void menu_process(ALLEGRO_EVENT event)
{
    if (event.type == ALLEGRO_EVENT_KEY_UP)
        if (event.keyboard.keycode == ALLEGRO_KEY_ENTER)
            judge_next_window = true;
    if (event.keyboard.keycode == ALLEGRO_KEY_Q)
        close_game = true;
}
void menu_draw()
{
    al_draw_bitmap(background, 0, 0, 0);
    //al_clear_to_color(al_map_rgb(100, 100, 100));
    al_draw_text(font, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT / 2 + 220, ALLEGRO_ALIGN_CENTRE, "Press 'Enter' to start");
    al_draw_rectangle(WIDTH / 2 - 150, 510, WIDTH / 2 + 150, 550, al_map_rgb(255, 255, 255), 0);
    al_draw_text(font, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT / 2 + 220 - 50, ALLEGRO_ALIGN_CENTRE, "Press 'q' to quit");
    al_draw_rectangle(WIDTH / 2 - 150, 510 - 50, WIDTH / 2 + 150, 550 - 50, al_map_rgb(255, 255, 255), 0);
}
void menu_destroy()
{
    al_destroy_font(font);
}

// function of game_scene
void game_scene_init()
{
    character_init();
    rocks_init();
    stars_init();
    for (int i = 0; i < 6; i++)
    {
        char temp[50];
        sprintf(temp, "./image/stage%d.jpg", i);
        background_game[i] = al_load_bitmap(temp);
    }
}
void game_scene_draw()
{
    al_draw_bitmap(background_game[game_level], 0, 0, 0);
    character_draw();
    stars_draw();
    rocks_draw();
}
void game_scene_destroy()
{
    rocks_destory();
    stars_destory();
    for (int i = 0; i < 6; i++)
    {
        al_destroy_bitmap(background_game[i]);
    }
    character_destory();
}

void gg_scene_init()
{
    fonts = al_load_ttf_font("./font/pirulen.ttf", 64, 0);
    font = al_load_ttf_font("./font/pirulen.ttf", 14, 0);
    background = al_load_bitmap("./image/ggback.png");
}

void gg_scene_process(ALLEGRO_EVENT event)
{
    if (event.type == ALLEGRO_EVENT_KEY_UP)
        if (event.keyboard.keycode == ALLEGRO_KEY_ENTER)
            judge_next_window = true;
    if (event.keyboard.keycode == ALLEGRO_KEY_Q)
        close_game = true;
}

void gg_scene_draw()
{
    al_draw_bitmap(background, 0, 0, 0);
    //fonts = al_load_ttf_font("./font/pirulen.ttf", 14, 0);
    al_draw_text(font, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT / 2 - 80, ALLEGRO_ALIGN_CENTRE, "Press 'Enter' to restart");
    al_draw_text(font, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT / 2 - 30, ALLEGRO_ALIGN_CENTRE, "Press 'q' to quit");
    char temp[50];
    al_draw_text(fonts, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT / 2 + 20, ALLEGRO_ALIGN_CENTRE, "Score");
    sprintf(temp, ">> %d <<", (int)(end_time - play_time));
    al_draw_text(fonts, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT / 2 + 100, ALLEGRO_ALIGN_CENTRE, temp);
    al_draw_text(fonts, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT / 2 - 180, ALLEGRO_ALIGN_CENTRE, "GG");
}

void gg_scene_destroy()
{
    al_destroy_font(font);
    al_destroy_font(fonts);
    al_destroy_bitmap(background);
}