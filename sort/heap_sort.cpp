#include <iostream>

void __adjust_heap(int array[], int hole, int len) {
    int tmp = array[hole];
    int second = 2 * hole + 2;
    while (second < len) {
        if (array[second] < array[second - 1]) {
            --second;
        }
        if (!(tmp < array[second])) {
            break;
        }
        array[hole] = array[second];
        hole = second;
        second = 2 * second + 2;
    }
    if (second == len && tmp < array[--second]) {
        array[hole] = array[second];
        hole = second;
    }
    array[hole] = tmp;
}
void __make_heap(int array[], int size) {
    int hole = (size - 2) / 2;
    while (true) {
        __adjust_heap(array, hole, size);
        if (hole == 0) break;
        --hole;
    }
}
void heap_sort(int array[], int size) {
    __make_heap(array, size);
    for (int i = size - 1; i >= 1; --i) {
        int tmp = array[0];
        array[0] = array[i];
        array[i] = tmp;
        __adjust_heap(array, 0, i);
    }
}

int main(int argc, char* argv[]) {
    int array[] = {6, 8, 7, 9, 0, 1, 3, 2, 4, 5};
    int size = sizeof(array) / sizeof(array[0]);
    heap_sort(array, size);
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    return 0;
}