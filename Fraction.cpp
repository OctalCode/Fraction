#include <iostream>

using namespace std;

class Fraction {
private:

    int num, den;

    static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    static int lcm(int a, int b) {
        return a * b / gcd(a, b);
    }

    void reduce() {
        int Gcd = gcd(num, den);
        if (Gcd != 1) {
            num /= Gcd, den /= Gcd;
        }
        if (den < 0) {
            num *= -1, den *= -1;
        }
    }

    static double GetFraction(const Fraction &fraction) {
        return (double) fraction.num / (double) fraction.den;
    }

public:
    Fraction() {
        num = 0, den = 1;
    }

    Fraction(int num, int den) {
        this->num = num;
        this->den = den;
        reduce();
    }

    Fraction(int num) {
        this->num = num;
        this->den = 1;
    }

    friend istream& operator>>(istream &input, Fraction &in) {
        char middle;
        input >> in.num >> middle >> in.den;
        return input;
    }

    friend ostream& operator<<(ostream &output, const Fraction &out) {
        output << out.num << '/' << out.den;
        return output;
    }

    friend Fraction operator+(const Fraction &fraction1, const Fraction &fraction2) {
        Fraction ans;
        if (fraction1.den != fraction2.den) {
            int NewDen = lcm(fraction1.den, fraction2.den);
            ans = Fraction(fraction1.num * (NewDen / fraction1.den) + fraction2.num * (NewDen / fraction2.den), NewDen);
        } else {
            ans = Fraction(fraction1.num + fraction2.num, fraction1.den);
        }
        ans.reduce();
        return ans;
    }

    friend Fraction operator+(const Fraction &fraction1, const int &fraction2) {
        return fraction1 + Fraction(fraction2);
    }

    friend Fraction operator+(const int &fraction1, const Fraction &fraction2) {
        return fraction2 + fraction1;
    }

    friend double operator+(const Fraction &fraction1, const double &fraction2) {
        return GetFraction(fraction1) + fraction2;
    }

    friend double operator+(const double &fraction1, const Fraction &fraction2) {
        return fraction2 + fraction1;
    }

    friend Fraction operator-(const Fraction &fraction1, const Fraction &fraction2) {
        Fraction ans;
        if (fraction1.den != fraction2.den) {
            int NewDen = lcm(fraction1.den, fraction2.den);
            ans = Fraction(fraction1.num * (NewDen / fraction1.den) - fraction2.num * (NewDen / fraction2.den), NewDen);
        } else {
            ans = Fraction(fraction1.num + fraction2.num, fraction1.den);
        }
        ans.reduce();
        return ans;
    }

    friend Fraction operator-(const Fraction &fraction1, const int &fraction2) {
        return fraction1 - Fraction(fraction2);
    }

    friend Fraction operator-(const int &fraction1, const Fraction &fraction2) {
        return Fraction(fraction1) - fraction2;
    }

    friend double operator-(const Fraction &fraction1, const double &fraction2) {
        return GetFraction(fraction1) - fraction2;
    }

    friend double operator-(const double &fraction1, const Fraction &fraction2) {
        return fraction1 - GetFraction(fraction2);
    }

    friend Fraction operator*(const Fraction &fraction1, const Fraction &fraction2) {
        Fraction ans;
        ans = Fraction(fraction1.num * fraction2.num, fraction1.den * fraction2.den);
        ans.reduce();
        return ans;
    }

    friend Fraction operator*(const Fraction &fraction1, const int &fraction2) {
        return fraction1 * Fraction(fraction2);
    }

    friend Fraction operator*(const int &fraction1, const Fraction &fraction2) {
        return fraction2 * fraction1;
    }

    friend double operator*(const Fraction &fraction1, const double &fraction2) {
        return GetFraction(fraction1) * fraction2;
    }

    friend double operator*(const double &fraction1, const Fraction &fraction2) {
        return fraction2 * fraction1;
    }

    friend Fraction operator/(const Fraction &fraction1, const Fraction &fraction2) {
        Fraction ans;
        ans = Fraction(fraction1.num * fraction2.den, fraction1.den * fraction2.num);
        ans.reduce();
        return ans;
    }

    friend Fraction operator/(const Fraction &fraction1, const int &fraction2) {
        return fraction1 / Fraction(fraction2);
    }

    friend Fraction operator/(const int &fraction1, const Fraction &fraction2) {
        return Fraction(fraction1) / fraction2;
    }

    friend double operator/(const Fraction &fraction1, const double &fraction2) {
        return GetFraction(fraction1) / fraction2;
    }

    friend double operator/(const double &fraction1, const Fraction &fraction2) {
        return fraction1 / GetFraction(fraction2);
    }

    friend bool operator==(const Fraction &fraction1, const Fraction &fraction2) {
        return (fraction1.num == fraction2.num && fraction1.den == fraction2.den);
    }

    friend bool operator==(const Fraction &fraction1, const int &fraction2) {
        return (fraction1 == Fraction(fraction2));
    }

    friend bool operator==(const int &fraction1, const Fraction &fraction2) {
        return (Fraction(fraction1) == fraction2);
    }

    friend bool operator==(const Fraction &fraction1, const double &fraction2) {
        return (abs(GetFraction(fraction1) - fraction2) < (double) (-1e9));
    }

    friend bool operator==(const double &fraction1, const Fraction &fraction2) {
        return (fraction2 == fraction1);
    }

    friend bool operator<(const Fraction &fraction1, const Fraction &fraction2) {
        int NewDen = lcm(fraction1.den, fraction2.den);
        return (fraction1.num * (NewDen / fraction1.den) < fraction2.num * (NewDen / fraction2.den));
    }

    friend bool operator<(const Fraction &fraction1, const int &fraction2) {
        return (fraction1 < Fraction(fraction2));
    }

    friend bool operator<(const int &fraction1, const Fraction &fraction2) {
        return (Fraction(fraction1) < fraction2);
    }

    friend bool operator<(const Fraction &fraction1, const double &fraction2) {
        return ((fraction2 - GetFraction(fraction1)) >= (double) (-1e9));
    }

    friend bool operator<(const double &fraction1, const Fraction &fraction2) {
        return ((GetFraction(fraction2) - fraction1) >= (double) (-1e9));
    }

    friend bool operator<=(const Fraction &fraction1, const Fraction &fraction2) {
        return ((fraction1 < fraction2) || (fraction1 == fraction2));
    }

    friend bool operator<=(const Fraction &fraction1, const int &fraction2) {
        return ((fraction1 < fraction2) || (fraction1 == fraction2));
    }

    friend bool operator<=(const int &fraction1, const Fraction &fraction2) {
        return ((fraction1 < fraction2) || (fraction1 == fraction2));
    }

    friend bool operator<=(const Fraction &fraction1, const double &fraction2) {
        return ((fraction1 < fraction2) || (fraction1 == fraction2));
    }

    friend bool operator<=(const double &fraction1, const Fraction &fraction2) {
        return ((fraction1 < fraction2) || (fraction1 == fraction2));
    }

    friend bool operator>(const Fraction &fraction1, const Fraction &fraction2) {
        return (!(fraction1 <= fraction2));
    }

    friend bool operator>(const Fraction &fraction1, const int &fraction2) {
        return (!(fraction1 <= fraction2));
    }

    friend bool operator>(const int &fraction1, const Fraction &fraction2) {
        return (!(fraction1 <= fraction2));
    }

    friend bool operator>(const Fraction &fraction1, const double &fraction2) {
        return (!(fraction1 <= fraction2));
    }

    friend bool operator>(const double &fraction1, const Fraction &fraction2) {
        return (!(fraction1 <= fraction2));
    }

    friend bool operator>=(const Fraction &fraction1, const Fraction &fraction2) {
        return (!(fraction1 < fraction2));
    }

    friend bool operator>=(const Fraction &fraction1, const int &fraction2) {
        return (!(fraction1 < fraction2));
    }

    friend bool operator>=(const int &fraction1, const Fraction &fraction2) {
        return (!(fraction1 < fraction2));
    }

    friend bool operator>=(const Fraction &fraction1, const double &fraction2) {
        return (!(fraction1 < fraction2));
    }

    friend bool operator>=(const double &fraction1, const Fraction &fraction2) {
        return (!(fraction1 < fraction2));
    }

    friend bool operator!=(const Fraction &fraction1, const Fraction &fraction2) {
        return (!(fraction1 == fraction2));
    }

    friend bool operator!=(const Fraction &fraction1, const int &fraction2) {
        return (!(fraction1 == fraction2));
    }

    friend bool operator!=(const int &fraction1, const Fraction &fraction2) {
        return (!(fraction1 == fraction2));
    }

    friend bool operator!=(const Fraction &fraction1, const double &fraction2) {
        return (!(fraction1 == fraction2));
    }

    friend bool operator!=(const double &fraction1, const Fraction &fraction2) {
        return (!(fraction1 == fraction2));
    }

    friend Fraction &operator+=(Fraction &fraction1, Fraction fraction2) {
        fraction1 = fraction1 + fraction2;
        fraction1.reduce();
        return fraction1;
    }

    friend Fraction &operator+=(Fraction &fraction1, const int &fraction2) {
        fraction1 = fraction1 + fraction2;
        fraction1.reduce();
        return fraction1;
    }

    friend Fraction &operator-=(Fraction &fraction1, const Fraction &fraction2) {
        fraction1 = fraction1 - fraction2;
        fraction1.reduce();
        return fraction1;
    }

    friend Fraction &operator-=(Fraction &fraction1, const int &fraction2) {
        fraction1 = fraction1 - fraction2;
        fraction1.reduce();
        return fraction1;
    }

    friend Fraction &operator*=(Fraction &fraction1, const Fraction &fraction2) {
        fraction1 = fraction1 * fraction2;
        fraction1.reduce();
        return fraction1;
    }

    friend Fraction &operator*=(Fraction &fraction1, const int &fraction2) {
        fraction1 = fraction1 * fraction2;
        fraction1.reduce();
        return fraction1;
    }

    friend Fraction &operator/=(Fraction &fraction1, const Fraction &fraction2) {
        fraction1 = fraction1 / fraction2;
        fraction1.reduce();
        return fraction1;
    }

    friend Fraction &operator/=(Fraction &fraction1, const int &fraction2) {
        fraction1 = fraction1 / fraction2;
        fraction1.reduce();
        return fraction1;
    }
};

int main() {
    // do something
    return 0;
}
