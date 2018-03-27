#include "DATE1.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int dia,mes,ano;		
	CDate d1(25, 12, 2005), d2(25, 12), d3(25), d4, d5, d6(2,2,1999);
			d1.print(); // imprime: 25/12/2005
			d2.print(); // imprime: 25/12/1970
			d3.print(); // imprime: 25/1/1970
			d4.print(); // imprime: 1/1/1970
	
	if (d1==d2) cout<<endl<<" d1 e d2 sao iguais"<<endl;
	else cout<<endl<<"d1 e d2 sao diferentes"<<endl;	
	
	cout << endl << endl << "Diferenca datas:" <<endl;	
	cout << d6 << " - " << d1 << " = " << d6.difDate(d1) << " dias"  << endl;	
	cout << d1 << " - " << d2 << " = " << d1.difDate(d2) << " dias"  << endl;	
	cout << d2 << " - " << d3 << " = " << d2.difDate(d3) << " dias"  << endl;	
	
	cout<<d6;
	
	//cout << endl << "Somar e Incrementar datas:" << endl;	
	//cout << d1 << " + 365 = " << d1+365 << endl; 
    //cout << d6 << "++ = " << ++d6 << endl;
    //cout << d5 << "++ = " << ++d5 << endl;
    //cout << d4 << "++ = " << ++d4 << endl; 

	cout<<endl;		
	cout<<"Dia: ";
	cin>>dia;
	cout<<"Mes: ";
	cin>>mes;
	cout<<"Ano: ";
	cin>>ano;
	
	d5.setDate(dia,mes,ano);
	d5.print();
		
	return 0;
}
