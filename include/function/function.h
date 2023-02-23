#pragma once

namespace functions {

    enum class Typeoffun {
        fack,
        sqrc
    };


    class Function {
    private:
        Typeoffun _type;
        int a;

    public:
        Function(Typeoffun type, int a);
        {
            _type = sqrc;
            a = a;

        };

        Function(Typeoffun type);
        {
            _type = fack;
            a = 0;
        };

        static Function create_fack(int a);
        static Function create_sqrc(int a);
        Function();

        Typeoffun get_type() const;

        int get_a() const;

        int create_value(int n) const;
    };

    const int CAPACITY = 5;

    class Function_List {
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