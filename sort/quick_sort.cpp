#include <iostream>

void quick_sort(int array[], int first, int last) {
    if (first >= last) {
        return;
    }
    int l = first, r = last;
    int pivot = array[first + (last - first + 1) / 2];
    while (true) {
        while (array[l] < pivot) ++l;
        while (array[r] > pivot) --r;
        if (!(l < r)) break;
        int tmp = array[l];
        array[l] = array[r];
        array[r] = tmp;
        ++l, --r;
    }
    quick_sort(array, first, l - 1);
    quick_sort(array, l, last);
}

int main(int argc, char* argv[]) {
    int array[] = {0, 16, 5, 6, 11, 7, 9, 1, 8, 4, 19, 17, 3, 18, 10, 14, 12, 15, 13, 2};
    int size = sizeof(array) / sizeof(array[0]);
    quick_sort(array, 0, size - 1);
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    return 0;
}