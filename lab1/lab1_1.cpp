// Problem 1:
// Write a program to check whether an integer is a prime or not. 
// If the input number is prime then print out "1". Otherwise print out "0".

// Examples:
// IN
// 7
// OUT
// 1
// IN 
// 8
// OUT 
// 0

#include <iostream>
using namespace std;

bool check_prime(int *p) {
    int n = *p;
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i * i < n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n = 0;
    cout << "Enter an integer: ";
    cin >> n;
    int* p = new int;
    p = &n;
    if (check_prime(p) == 1) {
        cout << "1";
    }
    else {
        cout << "0";
    }
    delete p;
    return 0;
}


