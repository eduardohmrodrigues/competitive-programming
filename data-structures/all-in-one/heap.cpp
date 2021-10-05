#include <cstdio>
#include <cstdlib>

class Heap {
public:
    int* items;

    Heap(){
        size = 0;
        capacity = 2;
        // items = (int*)malloc(sizeof(int)*capacity);
        items = new int [capacity];
    }
    ~Heap(){}

    int peek() {
        if (size == 0) {
          printf("No data available to peek\n");
          return -1;
        }
        return items[0];
    }

    int poll() {
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

    void add(int item) {
        ensureExtraCapacity();
        items[size] = item;
        ++size;
        heapifyUp();
    }

    void print() {
        for(int i=0; i<size; ++i){
            printf("%d", items[i]);
            if(i < size-1) printf(", ");
        }
        printf("\n");
    }

private:
    int capacity;
    int size;

    int getLeftChildIndex(int parentIndex) { return parentIndex * 2 + 1; }
    int getRightChildIndex(int parentIndex) { return parentIndex * 2 + 2; }
    int getSmallerChildIndex(int parentIndex) {
        if(!hasLeftChild(parentIndex)) {
            return -1;
        }

        int smallerChildIndex = getLeftChildIndex(parentIndex);
        if (hasRightChild(parentIndex) && rightChild(parentIndex) < leftChild(parentIndex)) {
            smallerChildIndex = getRightChildIndex(parentIndex);
        }

        return smallerChildIndex;
    }
    int getParentIndex(int childrenIndex) { return (childrenIndex-1)/2; }

    bool hasLeftChild(int index) { return getLeftChildIndex(index) < size; }
    bool hasRightChild(int index) { return getRightChildIndex(index) < size; }
    bool hasParent(int index) { return getParentIndex(index) >= 0; }

    int leftChild(int index) { return items[getLeftChildIndex(index)]; }
    int rightChild(int index) { return items[getRightChildIndex(index)]; }
    int parent(int index) { return items[getParentIndex(index)]; }

    void swap(int indexOne, int indexTwo) {
        int temp = items[indexOne];
        items[indexOne] = items[indexTwo];
        items[indexTwo] = temp;
    }

    void ensureExtraCapacity() {
        if(size == capacity) {
            capacity *= 2;
            items = (int*)realloc(items, capacity*sizeof(int));

            if (items == NULL) {
                printf("Error resizing heap. New memory wasn't allocated. Aborting execution.\n");
                exit(0);
            }
        }
    }

    void heapifyDown() {
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

    void heapifyUp() {
        int index = size-1, parentIndex;

        while(hasParent(index) && items[index] < parent(index)){
            parentIndex = getParentIndex(index);
            swap(index, parentIndex);
            index = parentIndex;
        }
    }
};
