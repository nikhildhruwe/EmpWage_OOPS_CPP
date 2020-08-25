#include <iostream>
#include <ctime>
using namespace std;

class Employee{
    private:
        int EMP_RATE_PER_HOUR = 20;
        int empHrs;
    public :
        int checkAttendance();
        int getDailyWage(int);
};

int Employee :: checkAttendance(){
    srand(time(0));
    return (rand() % 2);  
}

int Employee :: getDailyWage(int attendance){
    if (attendance == 1)
        empHrs = 8;
    else
        empHrs = 0;
   return empHrs * EMP_RATE_PER_HOUR;
}

int main(){
    cout << "\n\tWelcome To Employee Wage Computation" << endl;
    int attendance, empWage;
    Employee empObj;
    attendance = empObj.checkAttendance();
    empWage = empObj.getDailyWage(attendance);
    cout << "Employee Wage Per Day = " << empWage << endl;


}