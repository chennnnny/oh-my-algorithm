/*
 * 费波那契数列
 *   F(1)=1
 *   F(2)=1
 *   F(n)=F(n-1)+F(n-2) (n>=3，n∈N*)
 * author: cheny(dream.cy@foxmail.com)
 */
#include <iostream>

int fibonacci(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void print(int n) {
    std::cout << n << " ";
}

int main(int argc, char* argv[]) {
    for (int n = 1; n <= 10; ++n) {
        print(fibonacci(n));
    }
    std::cout << std::endl;
    return 0;
}