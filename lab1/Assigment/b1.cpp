//swap pointer
#include<iostream>
using namespace std;

void Swap(int* &a, int* &b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main() {
    int *a = NULL, *b = NULL;
    int x, y;
    a = &x;
    b = &y;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
    Swap(a,b);
    cout << "a = " << *a << ", b = " << *b << "\n";
    return 0;
}