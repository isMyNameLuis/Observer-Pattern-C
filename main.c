#include "provider.h"
#include "observer.h"

void main(void)
{
    provider_init();
    observer_init();

    provider_process();

    return;
}


