#include <fstream>
#include <iostream>
#include <string>
using namespace std;

//user class
class user
{
public:
	//char userType;
	//void selectUserType();
	virtual void printHeading() = 0;
};

/*
void user::selectUserType()
{
	if (userType == 'S')
	{
		cout << "Login as a Student" << endl;

	}
	else
	{
		cout << "Login as a teacher" << endl;
	}
}
*/

//student class
class student :public user
{
private:
	string fName, lName, DOB, subject;
	char studentClass;
	int grade, indexNo;
	int studentChoice;

public:
	void printHeading() { cout << "\nLogin as a Student" << endl; }
	void menuStudent();
	void insertStudent(); //enter student details
	void viewStudentList(); //view student details
	void seeTimeTable(); //view time table
	void seeExamResults();
	void seeBehaviouralReport();
	void seePerformanceReport();
};

void student::menuStudent()
{
	cout << "\n-----STUDENT----" << endl;
	cout << "\n*****MENU****" << endl;

	cout << "\n 1) Enter new record " << endl;
	cout << "\n 2) View student list " << endl;
	cout << "\n 3) See time table " << endl;
	cout << "\n 4) See exam results " << endl;
	cout << "\n 5) See performance report " << endl;
	cout << "\n 6) See behavioural report " << endl;

	cout << "\nChoice :";
	cin >> studentChoice;

	switch (studentChoice)
	{
	case 1:
		insertStudent(); break;
	case 2:
		viewStudentList(); break;
	case 3:
		seeTimeTable(); break;
	}
}

//insertStudents function
void student::insertStudent()
{
	system("cls");
	//define file oject with appropriate stream
	ofstream insertStudentRecordFile("studentRecordFile.txt", ofstream::app);

	cout << "Index Number :";
	cin >> indexNo;

	cout << "First Name :";
	cin >> fName;

	cout << "Last Name :";
	cin >> lName;

	cout << "Grade :";
	cin >> grade;

	cout << "DOB :";
	cin >> DOB;

	insertStudentRecordFile <<"\nIndex Number = " <<indexNo<< "\nFirst Name = " << fName << "\nLast Name = " << lName << "\nGrade = " << grade << "\nDate of Birth = " << DOB << endl;
	insertStudentRecordFile.close();
}

//view student details function
void student::viewStudentList()
{
	cout << "STUDENT INFORMATION" << endl;
	const int max_Size = 1000;

	//variables
	char buffer[max_Size];

	ifstream viewStudentRecordFile("studentRecordFile.txt");

	while (!viewStudentRecordFile.eof())
	{
		viewStudentRecordFile.getline(buffer, max_Size);
		cout << buffer << endl;
	}
}

void student::seeTimeTable()
{
	cout << "\nTime table" << endl;

	cout << "Your grade : ";
	cin >> grade;

	cout << "Your class : ";
	cin >> studentClass;

	cout << "Time Table " << grade << " - " << studentClass << endl;

	const int max = 1000;

	//variables
	char buffer[max];

	ifstream view12AtimeTable("TimeTable12A.txt");
	ifstream view12BtimeTable("TimeTable12B.txt");
	ifstream view13AtimeTable("TimeTable13A.txt");
	ifstream view13BtimeTable("TimeTable13B.txt");

	if (grade == 12)
	{
		if (studentClass == 'A')
		{
			while (!view12AtimeTable.eof())
			{
				view12AtimeTable.getline(buffer, max);
				cout << buffer << endl;
			}
		}
		else
		{
			while (!view12BtimeTable.eof())
			{
				view12BtimeTable.getline(buffer, max);
				cout << buffer << endl;
			}
		}
	}
	else
	{
		if (studentClass == 'A')
		{
			while (!view13AtimeTable.eof())
			{
				view13AtimeTable.getline(buffer, max);
				cout << buffer << endl;
			}
		}
		else
		{
			while (!view13BtimeTable.eof())
			{
				view13BtimeTable.getline(buffer, max);
				cout << buffer << endl;
			}
		}
	}
}

//TEACHER CLASS
class teacher :public user
{
private:
	int grade;
	string fName, lName, subject;  //variables for insertTeacher() and viewTeacherList() functions
	char selectSubject;  //teacher should select his subject to insert mark sheet
	char teachingClass;
	string MondayMorning, MondayEvening;
	string TuesdayMorning, TuesdayEvening;
	string WednesdayMorning, WednesdayEvening;
	string ThursdayMorning, ThursdayEvening;
	string FridayMorning, FridayEvening;
	float student1, student2, student3, student4, student5, student6, student7, student8, student9, student10;
	int teacherChoice;

public:
	void printHeading() { cout << "\nLogin as a Teacher" << endl; }
	void menuTeacher();
	void insertTeacher(); //enter teacher details
	void viewTeacherList(); //view teacher details
	void updateTimeTable();
	void updateExamResults();
};

void teacher::menuTeacher()
{
	cout << "\n-----TEACHER----" << endl;
	cout << "\n*****MENU****" << endl;

	cout << "\n 1) Enter teacher details " << endl;
	cout << "\n 2) View teacher details list " << endl;
	cout << "\n 3) update time table " << endl;
	cout << "\n 4) update exam results " << endl;

	cout << "\nChoice :";
	cin >> teacherChoice;

	switch (teacherChoice)
	{
	//case 1:
		//insertTeacher(); break;
	//case 2:
		//viewTeacherList(); break;
	case 3:
		updateTimeTable(); break;
	case 4:
		updateExamResults(); break;
	}
}

//updating time table
void teacher::updateTimeTable()
{
	system("cls");
	//define file oject with appropriate stream
	ofstream insert12ATimeTable("TimeTable12A.txt", ofstream::app);
	ofstream insert12BTimeTable("TimeTable12B.txt", ofstream::app);
	ofstream insert13ATimeTable("TimeTable13A.txt", ofstream::app);
	ofstream insert13BTimeTable("TimeTable13B.txt", ofstream::app);

	cout << "Grade : ";
	cin >> grade;

	cout << "Class : ";
	cin >> teachingClass;

	//Monday
	cout << "Monday Morning : ";
	cin >> MondayMorning;
	cout << "Monday Evening : ";
	cin >> MondayEvening;

	//Tuesday
	cout << "Tuesday Morning : ";
	cin >> TuesdayMorning;
	cout << "Tuesday Evening : ";
	cin >> TuesdayEvening;

	//wednesday
	cout << "Wednesday Morning : ";
	cin >> WednesdayMorning;
	cout << "Wednesday Evening : ";
	cin >> WednesdayEvening;

	//Thursday
	cout << "Thursday Morning : ";
	cin >> ThursdayMorning;
	cout << "Thursday Evening : ";
	cin >> ThursdayEvening;

	//Friday
	cout << "Friday Morning : ";
	cin >> FridayMorning;
	cout << "Friday Evening : ";
	cin >> FridayEvening;

	if (grade == 12)
	{
		if (teachingClass == 'A')
		{
			insert12ATimeTable << "Morning ---> " << MondayMorning << "\t" << TuesdayMorning << "\t" << WednesdayMorning << "\t" << ThursdayMorning << "\t" << FridayMorning << endl;
			insert12ATimeTable << "Evening ---> " << MondayEvening << "\t" << TuesdayEvening << "\t" << WednesdayEvening << "\t" << ThursdayEvening << "\t" << FridayEvening << endl;
			insert12ATimeTable.close();
		}
		else
		{
			insert12BTimeTable << "Morning ---> " << MondayMorning << "\t" << TuesdayMorning << "\t" << WednesdayMorning << "\t" << ThursdayMorning << "\t" << FridayMorning << endl;
			insert12BTimeTable << "Evening ---> " << MondayEvening << "\t" << TuesdayEvening << "\t" << WednesdayEvening << "\t" << ThursdayEvening << "\t" << FridayEvening << endl;
			insert12BTimeTable.close();
		}
	}
	else
	{
		if (teachingClass == 'A')
		{
			insert13ATimeTable << "Morning ---> " << MondayMorning << "\t" << TuesdayMorning << "\t" << WednesdayMorning << "\t" << ThursdayMorning << "\t" << FridayMorning << endl;
			insert13ATimeTable << "Evening ---> " << MondayEvening << "\t" << TuesdayEvening << "\t" << WednesdayEvening << "\t" << ThursdayEvening << "\t" << FridayEvening << endl;
			insert13ATimeTable.close();
		}
		else
		{
			insert13BTimeTable << "Morning ---> " << MondayMorning << "\t" << TuesdayMorning << "\t" << WednesdayMorning << "\t" << ThursdayMorning << "\t" << FridayMorning << endl;
			insert13BTimeTable << "Evening ---> " << MondayEvening << "\t" << TuesdayEvening << "\t" << WednesdayEvening << "\t" << ThursdayEvening << "\t" << FridayEvening << endl;
			insert13BTimeTable.close();
		}
	}
}

void teacher::updateExamResults()
{
	system("cls");
	//define file oject with appropriate stream
	ofstream insert12A_Maths("12A_MathsMarks.txt", ofstream::app);
	ofstream insert12A_Physics("12A_PhysicsMarks.txt", ofstream::app);
	ofstream insert12A_Chemistry("12A_ChemistryMarks.txt", ofstream::app);

	ofstream insert12B_Maths("12B_MathsMarks.txt", ofstream::app);
	ofstream insert12B_Physics("12B_PhysicsMarks.txt", ofstream::app);
	ofstream insert12B_Chemistry("12B_ChemistryMarks.txt", ofstream::app);

	ofstream insert13A_Maths("13A_MathsMarks.txt", ofstream::app);
	ofstream insert13A_Physics("13A_PhysicsMarks.txt", ofstream::app);
	ofstream insert13A_Chemistry("13A_ChemistryMarks.txt", ofstream::app);

	ofstream insert13B_Maths("13B_MathsMarks.txt", ofstream::app);
	ofstream insert13B_Physics("13B_PhysicsMarks.txt", ofstream::app);
	ofstream insert13B_Chemistry("13B_ChemistryMarks.txt", ofstream::app);

	cout << "\n\n------Insert Student Exam Results------" << endl;

	cout << "\n#####SUBJECT LIST####" << endl;
	cout << "\nMaths\t\t(M)" << endl;
	cout << "Physics\t\t(P)" << endl;
	cout << "Chemistry\t(C)" << endl;

	cout << "Select your subject : ";
	cin >> selectSubject;

	cout << "Grade : ";
	cin >> grade;

	cout << "class : ";
	cin >> teachingClass;

	cout << "\nEnter student marks" << endl;

	cout << "Register No 1 : ";
	cin >> student1;

	cout << "Register No 2 : ";
	cin >> student2;

	cout << "Register No 3 : ";
	cin >> student3;

	cout << "Register No 4 : ";
	cin >> student4;

	cout << "Register No 5 : ";
	cin >> student5;

	cout << "Register No 6 : ";
	cin >> student6;

	cout << "Register No 7 : ";
	cin >> student7;

	cout << "Register No 8 : ";
	cin >> student8;

	cout << "Register No 9 : ";
	cin >> student9;

	cout << "Register No 10 : ";
	cin >> student10;

	if (grade == 12)   //for grade 12 
	{
		if (teachingClass == 'A')  //for 12A class
		{
			if (selectSubject == 'M')
			{
				insert12A_Maths << "\nNo 1  =" << student1 << "\nNo 2  =" << student2 << "\nNo 3  =" << student3 << "\nNo 4  =" << student4 << "\nNo 5  =" << student5 << "\nNo 6  =" << student6 << "\nNo 7  =" << student7 << "\nNo 8  =" << student8 << "\nNo 9  =" << student9 << "\nNo 10  =" << student10 << endl;
				insert12A_Maths.close();
			}
			else if (selectSubject == 'P')
			{
				insert12A_Physics << "\nNo 1  =" << student1 << "\nNo 2  =" << student2 << "\nNo 3  =" << student3 << "\nNo 4  =" << student4 << "\nNo 5  =" << student5 << "\nNo 6  =" << student6 << "\nNo 7  =" << student7 << "\nNo 8  =" << student8 << "\nNo 9  =" << student9 << "\nNo 10  =" << student10 << endl;
				insert12A_Physics.close();
			}
			else
			{
				insert12A_Chemistry << "\nNo 1  =" << student1 << "\nNo 2  =" << student2 << "\nNo 3  =" << student3 << "\nNo 4  =" << student4 << "\nNo 5  =" << student5 << "\nNo 6  =" << student6 << "\nNo 7  =" << student7 << "\nNo 8  =" << student8 << "\nNo 9  =" << student9 << "\nNo 10  =" << student10 << endl;
				insert12A_Chemistry.close();
			}
		}
		else  //for 12B class
		{
			if (selectSubject == 'M')
			{
				insert12B_Maths << "\nNo 1  =" << student1 << "\nNo 2  =" << student2 << "\nNo 3  =" << student3 << "\nNo 4  =" << student4 << "\nNo 5  =" << student5 << "\nNo 6  =" << student6 << "\nNo 7  =" << student7 << "\nNo 8  =" << student8 << "\nNo 9  =" << student9 << "\nNo 10  =" << student10 << endl;
				insert12B_Maths.close();
			}
			else if (selectSubject == 'P')
			{
				insert12B_Physics << "\nNo 1  =" << student1 << "\nNo 2  =" << student2 << "\nNo 3  =" << student3 << "\nNo 4  =" << student4 << "\nNo 5  =" << student5 << "\nNo 6  =" << student6 << "\nNo 7  =" << student7 << "\nNo 8  =" << student8 << "\nNo 9  =" << student9 << "\nNo 10  =" << student10 << endl;
				insert12B_Physics.close();
			}
			else
			{
				insert12B_Chemistry << "\nNo 1  =" << student1 << "\nNo 2  =" << student2 << "\nNo 3  =" << student3 << "\nNo 4  =" << student4 << "\nNo 5  =" << student5 << "\nNo 6  =" << student6 << "\nNo 7  =" << student7 << "\nNo 8  =" << student8 << "\nNo 9  =" << student9 << "\nNo 10  =" << student10 << endl;
				insert12B_Chemistry.close();
			}

		}
	}
	else   //for grade 13
	{
		if (teachingClass == 'A')  //for 13A class
		{
			if (selectSubject == 'M')
			{
				insert13A_Maths << "\nNo 1  =" << student1 << "\nNo 2  =" << student2 << "\nNo 3  =" << student3 << "\nNo 4  =" << student4 << "\nNo 5  =" << student5 << "\nNo 6  =" << student6 << "\nNo 7  =" << student7 << "\nNo 8  =" << student8 << "\nNo 9  =" << student9 << "\nNo 10  =" << student10 << endl;
				insert13A_Maths.close();
			}
			else if (selectSubject == 'P')
			{
				insert13A_Physics << "\nNo 1  =" << student1 << "\nNo 2  =" << student2 << "\nNo 3  =" << student3 << "\nNo 4  =" << student4 << "\nNo 5  =" << student5 << "\nNo 6  =" << student6 << "\nNo 7  =" << student7 << "\nNo 8  =" << student8 << "\nNo 9  =" << student9 << "\nNo 10  =" << student10 << endl;
				insert13A_Physics.close();
			}
			else
			{
				insert13A_Chemistry << "\nNo 1  =" << student1 << "\nNo 2  =" << student2 << "\nNo 3  =" << student3 << "\nNo 4  =" << student4 << "\nNo 5  =" << student5 << "\nNo 6  =" << student6 << "\nNo 7  =" << student7 << "\nNo 8  =" << student8 << "\nNo 9  =" << student9 << "\nNo 10  =" << student10 << endl;
				insert13A_Chemistry.close();
			}
		}
		else  //for 13B class
		{
			if (selectSubject == 'M')
			{
				insert13B_Maths << "\nNo 1  =" << student1 << "\nNo 2  =" << student2 << "\nNo 3  =" << student3 << "\nNo 4  =" << student4 << "\nNo 5  =" << student5 << "\nNo 6  =" << student6 << "\nNo 7  =" << student7 << "\nNo 8  =" << student8 << "\nNo 9  =" << student9 << "\nNo 10  =" << student10 << endl;
				insert13B_Maths.close();
			}
			else if (selectSubject == 'P')
			{
				insert13B_Physics << "\nNo 1  =" << student1 << "\nNo 2  =" << student2 << "\nNo 3  =" << student3 << "\nNo 4  =" << student4 << "\nNo 5  =" << student5 << "\nNo 6  =" << student6 << "\nNo 7  =" << student7 << "\nNo 8  =" << student8 << "\nNo 9  =" << student9 << "\nNo 10  =" << student10 << endl;
				insert13B_Physics.close();
			}
			else
			{
				insert13B_Chemistry << "\nNo 1  =" << student1 << "\nNo 2  =" << student2 << "\nNo 3  =" << student3 << "\nNo 4  =" << student4 << "\nNo 5  =" << student5 << "\nNo 6  =" << student6 << "\nNo 7  =" << student7 << "\nNo 8  =" << student8 << "\nNo 9  =" << student9 << "\nNo 10  =" << student10 << endl;
				insert13B_Chemistry.close();
			}
		}
	}
}


int main()
{
	char userType;

	student student1;
	teacher teacher1;
	cout << "Student or Teacher : (S/T) :";
	cin >> userType;

	if (userType == 'S')
	{
		student1.printHeading();
		student1.menuStudent();
	}
	else
	{
		teacher1.printHeading();
		teacher1.menuTeacher();
	}
}

