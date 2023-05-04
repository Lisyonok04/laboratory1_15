#pragma once
#include <string>
#include <iostream>
#include <cstdio>
namespace function {

    enum class Type {
        fack,
        sqrc
    };


    class Function {
    private:
        Type _type;
        int _c;

    public:
        static Function create_fack();
        static Function create_sqrc(const int c);
        Function();
        Function(Type type);
        Function(Type type, int c);

        Type get_type() const;

        int get_c() const;
        int set_c(int c);
        int create_fun(int n);
        friend std::ostream& operator<<(std::ostream& out, const Type& type);
    };

    inline std::ostream& function::operator<<(std::ostream& out, const Type& type) {
        switch (type) {
        case Type::sqrc:
            out << "sqrc";
            return out;
        case Type::fack:
            out << "fack";
            return out;
        }
    }
    bool operator==(const Function& lhs, const Function& rhs);

    bool operator!=(const Function& lhs, const Function& rhs);

    class Function_List {

    private:
        Function** data;
        int _size;

    public:
        int get_size() const;
        void remove(int index);
        void swap(Function_List& arr);
        void insert(int index, Function& s);
        Function_List(const Function_List& arr);
        Function_List() : _size(0), data(nullptr) {};
        Function_List(int size);
        ~Function_List();
        Function& operator[](int index);
        Function operator[](int index) const;
        Function_List& operator=(Function_List arr);
        friend std::ostream& operator<<(std::ostream& out, const Function& seq);
    };

    int index_of_min_value(const Function_List& functions, int n);

    inline std::ostream& function::operator<<(std::ostream& out, const Function& seq) {
        int s = seq.get_c();
        if (seq.get_type() == Type::sqrc) { out << "Type: " << seq.get_type() << " " << "Shift: " << s; }
        else(out << "Type: " << seq.get_type());
        return out;
    }

}