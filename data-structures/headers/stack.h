//
// Created by Rodrigues, Eduardo on 05/10/21.
//

#ifndef STACK_H
#define STACK_H
#include "node.h"

class stack {
public:
    stack();
    ~stack();

    bool isEmpty();
    int peek();
    void push(int data);
    int pop();
    void print();

private:
    node* top;
};

#endif //STACK_H
