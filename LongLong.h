#pragma once
#include <iostream>
#include <ctime>
#include "Exception.h"
#define sgn(x) ((x > 0) ? 1 : (x < 0) ? -1 : 0)
using ulong = unsigned long;

class LongLong {
private:
	long a;
	ulong b, bmax;
	static ulong count;
public:
	LongLong() noexcept;
	LongLong(long num, ulong num2) noexcept;
	LongLong(const LongLong& num) noexcept;
	~LongLong() noexcept {}

	static ulong getcount();

	LongLong& operator=(const LongLong& num) noexcept;

	bool operator == (const LongLong& num) const noexcept;
	bool operator != (const LongLong& num) const noexcept;
	bool operator > (const LongLong& num) const noexcept;
	bool operator < (const LongLong& num) const noexcept;

	const LongLong& operator + () const noexcept;
	LongLong operator - () const noexcept;

	LongLong operator + (const LongLong& num) const noexcept;
	LongLong operator - (const LongLong& num) const noexcept;
	LongLong operator * (const LongLong& num) const noexcept;
	LongLong operator / (const LongLong& num) const;

	friend std::ostream& operator << (std::ostream& out, const LongLong& num) noexcept;
	LongLong nod(const LongLong& Num);
};
