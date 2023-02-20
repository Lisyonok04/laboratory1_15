#pragma once

namespace functions {

    enum class Type {
        fack,
        Sqrc
    };



    class Function {
    private:
        Type _type;
        float _a;
        int n;

        Function(Type type, float a, int n);
