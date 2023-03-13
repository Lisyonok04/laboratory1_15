#include <function/function.h>

#include <cassert>
#include <cmath>
#include <stdexcept>

using namespace function;
using namespace std;

Function Function::create_sqrc(const int c) {
    return Function(Type::sqrc, c);
}

Function Function::create_fack() {
    return Function(Type::fack);
}


Function::Function() : _type(Type::sqrc), _c(0) { }

Function::Function(const Type type) : _type(type), _c(0) { }

Function::Function(const Type type, int c) 
{
    switch (type) {
    case Type::sqrc:
        //_type = sqrc;
        //_c = c;
        for (int i = 0; i < capacity; i++) {
            sequence[i] = i * i + c;
        }
    case Type::fack:
        //_type = fack;
        //_c = 0;
        for (int i = 0; i < capacity; i++) {
            sequence[i] = factorial(i);
        }
    }
}

Type Function::get_type() const {
    return _type;
}

int Function::get_c() const {
    return _c;
}

int factorial(int n) {
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int Function::create_fun(int n) {
    switch (_type) {
    case Type::fack:
        return factorial(n);
    case Type::sqrc:
        return (n * n + get_c());
    default:
        throw runtime_error("[Function::create_value] Invalid function type.");
    }
}


bool function::operator==(const Function& lhs, const Function& rhs) {
    return
        lhs.get_type() == rhs.get_type() && lhs.get_c() == rhs.get_c();
}

bool function::operator!=(const Function& lhs, const Function& rhs) {
    return !(lhs == rhs);
}