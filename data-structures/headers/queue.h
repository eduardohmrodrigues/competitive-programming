//
// Created by Rodrigues, Eduardo on 05/10/21.
//

#ifndef LEARNING_QUEUE_H
#define LEARNING_QUEUE_H

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

#endif //LEARNING_QUEUE_H
