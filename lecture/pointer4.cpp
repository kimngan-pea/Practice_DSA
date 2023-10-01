//enter information of nth student include: ID, name, GPA
#include<iostream>
using namespace std;

struct Student {
    char ID[20];
    char Name[50];
    float GPA;
};

void Input_1_Std(Student &S) {
    cin.ignore();
    cout << "ID: ";
    gets(S.ID);
    cout << "Name: ";
    gets(S.Name);
    float temp;
    cout << "GPA: ";
    cin >> temp;
    S.GPA = temp;
}

void Input(Student* &S, int x) {
    S = new Student [x];
    for(int i = 0; i < x; i++) {
        cout << "Enter the information of " << i + 1 << "(th) student: \n";
        Input_1_Std(S[i]);
    }
}

void Output_1_Std(Student S) {
    cout << S.ID << "\t" 
    << S.Name << "\t" 
    << S.GPA << "\n";
}

void Output(Student* S, int x) {
    for(int i = 0; i < x; i++) {
        Output_1_Std(S[i]);
    }
}

int main() {
    int x;
    cout << "Enter the number of student: ";
    cin >> x;
    Student *A = NULL;
    Input(A, x);
    Output(A, x);
    return 0;
}