#include "config.h"
#include "display.h"

int main(int argc, char **argv) {
    (void) argc;
    (void) argv;

    int error = 0;
    // Constructor
    Config *config = initConfig(&error);
    if (error)
        return (error);

    Display *display = initDisplay(&error);
    if (error) {
        destroyConfig(config);
        return (error);
    }

    displayHandler(display);

    // Destructor
    destroyConfig(config);
    destroyDisplay(display);
    return (0);
}