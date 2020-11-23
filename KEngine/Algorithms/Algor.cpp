#include "Algor.hpp"

namespace ke
{

Protect& Protect::Get()
{
    ///returns instance of KEngine Protect class

    static Protect instance;
    return instance;
}


//////////


std::string Protect::Encrypt(const std::string& decoded)
{
    ///Encrypts given string

    int shift_val = Random::Int(1, 128);

    std::string encrypted;
    encrypted += shift_val;

    for (int i = 0; i < decoded.size(); i++)
        encrypted += (decoded[i] + shift_val);

    return encrypted;
}

std::string Protect::Decode(const std::string& encrypted)
{
    ///decodes encrypted string

    int shift_val = encrypted.front();

    std::string decoded;

    for (int i = 1; i < encrypted.size(); i++)
        decoded += (encrypted[i] - shift_val);

    return decoded;
}


std::wstring Protect::Encrypt(const std::wstring& decoded)
{
    ///Encrypts given string

    int shift_val = Random::Int(1, 128);

    std::wstring encrypted;
    encrypted += to_wstring(shift_val);

    for (int i = 0; i < decoded.size(); i++)
        encrypted += (decoded[i] + shift_val);

    return encrypted;
}

std::wstring Protect::Decode(const std::wstring& encrypted)
{
    ///decodes encrypted string

    int shift_val = encrypted.front();

    std::wstring decoded;

    for (int i = 1; i < encrypted.size(); i++)
        decoded += (encrypted[i] - shift_val);

    return decoded;
}



std::wstring stow(const std::string& str)
{
    ///std::string to std::wstring

    std::wstring temp(str.begin(), str.end());
    return temp;
}


void throw_error(const std::string& function_name, const std::string& message, const std::string& error_type)
{
    /** \brief throws error tu console using std::cout
     *
     * \param function_name     name of the function where error happened
     * \param message           error message
     * \param error_type        custom error type
     * \return void
     *
     */


    std::cout << error_type << " in [" << function_name << "]: " << message << '\n';
}


float RTD(float radians)
{
    return radians * (180 / PI);
}

float DTR(float degrees)
{
    return degrees * (PI / 180);
}


}
