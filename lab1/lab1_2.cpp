// Problem 2:
// Given a positive integer number n, write a program to create an array of the first n prime numbers (sorted in increasing order).

// Examples:
// Input
// 7
// Output
// 2 3 5 7 11 13 17

#include <iostream>
using namespace std;

bool check_prime(int j) {
    for (int i = 2; i < j; i++) {
        if (j % i == 0) {
            return 0;
        }
    }
    return 1;
}

void print_prime(int n) {
    int count = 0;
    int i = 2;
    while (count < 7) {
        if (check_prime(i) == 1) {
            cout << i << " ";
            count++;
        }
        i++;
    }
}

int main()
{
    int n = 0;
    cout << "Enter an possitive number: ";
    cin >> n;
    print_prime(n);
    return 0;
}
