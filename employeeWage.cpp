#include <iostream>
#include <ctime>
#include <unistd.h>
#include <vector>
#include <list>
using namespace std;

class CompanyEmpWage{
    private:
        int EMP_RATE_PER_HOUR;
        int NUM_OF_WORKING_DAYS;
        int MAX_MONTHLY_HRS;
        string companyName;
        int totalMonthlyWage;
        
    public :
        vector<int> dailyWageList;
        CompanyEmpWage(int, int, int, string);
        int getEmployeeType();
        int getEmployeeHours(int);
        int getTotalWorkingDays();
        int getMaxMonthlyHours();
        int getEmpRatePerHour();
        string getCompanyName();
        void setTotalMonthlyWage(int);
        int getTotalMonthlyWage();
        void empWageBuilder(CompanyEmpWage *);
};

CompanyEmpWage :: CompanyEmpWage(int EMP_RATE_PER_HOUR, int NUM_OF_WORKING_DAYS, int MAX_MONTHLY_HRS, string companyName){
    this->NUM_OF_WORKING_DAYS = NUM_OF_WORKING_DAYS;
    this ->EMP_RATE_PER_HOUR = EMP_RATE_PER_HOUR;
    this ->MAX_MONTHLY_HRS = MAX_MONTHLY_HRS;
    this ->companyName = companyName;
}

void CompanyEmpWage :: setTotalMonthlyWage(int totalMonthlyWage){
    this->totalMonthlyWage = totalMonthlyWage;   
}

int CompanyEmpWage :: getTotalMonthlyWage(){  
    return this->totalMonthlyWage;
}

string CompanyEmpWage :: getCompanyName(){
    return companyName;
}

int CompanyEmpWage :: getEmpRatePerHour(){
    return EMP_RATE_PER_HOUR;
}

int CompanyEmpWage :: getMaxMonthlyHours(){
    return MAX_MONTHLY_HRS;
}

int CompanyEmpWage :: getTotalWorkingDays(){
    return NUM_OF_WORKING_DAYS;
}
        
list<CompanyEmpWage> companyObjectList;

class EmployeeWageBuilder{
    public :
        CompanyEmpWage addCompanyDetails();
        int getEmployeeHours(int);
        void empWageComputation(CompanyEmpWage *);
        int getEmployeeType(){
             return (rand() % 3);  
        }
};

CompanyEmpWage EmployeeWageBuilder :: addCompanyDetails(){
        int EMP_RATE_PER_HOUR, NUM_OF_WORKING_DAYS, MAX_MONTHLY_HRS;
        string companyName;
        cout << "Enter Company Name: ";
        cin >> companyName;
        cout << "Enter total working days per month : ";
        cin >> NUM_OF_WORKING_DAYS;
        cout << "Enter maximum working hours : ";
        cin >> MAX_MONTHLY_HRS;
        cout << "Enter employee rate per hour : ";
        cin >> EMP_RATE_PER_HOUR;
        CompanyEmpWage companyObj(EMP_RATE_PER_HOUR, NUM_OF_WORKING_DAYS, MAX_MONTHLY_HRS, companyName);
        return companyObj;
}

int EmployeeWageBuilder :: getEmployeeHours(int empType){
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

void EmployeeWageBuilder :: empWageComputation(CompanyEmpWage *companyObj){
    int empType, empHrs, day = 0, totalEmpHrs = 0;
    
    while (day < companyObj->getTotalWorkingDays() && totalEmpHrs < companyObj->getMaxMonthlyHours()){
        day++;
        empType = getEmployeeType();
        empHrs = getEmployeeHours(empType);
        totalEmpHrs += empHrs;
        int dailyWage = empHrs * companyObj->getEmpRatePerHour();
        companyObj->dailyWageList.push_back(dailyWage);
    }
   int totalWage = totalEmpHrs * companyObj->getEmpRatePerHour();
   companyObj->setTotalMonthlyWage(totalWage);
}

void addCompany(EmployeeWageBuilder *empObj){
   CompanyEmpWage companyObj =  empObj->addCompanyDetails();
   empObj->empWageComputation(&companyObj);
   companyObjectList.push_back(companyObj);
}

void display(){
    list<CompanyEmpWage> :: iterator companyObj;
     for (companyObj = companyObjectList.begin() ; companyObj != companyObjectList.end() ;  companyObj++){
        cout << "Company: " << companyObj->getCompanyName() << endl;
        cout << "Daily Wage :" << endl;
        for (int i = 0; i < companyObj->dailyWageList.size(); i++){
            cout << "Day-" << i + 1 << " : " << companyObj->dailyWageList[i] << endl;
        }
        cout << "---------------------" << endl;
        cout << "Total Wage : " << companyObj->getTotalMonthlyWage() << endl;
    }
    cout << endl;
}

void displayOptions(){
    bool status = true;
    EmployeeWageBuilder empObj;

    while (status){
        srand(time(0));
        cout << "\n  Choose Operation.\n1.Add Company Details.\n2.Display.\n3.Exit" << endl;
        int choice;
        cin >> choice;
        switch (choice){
        case 1:
            addCompany(&empObj);
            break;
        case 2:
            cout << endl;
            display();
            break;
        case 3:
            status = false;
            break;
        default:
            cout << "Invalid Choice." << endl;
            break;
        }
    }
}

int main (){
    cout << "\n\tWelcome To Employee Wage Computation" << endl; 
    displayOptions();
}