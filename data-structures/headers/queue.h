//
// Created by Rodrigues, Eduardo on 05/10/21.
//

#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

class queue{
public:

    queue();
    ~queue();

    bool isEmpty();
    int peek();
    void add(int data);
    int remove();
    void print();

private:
    node* head;
    node* tail;
};

#endif //QUEUE_H
