/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** init_pause
*/

#include "prototype.h"

static void init_filter(pause_s *pause)
{
    sfVector2f size;
    sfVector2f pos;
    sfColor color;

    color.a = 100;
    color.b = 0;
    color.r = 0;
    color.g = 0;
    size.x = 1920;
    size.y = 1080;
    pos.x = 0;
    pos.y = 0;
    pause->filter = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(pause->filter, 0);
    sfRectangleShape_setFillColor(pause->filter, color);
    sfRectangleShape_setSize(pause->filter, size);
    sfRectangleShape_setPosition(pause->filter, pos);
}

static int init_resume(but_s *button)
{
    sfVector2f pos;
    sfVector2f size;
    sfTexture *start = sfTexture_createFromFile("assets/textures/button.jpg", NULL);

    pos.x = 773;
    pos.y = 400;
    size.x = 300;
    size.y = 100;
    button->is_clicked = 0;
    button->but = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(button->but, sfTransparent);
    sfRectangleShape_setOutlineThickness(button->but, 2);
    sfRectangleShape_setFillColor(button->but, sfWhite);
    sfRectangleShape_setSize(button->but, size);
    sfRectangleShape_setPosition(button->but, pos);
    sfRectangleShape_setTexture(button->but, start, sfFalse);
    button->txt = sfText_create();
    button->font = sfFont_createFromFile("assets/texts/menu.otf");
    set_text(button->txt, "resume", button->font, (sfVector2f){860, 420});
    return (1);
}

static int init_quit(but_s *button)
{
    sfVector2f pos;
    sfVector2f size;
    sfTexture *start = sfTexture_createFromFile("assets/textures/button.jpg", NULL);

    pos.x = 773;
    pos.y = 600;
    size.x = 300;
    size.y = 100;
    button->is_clicked = 0;
    button->but = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(button->but, sfTransparent);
    sfRectangleShape_setOutlineThickness(button->but, 2);
    sfRectangleShape_setFillColor(button->but, sfWhite);
    sfRectangleShape_setSize(button->but, size);
    sfRectangleShape_setPosition(button->but, pos);
    sfRectangleShape_setTexture(button->but, start, sfFalse);
    button->txt = sfText_create();
    button->font = sfFont_createFromFile("assets/texts/menu.otf");
    set_text(button->txt, "back to menu", button->font, (sfVector2f){800, 620});
}

static int init_quitgame(but_s *button)
{
    sfVector2f pos;
    sfVector2f size;
    sfTexture *start = sfTexture_createFromFile("assets/textures/button.jpg", NULL);

    pos.x = 773;
    pos.y = 800;
    size.x = 300;
    size.y = 100;
    button->is_clicked = 0;
    button->but = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(button->but, sfTransparent);
    sfRectangleShape_setOutlineThickness(button->but, 2);
    sfRectangleShape_setFillColor(button->but, sfWhite);
    sfRectangleShape_setSize(button->but, size);
    sfRectangleShape_setPosition(button->but, pos);
    sfRectangleShape_setTexture(button->but, start, sfFalse);
    button->txt = sfText_create();
    button->font = sfFont_createFromFile("assets/texts/menu.otf");
    set_text(button->txt, "quit game", button->font, (sfVector2f){833, 820});
}

int init_pause(pause_s *pause)
{
    char *path_back = "assets/textures/menu.jpg";

    init_filter(pause);
    pause->button = malloc(sizeof(but_s) * 4);
    if (pause->button == NULL)
        return (84);
    for (int i = 0; i != 4; i++)
        pause->button[i] = malloc(sizeof(struct button_s));
    if (pause->button[0] == NULL || pause->button[1] == NULL ||
        pause->button[2] == NULL)
        return (84);
    init_resume(pause->button[0]);
    init_quit(pause->button[1]);
    init_quitgame(pause->button[2]);
    pause->button[3] = NULL;
    pause->text_back = sfTexture_createFromFile(path_back, NULL);
    pause->spr_back = sfSprite_create();
    sfSprite_setTexture(pause->spr_back, pause->text_back, sfFalse);
    return (0);
}