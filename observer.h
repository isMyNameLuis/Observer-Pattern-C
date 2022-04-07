#ifndef __OBSERVER__H__
#define __OBSERVER__H__

#include "provider.h"

typedef struct observer_instance_s
{
    bool init;
    int data;
    char* name;
}observer_instance_t;

bool observer_init(void);
bool observer_deinit(void);

#endif

