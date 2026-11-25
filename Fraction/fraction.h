#ifndef fraction_h
#define fraction_h
#include <iostream>
class Fraction
{
private:
    int num;
    int denum;
    void reduce();
    int my_gcd(int, int);

public:
    // Fraction ();
    Fraction(int = 0, int = 1);
    Fraction(const Fraction &);
    ~Fraction() = default;
    int get_num() const;
    int get_denum() const;
    void set_num(int);
    void set_denum(int);
    Fraction &operator=(const Fraction &);
    Fraction operator++(int);
    Fraction &operator++();
    Fraction &operator+(const Fraction &);
    friend std::ostream &operator<<(std::ostream &, const Fraction &);
};
#endif
