//gia phong bo nho theo tham chieu
#include <iostream>
using namespace std;

void inputNumber(int*& p, int &n) {
	p = &n;
	cout << "Enter number: ";
	cin >> n;
}

void outputNumber(int* p, int n) {
	cout << "After change: " << n << " " << &n << " "
		<< p << " " << *p << "\n";
	delete p;
}

void inputArray(int*& a, int& n) {
	cout << "Enter the number of array: ";
	cin >> n;
	a = new int[n];
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
	cout << "The original number: " << n << " " << p << "\n";
	inputNumber(p, n);
	outputNumber(p, n);

	//array
	int n1 = 0;
	int* a = NULL;
	inputArray(a, n1);
	outputArray(a, n1);
	return 0;
}
