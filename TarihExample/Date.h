//
//  Date.h
//  TarihExample
//
//  Created by Kaan Şengün on 14.11.2023.
//
#include <iostream>
using namespace std;

class Date{
private:
    int year,month,day;
    const int monthDays[12]={31,29,31,30,31,30,31,31,30,31,31,31};
    const string monthString[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
public:
    Date(int d=1,int m=1,int y=1900);
    Date(const Date &oth);
    ~Date();
    void setDate(int d=1,int m=1,int y=1800);
    void setDay(int d){
        day=d;
    }
    void setMonth(int m){
        month=m;
    }
    void setYear(int y){
        year=y;
    }
    int getDay() const{
        return day;
    }
    int getMonth() const{
        return month;
    }
    int getYear() const{
        return year;
    }
    void increaseDay();
    void compareDate(const Date &othDate);
    void displayDate();
};
Date::Date(int d,int m,int y){
    cout<<"Constructor worked."<<endl;
    if((d<=0)||(d>31)){
        cout<<"Invalid day please try again."<<endl;
    }
    else if ((m<=0)||(m>12)){
        cout<<"Invalid month please try again."<<endl;
    }
    else{
        year=y;
        month=m;
        day=d;
    }
    
};
Date::~Date(){
    cout<<"Deconstructor worked."<<endl;
}
Date::Date(const Date &oth){
    day=oth.day;
    month=oth.month;
    year=oth.year;
}
void Date::setDate(int d,int m,int y){
    cout<<"Please enter the date DD,MM,YY format."<<endl;
    cin>>d>>m>>y;
    if((d<=0)||(d>31)){
        cout<<"Invalid day please try again."<<endl;
    }
    else if ((m<=0)||(m>12)){
        cout<<"Invalid month please try again."<<endl;
    }
    year=y;
    month=m;
    day=d;
}
void Date::increaseDay() {
    day++;

    if (day > monthDays[month - 1]) {
        day = 1;
        month++;

        if (month > 12) {
            month = 1;
            year++;
        }
    }
}
void Date::compareDate(const Date &othDate){
    if((year==othDate.year)&&(month==othDate.month)&&(day==othDate.day)){
        cout<<"Same date"<<endl;
    }
    cout<<"Not same date"<<endl;
}
void Date::displayDate(){
    if((day<=0)||(day>31)){
        cout<<"-------------------------------"<<endl;
    }
    else if ((month<=0)||(month>12)){
        cout<<"-------------------------------"<<endl;
    }
    else{
        cout<<day<<"/"<<monthString[month-1]<<"/"<<year<<endl;
    }
    return;
    
}

