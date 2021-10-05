//
// Created by Rodrigues, Eduardo on 04/10/21.
//

#include <cstdlib>
#include <cstdio>
#include "../headers/heap.h"


// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//        Constructors
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-

heap::heap(){
    size = 0;
    capacity = 2;
//    items = (int*)malloc(sizeof(int)*capacity);
    items = new int [capacity];
}

heap::~heap(){}

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//       Private Methods
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-

int heap::getLeftChildIndex(int parentIndex) { return parentIndex * 2 + 1; }

int heap::getRightChildIndex(int parentIndex) { return parentIndex * 2 + 2; }

int heap::getSmallerChildIndex(int parentIndex) {
    if(!hasLeftChild(parentIndex)) {
        return -1;
    }

    int smallerChildIndex = getLeftChildIndex(parentIndex);
    if (hasRightChild(parentIndex) && rightChild(parentIndex) < leftChild(parentIndex)) {
        smallerChildIndex = getRightChildIndex(parentIndex);
    }

    return smallerChildIndex;
}

int heap::getParentIndex(int childrenIndex) { return (childrenIndex-1)/2; }

bool heap::hasLeftChild(int index) { return getLeftChildIndex(index) < size; }

bool heap::hasRightChild(int index) { return getRightChildIndex(index) < size; }

bool heap::hasParent(int index) { return getParentIndex(index) >= 0; }

int heap::leftChild(int index) { return items[getLeftChildIndex(index)]; }

int heap::rightChild(int index) { return items[getRightChildIndex(index)]; }

int heap::parent(int index) { return items[getParentIndex(index)]; }

void heap::swap(int indexOne, int indexTwo) {
    int temp = items[indexOne];
    items[indexOne] = items[indexTwo];
    items[indexTwo] = temp;
}

void heap::ensureExtraCapacity() {
    if(size == capacity) {
        capacity *= 2;
        items = (int*)realloc(items, capacity*sizeof(int));

        if (items == NULL) {
            printf("Error resizing heap. New memory wasn't allocated. Aborting execution.\n");
            exit(0);
        }
    }
}

void heap::heapifyUp() {
    int index = size-1, parentIndex;

    while(hasParent(index) && items[index] < parent(index)){
        parentIndex = getParentIndex(index);
        swap(index, parentIndex);
        index = parentIndex;
    }
}

void heap::heapifyDown() {
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

int heap::peek() {
    if (size == 0) {
      printf("No data available to peek\n");
      return -1;
    }
    return items[0];
}

int heap::poll() {
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

void heap::add(int item) {
    ensureExtraCapacity();
    items[size] = item;
    ++size;
    heapifyUp();
}

void heap::print() {
    for(int i=0; i<size; ++i){
        printf("%d", items[i]);
        if(i < size-1) printf(", ");
    }
    printf("\n");
}
