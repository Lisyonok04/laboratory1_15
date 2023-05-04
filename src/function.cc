#include <function/function.h>

#include <cassert>
#include <cmath>
#include <cstdio>
#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace function;
using namespace std;

Function Function::create_sqrc(const int c) {
    return Function(Type::sqrc, c);
}

Function Function::create_fack() {
    return Function(Type::fack);
}


Function::Function() 
{
    _type = Type::fack;
    _c = 0;
}

Function::Function(const Type type) 
{
    _type = type;
    _c = 0;
}

Function::Function(const Type type, int c)
{
    _type = type;
    _c = c;
}

Type Function::get_type() const {
    return _type;
}

int Function::set_c(int c) {
    _c = c;
    return 0;
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
    case Type::sqrc:
        return n * n + _c;
        break;
    case Type::fack:
        return factorial(n);
        break;
    default:
        throw runtime_error("[Function::create_fun] Invalid function type.");
    }
}


bool function::operator==(const Function& lhs, const Function& rhs) {
    return
        lhs.get_type() == rhs.get_type() && lhs.get_c() == rhs.get_c();
}

bool function::operator!=(const Function& lhs, const Function& rhs) {
    return !(lhs == rhs);
}

std::ostream& function::operator<<(std::ostream& out, const Function& seq) {
    int s = seq.get_c();
    if (seq.get_type() == Type::sqrc) { out << "Type: " << seq.get_type() << " " << "Shift: " << s; }
    else(out << "Type: " << seq.get_type());
    return out;
}

std::ostream& function::operator<<(std::ostream& out, const Type& type) {
    switch (type) {
    case Type::sqrc:
        out << "sqrc";
        return out;
    case Type::fack:
        out << "fack";
        return out;
    }

}