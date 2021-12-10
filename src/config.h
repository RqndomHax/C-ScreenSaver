#ifndef CONFIG_H_
#define CONFIG_H_

/*
==> DISPLAY VIDEO MODE <==
*/
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define WINDOW_FULLSCREEN 1
#define WINDOW_TITLE "Screensaver by RqndomHax"
#define WINDOW_FONT "assets/FontAwesome.ttf"
#define FPS_LIMIT 300

/*
==> SPACE ALGORITHM OPTIONS <==
*/
#define STARS_GAP 1.05
#define STAR_RESPAWN_DELAY 20 // delay in milliseconds
#define STAR_MOVE_DELAY 20 // delay in milliseconds

#include "../includes/error.h"

enum Modes {
    SNOW,
    WORMHOLE,
    MIRROR
};

typedef struct
{
    enum Modes mode;
    int clearDisplay; // true = 1 ; false = 0
    void *algorithm;
}Config;

Config *initConfig(int *errorCode);

void destroyConfig(Config *config);

#endif /* !CONFIG_H_ */
