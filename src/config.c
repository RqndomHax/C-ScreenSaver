#include <stdio.h>
#include <stdlib.h>

#include "config.h"

Config *initConfig(int *errorCode) {
    Config *config = malloc(sizeof(Config));

    // init config structure
    if (!config)
        return (exit_function("configuration malloc", errorCode, CONFIG_INIT_MALLOC));

    // set config infos
    config->mode = (enum Modes) SNOW;
    config->clearDisplay = 1;
    config->algorithm = NULL;
    return (config);
}

void destroyConfig(Config *config) {
    free(config);
}