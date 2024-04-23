// HospitalManagementSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
// CONNECT SQL to C++. Database kay liye....
#include <iostream>
using namespace std;
class Patient
{
public:
	int patientID;
	string patientname;
	string patientgender;
	// string ya date form ki date of birth.........
	string address;
	string patientcnic;
	string contactno;
	string emailaddress;
	string emergencycontactname;
	string relationship;
	string contactnumber;
	string recordCNIC;
	friend void patientregandadmissionprocess();
};
int main()
{  
	string adminusername = "Admin", adminpassword = "hospitalp1";
	string username,  password;
	int choice = 0;
  cout << "Welcome to the Hospital management system!\n";
  cout << "Your one-stop pathway to the hospital" << endl;
  cout << "Kindly select your desired service" << endl;
  cout << "Press 1 for patient registration and admission process " << endl;
  cout << "Press 2 for appointment booking system" << endl;
  cout << "Press 3 to view hospital contact information" << endl;
  cout << "Press 4 to view your comprehensive health record report card" << endl;
  cout << "If you are an administrator, press 5 to track medicine and equipment  at the hospital \n";
  cin >> choice;
  if (choice == 1)
  { // patient registration and admission process
 friend	Patient :: void patientregandadmissionprocess()
	  {
		  cout << "Provide the following personal information:" << endl;
		  void patientinfo()
		  {
			  cout << "Enter your full name" << endl;
			  cin >> patientname;
				  cout << "Enter date of birth in format (dd/mm/yy)" << endl;
				  cin >> patientdateofbirth;
				  cout << "Enter gender" << endl;
				  cin >>patientgender;
				  cout << "Enter address" << endl;
				  cin >> address;
				  cout << "Enter contact number" << endl;
				  cin >> contactnumber;
				  cout << "Enter email address" << endl;
			  cin >> emailaddress;
				  cout << "Enter your CNIC for identification purposes" << endl;
			  cin >> patientcnic;
		  }
		  void emergencycontactinfo()
		  {
			  cout << "Enter emergency contact name" << endl;
			  cin >> emergencycontactname; // point can we access data members this way without creating
			  // object in non-member function
				  cout << "Kindly mention your relationship with patient" << endl;
				  cin >> relationship;
				  cout << " Enter emergency contact number" << endl;
				  cin >> contactnumber;
				  cout << "Enter your CNIC for identification purposes" << endl;
				  cin >> recordCNIC;
		  }
		  // UI saay "Confirm" ka feature daalo... 
		  cout << "You will be contacted soon after form is processed. We hope that you will enjoy your stay at our hospital" << endl;
	  }
  }
  else if (choice == 2)
  {
     // appointment booking
  }
  else if (choice == 3)
  {
  // display function... 
 // display database
	 //  cout <<
  }
  else if (choice == 4)
  {
  // display health record... database banay gi..............
  }
  else if (choice == 5)
  {

	  cout << "Kindly enter your credentials (UserName/ Password)" << endl;
	  cin >> username >> password;
	  if (username == adminusername && password == adminpassword)
	  {
		  cout << "Login successful. Identity verified \n";
			  // track inventory function ... file handling
	  }
	  else
	  {
		  cout << "Dear User, you have entered the wrong credentials" << endl;
		  // exit(1); // sys crash na hou agr koi galti say ghalat daal daay...
	  }
  }
}

class Administrator {


};
class Employee {


};
