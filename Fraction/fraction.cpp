#include "fraction.h"

// Fraction::Fraction():Fraction(0,1)
// {

// };
Fraction::Fraction(int num, int denum) //: num(num),denum(denum)
{
    if (denum == 0)
    {
        throw "Denum != 0\n";
    }
    this->num = num;
    this->denum = denum;
    reduce();
};

int Fraction::my_gcd(int a, int b)
{
    int temp = 0;
    if (a < b)
    {
        std::swap(a, b);
    }
    while (b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

void Fraction::reduce()
{
    int gcd = my_gcd(num, denum);
    num /= gcd;
    denum /= gcd;
}

Fraction::Fraction(const Fraction &init)
{
    num = init.num;
    denum = init.denum;
}

int Fraction::get_num() const
{
    return num;
}

int Fraction::get_denum() const
{
    return denum;
}

void Fraction::set_num(int num)
{
    this->num = num;
}

void Fraction::set_denum(int denum)
{
    if (denum == 0)
    {
        throw "Denum != 0\n";
    }
    this->denum = denum;
}

Fraction &Fraction::operator=(const Fraction &rhs)
{
    if (this != &rhs)
    {
        num = rhs.num;
        denum = rhs.denum;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Fraction &rhs)
{
    out << rhs.get_num() << " / " << rhs.denum << '\n';
    return out;
}

Fraction Fraction::operator++(int unused)
{
    Fraction copy(*this);
    num += denum;
    return copy;
}

Fraction &Fraction::operator++()
{
    num += denum;
    return *this;
}

Fraction &Fraction::operator+(const Fraction &frac)
{
}