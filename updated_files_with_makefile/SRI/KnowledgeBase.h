#ifndef KnowledgeBase_h
#define KnowledgeBase_h

#include <stdio.h>
#include "common.h"

class KnowledgeBase
{
    
public:
    
    map<string, vector<vector<string> > > FactDictionary;
 

    KnowledgeBase();
    
    void addFact(vector<string> mems);
    void dropFact(vector<string> mems);
    void removeAllFactsWithKey(string key);
    int totalFacts();
    vector<vector<string> > findFact(string assoc);
    bool exists(string);
    void dumpFact(ostream &os, string command);
    
};

#endif /* KnowledgeBase_hpp */
