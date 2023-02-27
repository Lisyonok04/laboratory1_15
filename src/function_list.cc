#include<function/function.h>

#include <stdexcept>

using namespace function;
using namespace std;


Function_List::Function_List() : _size(0) { }

int Function_List::size() const {
	return _size;
}

Function Function_List::operator[] (const int index) const{
	if (index < 0 || _size <= index) {
		throw out_of_range("[FunctionList::operator[]] Index is out of range.");
	}
	return data[index];
}
void Function_List::add(const Function f) {
	if (_size == CAPACITY) {
		throw runtime_error("[FunctionList::add] Capacity is reached.");
	}

	data[_size] = f;
	++_size;
}

void Function_List::insert(int index, const Function f) {
	if (_size == CAPACITY) {
		throw runtime_error("[FunctionList::add] Capacity is reached.");
	}
	this -> data[index]._type = f._type;
	this -> data[index]._c = f._c;
}

void Function_List::remove(int index) {

}

/*int Function_List::index_of_min_value(const Function_List& functions, int n) {
	int min_index = -1;
	int min_value = 10000;
	const auto n = functions.size();
	for (int i = 0; i < n; i++) {
		const auto value = functions[i].create_fun(i, _c);
		if 
	}
	return min_index;
}*/