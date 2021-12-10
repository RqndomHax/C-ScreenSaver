#ifndef DISPLAY_H_
#define DISPLAY_H_

/*
==> SFML IMPORTS FOR GRAPHICAL DISPLAY <==
*/
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#include "../includes/error.h"
#include "config.h"

typedef struct {
    sfRenderWindow *window;
    sfFont *font;
    sfClock *fpsClock;
}Display;

Display *initDisplay(int *errorCode);
void destroyDisplay(Display *display);

void displayHandler(Config *config, Display *display);

#endif /* !DISPLAY_H_ */