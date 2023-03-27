#include<function/function.h>

#include <stdexcept>

using namespace function;
using namespace std;


Function_List::Function_List() : _size(0) { }

int Function_List::get_size() const {
	return _size;
}

Function Function_List::operator[] (const int index) const{
	if (index < 0 || _size <= index) {
		throw out_of_range("[FunctionList::operator[]] Index is out of range.");
	}
	return data[index];
}
void Function_List::add(const Function f) {
	if (_size == capacity) {
		throw runtime_error("[FunctionList::add] Capacity is reached.");
	}

	data[_size] = f;
	++_size;
}


void Function_List::insert(int index, Function function) {
	if ((index < 0) || (index > capacity) || (_size == capacity)) {
		throw out_of_range("[FigureList::operator[]] Index is out of range.");
	}
	
	for (int i = _size - 1; i >= index; i--) 
	{
		data[i + 1] = data[i];
	}
	data[index] = function;
	++_size;
}

void Function_List::remove(int index) {
	if ((index < 0) || (index >= _size)) {
		throw out_of_range("[FigureList::operator[]] Index is out of range.");
	}
	for (int i = index; i < _size - 1; i++) {
		data[i] = data[i + 1];
	}
	--_size;
}

int function::index_of_min_value(const Function_List& sequence, int x) {
	int min_index = -1;
	int min_value = 0;

	const auto size = sequence.get_size();
	for (int i = 0; i < size; ++i) {
		const auto value = sequence[i].create_fun(x);
		if (min_index == -1 || value <= min_value) {
			min_index = i;
			min_value = value;
		}
	}

	return min_index;
}