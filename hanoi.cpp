/*
 * 汉诺塔
 * 
 * author: cheny(dream.cy@foxmail.com)
 */
#include <iostream>

void move(int disk, char m, char n) {
    std::cout << "Num " << disk << " disk: " << m << " -> " << n << std::endl;
}

void hanoi(int n, char x, char y, char z) {
    if (n == 1) {
        move(n, x, z);
    }
    else {
        hanoi(n - 1, x, z, y);
        move(n, x, z);
        hanoi(n - 1, y, x, z);
    }
}

int main(int argc, char* argv[]) {
    hanoi(3, 'X', 'Y', 'Z');
    return 0;
}