#include <iostream>

void shell_sort(int array[], int size) {
    int gap = size / 2;
    while (gap > 0) {
        for (int i = gap; i < size; ++i) {
            int tmp = array[i];
            int j = i;
            while (j >= gap && tmp < array[j - gap]) {
                array[j] = array[j - gap];
                j -= gap;
            }
            array[j] = tmp;
        }
        gap /= 2;
    }
}

int main(int argc, char* argv[]) {
    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(array) / sizeof(array[0]);
    shell_sort(array, size);
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    return 0;
}