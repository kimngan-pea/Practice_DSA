//find the max element of an 2-D array follow:
//1. column
//2. row
//3. compare is the 2-D array symmetic or not
#include<iostream>
using namespace std;

void input(int** &a, int &n) {
    cout << "Enter the size of array: ";
    cin >> n;
    a = new int *[n];
    cout << "Enter the array: \n";
    for(int i = 0; i < n; i++) {
        a[i] = new int [n];
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
}

void compute_column(int** a, int n) {
    cout << "The max element of each column in the array: \n";
    for(int column = 0; column < n; column++) {
        int max = a[column][0];
        for(int row = 1; row < n; row++) {
            if(a[row][column] > max) {
                max = a[row][column];
            }
        }
        cout << max << " ";
    }
    cout << "\n";
}

void compute_row(int** a, int n) {
    cout << "The max elements of each row in the array: \n";
    for(int row = 0; row < n; row++) {
        int max = a[0][row];
        for(int column = 0; column < n; column++) {
            if(a[row][column] > max) {
                max = a[row][column];
            }
        }
        cout << max << " ";
    }
    cout << "\n";
}

void compare(int** a, int n) {
    bool symmetric = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] != a[j][i]) {
                symmetric = false;
            }
        }
    }
    if(symmetric == true) {
        cout << "The array is symmetric.\n";
    } else {
        cout << "The array is not symmetric.\n";
    }
}

int main() {
    int** a = NULL, n;
    input(a,n);
    compute_column(a,n);
    compute_row(a,n);
    compare(a,n);
    return 0;
}