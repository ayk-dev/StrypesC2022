#ifndef _FUNCS_H_
#define _FUNCS_H_
typedef struct node node_t;
void listPush(node_t** head, uint64_t el);
node_t* maxElement(node_t* list);
int checkBit(uint64_t mask, unsigned bit);
void listFree(node_t** head);
void listPrint(node_t* list);

#endif