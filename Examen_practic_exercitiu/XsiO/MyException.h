#pragma once
#include <string>
using std::string;

class MyException
{
private:
	string message;

public:
	MyException(const string message) :message{ message } {};

	const string& get_message() const;
};

class ValidatorException : public MyException
{
public:
	ValidatorException(string message) : MyException(message) {};
};

class RepoException : public MyException
{
public:
	RepoException(string message) : MyException(message) {};
};

