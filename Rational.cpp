#include "Rational.h"

ulong Rational::count = 0;




Rational::Rational(const LongLong& num, const LongLong& num2) : a(num), b(num2) {
	LongLong zero(0, 0);
	if (b == zero) throw RationalError();
	reduce();
	++count;
}

Rational::Rational(const Rational& num) noexcept : a(num.a), b(num.b) {
	++count;
}

ulong Rational::getcount() {
	return count;
}

void Rational::reduce() noexcept {
	LongLong c = a.nod(b);
	a = a / c;
	b = b / c;
}


bool Rational::operator == (const Rational& num) noexcept {
	return (a == num.a && b == num.b);
}

bool Rational::operator > (const Rational& num) noexcept {
	return (a * num.b > b * num.a);
}

bool Rational::operator < (const Rational& num) noexcept {
	return (a * num.b < b* num.a);
}

Rational Rational::operator + (const Rational& num) noexcept {
	Rational num2(a * num.b + b * num.a, b * num.b);
	return num2;
}

Rational Rational::operator - (const Rational& num) noexcept {
	Rational num2(a * num.b - b * num.a, b * num.b);
	return num2;
}

Rational Rational::operator * (const Rational& num) noexcept {
	Rational num2(a * num.a, b * num.b);
	return num2;
}

Rational Rational::operator / (const Rational& num) {
	LongLong zero(0, 0);
	if (num.a == zero) throw RationalError();
	Rational num2(a * num.b, b * num.a);
	return num2;
}

std::ostream& operator << (std::ostream& out, const Rational& num) noexcept {
	out << num.a << " / " << num.b;
	return out;
}

void Rational::generate() noexcept {
	Rational Num;
	*this = Num;
}
