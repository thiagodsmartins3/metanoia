#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>
#include <string>

class Exceptions : public std::exception {
public:
	enum ExceptionError {
		loadTextureFailure,
		windowFailure,
	};

	Exceptions(ExceptionError exception);
	char* what();

private:
	std::string message;
};

#endif