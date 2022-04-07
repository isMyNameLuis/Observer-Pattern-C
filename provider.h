#ifndef __PROVIDER__H__
#define __PROVIDER__H__

#include "std_includes.h"

typedef bool (*notification_prototype)(void* instance, const int* example_data );

typedef struct observer_s
{
	void* instance;
	notification_prototype notification;
	char* name;
}observer_t;


bool provider_init(void);
bool provider_process(void);
bool provider_attach(const observer_t* observer);
bool provider_detach(const observer_t* observer);

#endif
