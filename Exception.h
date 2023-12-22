#pragma once
#pragma once
#include <string>

class LongLongError : public std::exception {
private:
	std::string error;
public:
	LongLongError() noexcept;
	const char* what() const noexcept override;
};

class RationalError : public std::exception {
private:
	std::string error;
public:
	RationalError() noexcept;
	const char* what() const noexcept override;
};
