#include<iostream>
using namespace std;

int fib_non(int n)
{
    int a = 0, b = 1, c, i;
    if (n == 0)
        return a;
    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main(){
int n = 9;
    cout<<"with recursive"<<endl;
    cout << n << "th Fibonacci Number: " << fib(n);
    cout<<"without recursive"<<endl;
    cout << n << "th Fibonacci Number: " << fib_non(n);
    return 0;
}




/*
time complexity: 
1. non recursive: O(n)
2. recursive: O(2^n)

space complexity:
1. non recursive: O(1)
2. recursive: O(n)
"""

*/
