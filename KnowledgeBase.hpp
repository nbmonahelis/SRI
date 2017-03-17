#ifndef KnowledgeBase_hpp
#define KnowledgeBase_hpp

#include <stdio.h>
#include "common.h"

class KnowledgeBase
{
    
public:
    
    map<string, vector<vector<string>>> FactDictionary;

    KnowledgeBase();
    
    void addFact(vector<string> mems);
    void dropFact(vector<string> mems);
    void removeAllFactsWithKey(string key);
    int totalFacts();
    vector<vector<string>> findFact(string assoc);
    bool exists(string);
    
};

#endif /* KnowledgeBase_hpp */
