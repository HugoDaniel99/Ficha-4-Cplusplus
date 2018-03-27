#include "DATE1.h"

CDate::CDate(int dia, int mes, int ano){
	day=dia;
	month=mes;
	year=ano;
	
	//Também se podia fazer:
   //setDate(d, m, a);
}
CDate::~CDate(){}

void CDate::print() const{
	cout<<day<<"/"<<month<<"/"<<year<<endl;
}

void CDate::setDate(int d,int m,int a){

	if( (d>=1) && ( d<=checkDay() ))
		day=d;
	
	if(m>=1 && m<=12)
		month=m;
	
	if(a>=1970)
	year=a;
}

int CDate::checkDay(){
		if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
			return 31;
		else if (month==4 || month==6 || month==9 || month==11)
			return 30;
		else if (month==2){
			if((year/4==0 && year/100!=0) || year/400==0)
			return 29;
			else 
			return 28;
		}
}

bool CDate::operator== (const CDate& rhs){
	return (day==rhs.day && month==rhs.month && year==rhs.year);
}

ostream& operator<< (ostream& os, CDate &d){
 os << d.day << '/' << d.month << '/' << d.year;  
    return os;  
}

// Operator usando ctime struct tm:
//CDate& CDate::operator+ (const int nd)
//{
  //  tm t = {};
  //  t.tm_year = year - 1900; //Anos em tm começam em 1900
  //  t.tm_mon  = month - 1;    //Meses em tm começam com 0 e não 1
  //  t.tm_mday = day + nd;
  //  mktime(&t);    
//	CDate d(t.tm_mday, t.tm_mon+1, t.tm_year+1900);
//	cout << asctime(&t) << " - " << d << endl << endl;
//	return d;
//}

// Operator usando ctime struct tm:
//CDate& CDate::operator++()
//{
  //  tm t = {};
  //  t.tm_year = year - 1900;  //Anos em tm começam em 1900
  //  t.tm_mon  = month - 1;	 //Meses em tm começam com 0 e não 1
  //  t.tm_mday = ++day;
  //  mktime(&t); 
  //  day= t.tm_mday; month=t.tm_mon+1; year = t.tm_year+1900;
	//cout << asctime(&t) << " - " << *this << endl << endl;
//    return *this;
//}

int CDate::difDate(CDate d2)
{
	int jDate1, jDate2, difDays;
	// Converte a data em valor númerico
	jDate1 = (1461 * (year + 4800 + (month - 14)/12))/4 +(367 * (month - 2 - 12 * ((month - 14)/12)))/12 - (3 * ((year + 4900 + (month - 14)/12)/100))/4 + day - 32075;
	jDate2 = (1461 * (d2.year + 4800 + (d2.month - 14)/12))/4 +(367 * (d2.month - 2 - 12 * ((d2.month - 14)/12)))/12 - (3 * ((d2.year + 4900 + (d2.month - 14)/12)/100))/4 + d2.day - 32075;
	// Calcula a diferença entre dois números
	difDays = jDate1 - jDate2;
	return difDays;
}
