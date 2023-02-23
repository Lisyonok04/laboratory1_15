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

long double fact(int n)
{
    if(n < 0) 
        return 0; 
    if (n == 0) 
        return 1; 
    else 
        return n * fact(n - 1); 
};
long double sqr(int n, float c)
{
	return (n*n + c)
}
long double min(int n)
{
	
}