#include <iostream>

void insertion_sort(int array[], int size) {
    for (int i = 1; i < size; ++i) {
        int tmp = array[i];
        if (tmp < array[0]) {
            for (int n = i; n > 0; --n) {
                array[n] = array[n - 1];
            }
            array[0] = tmp;
        }
        else {
            int n = i;
            while (tmp < array[n - 1]) {
                array[n] = array[n - 1];
                --n;
            }
            array[n] = tmp;
        }
    }
}

void insertion_sort2(int array[], int size) {
    for (int i = 1; i < size; ++i) {
        int tmp = array[i];
        int j = i;
        while (j > 0 && tmp < array[j - 1]) {
            array[j] = array[j - 1];
            --j;
        }
        array[j] = tmp;
    }
}

int main(int argc, char* argv[]) {
    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(array) / sizeof(array[0]);
    insertion_sort(array, size);
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    return 0;
}