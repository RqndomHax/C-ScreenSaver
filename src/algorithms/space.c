#include "space.h"
#include "../config.h"
#include "../utils/position.h"
#include <stdlib.h>

static SpaceAlgorithm *initSpaceAlgorithm(void)
{
    SpaceAlgorithm *algorithm = malloc(sizeof(SpaceAlgorithm));

    algorithm->stars = NULL;
    algorithm->respawn = sfClock_create();
    algorithm->moveDelay = sfClock_create();
    return (algorithm);
}

static void generateStar(SpaceAlgorithm *algorithm) {
    Position *star = malloc(sizeof(Position));
    star->x = 100-(random()%200);
    star->y = 100-(random()%200);
    list_push_back(&algorithm->stars, star);
}

static void moveStars(list_t *stars)
{
    list_t *current = stars;
    int i = 0;
    int size = list_size(stars);

    while (current != NULL) {
        Position *position = (Position *) current->data;
        position->x = position->x * STARS_GAP;
        position->y = position->y * STARS_GAP;

        i++;
        current = current->next;
    }
}

static void destroyStars(list_t **stars)
{
    list_t *current = *stars;
    list_t *previous = NULL;
    list_t *tmp = NULL;

    int centerX = WINDOW_WIDTH / 2;
    int centerY = WINDOW_HEIGHT / 2;

    while (current != NULL) {
        Position *position = (Position *) current->data;

        if (position->x + centerX <= 0 || position->x + centerX >= WINDOW_WIDTH || position->y + centerY <= 0 || position->y + centerY >= WINDOW_HEIGHT) {
            if (current->next == NULL) {
                free(current->data);
                free(current);
                if (!previous)
                    *stars = NULL;
                else
                    previous->next = NULL;
                return;
            }
            if (previous) {
                previous->next = current->next;
                free(current->data);
                free(current);
                current = previous->next;
                continue;
            }
            tmp = current;
            current = current->next;
            *stars = current;
            free(tmp->data);
            free(tmp);
            continue;
        }
        previous = current;
        current = current->next;
    }
}

list_t *spaceAlgorithm(SpaceAlgorithm **algorithm)
{

    // Check if the algorithm has been initialized
    if (!(*algorithm))
        *algorithm = initSpaceAlgorithm();

    if ((*algorithm)->stars && sfTime_asMilliseconds(sfClock_getElapsedTime((*algorithm)->moveDelay)) >= STAR_MOVE_DELAY) {
        moveStars((*algorithm)->stars);
        destroyStars(&(*algorithm)->stars);
        sfClock_restart((*algorithm)->moveDelay);
    }

    if (sfTime_asMilliseconds(sfClock_getElapsedTime((*algorithm)->respawn)) >= STAR_RESPAWN_DELAY) {
        generateStar(*algorithm);
        sfClock_restart((*algorithm)->respawn);
    }

    return ((*algorithm)->stars);
}

void destroySpaceAlgorithm(SpaceAlgorithm *algorithm) {
    if (algorithm) {
        list_destroy(&algorithm->stars);
        sfClock_destroy((*algorithm).respawn);
        sfClock_destroy((*algorithm).moveDelay);
        free(algorithm);
    }
}