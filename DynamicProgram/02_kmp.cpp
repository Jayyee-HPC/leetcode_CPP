#include<string>
#include<cassert>
#include<iostream>

void get_next(std::string pattern, int next[] );
bool string_match(std::string str, std::string pattern);


int main(int argc, char** argv)
{
    bool is_match = string_match("adffgadfgfgddfg", "aaaafgaaaaaaaaaaaaaaaaaaafg");
    assert(is_match == false);
    return 0;
}

bool string_match(std::string str, std::string pattern)
{
    int next[pattern.size()];
    get_next(pattern, next);

    int pos = 0;
    for (int i = 0; i < str.size();)
    {
        if (pos == -1 || str[i] == pattern[pos])
        {
            ++pos;
            ++i;
            if (pos == pattern.size())
                return true;

            continue;
        }

        pos = next[pos];
    }

    if (pos >= pattern.size())
        return true;

    return false;
}

void get_next(std::string pattern, int next[] )
{
    next[0] = -1; // -1 for compuuting
    int i = 0, j = -1; // begin with the third letter

    while (i < pattern.size())
    {
        if (j == -1 || pattern[i] == pattern[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }

}