#include <iostream>
#include <ctime>
#include <unistd.h>
using namespace std;

class Company{
    private:
        int EMP_RATE_PER_HOUR;
        int NUM_OF_WORKING_DAYS;
        int MAX_MONTHLY_HRS;
        string companyName;
    public :
            Company();
        int getEmployeeType();
        int getEmployeeHours(int);
        int getTotalWorkingDays();
        int getMaxMonthlyHours();
        int getEmpRatePerHour();
        string getCompanyName();
};

Company :: Company(){
    cout << "Enter Company Name: ";
    cin >> companyName;
    cout << "Enter total working days per month : ";
    cin >> NUM_OF_WORKING_DAYS;
    cout << "Enter maximum working hours : ";
    cin >> MAX_MONTHLY_HRS;
    cout << "Enter employee rate per hour : ";
    cin >> EMP_RATE_PER_HOUR;
}

string Company :: getCompanyName(){
    return companyName;
}

int Company :: getEmpRatePerHour(){
    return EMP_RATE_PER_HOUR;
}

int Company :: getMaxMonthlyHours(){
    return MAX_MONTHLY_HRS;
}

int Company :: getTotalWorkingDays(){
    return NUM_OF_WORKING_DAYS;
}

int Company :: getEmployeeType(){
    return (rand() % 3);  
}

int Company :: getEmployeeHours(int empType){
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

int getMonthlyEmployeeWage(Company obj){
    int empType, empHrs, day = 0, totalEmpHrs = 0;

    while (day < obj.getTotalWorkingDays() && totalEmpHrs < obj.getMaxMonthlyHours()){
        day++;
        empType = obj.getEmployeeType();
        empHrs = obj.getEmployeeHours(empType);
        totalEmpHrs += empHrs;
    }
    
    return totalEmpHrs * obj.getEmpRatePerHour();
}


int main(){
    cout << "\n\tWelcome To Employee Wage Computation" << endl;
    int totalEmpWage;
    srand(time(0));

    Company obj1;
    totalEmpWage = getMonthlyEmployeeWage(obj1);
    cout << "\nCompany : " << obj1.getCompanyName() << endl;
    cout << "Employee Wage for a month = " << totalEmpWage << endl;
    cout << endl;
    Company obj2;
    totalEmpWage = getMonthlyEmployeeWage(obj2);
    cout << "\nCompany : " << obj2.getCompanyName() << endl;
    cout << "Employee Wage for a month = " << totalEmpWage << endl;
}