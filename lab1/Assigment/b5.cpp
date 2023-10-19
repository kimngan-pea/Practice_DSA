//find the average, max, min of an array follow:
//1. column
//2. row
//standardized the array
#include<iostream>
#include<iomanip>
using namespace std;

void input(int** &a, int &n) {
    cout << "Enter the size of array: ";
    cin >> n;
    a = new int*[n];
    cout << "Enter the array: \n";
    for(int i = 0; i < n; i++) {
        a[i] = new int [n];
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
}

void compute_column(int** a, int n) {
    for(int column = 0; column < n; column++) {
        int average = 0, min = a[column][0], max = a[column][0];
        for(int row = 0; row < n; row++) {
            average += a[row][column];
            if(a[row][column] > max) {
                max = a[row][column];
            }
            if(a[row][column] < min) {
                min = a[row][column];
            }
        }
        cout << "The " << column + 1 << "(th) column has: " 
        << "Average: " << setprecision(3) << average << "\t" 
        << "Min: " << min << "\t"
        << "Max: " << max << "\n";
    }
}

void compute_row(int** a, int n) {
    for(int row = 0; row < n; row++) {
        int average = 0, min = a[row][0], max = a[row][0];
        for(int column = 0; column < n; column++) {
            average += a[row][column];
            if(a[row][column] > max) {
                max = a[row][column];
            }
            if(a[row][column] < min) {
                min = a[row][column];
            }
        }
        cout << "The " << row + 1 << "(th) row has: " 
        << "Average: " << setprecision(3) << average << "\t" 
        << "Min: " << min << "\t"
        << "Max: " << max << "\n";
    }
}

void standardized_column(int** a, int n) {
    cout << "The standardized elements in each column in array is: \n";
    for(int column = 0; column < n; column++) {
        int average = 0, min = a[column][0], max = a[column][0];
        for(int row = 0; row < n; row++) {
            average += a[row][column];
            if(a[row][column] > max) {
                max = a[row][column];
            }
            if(a[row][column] < min) {
                min = a[row][column];
            }
        }
        average = average / n;
        float new_value = 0;
        for(int row = 0; row < n; row++) {
            new_value = (float) (a[row][column] - average) / (max - min);
            cout << new_value << "\t";
        }
        cout << "\n";
    }
}

void standardized_row(int** a, int n) {
    cout << "The standardized elements in each column in array is: \n";
    for(int row = 0; row < n; row++) {
        int average = 0, min = a[row][0], max = a[row][0];
        for(int column = 0; column < n; column++) {
            average += a[row][column];
            if(a[row][column] > max) {
                max = a[row][column];
            }
            if(a[row][column] < min) {
                min = a[row][column];
            }
        }
        average = average / n;
        float new_value = 0;
        for(int column = 0; column < n; column++) {
            new_value = (float) (a[row][column] - average) / (max - min);
            cout << new_value << "\t";
        }
        cout << "\n";
    }
}

int main() {
    int** a = NULL, n;
    input(a,n);
    compute_column(a,n);
    cout << "\n";
    compute_row(a,n);
    cout << "\n";
    standardized_column(a,n);
    cout << "\n";
    standardized_row(a,n);
    return 0;
}
