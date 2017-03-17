//
//  Parser.hpp
//  SRI
//
//  Created by Babbie Monahelis on 3/9/17.
//  Copyright © 2017 Babbie Monahelis. All rights reserved.
//

#ifndef Parse_hpp
#define Parse_hpp

#include <stdio.h>
#include "common.h"

class Parse
{
    
public:
    
    Parse();
    
    bool getType(string);     //determine whether a given line is a fact, rule, or inference
    //returns 'true' for fact and 'false' for rule
    bool getGate(string);     //returns the type of gate used in any given rule
    //returns 'true' for AND and 'false' for OR
    string getFactAssoc(string);   //returns association type of a fact line
    string getRuleAssoc(string);     //returns left-most association type of a rule line
    string getInferAssoc(string);     //returns the association of an inference command statement
    
    vector<string> getFactParam(string);     //returns a vector of the parameters in any given fact line
    vector<string> getRuleFacts(string);     //returns a vector of the rule params
    map<string, vector<string> > addRule(string); //takes a rule as a string to add into the rulebase
    vector<string> getInference(string);
    vector<string> evaluateRule(string);
    vector<string> evaluateFact(string);
    
    size_t betterFind(const string& haystack, size_t pos, const string& needle, size_t n)    //find the nth instance of a string
    {
        size_t found = haystack.find(needle, pos);
        if (0 == n || string::npos == found)
            return found;
        return betterFind(haystack, found + 1, needle, n - 1);
    }
    
    ~Parse();
    
private:
    
    vector<string> fileLines;
    
    
};

#endif /* Parse_hpp */


