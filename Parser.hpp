//
//  Parser.hpp
//  SRI
//
//  Created by Babbie Monahelis on 3/10/17.
//  Copyright © 2017 Babbie Monahelis. All rights reserved.
//

#ifndef Parser_hpp
#define Parser_hpp

#include <stdio.h>
#include "common.h"

class Parser{
    
private:
    vector<string> lines;
    
public:
    Parser();
    ~Parser();
    
    bool getType(string);     //determine whether a given line is a fact, rule, or inference
    //returns 'true' for fact and 'false' for rule
    bool getGate(string);     //returns the type of gate used in any given rule
    //returns 'true' for AND and 'false' for OR
    string getFactAssoc(string);   //returns association type of a fact line
    string getRuleAssoc(string);     //returns left-most association type of a rule line
    string getInferAssoc(string);     //returns the association of an inference command statement
    
    size_t betterFind(const string& haystack, size_t pos, const string& needle, size_t n)    //find the nth instance of a string
    {
        size_t found = haystack.find(needle, pos);
        if (0 == n || string::npos == found)
            return found;
        return betterFind(haystack, found + 1, needle, n - 1);
    }
    
    vector<string> addFact(string p_string);
    map<string, vector<string>> addRule(string p_string);
    vector<string> parseRule(string p_string);
    vector<string> inference(string p_string); 
    
};


#endif /* Parser_hpp */
