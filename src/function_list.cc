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

void Function_List::insert(int index, Function& function) {
	if ((index < 0) || (index > _size)) {
		throw runtime_error("[FigureList::operator[]] Index is out of range.");
	}
	
	Function** ptr = new Function * [_size + 1];
	for (int i = 0; i <= index; i++) {
		ptr[i] = new Function;
	}

	memcpy(ptr, data, sizeof(Function*) * index);
	*ptr[index] = function;
	memcpy(ptr + index + 1, data + index, sizeof(Function*) * (_size - index));
	++_size;

	delete[] data;
	data = ptr;
	ptr = nullptr;
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