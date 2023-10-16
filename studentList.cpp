#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

/*
 * Author | Sophia You
 * Date | 10/03/2023
 * Description | This program stores the name, ID, and GPA of students.
 * When you type in "add," you can add a student and enter their information.
 * When you type in "print," the computer prints out all the student info.
 * When you type in "delete," the computer requests the student id and deletes
 * that student.
 * Sources |
 * https://cplusplus.com/forum/beginner/25343/
 * https://www.shiksha.com/online-courses/articles/erasing-elements-from-a-vector-in-c/
 */

// a data type called Student, which stores student info
struct Student {
  char first[25];
  char last[25];
  int id;
  float gpa;
};

// Function prototypes
void addStudent(vector<Student*> &studentList);
void deleteStudent(vector<Student*> &studentList);
void print(vector<Student*> &studentList);

int main()
{

  vector<Student*> studentList;
  int max = 10; // max number of characters the input can accept
  char input[max];

  // compare these character arrays to the user input
  // for example, if the user's command matches 'add', then add a student
  char addCommand[] = "add";
  char deleteCommand[] = "delete";
  char printCommand[] = "print";

  bool editing = true;
  while (editing) // prompts the user to keep entering commands until they type 'n'
    {
      // prompts user for command type
      cout << "Type 'add' to add a student." << endl;
      cout << "Type 'delete' to delete a student." << endl;
      cout << "Type 'print' to print the student roster." << endl;
      cout << "Type 'quit' to exit editing mode." << endl;
      cin.getline(input, max);
      int length = strlen(input);
      input[length + 1] = '\0';
      
      if (strcmp(input, addCommand) == 0)
	{
	  cout << "You are now adding a student to the roster." << endl;
	  addStudent(studentList);
	}
      else if (strcmp(input, deleteCommand) == 0)
	{
	  cout << "You are now deleting a student from the roster." << endl;
	  deleteStudent(studentList);
	}
      else if (strcmp(input, printCommand) == 0)
	{
	  cout << "Printing roster..." << endl;
	  print(studentList);
	}
      else if (strcmp(input, "quit") == 0)
	{
	  editing = false; 
	}
      else
	{
	  cout << "Command not recognized." << endl;
	  cout << "Check your spelling and remember to use only lowercase letters." << endl;
	}

      // if 'y', the loop continues, otherwise exit the program
      //cout << "Continue editing? Type 'y' to continue, type 'n' to quit" << endl;
      //cin >> editing;
      //cin.ignore(80, '\n');
    }
  
  cout << "Roster updated." << endl;
  return 0;
}

/*
 * This function creates a new Student (data type) and saves the student's 
 * pointer to the studentList of pointers.
 */
void addStudent(vector<Student*> &studentList) // by reference/changing the og vector
{
  int max = 25;
  Student* student = new Student(); // this new pointer will go into the vector


  /* when we ask for the student's information, we assign those values
   * to the dereference of the new Student pointer
   * so basically, we go to where the pointer is pointing
   * and change the values there
   */
  cout << "First name: " << endl;
  cin.getline((*student).first, max); 
  cout << "Last name: " << endl;
  cin.getline((*student).last, max);
  cout << "Student ID: " << endl;
  cin >> (*student).id;
  cout << "Student grade point average: " << endl;
  cin >> (*student).gpa;
  cin.ignore(80, '\n');

  studentList.push_back(student); // add the student
  cout << "Student added successfully. " << endl;

}

/*
 * This function prompts the user for a student's ID, and removes them from the roster
 */
void deleteStudent(vector<Student*> &studentList)
{
  int currentID = 0;
  cout << "Enter the student id of the student you wish to remove from the roster." << endl;
  cin >> currentID;
  cin.ignore(80, '\n');
  for (vector<Student*>::iterator it = studentList.begin(); it != studentList.end(); it++)
    {
      if (currentID == (*it)->id)
	{
	  cout << "Student found. Removing " << (*it)->first << " " << (*it)->last << endl;
	  studentList.erase(it); // delete the pointer in memory from the studentList vector
	  delete *it; // we have to delete the student that we made on the heap
	  break;
	}
    }
  
}

/*
 * This function prints out the entire student roster like so
 * firstname lastname, ID, GPA
 */
void print(vector<Student*> &studentList)
{
  cout << '\n' << endl;

  // walks through each value in the vector, finds the thing it is pointing to, and prints out values
  for (vector<Student*>::iterator it = studentList.begin(); it != studentList.end(); it++)
    {
      cout << (*it)->first << " ";
      cout << (*it)->last << ", ";
      cout << (*it)->id << ", ";

      // make sure the precision is set correctly for GPA
      cout.precision(3);
      cout.setf(ios::showpoint);
      cout << (*it)->gpa << endl;
    }
}

