#ifndef ERROR_H_
#define ERROR_H_

/*
==> CONFIGURATION ERROR CODES <==
*/
#define CONFIG_INIT_MALLOC 1
#define CONFIG_INIT_FILE 2

/*
==> DISPLAY ERROR CODES <==
*/
#define DISPLAY_INIT_MALLOC 3
#define DISPLAY_INIT_WINDOW 4
#define DISPLAY_INIT_FONT 5
#define DISPLAY_INIT_FPS_CLOCK 6
#define DISPLAY_INIT_FPS_TEXT 7
#define DISPLAY_INIT_SPRITES 8
#define DISPLAY_DRAW 9

void *exit_function(char *errorMessage, int *errorCode, int error);

#endif /* !ERROR_H_ */
