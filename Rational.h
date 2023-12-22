#pragma once
#pragma once
#include "LongLong.h"

class Rational : public LongLong {
private:
	LongLong a, b;
	void reduce() noexcept;
	static ulong count;
public:
	Rational()= default;
	Rational(const LongLong& a, const LongLong& b);
	Rational(const Rational& num) noexcept;
	~Rational() noexcept {}

	static ulong getcount();



	bool operator == (const Rational& num) noexcept;
	bool operator > (const Rational& num) noexcept;
	bool operator < (const Rational& num) noexcept;

	Rational operator + (const Rational& num) noexcept;
	Rational operator - (const Rational& num) noexcept;
	Rational operator * (const Rational& num) noexcept;
	Rational operator / (const Rational& num);

	friend std::ostream& operator << (std::ostream& out, const Rational& num) noexcept;
	void generate() noexcept;
};
