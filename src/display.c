#include "display.h"

#include <stdio.h>
#include <stdlib.h>

static void displayEvents(Display *display);
static void displayDraw(Display *display);

Display *initDisplay(int *errorCode) {
    Display *display = malloc(sizeof(Display));

    // init display structure
    if (!display)
        return (exit_function("display malloc", errorCode, DISPLAY_INIT_MALLOC));

    // Video mode
    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 8};
    sfUint32 windowStyle = sfClose | (WINDOW_FULLSCREEN ? sfFullscreen : 0);

    // init window
    display->window = sfRenderWindow_create(mode, WINDOW_TITLE, windowStyle, NULL);
    if (!display->window) {
        free(display);
        return (exit_function("display window initialization", errorCode, DISPLAY_INIT_WINDOW));
    }

    // set fps limit
    sfRenderWindow_setFramerateLimit(display->window, FPS_LIMIT);
    // TODO SET ICON

    // disable window cursor
    sfRenderWindow_setMouseCursorVisible(display->window, sfFalse);

    // FONT
    display->font = sfFont_createFromFile(WINDOW_FONT);
    if (!display->font) {
        sfRenderWindow_destroy(display->window);
        free(display);
        return (exit_function("font initalization", errorCode, DISPLAY_INIT_FONT));
    }

    // FPS Clock
    display->fpsClock = sfClock_create();
    if (!display->fpsClock) {
        sfRenderWindow_destroy(display->window);
        sfFont_destroy(display->font);
        free(display);
        return (exit_function("display fps clock initalization", errorCode, DISPLAY_INIT_FPS_CLOCK));
    }
    return (display);
}

void destroyDisplay(Display *display) {
    sfRenderWindow_destroy(display->window);
    sfFont_destroy(display->font);
    sfClock_destroy(display->fpsClock);
    free(display);
}

void displayHandler(Display *display) {
    while (sfRenderWindow_isOpen(display->window)) {

        // compute sreensaver algorithm

        // check events
        displayEvents(display);

        // draw screen
        displayDraw(display);
    }
}

static void displayEvents(Display *display) {
    sfEvent event;

    while (sfRenderWindow_pollEvent(display->window, &event)) {

        // Check exit
        if ((event.type == sfEvtClosed) || (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)) {
            sfRenderWindow_close(display->window);
            return;
        }

    }
}

static void displayDraw(Display *display) {
    // Reset screen
    sfRenderWindow_clear(display->window, sfBlack);

    // TODO draw screensaver

    // Refresh screen
    sfRenderWindow_display(display->window);
}