//
//  Rule.hpp
//  SRI
//
//  Created by Babbie Monahelis on 3/9/17.
//  Copyright © 2017 Babbie Monahelis. All rights reserved.
//

#ifndef Rule_hpp
#define Rule_hpp

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
