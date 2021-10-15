#include <stdlib.h>
#include <iostream>
#include <string>

int brute_force_str_match(std::string str, std::string pattern)
{
    if (pattern.size() == 0)
        return 0;

    if (pattern.size() > str.size())
        return -1;

    unsigned int pattern_size = pattern.size();
    for (unsigned int i = 0; i < str.size() - pattern_size; ++i)
    {
        if (pattern.compare(str.substr(i, pattern_size)) == 0)
            return i;
    }

    return -1;
}

int main(int argc, char* *argv)
{
    std::string str = 
}