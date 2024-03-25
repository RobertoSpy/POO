#include "Math.h"
#include <stdarg.h>
#include <cstring>
#include <cstdio>
#include<cstdlib>

int Math::Add(int a, int b)
{
    return a + b;
}

int Math::Add(int a, int b, int c)
{
    return a + b + c;
}

int Math::Add(double a, double b)
{
    return static_cast<int>(a + b);
}

int Math::Add(double a, double b, double c)
{
    return static_cast<int>(a + b + c);
}

int Math::Mul(int a, int b)
{
    return a * b;
}

int Math::Mul(int a, int b, int c)
{
    return a * b * c;
}

int Math::Mul(double a, double b)
{
    return static_cast<int>(a * b);
}

int Math::Mul(double a, double b, double c)
{
    return static_cast<int>(a * b * c);
}

int Math::Add(int count, ...)
{
    va_list args;
    va_start(args, count);
    int sum = 0;
    for (int i = 0; i < count; ++i)
    {
        sum += va_arg(args, int);
    }
    va_end(args);
    return sum;
}

char* Math::Add(const char* a, const char* b)
{
    int sir1 = atoi(a);
    int sir2 = atoi(b);
    int sum = sir1 + sir2;

    char* rez = new char[30];
    sprintf(rez, "%d", sum);
    return rez;
}
