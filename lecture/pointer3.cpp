//2D array theo tham chieu
#include<iostream>
using namespace std;

void Input(int** &A, int &n, int &m) {
    cout << "Enter the number of column(s) of the array: ";
    cin >> n;
    cout << "Enter the number of row(s) of the array: ";
    cin >> m;
    cout << "Enter the elements of the array: \n";
    A = new int *[n];
    for (int i = 0; i < n; i++) {
        A[i] = new int [m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
}

void Output(int** A, int n, int m) {
    cout << "The array is: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
    delete [] A;
}

int main() {
    int** A = NULL;
    int n, m;
    Input(A, n, m);
    Output(A, n, m);
    return 0;
}