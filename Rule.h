#ifndef Rule_h
#define Rule_h

#include <stdio.h>
#include "common.h"

class Rule
{
private:
    
    string assoc;
    vector<string> members;
public:
    
    Rule(string a, vector<string> mems);
    string getAssoc();
    ~Rule();
    
};

#endif /* Rule_hpp */
