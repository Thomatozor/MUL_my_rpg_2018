/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** disp
*/

#include <stdio.h>
#include "prototype.h"
#include "particles.h"

static int recreate_particles(particle_t *particles)
{
    sfColor color;

    if (particles == NULL)
        return (1);
    color = sfCircleShape_getFillColor(particles->circle);
    if (color.a == 0) {
        free_particles(particles);
        return (1);
    }
    return (0);
}

static void disp_map(sfRenderWindow *window, map_t *map)
{
    particle_t *particles = map->particles;

    for (map_obj_t *obj = map->objects; obj != NULL; obj = obj->next)
        sfRenderWindow_drawSprite(window, obj->sprite, NULL);
    for (; particles != NULL; particles = particles->next)
        sfRenderWindow_drawCircleShape(window, particles->circle, NULL);
    if (recreate_particles(map->particles))
        map->particles = create_particles(10, 510, 90);
}

void disp_scene(scene_t *scene, particle_t *particles)
{
    obj_t *ennemie = scene->ennemi;
    obj_t *pnj = scene->pnj;

    sfRenderWindow_clear(scene->window, sfBlack);
    disp_map(scene->window, scene->map);
    sfRenderWindow_drawSprite(scene->window, scene->perso->sprite, NULL);
    while (ennemie) {
        sfRenderWindow_drawSprite(scene->window, ennemie->sprite, NULL);
        ennemie = ennemie->next;
    }
    while (pnj) {
        sfRenderWindow_drawSprite(scene->window, pnj->sprite, NULL);
        if (pnj->discuss == 1) {
            sfRenderWindow_drawSprite(scene->window, pnj->text.sprite_bubble, NULL);
            sfRenderWindow_drawText(scene->window, pnj->text.phrase, NULL);
        }
        pnj = pnj->next;
    }
    sfRenderWindow_display(scene->window);
}