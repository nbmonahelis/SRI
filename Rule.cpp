//
//  Rule.cpp
//  SRI
//
//  Created by Babbie Monahelis on 3/9/17.
//  Copyright © 2017 Babbie Monahelis. All rights reserved.
//

#include "Rule.hpp"

Rule::Rule(string a, vector<string> m)
{
    assoc = a;
    members = m;
}

string Rule::getAssoc()
{
    return assoc;
}
