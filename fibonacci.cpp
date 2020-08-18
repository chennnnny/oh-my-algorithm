/*
 * 斐波那契数列
 *   F(0)=0
 *   F(1)=1
 *   F(n)=F(n-1)+F(n-2) (n>=2)
 * author: cheny(dream.cy@foxmail.com)
 */
#include <iostream>
#include <map>

int fibonacci(int n) {
    if (n < 2) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// 动态规划的思想 —— 自上而下
int fibonacci2(int n, std::map<int, int>& lookup) {
    if (n < 2) {
        lookup[n] = n;
    }
    if (lookup.end() == lookup.find(n)) {
        lookup[n] = fibonacci2(n - 1, lookup) + fibonacci2(n - 2, lookup);
    }
    return lookup[n];
}

// 动态规划的思想 —— 自下而上
int fibonacci3(int n, std::map<int, int>& lookup) {
    lookup[0] = 0;
    lookup[1] = 1;
    for (int i = 2; i <= n; ++i) {
        lookup[i] = lookup[i - 1] + lookup[i - 2];
    }
    return lookup[n];
}

void print(int n) {
    std::cout << n << " ";
}

int main(int argc, char* argv[]) {
    for (int n = 0; n <= 10; ++n) {
        print(fibonacci(n));
    }
    std::cout << std::endl;
    std::map<int, int> lookup;
    for (int n = 0; n <= 10; ++n) {
        print(fibonacci2(n, lookup));
    }
    std::cout << std::endl;
    lookup.clear();
    for (int n = 0; n <= 10; ++n) {
        print(fibonacci3(n, lookup));
    }
    return 0;
}