//
// Created by Rodrigues, Eduardo on 05/10/21.
//

#include <cstdio>
#include "../headers/stack.h"

stack::stack() {
    top = nullptr;
}

stack::~stack() {}

bool stack::isEmpty() {
    return top == nullptr;
}

int stack::peek() {
    return top->data;
}

void stack::push(int data) {
    node* curr = new node(data);
    curr->next = top;
    top = curr;
}

int stack::pop() {
    if(isEmpty()) return -1;

    int data = top->data;
    top = top->next;
    return data;
}

void stack::print() {
    node* curr = top;
    while (curr) {
        printf("%d", curr->data);

        if(curr->next) printf(", ");
        else printf("\n");

        curr = curr->next;
    }
}
