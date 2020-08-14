#include <iostream>

void bubble_sort(int array[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        bool exchange = false;
        for (int j = 0; j < size - 1 - i; ++j) {
            if (array[j] > array[j + 1] ) {
                int tmp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = tmp;
                exchange = true;
            }
        }
        if (false == exchange) {
            break;
        }
    }
}

int main(int argc, char* argv[]) {
    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(array) / sizeof(array[0]);
    bubble_sort(array, size);
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    return 0;
}