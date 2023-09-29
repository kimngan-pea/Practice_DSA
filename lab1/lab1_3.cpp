// Problem 3:
// Create an array A of the first n prime numbers as in P1.02. Given a positive integer y, find the number of elements of A that contains y.

// Input Format:
// Input will contain two integers y and n, separated by a newline.
// Constraint:
// 0 <= y <= 9

// Output Format:
// the number of elements of A that contains y.

// Examples:
// Input
// 1
// 7
// Output
// 3

#include <iostream>
using namespace std;

bool check_prime(int j) {
    if (j < 2) {
        return 0;
    }
    for (int i = 2; i < j; i++) {
        if (j % i == 0) {
            return 0;
        }
    }
    return 1;
}

void print_prime(int n, int* A) {
    int count = 0;
    int i = 2;
    int j = 0;
    while (count < 7) {
        if (check_prime(i) == 1) {
            A[j] = i;
            j++;
            count++;
        }
        i++;
    }
}

int main()
{
    int n = 0, y = 0;
    cout << "Enter the number which is the number of elements of A: ";
    cin >> y;
    cout << "Enter an possitive integer (length of A): ";
    cin >> n;
    int* A = new int[n];
    print_prime(n, A);
    cout << "The number of elements of A is: " << A[y] << "\n";
    delete A;
    return 0;
}

