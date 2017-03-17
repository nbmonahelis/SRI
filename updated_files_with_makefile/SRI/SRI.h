#ifndef SRI_h
#define SRI_h

#include <stdio.h>
#include "common.h"
#include "RuleBase.h"
#include "KnowledgeBase.h"
#include "Parser.h"

class KnowledgeBase;
class RuleBase;
class Parser;

class SRI
{
private:
    KnowledgeBase * kb;
    RuleBase * rb;
    Parser * parse;
    
    
public:
    vector<thread> threads;
    mutex mutexT;
    bool joined;
    int threadCount = 0;
    SRI();
    ~SRI();
    
    void inputLine(stringstream &);
    void addFact(string);
    void addRule(string);
    void load(string);
    void dump(string command);
    void dumpRF(ostream &os, KnowledgeBase *kb, RuleBase *rb);
    void drop(string param);
    vector<map<string,string> > inferenceFact(string, vector<string> &);
    vector<map<string,string> > inferenceRule(string, vector<string> &);
    map<string, vector<string> > findRule(string, int);
    void inference(string);
    
    
};



#endif
