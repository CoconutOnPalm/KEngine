#ifndef ALGOR_HPP_INCLUDED
#define ALGOR_HPP_INCLUDED

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

#include "RandomGenerator.hpp"
#include "../Data/Data.hpp"

namespace ke
{

class Protect
{
public:

    operator= (const Protect&) = delete;

    static Protect& Get();

    static std::string Encrypt(const std::string& decoded);
    static std::string Decode (const std::string& encrypted);

    static std::wstring Encrypt(const std::wstring& decoded);
    static std::wstring Decode (const std::wstring& encrypted);
};



std::wstring stow(const std::string& str);

template <typename T>
std::wstring to_wstring(const T& n)
{
    ///converts T to wstring

    std::wstringstream stm;
    stm << n;
    return stm.str();
}

template <typename T> int sgn(T val)
{
    ///signum

    return (T(0) < val) - (val < T(0));
}

void throw_error(const std::string& function_name, const std::string& message, const std::string& error_type = "ERROR");

float RTD(float radians);
float DTR(float degrees);

}

#endif // ALGOR_HPP_INCLUDED
