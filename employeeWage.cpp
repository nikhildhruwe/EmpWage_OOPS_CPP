#include <iostream>
#include <ctime>
#include <unistd.h>
using namespace std;

class Employee{
    private:
        int EMP_RATE_PER_HOUR = 20;
        int NUM_OF_WORKING_DAYS = 20;
        int MAX_MONTHLY_HRS = 100;
    public :
        int getEmployeeType();
        int getEmployeeHours(int);
        int getTotalWorkingDays();
        int getMaxMonthlyHours();
        int getEmpRatePerHour();
};

int Employee :: getEmpRatePerHour(){
    return EMP_RATE_PER_HOUR;
}

int Employee :: getMaxMonthlyHours(){
    return MAX_MONTHLY_HRS;
}

int Employee :: getTotalWorkingDays(){
    return NUM_OF_WORKING_DAYS;
}

int Employee :: getEmployeeType(){
    return (rand() % 3);  
}

int Employee :: getEmployeeHours(int empType){
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
        return empHrs;
}

int getMonthlyEmployeeWage(Employee empObj){
    int empType, empHrs, day = 0, totalEmpHrs = 0;

    while (day < empObj.getTotalWorkingDays() && totalEmpHrs < empObj.getMaxMonthlyHours()){
        day++;
        empType = empObj.getEmployeeType();
        empHrs = empObj.getEmployeeHours(empType);
        totalEmpHrs += empHrs;
    }
    
    return totalEmpHrs * empObj.getEmpRatePerHour();
}


int main(){
    cout << "\n\tWelcome To Employee Wage Computation" << endl;
    srand(time(0));

    Employee empObj;
    int totalEmpWage = getMonthlyEmployeeWage(empObj);
    cout << "Employee Wage for a month = " << totalEmpWage << endl;
}