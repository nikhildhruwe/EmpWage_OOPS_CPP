#include <iostream>
#include <ctime>
using namespace std;

class Employee{
    private:
        int EMP_RATE_PER_HOUR = 20;
    public :
        int getEmployeeType();
        int getDailyWage(int);
};

int Employee :: getEmployeeType(){
    srand(time(0));
    return (rand() % 3);  
}

int Employee :: getDailyWage(int empType){
    const int FULL_TIME = 0, PART_TIME = 1;
    int empHrs;

   switch(empType){
        case FULL_TIME:
            empHrs = 8;
            break;
        case PART_TIME:
            empHrs = 4;
            break;
        default:
            empHrs = 0;
   }
        return empHrs * EMP_RATE_PER_HOUR;
}

int main(){
    cout << "\n\tWelcome To Employee Wage Computation" << endl;
    int empType, empWage;
    Employee empObj;
    empType = empObj.getEmployeeType();
    empWage = empObj.getDailyWage(empType);
    cout << "Employee Wage Per Day = " << empWage << endl;
}