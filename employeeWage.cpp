#include <iostream>
#include <ctime>
#include <unistd.h>
using namespace std;

class Employee{
    private:
        int EMP_RATE_PER_HOUR = 20;
        int NUM_OF_WORKING_DAYS = 20;
    public :
        int getEmployeeType();
        int getDailyWage(int);
        int getTotalWorkingDays();
};

int Employee :: getTotalWorkingDays(){
    return NUM_OF_WORKING_DAYS;
}

int Employee :: getEmployeeType(){
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
    int empType, empWage, day = 0, totalEmpWage= 0;
    srand(time(0));

    Employee empObj;
    while (day < empObj.getTotalWorkingDays()){
        day++;
        empType = empObj.getEmployeeType();
        empWage = empObj.getDailyWage(empType);
        totalEmpWage += empWage;
    }
    
    cout << "Employee Wage for a month = " << totalEmpWage << endl;
}