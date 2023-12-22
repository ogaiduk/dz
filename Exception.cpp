#include "Exception.h"

LongLongError::LongLongError() noexcept : error("Divide by zero") {}

const char* LongLongError::what() const noexcept {
	return error.c_str();
}

RationalError::RationalError() noexcept : error("Divide by zero") {}

const char* RationalError::what() const noexcept {
	return error.c_str();
}
