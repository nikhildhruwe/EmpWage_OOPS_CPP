#include <iostream>
#include <ctime>
using namespace std;

class Employee{
    public :
        void checkAttendance(){
            srand(time(0));
            int empCheck = (rand() % 2);
            if (empCheck == 1)
                cout << "Employee is Present" << endl;
            else
                cout << "Employee is Absent" << endl;
            }
};

int main(){
    cout << "\n\tWelcome To Employee Wage Computation" << endl;
    Employee empObj;
    empObj.checkAttendance();
}