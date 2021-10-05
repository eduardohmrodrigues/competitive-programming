//
// Created by Rodrigues, Eduardo on 04/10/21.
//

#include <cstdlib>
#include <cstdio>
#include "../headers/Heap.h"


// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//        Constructors
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-

Heap::Heap(){
    size = 0;
    capacity = 2;
//    items = (int*)malloc(sizeof(int)*capacity);
    items = new int [capacity];
}

Heap::~Heap(){}

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//       Private Methods
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-

int Heap::getLeftChildIndex(int parentIndex) { return parentIndex * 2 + 1; }

int Heap::getRightChildIndex(int parentIndex) { return parentIndex * 2 + 2; }

int Heap::getSmallerChildIndex(int parentIndex) {
    if(!hasLeftChild(parentIndex)) {
        return -1;
    }

    int smallerChildIndex = getLeftChildIndex(parentIndex);
    if (hasRightChild(parentIndex) && rightChild(parentIndex) < leftChild(parentIndex)) {
        smallerChildIndex = getRightChildIndex(parentIndex);
    }

    return smallerChildIndex;
}

int Heap::getParentIndex(int childrenIndex) { return (childrenIndex-1)/2; }

bool Heap::hasLeftChild(int index) { return getLeftChildIndex(index) < size; }

bool Heap::hasRightChild(int index) { return getRightChildIndex(index) < size; }

bool Heap::hasParent(int index) { return getParentIndex(index) >= 0; }

int Heap::leftChild(int index) { return items[getLeftChildIndex(index)]; }

int Heap::rightChild(int index) { return items[getRightChildIndex(index)]; }

int Heap::parent(int index) { return items[getParentIndex(index)]; }

void Heap::swap(int indexOne, int indexTwo) {
    int temp = items[indexOne];
    items[indexOne] = items[indexTwo];
    items[indexTwo] = temp;
}

void Heap::ensureExtraCapacity() {
    if(size == capacity) {
        capacity *= 2;
        items = (int*)realloc(items, capacity*sizeof(int));

        if (items == NULL) {
            printf("Error resizing heap. New memory wasn't allocated. Aborting execution.\n");
            exit(0);
        }
    }
}

void Heap::heapifyUp() {
    int index = size-1, parentIndex;

    while(hasParent(index) && items[index] < parent(index)){
        parentIndex = getParentIndex(index);
        swap(index, parentIndex);
        index = parentIndex;
    }
}

void Heap::heapifyDown() {
    int index = 0, smallerChildIndex;

    while (hasLeftChild(index)) {
        smallerChildIndex = getSmallerChildIndex(index);
        if(items[index] < items[smallerChildIndex]) {
            break;
        }

        swap(index, smallerChildIndex);
        index = smallerChildIndex;
    }
}

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//       Public Methods
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-

int Heap::peek() {
    if (size == 0) {
      printf("No data available to peek\n");
      return -1;
    }
    return items[0];
}

int Heap::poll() {
    if (size == 0) {
        printf("No data available to poll\n");
        return -1;
    }

    int item = items[0];
    items[0] = items[size-1];
    --size;
    heapifyDown();
    return item;
}

void Heap::add(int item) {
    ensureExtraCapacity();
    items[size] = item;
    ++size;
    heapifyUp();
}

void Heap::print() {
    for(int i=0; i<size; ++i){
        printf("%d", items[i]);
        if(i < size-1) printf(", ");
    }
    printf("\n");
}
