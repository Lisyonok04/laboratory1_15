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

void PrintList(Function_List& arr) {
	system("cls");
	if (arr.get_size() == 0)
		cout << "Массив последовательностей пуст";
	for (int i = 0; i < arr.get_size(); ++i) {
		cout << "[" << i + 1 << "]\t" << arr[i] << endl;
	}
	cout << endl;
	cout << "Для продолжения нажмите любую кнопку ";
	get_key();
}

Type InputType() {
	string types[] = { "SEQUENCE", "FACTORIAL" };
	Type ctypes[] = { Type::sqrc, Type::fack };
	int choose = 0;
	int flag = true;
	system("cls");
	while (flag) {
		cout << "Выберите тип последовательности: " << endl;
		cout << "1)" << "Квадрат числа со сдвигом с" << endl;
		cout << "2)" << "Факториал" << endl;
		int seq_type = get_key();
		if (seq_type == 49) { choose = 0; flag = false; }
		else if (seq_type == 50) { choose = 1; flag = false; }
		else { cout << "Номер выбора введен некорректно, попробуйте ещё раз." << endl; }

	}
	return ctypes[choose];
}

void InputShift(Function& fun) {
	int c = 0;
	cout << "Введите целочисленный сдиг с" << endl;
	cin >> c;
	fun.set_c(c);
}

int InputIndex(int size) {
	bool flag = true;
	int index;
	while (flag) {
		cout << "Введите индекс, куда хотите вставить элемент, или -1, если хотите выйти: ";
		cin >> index;
		index--;
		if (cin.fail() || index < -1 || index >= size) {
			std::cin.clear();
			system("cls");
			cout << "Неверно введен индекс или код выхода! Попробуйте еще раз." << endl;
		}
		else {
			flag = false;
		}
	}
	return index;
}

void AddSequence(Function_List& arr) {
	system("cls");
	int index = InputIndex(arr.get_size() + 1);
	if (index != -1) {
		Function seq(InputType());
		Type type = seq.get_type();
		if (type == Type::sqrc) { InputShift(seq); }
		arr.insert(index, seq);
	}
}


void DeletePoint(Function_List& arr) {
	int index = InputIndex(arr.get_size());
	if (index != -1) { arr.remove(index); }
}

void FindMinElement(Function_List& arr) {
	system("cls");
	cout << "Введите n: ";
	int n;
	cin >> n;
	int index = index_of_min_value(arr, n);
	cout << "Последовательностью с минимальным n-ым членом, при n=" << n << " является: " << "[" << index << "]" << " " << arr[index] << endl;
	get_key();
}

void ChangeSequence(Function_List& arr) {
	system("cls");
	int index = InputIndex(arr.get_size());
	if (index != -1) {
		Function seq(InputType());
		Type type = seq.get_type();
		if (type == Type::sqrc) { InputShift(seq); }
		arr[index] = seq;

	}
}

int menu1() {
	cout << "1)" << "Вывести последовательности на экран" << endl;
	cout << "2)" << "Добавить последовательность в массив по индексу" << endl;
	cout << "3)" << "Удалить последовательность из массива по индексу" << endl;
	cout << "4)" << "Вывести последовательность с минимальным n-ым членом" << endl;
	cout << "5)" << "Заменить последовательность из массива по индексу" << endl;
	cout << "6)" << "Выход" << endl;

	while (true) {
		int key = get_key();
		if ((key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 54)) return key;
	}
}




int main() {
	setlocale(LC_ALL, "Russian");
	Function_List array;
	while (true) {
		system("cls");
		printf("Меню\n");
		int m1 = menu1();
		if (m1 == 49) { PrintList(array); };
		if (m1 == 50) { system("cls"); AddSequence(array); }
		if (m1 == 51) { DeletePoint(array); }
		if (m1 == 52) { FindMinElement(array); };
		if (m1 == 53) { ChangeSequence(array); };
		if (m1 == 54) break;
	}
	return 0;
}