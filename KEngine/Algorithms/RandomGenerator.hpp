#ifndef RANDOMGENERATOR_HPP_INCLUDED
#define RANDOMGENERATOR_HPP_INCLUDED

#include <iostream>
#include <cstdlib>

namespace ke
{

class Random
{
public:

    //Random(const Random&) = delete;
    operator= (const Random&) = delete;

    static Random& Get();

    static bool Chance(float percent);

    static float Float(float min, float max);
    static int Int(int min, int max);
    static char Char(char min, char max);

    static int Unique(int min, int max);

private:

    int last;

};

}

#endif // RANDOMGENERATOR_HPP_INCLUDED
