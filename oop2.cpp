#include<iostream>
#include<string>
using namespace std;

class StudentData; 

class Student {
    string name;
    int roll_no;
    string cls;
    string division;  // Changed to string
    string dob;
    string bloodgroup;  // Changed to string
    static int count;

public:
    Student();  // Default Constructor
    ~Student();
    static int getCount();
    void getData(StudentData*); 
    void displayData(StudentData*);
};

class StudentData {
    string caddress;
    long int telno;
    long int dlno;
    
    friend class Student;

public:
    StudentData();
    ~StudentData();
    void getStudentData();
    void displayStudentData();
};

Student::Student() {  // Default Constructor
    name = ""; 
    roll_no = 0; 
    cls = ""; 
    division = "";
    dob = "dd/mm/yyyy"; 
    bloodgroup = "";
}

Student::~Student() {}

int Student::count = 0;

int Student::getCount() {
    return count;
}

void Student::getData(StudentData* st) {
    cout << "Enter Student Name: "; 
    getline(cin, name);
    cout << "Enter Roll Number: "; 
    cin >> roll_no;
    cin.get();  // To consume the newline after reading integer
    cout << "Enter Class: "; 
    getline(cin, cls);
    cout << "Enter Division: "; 
    getline(cin, division);  // Now division is a string
    cout << "Enter Date of Birth: "; 
    getline(cin, dob);
    cout << "Enter Blood Group: "; 
    getline(cin, bloodgroup);  // Now bloodgroup is a string
    st->getStudentData();
    count++;
}

void Student::displayData(StudentData* st1) {
    cout << "Student Name: " << name << endl;
    cout << "Roll Number: " << roll_no << endl;
    cout << "Class: " << cls << endl;
    cout << "Division: " << division << endl;
    cout << "Date of Birth: " << dob << endl;
    cout << "Blood Group: " << bloodgroup << endl;
    st1->displayStudentData();
}

StudentData::StudentData() {
    caddress = "";
    telno = 0;
    dlno = 0;
}

StudentData::~StudentData() {}

void StudentData::getStudentData() {
    cout << "Enter Contact Address: "; 
    cin.get();  // To consume the newline from previous input
    getline(cin, caddress);
    cout << "Enter Telephone Number: "; 
    cin >> telno;
    cout << "Enter Driving License Number: "; 
    cin >> dlno;
}

void StudentData::displayStudentData() {
    cout << "Contact Address: " << caddress << endl;
    cout << "Telephone Number: " << telno << endl;
    cout << "Driving License Number: " << dlno << endl;
}

int main() {
    Student* stud1[100]; 
    StudentData* stud2[100]; 
    int n = 0;
    char ch;

    do {
        stud1[n] = new Student; 
        stud2[n] = new StudentData;
        stud1[n]->getData(stud2[n]); 
        n++;
        cout << "Do you want to add another student (y/n): "; 
        cin >> ch;
        cin.get();  // To consume the newline
    } while (ch == 'y' || ch == 'Y');

    for (int i = 0; i < n; i++) {
        cout << endl;
        stud1[i]->displayData(stud2[i]);
    }

    cout << endl;
    cout << "Total Students: " << Student::getCount() << endl;
    cout << endl;

    for (int i = 0; i < n; i++) {
        delete stud1[i]; 
        delete stud2[i];
    }

    return 0;
}
