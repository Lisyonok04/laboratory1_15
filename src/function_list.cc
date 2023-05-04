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
		throw std::runtime_error("Index out of range.");
	}

	return *data[index];
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
	Function** ptr = new Function * [_size - 1];
	for (int i = 0; i < _size - 1; i++) {
		ptr[i] = new Function;
	}
	memcpy(ptr, data, sizeof(Function*) * index);
	memcpy(ptr + index, data + index + 1, sizeof(Function*) * (_size - index));
	delete data[index];
	delete[] data;
	data = ptr;
	ptr = nullptr;
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

void Function_List::swap(Function_List& arr) {
	std::swap(_size, arr._size);
	std::swap(data, arr.data);
}

Function_List& ::Function_List::operator=(Function_List arr) {
	this->swap(arr);
	return *this;
}

Function_List::~Function_List() {
	for (int i = 0; i < _size; i++) {
		delete data[i];
	}
	delete[] data;
}
