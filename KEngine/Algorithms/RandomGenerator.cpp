#include "RandomGenerator.hpp"

namespace ke
{

Random& Random::Get()
{
    ///returns instance of KEngine Random

    static Random instance;
    return instance;
}


//////////


bool Random::Chance(float prc)
{
    ///returns true or false based on percent given in argument

    return Float(0.0f, 100.0f) < prc;
}


int Random::Int(int min, int max)
{
    ///returns random int

    return rand() % (max - min + 1) + min;
}

float Random::Float(float min, float max)
{
    ///returns random float

    return ((max - min) * ((static_cast<float>(rand()) / RAND_MAX))) + min;
}

char Random::Char(char min, char max)
{
    ///returns random char

    if (min < 32 || min > 254) min = 32;
    if (max < 32 || max > 254) max = 32;

    return Int(static_cast<int>(min), static_cast<int>(max));
}

int Random::Unique(int min, int max)
{
    ///returns random int different than the previous one (use once at time)

    if (min == max && min == Get().last) return min;

    int rv;
    do
    {
        rv = Int(min, max);
    } while (rv == Get().last);

    Get().last = rv;
    return rv;
}

}
