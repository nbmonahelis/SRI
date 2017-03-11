#ifndef Inference_hpp
#define Inference_hpp

#include <stdio.h>
#include "common.h"
#include "RuleBase.hpp"
#include "KnowledgeBase.hpp"
#include "Parser.hpp"

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
    SRI();
    ~SRI();
    
    void inputLine(stringstream &);
    void addFact(string);
    void addRule(string);
    void load(string);
    void dump(KnowledgeBase *kb, RuleBase *rb);
    void dumpRF(ostream &os, KnowledgeBase *kb, RuleBase *rb);
    void drop(string param);
    vector<map<string,string>> inferenceFact(string, vector<string> &);
    vector<map<string,string>> inferenceRule(string, vector<string> &);
    map<string, vector<string>> findRule(string, int);
    void inference(string);
    
    
};



#endif /* Inference_hpp */
