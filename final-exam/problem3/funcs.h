#ifndef _FUNCS_H_
#define _FUNCS_H_
typedef struct node node_t;
void listPush(node_t** head, uint64_t el);
void listFree(node_t** head);
void listPrint(node_t* list);

#endif