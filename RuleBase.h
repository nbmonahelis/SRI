#ifndef RuleBase_h
#define RuleBase_h

#include <stdio.h>
#include "common.h"

class RuleBase
{
    
public:
    
    map<string, vector<map <string, vector<string> > > > RuleDictionary;

    RuleBase();
    
    void addRule(map<string, vector<string> > mems);
    void dropRule(map<string, vector<string> > mems);
    void removeAllRulesWithKey(string key); //removes all rules with the key
    int totalRules();
    bool exists(string);
    //void dropRule(string param, RuleBase *rb);
    vector<map <string, vector<string> > > findRule(string);
    
    ~RuleBase();
};

#endif /* RuleBase_hpp */
