/*
 * 阶乘
 *   n! = 1 x 2 x 3 x ... x (n-1) x n
 * 
 * author: cheny(dream.cy@foxmail.com)
 */
#include <iostream>

unsigned int factorial(unsigned int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return factorial(n - 1) * n;
}

int main(int argc, char* argv[]) {
    std::cout << factorial(5) << std::endl;
    return 0;
}