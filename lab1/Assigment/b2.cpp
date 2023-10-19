//find max in an pointer array
#include<iostream>
using namespace std;

void input(int* &a, int &n) {
    cout << "Enter the size of array: ";
    cin >> n;
    a = new int [n];
    cout << "Enter the array: ";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void Max(int* a, int n) {
    int max = a[0];
    for(int i = 0; i < n; i++) {
        if(a[i] > max) {
            max = a[i];
        }
    }
    cout << "The max element in the array is: " << max;
}

int main() {
    int *a = NULL, n;
    input(a, n);
    Max(a, n);
    return 0;
}