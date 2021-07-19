#include "EngineException.h"
#include <sstream>


EngineException::EngineException(int line, const char* file) noexcept
	:
	line(line),
	file(file)
{}

const char* EngineException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* EngineException::GetType() const noexcept
{
	return "n3u2o Engine Exception";
}

std::string EngineException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << std::endl
		<< "[Line] " << line;
	return oss.str();
}