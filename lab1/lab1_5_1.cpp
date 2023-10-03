//in form of array:

// Định nghĩa (khai báo) kiểu dữ liệu cấu trúc để quản lý sinh viên gồm các thành phần là Mã số Sinh viên (kiểu chuỗi), 
// Họ và Tên (kiểu chuỗi), Năm sinh (kiểu chuỗi), Giới tính (kiểu ký tự), 
// Điểm toán (kiểu số thực), Điểm lý (kiểu số thực), Điểm hóa (kiểu số thực), Điểm Trung bình (kiểu số thực). 
// Viết Chương trình nhập và xuất thông tin của danh sách gồm n (0 < n ≤ 100) sinh viên.
// Lưu ý Điểm trung bình được tính bằng công thức: (Điểm toán+Điểm lý+Điểm hóa)/3.

// INPUT
// Dãy các ký tự và số trong đó: (Giả sử luôn thỏa điều kiện nhập)

// Dòng đầu tiên: Số lượng n phần tử trong danh sách.
// (n*7) dòng liên tiếp tiếp theo: Trong đó cứ mỗi 7 dòng thể hiện 7 thông tin của một sinh viên trong mảng:
// Dòng thứ 1: Chuỗi Mã số sinh viên
// Dòng thứ 2: Chuỗi Họ tên sinh viên
// Dòng thứ 3: Chuỗi Ngày tháng năm sinh (Nhập chuỗi có dạng sau: dd/mm/yyyy, ví dụ: "01/01/2018")
// Dòng thứ 4: Ký tự thể hiện giới tính: M (Nam) hoặc F (Nữ)
// Dòng thứ 5: Số thực lưu Điểm toán
// Dòng thứ 6: Số thực lưu Điểm lý
// Dòng thứ 7: Số thực lưu Điểm hóa

// OUTPUT
// Hiển thị n sinh viên trong mảng trên n dòng liên tiếp. Mỗi dòng hiển thị 8 thông tin theo thứ tự sau:
// Mã số Sinh viên, Họ và Tên, Năm sinh, Giới tính, Điểm toán, Điểm lý, Điểm hóa, Điểm Trung bình.
// Mỗi thông tin cách nhau một dấu tab.
// Điểm trung bình hiển thị nhiều nhất hai số lẻ sau dấu thập phân (nếu có). Gợi ý dùng precision.

// EXAMPLE
// Input	
// 3
// 07520045
// Nguyen Thi Lan
// 27/05/1989
// F
// 10
// 9
// 8
// 07520504
// Luong Thanh
// 31/07/1989
// M
// 10
// 9.5
// 10
// 07520111
// Nguyen Anh Hong
// 07/12/1991
// F
// 7
// 7.5
// 8
// Output
// 07520045	Nguyen Thi Lan	27/05/1989	F	10	9	8	9
// 07520504	Luong Thanh	31/07/1989	M	10	9.5	10	9.83
// 07520111	Nguyen Anh Hong	07/12/1991	F	7	7.5	8


#include<iostream>
#include<iomanip>
using namespace std;

struct Student {
	char ID[50];
	char Name[100];
	char DOB[50];
	char gender;
	float math;
	float physic;
	float chemistry;
	float average;

	void Input() {
		cin.ignore();
		cout << "ID: ";
		cin.getline(ID, 50);
		cout << "Name: ";
		cin.getline(Name, 100);
		cout << "DOB (dd/mm/yyyy): ";
		cin.getline(DOB, 50);
		cout << "Gender (M/F): ";
		cin >> gender;
		cout << "Math score: ";
		cin >> math;
		cout << "Physic score: ";
		cin >> physic;
		cout << "Chemistry score: ";
		cin >> chemistry;
	}

	void Output() {
		average = (float)(math + physic + chemistry) / 3.0;
		cout << ID << "\t"
			<< Name << "\t"
			<< DOB << "\t"
			<< gender << "\t"
			<< math << "\t"
			<< physic << "\t"
			<< chemistry << "\t"
			<< setprecision(3) << average << "\n";
	}
};

void Input(Student* &S, int x) {
	for(int i = 0; i < x; i++) {
		cout << "Enter the " << i + 1 << "(th) student information: \n";
        S[i].Input();
    }
}

void Output(Student* S, int x) {
    for(int i = 0; i < x; i++) {
        S[i].Output();
    }
}

int main() {
	int x;
	cout << "Enter the number of student: ";
	cin >> x;
    Student *Std = NULL;
    Std = new Student[x];
	Input(Std, x);
	Output(Std,x);
	return 0;
}
