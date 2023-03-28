//Tinh ngay tiep theo
#include <iostream>

using namespace std;

class Calendar{
private:
	int day, month, year;
public:
	int getDay(){return day;}
	void setDay(int day){
		this->day = day;
	}
	int getMonth(){return month;}
	void setMonth(int month){
		this->month = month;
	}
	int getYear(){return year;}
	void setYear(int year){
		this->year = year;
	}
	friend istream& operator >>(istream&, Calendar&);
	friend ostream& operator <<(ostream&, Calendar&);
	bool isLeapYear(int);
	bool isValidDate(int&, int&, int&);
	void NextDay();
};

int main(){
	Calendar date;
	cin >> date;
	date.NextDay();
	cout << date;
	return 0;
}

istream& operator >> (istream& is, Calendar& a){
	cout << "Nhap vao ngay thang nam:\n";
	do{
	cout << "Nhap ngay: ";
	is >> a.day;
	cout << "Nhap thang: ";
	is >> a.month;
	cout << "Nhap nam: ";
	is >> a.year;
	if(a.isValidDate(a.day, a.month, a.year) == false)
		cout << "\nNgay thang nam khong hop le, vui long nhap lai.\n\n";
	} while(a.isValidDate(a.day, a.month, a.year) == false);
	return is;
}

ostream& operator <<(ostream& os, Calendar& a){
	os << "\nNgay tiep theo la: ";
	os << a.getDay() << "/" << a.getMonth() << "/" << a.getYear() << "\n";
	return os;
}

bool Calendar::isLeapYear(int year){
    return (((year%4 == 0) && (year % 100 != 0)) || (year%400 == 0));
}

void Calendar::NextDay(){
	int daysInMonth;
	if(month == 2){
		if(isLeapYear(year))
			daysInMonth = 29;
		else daysInMonth = 28;
	}
	else if(month == 4 || month == 6 || month == 9 || month == 11)
		daysInMonth = 30;
	else daysInMonth = 31;

	if(day == daysInMonth){
		day = 1;
		if (month == 12){
			month = 1;
			year++;
		}
		else month++;
	}
	else day++;
}

bool Calendar::isValidDate(int& day, int& month, int& year) {
    if (year < 0) {
        return false;
    }
    if (month < 1 || month > 12) {
        return false;
    }
    int daysInMonth;
    if (month == 2) {
        if (isLeapYear(year)) {
            daysInMonth = 29;
        } else {
            daysInMonth = 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    } else {
        daysInMonth = 31;
    }
    if (day < 1 || day > daysInMonth) {
        return false;
    }
    return true;
}