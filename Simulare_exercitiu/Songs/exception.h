#pragma once
#include <string>
using std::string;

class My_exception
{
private:
	string message;

public:

	My_exception(const string message) : message{ message } {};

	const string& get_message() const;
};

class ValidatorException : public My_exception
{
public:
	ValidatorException(const string message) : My_exception(message) {};
};

class RepoException : public My_exception
{
public:
	RepoException(const string message) : My_exception(message) {};
};
