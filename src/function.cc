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


Function::Function() : _type(Type::sqrc), _c(1) { }

Function::Function(const Type type) : _type(Type::fack), _c(0) { }

Function::Function(const Type type, const int c) : _type(Type::sqrc), _c(c) { }

Type Function::get_type() const {
    return _type;
}

int Function::get_c() const {
    return _c;
}

int Function::create_fack(int n) {
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    else
        return n * create_fack(n - 1);
};

int Function::create_sqrc(int n, int c) {
    return(n * n + c);
}

/*bool function::operator==(const Function& lhs, const Function& rhs) {
    return
        lhs.get_type() == rhs.get_type() &&
        abs(lhs.get_a() - rhs.get_a()) < EPSILON;
}*/

bool function::operator!=(const Function& lhs, const Function& rhs) {
    return !(lhs == rhs);
}