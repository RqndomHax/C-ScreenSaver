#ifndef CONFIG_H_
#define CONFIG_H_

#include "../includes/error.h"

enum Modes {
    SNOW,
    WORMHOLE,
    MIRROR
};

typedef struct
{
    enum Modes mode;
}Config;

Config *initConfig(int *errorCode);

void destroyConfig(Config *config);

#endif /* !CONFIG_H_ */
