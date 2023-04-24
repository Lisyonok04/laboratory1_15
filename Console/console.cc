#include <iostream>
#include <stdlib.h>
#include <sequence/sequence.h>
#include <string>
#include <conio.h>
#include <locale.h>
using namespace std;
using namespace sequences;


int get_key() {
	int key = _getch();
	if ((key == 0) || (key == 224)) key = _getch();
	return key;
}