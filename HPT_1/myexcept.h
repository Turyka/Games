#pragma once

#include <exception>
#include <string>

class tulcimzesException : public std::exception {
	std::string uzenet;
public:
	tulcimzesException(std::string _uzenet) : uzenet(_uzenet), exception() {}

	virtual const char* what() const noexcept {
		return uzenet.c_str();
	}
};