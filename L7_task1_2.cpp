#include <iostream>
#include <iomanip>
#include <memory>
using namespace std;

class Date {
 private:
    int day;
    int month;
    int year;
 public:
    Date (int d, int m, int y) : day(d), month(m), year(y) { }
    int getDay () const{return day;}
    int getMonth () const{return month;}
    int getYear () const{return year;}
    friend ostream& operator<< (ostream& os, Date d){
        return os << d.getDay() << '/' <<  d.getMonth() << '/' << d.getYear() << endl;
    }
};

 Date& compare (const unique_ptr <Date>& d1, const unique_ptr <Date>& d2 ){
     if(d1->getYear() > d2->getYear ()) return *d1;
     else if(d1->getYear() < d2->getYear ()) return *d2;
     
     if(d1->getMonth() > d2->getMonth ()) return *d1;
     else if(d1->getMonth() < d2->getMonth ()) return *d2;
     
     if(d1->getDay() > d2->getDay ()) return *d1;
     else if(d1->getDay() < d2->getDay ()) return *d2;
     
 } 
 
 void ptr_swap(unique_ptr <Date>& d1, unique_ptr <Date>& d2) {
     unique_ptr <Date> tmp;
     tmp = move(d1);
     d1 = move(d2);
     d2 = move(tmp);
 }

int main()
{
  unique_ptr<Date> today = make_unique<Date>(2, 8, 2020);
  cout << today->getDay() << endl;
  cout << today->getMonth() << endl;
  cout << today->getYear() << endl;
  cout << *today << endl;
  unique_ptr<Date> date = move(today);
  if(!today) {cout << "today is Nullptr" << endl;}
  if(!date) {cout << "date is Nullptr" << endl;}
  unique_ptr<Date> date1 = make_unique<Date>(2, 8, 2020);
  unique_ptr<Date> date2 = make_unique<Date>(3, 8, 2020);
  cout << compare(date1, date2) << endl;
  ptr_swap(date1, date2);
  cout << *date1 << endl;
  cout << *date2 << endl;

    return 0;
}
