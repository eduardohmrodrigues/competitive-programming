//
// Created by Rodrigues, Eduardo on 05/10/21.
//

#include <cstdio>
#include "../headers/queue.h"

queue::queue() {
    head = nullptr;
    tail = nullptr;
}

queue::~queue() {
}

bool queue::isEmpty() {
    return head == nullptr;
}

int queue::peek() {
    if(isEmpty()) return -1;

    return head->data;
}

void queue::add(int data) {
    node* node = new node(data);
    if(tail == nullptr) {
        head = tail = node;
        return;
    }

    tail->next = node;
    tail = node;
}

int queue::remove() {
    if(isEmpty()) return -1;

    int data = head->data;
    head = head->next;
    if(isEmpty()) tail = nullptr;

    return data;
}

void queue::print() {
    node* curr = head;
    while(curr != nullptr) {
        printf("%d", curr->data);
        curr = curr->next;
        if(curr != nullptr) printf(", ");
    }

    printf("\n");
}
