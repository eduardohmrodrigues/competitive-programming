//
// Created by Rodrigues, Eduardo on 04/10/21.
//

#ifndef HEAP_H
#define HEAP_H

class Heap {
public:
    int* items;

    Heap();
    ~Heap();

    int peek();
    int poll();
    void add(int item);
    void print();

private:
    int capacity;
    int size;

    int getLeftChildIndex(int parentIndex);
    int getRightChildIndex(int parentIndex);
    int getSmallerChildIndex(int parentIndex);
    int getParentIndex(int childrenIndex);

    bool hasLeftChild(int index);
    bool hasRightChild(int index);
    bool hasParent(int index);

    int leftChild(int index);
    int rightChild(int index);
    int parent(int index);

    void swap(int indexOne, int indexTwo);
    void ensureExtraCapacity();

    void heapifyUp();
    void heapifyDown();
};

#endif //HEAP_H
