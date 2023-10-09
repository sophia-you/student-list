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
 */


struct Student {
  char first[25];
  char last[25];
  int id;
  float GPA;
};

// Function prototypes
void add(vector<Student*> &studentList);

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
  
  cout << "Type 'add' to add a student." << endl;
  cout << "Type 'delete' to delete a student." << endl;
  cout << "Type 'print' to print the student roster." << endl;
  cin.getline(input, max);
  int length = strlen(input);
  input[length + 1] = '\0';
  if (strcmp(input, addCommand) == 0)
    {
      cout << "You are now adding a student to the roster." << endl;
      add(studentList);
    }
  else if (strcmp(input, deleteCommand) == 0)
    {
      cout << "You are now deleting a student from the roster." << endl;
    }
  else if (strcmp(input, printCommand) == 0)
    {
      cout << "Printing roster..." << endl;
    }
  
  return 0;
}

/*
 * This function creates a new Student (data type) and saves the student's 
 * pointer to the studentList of pointers.
 */
void add(vector<Student*> &studentList) // passing by reference
{
  int max = 25;
  Student* student = new Student(); // this new pointer will go into the vector


  /* when we ask for the student's information, we assign those values
   * to the dereference of the new Student pointer
   */
  cout << "First name: " << endl;
  cin.getline((*student).first, max); 
  cout << "Last name: " << endl;
  cin.getline((*student).last, max);
  cout << "Student ID: " << endl;
  cin >> (*student).id, max);
  cout << "Student grade point average: " << endl;
  cin.getline((*student).gpa, max);

  cout << (*student).first << endl;
  cout << (*student).last << endl;
  cout << (*student).id << endl;
  cout << (*student).gpa << endl;
  studentList.push_back(student);

}
