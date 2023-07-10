#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<vector>
#include<sstream>
using namespace std;
struct course {
	string name;
	int crd = 0;
	int faculty;
	int fee = 0;
	int id = 0;
	string f_name;
};
struct quiz {
	string name;
	int marks;
	int weightage;
	string content;
	int id;
	int o_marks = 0;
	quiz* nptr;
};
quiz* fptr = NULL;
struct assign {
	string name;
	int marks;
	int weightage;
	string content;
	int id;
	assign* nptr;
};
assign* fptr2 = NULL;
struct project {
	string name;
	int marks;
	int weightage;
	string content;
	int id;
	project* nptr;
};
project* fptr3 = NULL;
struct sessional {
	string name;
	int marks;
	int weightage;
	string content;
	int id;
	sessional* nptr;
};
sessional* fptr4 = NULL;
const int max_semesters = 8;
const int max_courses = 8;
class person {
protected:
	string name;
	string phone;
	string address;
	string dob;
public:
	void enter_data()
	{
		cout << "\nEnter name : ";
		cin >> name;
		cout << "\nEnter phone : ";
		cin >> phone;
		cout << "\nEnter address : ";
		cin >> address;
		cout << "\nEnter date of birth : ";
		cin >> dob;
	}
	void show_data()
	{
		cout << "\nName : " << name;
		cout << "\nPhone : " << phone;
		cout << "\nAddress : " << address;
		cout << "\nDate of Birth : " << dob;
	}
};
course courses[max_semesters][max_courses];
void write_courses(course courses[][max_courses]) {
    ofstream myfile("courses.txt");
    
    if (myfile.is_open()) {
        for (int i = 0; i < max_semesters; i++) {
            for (int j = 0; j < max_courses; j++) {
                myfile << courses[i][j].name << "," << courses[i][j].crd << "," << courses[i][j].faculty << "," << courses[i][j].fee << "," << courses[i][j].id << "\n";
            }
        }
        
        myfile.close();
        cout << "Courses saved to file.\n";
    }
    else {
        cout << "Error opening file for writing.\n";
    }
}
class student : public person {
private:
	vector<course> en_courses;
	bool hostel = false;
	bool transport = false;
	bool new_s = false;
	int marks;
	vector<int> quizmarks;
	vector<int> ass_marks;
	vector<int> pro_marks;
	vector<int> sess_marks;
public:
	person p1;
	string id;
	string name;
	int fee = 0;
	string pass;
	string batch;
	string dob;
	int c;
	vector<string> array;
	void display_data()
	{
		p1.show_data();
	}

	void cal_fee()
	{
		int total_fee = 0;
		int h_fee = 0, t_fee = 0;
		int reg_fee = 0;
		cout << "\nCourses registration fee : " << fee << endl;
		if (hostel == true)
		{
			h_fee = 20000;
		}
		if (transport == true)
		{
			t_fee = 20000;
		}
		if (new_s == true)
		{
			reg_fee = 40000;
		}
		int lib_fee = 10000;
		total_fee = h_fee + t_fee + fee + lib_fee + reg_fee;
		cout << "\nNew Student registration fee : " << reg_fee << endl;
		cout << "\nLibrary Charges : " << lib_fee << endl;
		cout << "\nHostel Charges : " << h_fee << endl;
		cout << "\nTransport Charges : " << t_fee << endl;
		cout << "\nTotal fee : " << total_fee << endl;
		fstream myfile;
		myfile.open("FeeChallan.txt", ios::out);
		myfile << "\nCourses registration fee : " << fee << endl;
		myfile << "\nNew Student registration fee : " << reg_fee << endl;
		myfile << "\nLibrary Charges : " << lib_fee << endl;
		myfile << "\nHostel Charges : " << h_fee << endl;
		myfile << "\nTransport Charges : " << t_fee << endl;
		myfile << "\nTotal fee : " << total_fee << endl;
		myfile.close();
		if (myfile)
		{
			cout << "\nFee Challan generated as a file.\n";
		}
		else
		{
			cout << "\nCouldn't generate fee challan";
		}
		cout << endl;
	}
	void hostel_reg()
	{
		cout << "\nEnter 1 if you want to avail hostel else 0 : ";
		cin >> hostel;
		cout << "\nEnter 1 if you want to avail transport else 0 : ";
		cin >> transport;
		cout << "\nEnter 1 if you're a new student (1st semester) else 0 : ";
		cin >> new_s;
	}
	void add_quiz(int marks)
	{
		quizmarks.push_back(marks);
	}
	void add_assignment(int marks)
	{
		ass_marks.push_back(marks);
	}
	void add_project(int marks)
	{
		pro_marks.push_back(marks);
	}
	void add_sessional(int marks)
	{
		sess_marks.push_back(marks);
	}
	void enroll_semester()
{
	    int sem;
		cout << "\nEnroll semester : ";
		cin >> sem;
		system("pause");
		system("cls");
		cout << "\nCourses available in " << sem << " semester : \n";
		if (sem == 1)
		{
			cout << setw(5) << "No" << setw(20) << "Course name" << setw(20) << "Faculty" << setw(12) << "Credit hours" << setw(10) << "Course ID" << endl;
			for (int i = 0; i < 2; i++)
			{
				cout << setw(5) << i + 1 << setw(20) << courses[1][i].name;
				cout << setw(20) << courses[1][i].f_name;
				cout << setw(12) << courses[1][i].crd;
				cout << setw(10) << courses[1][i].id;
				cout << endl;
			}
		}
		if (sem == 2)
		{
			cout << setw(5) << "No" << setw(20) << " Course name" << setw(20) << " Faculty" << setw(12) << " Credit hours" << setw(10) << " Course ID" << endl;
			for (int i = 0; i < 2; i++)
			{
				cout << setw(5) << i + 1 << setw(20) << courses[2][i].name;
				cout << setw(20) << courses[2][i].f_name;
				cout << setw(12) << courses[2][i].crd;
				cout << setw(10) << courses[2][i].id;
				cout << endl;
			}
		}
		if (sem == 3)
		{
			cout << setw(5) << "No" << setw(20) << " Course name" << setw(20) << " Faculty" << setw(12) << " Credit hours" << setw(10) << " Course ID" << endl;
			for (int i = 0; i < 2; i++)
			{
				cout << setw(5) << i + 1 << setw(20) << courses[3][i].name;
				cout << setw(20) << courses[3][i].f_name;
				cout << setw(12) << courses[3][i].crd;
				cout << setw(10) << courses[3][i].id;
				cout << endl;
			}
		}
		if (sem == 4)
		{
			cout << setw(5) << "No" << setw(20) << " Course name" << setw(20) << " Faculty" << setw(12) << " Credit hours" << setw(10) << " Course ID" << endl;
			for (int i = 0; i < 2; i++)
			{
				cout << setw(5) << i + 1 << setw(20) << courses[4][i].name;
				cout << setw(20) << courses[4][i].f_name;
				cout << setw(12) << courses[4][i].crd;
				cout << setw(10) << courses[4][i].id;
				cout << endl;
			}
		}
		if (sem == 5)
		{
			cout << setw(5) << "No" << setw(20) << " Course name" << setw(20) << " Faculty" << setw(12) << " Credit hours" << setw(10) << " Course ID" << endl;
			for (int i = 0; i < 2; i++)
			{
				cout << setw(5) << i + 1 << setw(20) << courses[5][i].name;
				cout << setw(20) << courses[5][i].f_name;
				cout << setw(12) << courses[5][i].crd;
				cout << setw(10) << courses[5][i].id;
				cout << endl;
			}
		}
		if (sem == 6)
		{
			cout << setw(5) << "No" << setw(20) << " Course name" << setw(20) << " Faculty" << setw(12) << " Credit hours" << setw(10) << " Course ID" << endl;
			for (int i = 0; i < 2; i++)
			{
				cout << setw(5) << i + 1 << setw(20) << courses[6][i].name;
				cout << setw(20) << courses[6][i].f_name;
				cout << setw(12) << courses[6][i].crd;
				cout << setw(10) << courses[6][i].id;
				cout << endl;
			}
		}
		if (sem == 7)
		{
			cout << setw(5) << "No" << setw(20) << " Course name" << setw(20) << " Faculty" << setw(12) << " Credit hours" << setw(10) << " Course ID" << endl;
			for (int i = 0; i < 2; i++)
			{
				cout << setw(5) << i + 1 << setw(20) << courses[7][i].name;
				cout << setw(20) << courses[7][i].f_name;
				cout << setw(12) << courses[7][i].crd;
				cout << setw(10) << courses[7][i].id;
				cout << endl;
			}
		}
		if (sem == 8)
		{
			cout << setw(5) << "No" << setw(20) << " Course name" << setw(20) << " Faculty" << setw(12) << " Credit hours" << setw(10) << " Course ID" << endl;
			for (int i = 0; i < 2; i++)
			{
				cout << setw(5) << i + 1 << setw(20) << courses[8][i].name;
				cout << setw(20) << courses[8][i].f_name;
				cout << setw(12) << courses[8][i].crd;
				cout << setw(10) << courses[8][i].id;
				cout << endl;
			}
		}
		int en;
		course s_course;
		cout << "\nEnter number of courses you want to enroll : ";
		cin >> en;
		if (en >= 0 && en <= 6)
		{
			for (int i = 0; i < en; i++)
			{
				int id1;
				cout << "\nEnter ID of course you want to enroll : ";
				cin >> id1;
				for (int j = 0; j < en; j++)
				{
					if (id1 == courses[sem][i].id)
					{
						
						fee = fee + courses[sem][i].fee;
						cout << "\nEnrolled in " << courses[sem][i].name << " course successfully.\n";
						c = id1;
						break;
					}
					else
					{
						cout << "\nCouldnt enroll in course.\n";
						break;
					}
				}
			}
		}
		else
			cout << "\nInvalid number of courses.\n";
			
		}
		void show_attendace()
    {
		
			cout << "Attendance: ";
			for (const auto& attendance : array) {
				cout << attendance << endl;
			}
	}
	student* nptr;
};
student* fptr6 = NULL;
class faculty : public person {
private:
	string quize;
public:
	int id;
	int p1;
	string name;
	string dob;
	string phone;
	string course;
	person p;
	student s2;
	int course_id;
	void enter_quiz()
	{
		int q_id;
		cout << "\nEnter id of quiz :";
		cin >> q_id;
		quiz* cptr;
		cptr = fptr;
		int marks;
		while (cptr != NULL)
		{
			if (q_id == cptr->id)
			{
				cout << "\nEnter marks for student : ";
				cin >> marks;
				s2.add_quiz(marks);
				cout << "\nQuiz marks added.";
				break;
			}
			else
			{
				cout << cptr->name << " of this id found.\n";
				break;
			}
			cptr = cptr->nptr;
		}


	}
	void enter_assignment()
	{
		int a_id;
		cout << "\nEnter id of Assignment:";
		cin >> a_id;
		assign* cptr;
		cptr = fptr2;
		int marks;
		while (cptr != NULL)
		{
			if (a_id == cptr->id)
			{
				cout << "\nEnter marks for student : ";
				cin >> marks;
				s2.add_assignment(marks);
				cout << cptr->name << " marks added.";
				break;
			}
			else
			{
				cout << "\nNo Assignment of this id found.\n";
				break;
			}
			cptr = cptr->nptr;
		}
	}
	void enter_project()
	{
		int p_id;
		cout << "\nEnter id of Project :";
		cin >> p_id;
		project* cptr;
		cptr = fptr3;
		int marks;
		while (cptr != NULL)
		{
			if (p_id == cptr->id)
			{
				cout << "\nEnter marks for student : ";
				cin >> marks;
				s2.add_project(marks);
				cout << cptr->name << " marks added.";
				break;
			}
			else
			{
				cout << "\nNo Project of this id found.\n";
				break;
			}
			cptr = cptr->nptr;
		}
	}
	void enter_sessional()
	{
		int s_id;
		cout << "\nEnter id of Sessional :";
		cin >> s_id;
		sessional* cptr;
		cptr = fptr4;
		int marks;
		while (cptr != NULL)
		{
			if (s_id == cptr->id)
			{
				cout << "\nEnter marks for student : ";
				cin >> marks;
				s2.add_sessional(marks);
				cout << cptr->name << " marks added.";
				cout << endl;
				break;
			}
			else
			{
				cout << "\nNo Project of this id found.\n";
				break;
			}
			cptr = cptr->nptr;
		}
	}


	void assessment()
	{
		int a;
		system("cls");
		cout << "\n1.Quiz";
		cout << "\n2.Assignment";
		cout << "\n3.Project";
		cout << "\n4.Sessional\n";
		cin >> a;
		cout << endl;
		if (a == 1)
		{
			quiz* ptr = new quiz;
			if (fptr == NULL) {
				fptr = ptr;
				fptr->nptr = NULL;
			}
			else {
				quiz* cptr = fptr;
				while (cptr->nptr != NULL) {
					cptr = cptr->nptr;
				}
				cptr->nptr = ptr;
				ptr->nptr = NULL;
			}

			cout << "Enter Quiz name: ";
			cin >> ptr->name;
			cout << "Enter Quiz marks: ";
			cin >> ptr->marks;
			cout << "Enter Quiz weightage: ";
			cin >> ptr->weightage;
			cout << "Enter content of quiz : ";
			cin >> ptr->content;
			cout << "Enter Quiz id : ";
			cin >> ptr->id;
			ofstream file("Quiz.txt", ios::out|ios::app);
			if (file.is_open()) {
				file << "Quiz name: " << ptr->name << endl;
				file << "Marks: " << ptr->marks << endl;
				file << "Weightage: " << ptr->weightage << endl;
				file << "Content : " << ptr->content;
				file << endl;
				file.close();
				cout << "\nQuiz file created.\n";
			}
			else {
				cout << "Failed to open file." << endl;
			}
		}

		if (a == 2)
		{
			assign* ptr2;
			ptr2 = new assign;
			if (fptr2 == NULL) {
				fptr2 = ptr2;
				fptr2->nptr = NULL;
			}
			else {
				assign* cptr2 = fptr2;
				while (cptr2->nptr != NULL) {
					cptr2 = cptr2->nptr;
				}
				cptr2->nptr = ptr2;
				ptr2->nptr = NULL;
			}

			cout << "Enter Assignment name: ";
			cin >> ptr2->name;
			cout << "Enter Assignment marks: ";
			cin >> ptr2->marks;
			cout << "Enter Assignment weightage: ";
			cin >> ptr2->weightage;
			cout << "Enter Assignment ID : ";
			cin >> ptr2->id;
			ofstream file("Assignment.txt", ios::app);
			if (file.is_open()) {
				file << "Assignemnt name: " << ptr2->name << endl;
				file << "Marks: " << ptr2->marks << endl;
				file << "Weightage: " << ptr2->weightage << endl;
				file << endl;
				file.close();
				cout << "\nAssignment file created.\n";
			}
			else {
				cout << "Failed to open file." << endl;
			}

		}
		if (a == 3)
		{
			project* ptr3;
			ptr3 = new project;
			if (fptr3 == NULL) {
				fptr3 = ptr3;
				fptr3->nptr = NULL;
			}
			else {
				project* cptr3 = fptr3;
				while (cptr3->nptr != NULL) {
					cptr3 = cptr3->nptr;
				}
				cptr3->nptr = ptr3;
				ptr3->nptr = NULL;
			}

			cout << "Enter Project name: ";
			cin >> ptr3->name;
			cout << "Enter Project marks: ";
			cin >> ptr3->marks;
			cout << "Enter project weightage: ";
			cin >> ptr3->weightage;
			cout << "Enter project id : ";
			cin >> ptr3->id;
			ofstream file("project.txt", ios::app);
			if (file.is_open()) {
				file << "project name: " << ptr3->name << endl;
				file << "Marks: " << ptr3->marks << endl;
				file << "Weightage: " << ptr3->weightage << endl;
				file << endl;
				file.close();
				cout << "\nProject file created.\n";
			}
			else {
				cout << "Failed to open file." << endl;
			}

		}
		if (a == 4)
		{
			sessional* ptr;
			ptr = new sessional;
			if (fptr4 == NULL) {
				fptr4 = ptr;
				fptr4->nptr = NULL;
			}
			else {
				sessional* cptr = fptr4;
				while (cptr->nptr != NULL) {
					cptr = cptr->nptr;
				}
				cptr->nptr = ptr;
				ptr->nptr = NULL;
			}

			cout << "Enter sessional name: ";
			cin >> ptr->name;
			cout << "Enter sessional marks: ";
			cin >> ptr->marks;
			cout << "Enter sessional weightage: ";
			cin >> ptr->weightage;
			cout << "Enter Sessional ID : ";
			cin >> ptr->id;
			ofstream file("sessional.txt", ios::out);
			if (file.is_open()) {
				file << "sessional name: " << ptr->name << endl;
				file << "Marks: " << ptr->marks << endl;
				file << "Weightage: " << ptr->weightage << endl;
				file << endl;
				file.close();
				cout << "\nSessional file created.\n";
			}
			else {
				cout << "Failed to open file." << endl;
			}
		}
	}
	string des;
	faculty* nptr;
};
faculty* fptr5 = NULL;
class admin {
private:
	string semester;
	int s = 0;
public:
	faculty f2;
	void in_semester()
	{
		string s1;
		string f;
		string c;
	sem1:
		int n8;
		cout << "\nEnter semester to be offered : ";
		cin >> semester;
		cout << "\nEnter number of courses you want to offer : ";
		cin >> n8;
		if (semester == "fall")
		{
			cout << "\nSemesters : \n1.1st semester\n2.3rd semester\n3.5th semester\n4.7th semester\n";
			cout << "\nchoice : ";
			cin >> s;
			system("pause");
			system("cls");
			cout << endl;
			if (s == 1)
			{
				cout << "Enter 1st semester courses : ";
				for (int i = 0; i < n8; i++)
				{
					cout << "\nName of course " << i + 1 << " : ";
					cin >> courses[1][i].name;
					cout << "Faculty member assigned for course : ";
					cin >> courses[1][i].faculty;
					int f3;
					f3 = courses[1][i].faculty;
					faculty* cptr;
					cptr = fptr5;
					bool facultyFound = false;

                    while (cptr != NULL) {
                        if (f3 == cptr->id) {
                        cout << cptr->name << " is assigned for this course" << endl;
                       cptr->course = courses[1][i].name;
                       cptr->course_id = courses[1][i].id;
                       courses[1][i].f_name = cptr->name;
                       facultyFound = true;
                       break;
                     }
                   cptr = cptr->nptr;
                  }

                 if (!facultyFound) {
                   cout << "No faculty member for this ID found." << endl;
                  }
					cout << "Credit hours of course : ";
					cin >> courses[1][i].crd;
					cout << "Fee of course : ";
					cin >> courses[1][i].fee;
					cout << "ID of course : ";
					cin >> courses[1][i].id;
                 
                    write_courses(courses);
				}
				system("pause");
				system("cls");
			}
			if (s == 2)
			{
				cout << "\nEnter 3rd semester courses : ";
				for (int i = 0; i < n8; i++)
				{
					cout << "\nName of course " << i + 1 << " : ";
					cin >> courses[3][i].name;
					cout << "Faculty member assigned for course : ";
					cin >> courses[3][i].faculty;
					faculty* cptr;
					cptr = fptr5;
				bool facultyFound = false;

                    while (cptr != NULL) {
                        if (courses[3][i].faculty == cptr->id) {
                        cout << cptr->name << " is assigned for this course" << endl;
                       cptr->course = courses[3][i].name;
                       cptr->course_id = courses[3][i].id;
                       facultyFound = true;
                       break;
                     }
                   cptr = cptr->nptr;
                  }

                 if (!facultyFound) {
                   cout << "No faculty member for this ID found." << endl;
                  }
					cout << "Credit hours of course : ";
					cin >> courses[3][i].crd;
					cout << "Fee of course : ";
					cin >> courses[3][i].fee;
					cout << "ID of course : ";
					cin >> courses[3][i].id;
				    write_courses(courses);

				}
				system("pause");
				system("cls");
			}
			if (s == 3)
			{
				cout << "\nEnter 5th semester courses : ";
				for (int i = 0; i < n8; i++)
				{
					cout << "\nName of course " << i + 1 << " : ";
					cin >> courses[5][i].name;
					cout << "Faculty memeber assigned for course : ";
					cin >> courses[5][i].faculty;
						faculty* cptr;
					cptr = fptr5;
				    bool facultyFound = false;

                    while (cptr != NULL) {
                        if (courses[5][i].faculty == cptr->id) {
                        cout << cptr->name << " is assigned for this course" << endl;
                       cptr->course = courses[5][i].name;
                       cptr->course_id = courses[5][i].id;
                       facultyFound = true;
                       break;
                     }
                   cptr = cptr->nptr;
                  }

                 if (!facultyFound) {
                   cout << "No faculty member for this ID found." << endl;
                  }
					cout << "Credit hours of course : ";
					cin >> courses[5][i].crd;
					cout << "Fee of course : ";
					cin >> courses[5][i].fee;
					cout << "ID of course : ";
					cin >> courses[5][i].id;
				    write_courses(courses);

				}
				system("pause");
				system("cls");
			}
			if (s == 4)
			{
				cout << "\nEnter 7th semester course : ";
				for (int i = 0; i < n8; i++)
				{
					cout << "\nName of course " << i + 1 << " : ";
					cin >> courses[7][i].name;
					cout << "Faculty memeber assigned for course : ";
					cin >> courses[7][i].faculty;
						faculty* cptr;
					cptr = fptr5;
				bool facultyFound = false;

                    while (cptr != NULL) {
                        if (courses[7][i].faculty == cptr->id) {
                        cout << cptr->name << " is assigned for this course" << endl;
                       cptr->course = courses[7][i].name;
                       cptr->course_id = courses[7][i].id;
                       facultyFound = true;
                       break;
                     }
                   cptr = cptr->nptr;
                  }

                 if (!facultyFound) {
                   cout << "No faculty member for this ID found." << endl;
                  }
					cout << "Credit hours of course : ";
					cin >> courses[7][i].crd;
					cout << "Fee of course : ";
					cin >> courses[7][i].fee;
					cout << "ID of course : ";
					cin >> courses[7][i].id;
				     write_courses(courses);

				}
				system("pause");
				system("cls");

			}
		}
		if (semester == "spring")
		{
			cout << "\nSemesters : \n1.2nd semester\n2.4th semester\n3.6th semester\n4.8th semester\n.";
			cout << "\nchoice : ";
			cin >> s;
			system("pause");
			system("cls");
			cout << endl;
			if (s == 1)
			{
				cout << "\nEnter 2nd semester courses : ";
				for (int i = 0; i < n8; i++)
				{
					cout << "\n\nName of course " << i + 1 << " : ";
					cin >> courses[2][i].name;
					cout << "Faculty memeber assigned for course : ";
					cin >> courses[2][i].faculty;
						faculty* cptr;
					cptr = fptr5;
				bool facultyFound = false;

                    while (cptr != NULL) {
                        if (courses[2][i].faculty == cptr->id) {
                        cout << cptr->name << " is assigned for this course" << endl;
                       cptr->course = courses[2][i].name;
                       cptr->course_id = courses[2][i].id;
                       facultyFound = true;
                       break;
                     }
                   cptr = cptr->nptr;
                  }

                 if (!facultyFound) {
                   cout << "No faculty member for this ID found." << endl;
                  }
					cout << "Credit hours of course : ";
					cin >> courses[2][i].crd;
					cout << "Fee of course : ";
					cin >> courses[2][i].fee;
					cout << "ID of course : ";
					cin >> courses[2][i].id;
					 write_courses(courses);

				}
				system("pause");
				system("cls");
			}
			if (s == 2)
			{
				cout << "\nEnter 4th semester courses : ";
				for (int i = 0; i < n8; i++)
				{
					cout << "\nName of course " << i + 1 << " : ";
					cin >> courses[4][i].name;
					cout << "Faculty memeber assigned for course : ";
					cin >> courses[4][i].faculty;
						faculty* cptr;
					cptr = fptr5;
				bool facultyFound = false;

                    while (cptr != NULL) {
                        if (courses[4][i].faculty == cptr->id) {
                        cout << cptr->name << " is assigned for this course" << endl;
                       cptr->course = courses[4][i].name;
                       cptr->course_id = courses[4][i].id;
                       courses[4][i].f_name = cptr->name;
                       facultyFound = true;
                       break;
                     }
                   cptr = cptr->nptr;
                  }

                 if (!facultyFound) {
                   cout << "No faculty member for this ID found." << endl;
                  }
					cout << "Credit hours of course : ";
					cin >> courses[4][i].crd;
					cout << "Fee of course : ";
					cin >> courses[4][i].fee;
					cout << "ID of course : ";
					cin >> courses[4][i].id;
				 write_courses(courses);
				}
				system("pause");
				system("cls");
			}
			if (s == 3)
			{
				cout << "\nEnter 6th semester courses : ";
				for (int i = 0; i < n8; i++)
				{
					cout << "\nName of course " << i + 1 << " : ";
					cin >> courses[6][i].name;
					cout << "Faculty memeber assigned for course : ";
					cin >> courses[6][i].faculty;
						faculty* cptr;
					cptr = fptr5;
				bool facultyFound = false;

                    while (cptr != NULL) {
                        if (courses[6][i].faculty == cptr->id) {
                        cout << cptr->name << " is assigned for this course" << endl;
                       cptr->course = courses[6][i].name;
                       cptr->course_id = courses[6][i].id;
                       facultyFound = true;
                       break;
                     }
                   cptr = cptr->nptr;
                  }

                 if (!facultyFound) {
                   cout << "No faculty member for this ID found." << endl;
                  }
					cout << "Credit hours of course : ";
					cin >> courses[6][i].crd;
					cout << "Fee of course : ";
					cin >> courses[6][i].fee;
					cout << "ID of course : ";
					cin >> courses[6][i].id;
					 write_courses(courses);

				}
			
			}
			if (s == 4)
			{
				cout << "\nEnter 8th semester course : ";
				for (int i = 0; i < n8; i++)
				{
					cout << "\nName of course " << i + 1 << " : ";
					cin >> courses[8][i].name;
					cout << "Faculty member assigned for course : ";
					cin >> courses[8][i].faculty;
						faculty* cptr;
					cptr = fptr5;
				    bool facultyFound = false;
                    while (cptr != NULL) {
                        if (courses[8][i].faculty == cptr->id) {
                        cout << cptr->name << " is assigned for this course" << endl;
                       cptr->course = courses[8][i].name;
                       cptr->course_id = courses[8][i].id;
                       facultyFound = true;
                       break;
                     }
                   cptr = cptr->nptr;
                  }

                 if (!facultyFound) {
                   cout << "No faculty member for this ID found." << endl;
                  }
					cout << "Credit hours of course : ";
					cin >> courses[8][i].crd;
					cout << "Fee of course : ";
					cin >> courses[8][i].fee;
					cout << "ID of course : ";
					cin >> courses[8][i].id;
				     write_courses(courses);

				}

			}
		}
		int ch;
		cout << "\n1.Enroll another semester.";
		cout << "\n2.Return to main-menu.";
		cin >> ch;
		if (ch == 1)
		{
			goto sem1;
		}

	}
	void subjects()
	{
		faculty* cptr;
		cptr = fptr5;
		while (cptr != NULL)
		{
			cout << "\nName of Faculty : " << cptr->name << endl;
			cout << "Course assigned for faculty : " << cptr->course << endl;
			cout << "Designation of faculty : " << cptr->des << endl;
			cptr = cptr->nptr;
		}
	}
	void stud()
	{
		student* cptr;
		cptr = fptr6;
		while (cptr != NULL)
		{
			cout << "\n\nName of student : " << cptr->name << endl;
			cout << "\nCourse enrolled by student : " << cptr->c << endl;
			cout << "\nDate of birth of student : " << cptr->dob << endl;
			cout << "\nID of student : " << cptr->id << endl;
			cout << "\nBatch of student : " << cptr->batch << endl;
			cptr = cptr->nptr;
		}
	}

};


void add_student()
{
		student* ptr;
		ptr = new student;
		if (fptr6 == NULL)
		{
			fptr6 = ptr;
			ptr->nptr = NULL;
		}
		else
		{
			student* cptr;
			cptr = fptr6;
			while (cptr->nptr != NULL)
			{
				cptr = cptr->nptr;
			}
			cptr->nptr = ptr;
			ptr->nptr = NULL;
		}
		cout << "\nName of student  : ";
		cin >> ptr->name;
		cout << "\nBatch of student : ";
		cin >> ptr->batch;
		cout << "\nDate of birth : ";
		cin >> ptr->dob;
		cout << "\nEnter ID of student : ";
		cin >> ptr->id;
		cout << "\nEnter Password for id : ";
		cin >> ptr->pass;
		fstream myfile;
		myfile.open("Student_data.txt",ios::out|ios::app);
		if(!myfile)
		{
			cout << "\nCouldnt open file.\n";
		}
		else
		{
			myfile << ptr->name << " , " << ptr->batch << " , " << ptr->dob << " , " << ptr->id << " , " << ptr->pass << "\n";
			myfile.close();
			cout << "\nData saved to file\n";
		}
}
string trim(const string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first)
    {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}
void read_student()
{
	ifstream myfile;
	myfile.open("Student_data.txt",ios::in);
	if(!myfile)
	{
		cout << "\nCouldnt open the file.\n";
	}
	else
	{
		student *pre =NULL;
		while(!myfile.eof())
		{
			student *cptr;
			cptr = new student;
			getline(myfile, cptr->name, ',');
			getline(myfile, cptr->batch, ',');
			getline(myfile, cptr->dob, ',');
			getline(myfile, cptr->id, ',');
			myfile >> cptr->pass;
			cptr->nptr = NULL;
			cptr->id = trim(cptr->id); 
            cptr->nptr = NULL;
			if(pre == NULL)
			{
				fptr6 = cptr; //First node
			}
			else
			{
				pre->nptr = cptr; //Next node in list
			}
			pre = cptr; //Updating the previous node
		}
		myfile.close();
		cout << "\n\nData loaded from file.\n";
	}
}

void add_faculty()
{
	    faculty* ptr;
		ptr = new faculty;
		if (fptr5 == NULL)
		{
			fptr5 = ptr;
			ptr->nptr = NULL;
		}
		else
		{
			faculty* cptr = fptr5;
			while (cptr->nptr != NULL)
			{
				cptr = cptr->nptr;
			}
			cptr->nptr = ptr;
			ptr->nptr = NULL;
		}
	
		cout << "\nEnter Name : ";
		cin >> ptr->name;
		cout << "\nEnter Phone Number : ";
		cin >> ptr->phone;
		cout << "\nEnter Date of Birth : ";
		cin >> ptr->dob;
		cout << "\nEnter Designation : ";
		cin >> ptr->des;
		cout << "\nEnter ID : ";
		cin >> ptr->id;
		cout << "\nEnter Password : ";
		cin >>ptr->p1;
		fstream myfile;
		myfile.open("Faculty_Data.txt",ios::out|ios::app);
		if(!myfile)
		{
			cout << "\nCouldnt open the file.\n";
		}
		else
		{
			myfile << ptr->name << " , " << ptr->phone << " , " << ptr->dob << " , " << ptr->des << " , " << ptr->id << "\n";
			myfile.close();
			cout << "\nData saved in file.\n";
		}
}
void read_faculty()
{
	ifstream myfile;
	myfile.open("Faculty_Data.txt",ios::in);
	if(!myfile)
	{
		cout << "\nCouldnt open file.\n";
	}
	else
	{
		faculty *pre = NULL;
		while(!myfile.eof())
		{
			faculty *cptr;
			cptr = new faculty;
			getline(myfile, cptr->name, ',');
			getline(myfile, cptr->phone, ',');
			getline(myfile, cptr->dob, ',');
			getline(myfile, cptr->des, ',');
			myfile >> cptr->id;
			cptr->nptr = NULL;
			if(pre == NULL)
			{
				fptr5 = cptr; //First node
			}
			else
			{
				pre->nptr = cptr; //Next node in list
			}
			pre = cptr; //Updating previous node
		}
		myfile.close();
		cout << "\nData loaded from file.\n\n";
	}
}

void enter_attendance()
{
	int id1, day;
	cout << "\nEnter your id : ";
	cin >> id1;
	cout << "\nEnter number of days for attendance : ";
	cin >> day;
	string *att = new string[day];
	faculty* cptr;
	cptr = fptr5;
	while (cptr != NULL)
	{
		if (cptr->id == id1)
		{
			cout << "\n\nCourse : " << cptr->course;
			cout << "\nStudents enrolled in course : ";
			student* cptr2;
			cptr2 = fptr6;
			while (cptr2 != NULL)
			{
				if (cptr2->c == cptr->course_id)
				{
					cout << cptr2->name;
					cout << "\nEnter attendace : ";
					cout << "\nA for absent.\nP for present.\n";
					for (int i = 0; i < day; i++)
					{
						
						cout << "\nFor slot " << i + 1 << " : ";
						cin >> att[i];
						cptr2->array.push_back(att[i]);
					}

					
				}

				cptr2 = cptr2->nptr;
			}
		}
		cptr = cptr->nptr;
	}

}


void read_courses(course courses[][max_courses]) {
    ifstream myfile("courses.txt", ios::in);
    
    if (myfile.is_open()) {
        string line;
        int semester = 0;
        int courseIndex = 0;
        
        while (getline(myfile, line)) {
            string name;
            int crd, fee,faculty, id;
            
            size_t pos = 0;
            string token;
            int tokenIndex = 0;
            
            while ((pos = line.find(",")) != string::npos) {
                token = line.substr(0, pos);
                
                switch (tokenIndex) {
                    case 0:
                        name = token;
                        break;
                    case 1:
                        crd = stoi(token);
                        break;
                    case 2:
                        faculty = stoi(token);
                        break;
                    case 3:
                        fee = stoi(token);
                        break;
                    case 4:
                        id = stoi(token);
                        break;
                }
                
                line.erase(0, pos + 1);
                tokenIndex++;
            }
            
            courses[semester][courseIndex].name = name;
            courses[semester][courseIndex].crd = crd;
            courses[semester][courseIndex].faculty = faculty;
            courses[semester][courseIndex].fee = fee;
            courses[semester][courseIndex].id = id;
            
            courseIndex++;
            
            if (courseIndex == max_courses) {
                courseIndex = 0;
                semester++;
            }
        }
        
        myfile.close();
        cout << "Courses loaded from file.\n";
    }
    else {
        cout << "Error opening file for reading.\n";
    }
}

int main()
{
	int n, pass1, pass2, pass3;
	cout << "\n\t----------------------------------------\t";
	cout << "\n\t|\tSTUDENT MANAGEMENT SYSTEM\t|\t\n";
	cout << "\t----------------------------------------\t";
	string a_id;
	bool found1 = false;
	string s_id;
	string pass;
	int f_id;
	int p;
	read_student();
	read_faculty();
	read_courses(courses);
	student s1;
	faculty f1;
	student *cptr1 = fptr6;
	faculty *cptr2 = fptr5;
	while (1)
	{
	main:
		system("pause");
		system("cls");
		cout << "\nMENU\n";
		cout << "Login as : \n";
		cout << "1.Admin\n";
		cout << "2.Faculty-member\n";
		cout << "3.Student\n";
		cin >> n;
		admin c1;
		system("pause");
		system("cls");
		switch (n)
		{
		case 1:
		pass1:
			cout << "\n\nEnter username : ";
			cin >> a_id;
			cout << "\nEnter 4 digit PIN for admin : ";
			cin >> pass1;
			system("pause");
			system("cls");
			if (pass1 == 1111 && a_id == "admin")
			{
				int c;
			menu4:
				system("pause");
				system("cls");
				cout << "\nMenu";
				cout << "\n1.Add Semester";
				cout << "\n2.Add Faculty";
				cout << "\n3.Add Student";
				cout << "\n4.Show faculty";
				cout << "\n5.Show Students";
				cout << "\n6.Log-out as admin\n";
				cin >> c;
				if (c == 1)
					c1.in_semester();
				if (c == 2)
				{
					add_faculty();
				}
				if (c == 3)
				{
					add_student();
				}
				if (c == 4)
					c1.subjects();
				if (c == 5)
					c1.stud();
				if (c == 6)
					goto main;
				int ch8;
				cout << "\n1.Go to menu.";
				cout << "\n2.Log-out as admin.";
				cin >> ch8;
				if (ch8 == 1)
					goto menu4;
				if (ch8 == 2)
					goto main;
			}
			else
			{
				cout << "\nIncorrect Try again!";
				goto pass1;
			}
			break;
		case 2:
		pass2:
		    cout << "\nEnter ID : ";
		    cin >> f_id;
		    cout << "\nEnter password : ";
		    cin >> p;
		    
		    while(cptr2!=NULL)
		    {
		    	if(cptr2->id == f_id && cptr2->p1 == p)
		    	{
		    	found1 = true;
		    	break;
		       } 
				cptr2 = cptr2->nptr;
			}
			if(found1)
			{
			menu1:
				int ch4;
				system("pause");
				system("cls");
				cout << "\nMenu";
				cout << "\n1.Enter Attendance.";
				cout << "\n2.Create Assessment.";
				cout << "\n3.Enter Grades\n";
				cin >> ch4;
				cout << endl;
				switch (ch4)
				{
				case 1:
					enter_attendance();
					break;
				case 2:
					cptr2->assessment();
					int ch7;
					break;
				case 3:
					int ch6;
					cout << "\n1.Quiz Marks.";
					cout << "\n2.Assignment marks.";
					cout << "\n3.Project marks";
					cout << "\n4.Sessional marks";
					cin >> ch6;
					if (ch6 == 1)
					{
						cptr2->enter_quiz();
					}
					if (ch6 == 2)
					{
						cptr2->enter_assignment();
					}
					if (ch6 == 3)
					{
						cptr2->enter_project();
					}
					if (ch6 == 4)
					{
						cptr2->enter_sessional();
					}
					break;
				}
			}
			if(!found1)
			{
				cout << "\nWrong ID or password.\n";
				goto pass2;
			}
				int ch7;
				cout << "\n1.Go to menu.";
				cout << "\n2.Log-out as faculty.";
				cin >> ch7;
				if (ch7 == 1)
					goto menu1;
				if (ch7 == 2)
					goto main;
			
		
			break;
		case 3:
		pass3:
			cout << "\nEnter student ID : ";
			cin >> s_id;
			cout << "\nEnter student password : ";
			cin >> pass;
			bool found;
			while(cptr1!=NULL)
			{
				if(s_id == cptr1->id && pass == cptr1->pass)
				{
					found = true;
				int ch1;
				while (1)
				{
				menu:
					int ch1;
					system("pause");
					system("cls");
					cout << "\n1.Student Registration";
					cout << "\n2.Hostel-Transport registration";
					cout << "\n3.Fee Challan generation";
					cout << "\n4.View Attendance.\n";
					cin >> ch1;
					system("pause");
					system("cls");
					if (ch1 == 1)
						cptr1->enroll_semester();
					if (ch1 == 2)
						cptr1->hostel_reg();
					if (ch1 == 3)
						cptr1->cal_fee();
					if (ch1 == 4)
						cptr1->show_attendace();
					int ch5;
					cout << "\n1.Return to Menu.";
					cout << "\n2.Log-out from student ID.\n";
					cin >> ch5;
					if (ch5 == 1)
						goto menu;
					if (ch5 == 2)
						goto main;
				}
					
			}
			cptr1 = cptr1->nptr;
		}
		if(!found)
		{
			cout << "\nWrong id or password.\n";
			goto pass3;
		}
			break;
		default:
			cout << "\nChoose right option.\n";

		}
	}

}      

		
