#include "Exception.h"

const string& MyException::get_message() const noexcept
{
    return message;
}
