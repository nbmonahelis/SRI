#include "Rule.h"

Rule::Rule(string a, vector<string> m)
{
    assoc = a;
    members = m;
}

string Rule::getAssoc()
{
    return assoc;
}
