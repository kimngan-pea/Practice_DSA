//gia phong bo nho theo tham tri
#include <iostream>
using namespace std;

void inputArray(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
 }

void outputArray(int* a, int n) {
	cout << "The array is: ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
	delete[] a;
}

int main() {
	//number
	int n = 10;
	int* p = new int;
    p = &n;
	cout << "The original number: " << n << " " << p << "\n";
	cout << "After change: " << n << " " << &n << " "
		<< p << " " << *p << "\n";
	delete p;

	//array
	int n1 = 0;
	int* a = NULL;
    a = new int[n1];
    cout << "Enter the number of array: ";
	cin >> n1;
	inputArray(a, n1);
	outputArray(a, n1);
	return 0;
}
