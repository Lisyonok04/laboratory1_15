#pragma once

namespace function {

    enum class Type {
        fack,
        sqrc
    };


    class Function {
    private:
        Type _type;
        int c;

    public:
        static Function create_fack();
        static Function create_sqrc(int c);
        Function();

        Type get_type() const;

        int get_c() const;

        int create_value(int n) const;
    };

    bool operator==(const Function& lhs, const Function& rhs);

    bool operator!=(const Function& lhs, const Function& rhs);

    class Function_List {
    public:
        static const int CAPACITY = 5;

    private:
        Function data[CAPACITY];
        int _size;

    public:
        Function_List();
        int size() const;

        Function operator[](int index) const;

        void insert(int index, Function x);

        void remove(int index);

    };

    int index_of_min_value(const Function_List& functions, int n);
}