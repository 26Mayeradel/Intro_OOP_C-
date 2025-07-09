#include <iostream>
#include <string> 
#include <climits>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
#include <cstring>
#include <list>
//======================================================================//
using namespace std;
#define fx(s) fixed << setprecision(6)
#define ll long long
#define Fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
class student {
	int id;
	string name;
	float gr;
	string depart;
public:

	student() {};
	enum Department {IT=0, CS,IS,SE};
	struct Address {
		string street;
		string city;
		int buildingNumber;
	};
	Address ad;
	void addStudent() {

		int num;
		cout << "Enter ID: ";
		cin >> id;
		cout << "Enter Name: ";
		cin.ignore();
		getline(cin, name);
		cout << "Enter Grade: ";
		cin >> gr;
		cout << "Enter Department: ( 0=IT , 1=CS , 2=IS , 3=SE ) :   ";
		cin >>num ;
		switch (num) {
		case 0:depart = "IT";break;
		case 1:depart = "CS";break;
		case 2:depart = "IS";break;
		case 3:depart = "SE";break;
		}
		cout << "Enter Street: ";
		cin.ignore();
		getline(cin,ad.street);
		cout << "Enter City: ";
		cin >> ad.city;
		cout << "Enter Postal Code: ";
		cin >> ad.buildingNumber;
		cout << "Student added successfully.\n";
	}
	int getID()
	{
		return id;
	}
	void printInfo(student studs[], int& cnt, int idd)
	{
		for (int i = 0; i < cnt; i++)
		{
			if (studs[i].getID() == idd) {
				cout << "ID: " << studs[i].id << "\n"
					<< "Name: " << studs[i].name << "\n"
					<< "Department: " << studs[i]. depart << "\n"
					<< "Grade: " << studs[i].gr << "\n"
					<< "Address: " << studs[i].ad.street << " , " <<
					studs[i].ad.city << " , " << studs[i].ad.buildingNumber << "\n";
			}
			else
				cout << "This student was deleted...? \n";
		}
	}
	void deleteStudent(student studs[],int &cnt,int idd) {
		for (int i = 0; i < cnt; i++)
		{
			if (studs[i].getID() == idd)
			{
				for (int j = i; j < cnt - 1; j++)
				{
					studs[j] = studs[j + 1];
				}
				i--;
				cnt--;
				cout << "Student deleted.\n";
				break;
			}
		
			

		}
	}
	~student() {};
	
	
};
int main()
{
	Fast
		student add,Delet,viw;
	student Studs[50];
	int cnt = 0;int n;
	do {
		cout << "---Student Management Menu---\n";
		cout << "1. Add Student\n";
		cout << "2. View Student\n";
		cout << "3. Delete Student\n";
		cout << "4. Exit \n";
		cout << "Enter you choice:  ";
		cin >> n;

		if (n == 1) {
			if (cnt <= 20) {
				Studs[cnt].addStudent();
				cnt++;
			}
		}
		else if (n == 2)
		{
			cout << "Enter Student ID to view: ";
			int cc;
			cin >> cc;
			viw.printInfo(Studs,cnt,cc);
		}
		else if (n == 3)
		{
			cout << "Enter Student ID to delete: ";
			int idd;
			cin >> idd;
			Delet.deleteStudent(Studs, cnt, idd);
		}
		else {
			cout << " Exiting program..";
			break;
		}
	} while (true);
}

