#include <iostream>
#include <ctime>
using namespace std;

class Employee{
    public :
        int getAttendance(){
            srand(time(0));
            return (rand() % 2);
        }

};

int main(){
    cout << "\n\tWelcome To Employee Wage Computation" << endl;
    Employee empObj;
    int attendance = empObj.getAttendance();

    if (attendance == 1) {
        cout << "Employee is Present" << endl;
    }
    else {
        cout << "Employee is Absent" << endl;
    }    
    return 0;
}