#include <iostream>

void quick_sort(int array[], int first, int last) {
    if (first >= last) {
        return;
    }
    int l = first, r = last;
    int pivot = array[first + (last - first) / 2];
    while (true) {
        while (array[l] < pivot) ++l;
        while (array[r] > pivot) --r;
        if (l >= r) break;
        int tmp = array[l];
        array[l] = array[r];
        array[r] = tmp;
        ++l, --r;
    }
    quick_sort(array, first, l - 1);
    quick_sort(array, l + 1, last);
}

int main(int argc, char* argv[]) {
    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(array) / sizeof(array[0]);
    quick_sort(array, 0, size - 1);
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    return 0;
}