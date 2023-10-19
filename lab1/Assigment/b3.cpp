//compute sum of elements in an array
#include<iostream>
using namespace std;

void input(int* &a, int &n) {
    cout << "Enter the size of array: ";
    cin >> n;
    a = new int[n];
    cout << "Enter the array: ";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void compute(int* a, int n) {
    int S = 0;
    for(int i = 0; i < n; i++) {
        S += a[i];
    }
    cout << "The sum of the array is: " << S;
}

int main() {
    int* a = NULL, n;
    input(a,n);
    compute(a,n);
    return 0;
}