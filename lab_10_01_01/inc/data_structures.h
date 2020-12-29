#ifndef __DATA_STRUCTURES_H__

#define __DATA_STRUCTURES_H__

typedef struct node_t
{
    void *data;

    struct node_t *next;
} node_t;

#endif // __DATA_STRUCTURES_H__
