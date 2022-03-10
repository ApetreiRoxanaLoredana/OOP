#pragma once
#include <string>
using std::string;

class Exception
{
private:
	string message;

public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="message">string</param>
	Exception(const string& message) : message{ message } {};

	/// <summary>
	/// Returneaza mesajul de eroare
	/// </summary>
	/// <returns>string</returns>
	const string& get_message() const;
};

class ValidatorException: public Exception
{

public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="message">string</param>
	ValidatorException(string message) : Exception(message) {};
};

class RepoException : public Exception
{

public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="message">string</param>
	RepoException(string message) : Exception(message) {};
};


