#include "exceptions.hpp"

Exceptions::Exceptions(ExceptionError exception) {
	switch (exception)
	{
	case Exceptions::loadTextureFailure:
		message = "Error loading texture";
		break;
	case Exceptions::windowFailure:
		message = "Window could not be loaded";
		break;
	default:
		break;
	}
}

char* Exceptions::what() {
	return (char*)message.c_str();
}