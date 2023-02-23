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