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

/*
==> DISPLAY VIDEO MODE <==
*/
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define WINDOW_FULLSCREEN 1
#define WINDOW_TITLE "Screensaver by RqndomHax"
#define WINDOW_FONT "assets/FontAwesome.ttf"
#define FPS_LIMIT 60

typedef struct {
    sfRenderWindow *window;
    sfFont *font;
    sfClock *fpsClock;
}Display;

Display *initDisplay(int *errorCode);
void destroyDisplay(Display *display);

void displayHandler(Display *display);

#endif /* !DISPLAY_H_ */