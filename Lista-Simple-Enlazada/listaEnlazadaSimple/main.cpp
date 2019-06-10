#include <iostream>
#include "lista.h"
#include <regex>
int main() {

	lista* ls = new lista();
	/*ls->insertarInicio(1);
	ls->insertarInicio(2);
	ls->insertarInicio(3);*/
	ls->insertarFinal(1);
	ls->insertarFinal(2);
	ls->insertarFinal(3);
	cout << ls->toString() << endl;
	string num = "123.5h";
	regex integer("^[0-9]+(\.[0-9]+)?$");
	if (regex_match(num, integer))
	 	cout << "Good" << endl;
 	else
	{
		cout << "Invalid input" << endl;
	}


	system("pause");
	return 0;
}