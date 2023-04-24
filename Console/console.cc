#include <function/function.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include <locale.h>

using namespace function;
using namespace std; 


int get_key() {
	int key = _getch();
	if ((key == 0) || (key == 224)) key = _getch();
	return key;
}
