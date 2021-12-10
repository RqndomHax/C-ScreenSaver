#ifndef SPACE_H_
#define SPACE_H_

#include "../../includes/error.h"
#include "../utils/list.h"
#include "../display.h"

typedef struct {

    list_t *stars;
    sfClock *respawn;
    sfClock *moveDelay;

}SpaceAlgorithm;

list_t *spaceAlgorithm(SpaceAlgorithm **algorithm);

void destroySpaceAlgorithm(SpaceAlgorithm *algorithm);

#endif /* !SPACE_H_ */