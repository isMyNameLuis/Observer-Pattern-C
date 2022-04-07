#include "provider.h"


struct ListNode
{
	observer_t item;
	struct ListNode* next;
};
typedef struct ListNode Node;

struct list
{
	Node* head;
};

typedef struct list List;

static List Observers = {NULL};
int example_data = 1;

bool provider_init(void)
{
    /*INIT*/
    printf("provider_init!\r\n");

	return true;
}

bool provider_deinit(void)
{
    printf("provider_deinit!\r\n");
    
    return true;
}


static Node * _createNode(observer_t item)
{
	Node * newNode = malloc(sizeof(Node));
	if(!newNode)
	{
		return NULL;
	}
	newNode->item = item;
	newNode->next = NULL;
  return newNode;
}

static void _append2List(const observer_t* observer)
{
	Node * current = NULL;
  	if(Observers.head == NULL)
	{
	  Observers.head = _createNode(*observer);
  	}
  	else 
	{
	  current = Observers.head; 
	  while (current->next!=NULL)
	  {
		current = current->next;
	  }
  	  	current->next = _createNode(*observer);
	}
}
static void _removeFromList(const observer_t* observer)
{
	Node * current = Observers.head;            
	Node * previous = current;           
	while(current != NULL)
	{           
		if(current->item.instance == observer->instance)
		{      
			previous->next = current->next;
			if(current == Observers.head)
				Observers.head = current->next;
			free(current);
			return;
		}                               
		previous = current;             
		current = current->next;        
	}  
}
bool provider_attach(const observer_t* observer)
{
	_assertNull(observer);
	_append2List(observer);	
}
bool provider_detach(const observer_t* observer)
{
	_assertNull(observer);
	_removeFromList(observer);
}

bool provider_process(void)
{
	_assertNull(Observers.head);
	Node* current = Observers.head;
	/*Main activity for what you want to provide here*/
    
	/*Notify change to subs -  ideally there is a condition for this to happen*/
    while(NULL != current)
    {
        observer_t* observer = &current->item;
        observer->notification(observer->instance, &example_data);
        current = current->next;
    }
    return true;
}


