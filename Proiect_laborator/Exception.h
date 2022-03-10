#pragma once
#include <string>
using std::string;

class MyException
{
public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="message">mesaj de eroare</param>
	MyException(const string message) :message{ message } {};

	/// <summary>
	/// Returneaza mesajul de eroare
	/// </summary>
	/// <returns>m=string</returns>
	const string& get_message() const noexcept;

private:
	string message;
};

class RepoException : public MyException
{
public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="message">mesaj de eroare</param>
	RepoException(string message) :MyException(message) {};
};

class ValidatorException : public MyException
{
public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="message">mesaj de eroare</param>
	ValidatorException(string message) :MyException(message) {};
};

class CosException : public MyException
{
public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="message">mesaj de eroare</param>
	CosException(string message) :MyException(message) {};
};

class ServiceException : public MyException
{
public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="message">mesaj de eroare</param>
	ServiceException(string message) :MyException(message) {};
};
