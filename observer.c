#include "observer.h"

static observer_instance_t observer_instance = {false,0, "OBSERVER_1"};
static observer_t observer_id = {NULL,NULL,NULL};

static bool provider_notification(void* instance, const int* example_data )
{
	_assertNull(instance);
	_assertNull(example_data);

	/*Do something*/
    printf("Observer name %s notification called!\r\n", observer_instance.name);
    return true;
}

bool observer_init(void)
{
	observer_id.instance = &observer_instance;
	observer_id.notification = &provider_notification;
    observer_id.name = malloc(MAX_NAME_CHARS);
	strcpy(observer_id.name,observer_instance.name);
	provider_attach(&observer_id);
	observer_instance.init = true;
    printf("observer_init!\r\n");

	return true;
}

bool observer_deinit(void)
{
    free(observer_id.name);
    printf("observer_deinit!\r\n");

    return true;
}
