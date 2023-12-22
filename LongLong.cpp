#include "LongLong.h"

ulong LongLong::count = 0;

LongLong::LongLong() noexcept {
	a = 100 + rand() % 900;
	b = 100 + rand() % 900;
	bmax = 1;
	while (b >= bmax)
		bmax *= 10;
	++count;
}

LongLong::LongLong(long num, ulong num2) noexcept : a(num), b(num2) {
	bmax = 1;
	while (b >= bmax)
		bmax *= 10;
	++count;
}

LongLong::LongLong(const LongLong& num) noexcept : a(num.a), b(num.b), bmax(num.bmax) {
	++count;
}

ulong LongLong::getcount() { //!!! Почему метод не константный(потому что ulong static, то const не надо)
	return count;
}

LongLong& LongLong::operator=(const LongLong& num) noexcept {
	// Проверка на самоприсваивание
	if (this == &num) {
		return *this;
	}

	// Копирование значений из переданного объекта
	a = num.a;
	b = num.b;
	bmax = num.bmax;
	return *this;
}


bool LongLong::operator == (const LongLong& num) const noexcept {
	return (a == num.a && b == num.b);
}

bool LongLong::operator != (const LongLong& num) const noexcept {
	return (a != num.a || b != num.b);
}

bool LongLong::operator > (const LongLong& num) const noexcept {
	return (a > num.a || (a == num.a && b > num.b));
}

bool LongLong::operator < (const LongLong& num) const noexcept {
	return (a < num.a || (a == num.a && b < num.b));
}

const LongLong& LongLong::operator + () const noexcept {
	return *this;
}

LongLong LongLong::operator - () const noexcept {
	LongLong res(-a, b);
	return res;
}

LongLong LongLong::operator + (const LongLong& number) const noexcept {
	if (a < 0 && number.a < 0) {
		LongLong num(-a, b);
		LongLong num2(-number.a, number.b);
		return -(num + num2);
	}
	else {
		if (a < 0) {
			LongLong num(-a, b);
			return number - num;
		}
		if (number.a < 0) {
			LongLong num(-number.a, number.b);
			return *this - num;
		}
	}
	LongLong res;
	res.a = a + number.a;
	res.b = b + number.b;
	while (res.b > bmax) {
		++res.a;
		res.b -= bmax;
	}
	res.bmax = bmax;
	return res;
}

LongLong LongLong::operator-(const LongLong& number) const noexcept {
	if (a < 0 && number.a < 0) {
		LongLong num(-number.a, number.b);
		LongLong num2(-a, b);
		return num - num2;
	}
	else {
		if (a < 0) {
			LongLong num(-a, b);
			return -(num + number);
		}
		if (number.a < 0) {
			LongLong num(-number.a, number.b);
			return *this + num;
		}
	}
	LongLong res;
	if (a > number.a) {
		res.a = a - number.a;
		long x = b - number.b;
		while (x < 0) {
			--res.a;
			x += bmax;
		}
		res.b = x;
		res.bmax = bmax;
	}
	else {
		res.a = a - number.a;
		long x = number.b - b;
		while (x < 0) {
			--res.a;
			x += bmax;
		}
		res.b = x;
		res.bmax = bmax;
	}
	return res;
}

LongLong LongLong::operator * (const LongLong& number) const noexcept {
	short sign = sgn(a) * sgn(number.a);
	LongLong num(*this);
	num.a = abs(num.a);
	LongLong num2(number);
	num2.a = abs(num2.a);
	LongLong res(num.a * num2.a * bmax + num.a * num2.b + b * num2.a, b + num2.b);
	res.a *= sign;
	return res;
}

LongLong LongLong::operator / (const LongLong& number) const {
	if (number.a == 0 && number.b == 0) throw LongLongError();
	short sign = sgn(a) * sgn(number.a);
	LongLong num(*this);
	num.a = abs(num.a);
	LongLong num2(number);
	num2.a = abs(num2.a);
	LongLong res((num.a + num.b / bmax) / (num2.a + num2.b / num2.bmax), 0);
	res.a *= sign;
	return res;
}

std::ostream& operator << (std::ostream& out, const LongLong& num) noexcept {
	if (num.a == 0 && num.b == 0)
		out << 0;
	else {
		if (num.a == 0)
			out << num.b;
		if (num.b == 0)
			out << num.a;
		if (num.a != 0 && num.b != 0)
			out << num.a << num.b;
	}
	return out;
}

LongLong LongLong::nod(const LongLong& number) {
	short sign = sgn(a) * sgn(number.a);
	LongLong c(*this);
	c.a = abs(c.a);
	LongLong d(number);
	d.a = abs(d.a);
	while (c != d && c.a > 0 && d.a > 0) {
		if (c > d)
			c = c - d;
		else
			d = d - c;
	}
	if (c.a <= 0) {
		d.a *= sign;
		return d;
	}
	c.a *= sign;
	return c;
}
