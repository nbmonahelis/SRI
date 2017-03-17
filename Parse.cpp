//
//  Parser.cpp
//  SRI
//
//  Created by Babbie Monahelis on 3/9/17.
//  Copyright © 2017 Babbie Monahelis. All rights reserved.
//

#include "Parse.hpp"
#include "common.h"

Parse::Parse()
{
    
}

bool Parse::getType(string s)
{
    string str = s.substr(0,4);
    
    if (str == "FACT")
        return true;
    else if (str == "RULE")
        return false;
    else
        return false;
}

bool Parse::getGate(string s)
{
    int str = s.find(" AND ");
    if (str > 999999)
        return false;
    else
        return true;
}

string Parse::getFactAssoc(string s)
{
    int spaceIndex = s.find(" ");
    int paranIndex = s.find("(");
    
    string strtemp = s.substr(spaceIndex, paranIndex);
    return strtemp;
}

string Parse::getRuleAssoc(string s)
{
    int spaceIndex = s.find(" ");
    int paranIndex = s.find("(");
    
    string strtemp = s.substr(spaceIndex, paranIndex - spaceIndex);
    return strtemp;
}

string Parse::getInferAssoc(string s)
{
    int spaceIndex = s.find(" ");
    int paranIndex = s.find("(");
    
    string strtemp = s.substr(spaceIndex+1, (paranIndex -spaceIndex)-1);
    
    return strtemp;
}

vector<string> Parse::evaluateFact(string assoc)
{
    
    //declare vector and initialize stream
    stringstream newStream(assoc);
    vector<string> params;
    
    string relationship = "";
    string rest = "";
    
    getline(newStream, relationship,'(');
    getline(newStream, rest, ')');
    stringstream newerStream(rest);
    
    params.push_back(relationship);
    while(getline(newerStream, rest, ',')){
        params.push_back(rest);
    }
    return params;
}


vector<string> Parse::getFactParam(string str)
{
    vector<int> indices;
    
    int i = 0;
    while (betterFind(str, 0, ",", i) < 999999) {
        
        size_t paramCount = betterFind(str, 2, ",", i);
        indices.push_back(paramCount);
        i++;
    }
    
    vector<string> param;
    param.push_back(str.substr(str.find('(') + 1, (str.find(',') - str.find('(') - 1)));   //param[0] = first parameter
    
    for (int j = 0; j < indices.size() - 1; j++)
    {
        int x = indices[j];
        int y = indices[j + 1];
        
        param.push_back(str.substr(x + 1, (y - x) - 1));   //push the rest of the paramters to the vector param
    }
    
    return param;
}

vector<string> Parse::getRuleFacts(string str)
{
    
    stringstream stream(str);
    string assoc;
    string param;
    string member;
    vector<string> temp;
    
    getline(stream, assoc, '(');
    temp.push_back(assoc); //adding rule assoc to vector
    
    getline(stream, param, ')');
    stringstream mems(param); //finding the members of the rule
    
    while( getline(mems, member, ',') )
        temp.push_back(member); //adding the member of the rule to the vector
    
    return temp;
}

map<string, vector<string> > Parse::addRule(string rule)
{
    
    stringstream stream(rule);
    map<string, vector<string>> myRule;
    string head;
    string operators;
    string mems;
    string remaining;
    string params;
    int i = 1;
    
    getline(stream, head, ':');
    vector<string> base = getRuleFacts(head);
    
    myRule["association"].push_back(base[0]);
    
    for (int i = 1; i<base.size(); i++)
        myRule["mems"].push_back(base[i]);
    
    getline(stream, remaining, ' ');
    getline(stream, operators, ' ');
    
    myRule["operators"].push_back(operators);
    
    while(getline(stream, params, ' '))
    {
        string member = "member";
        member += to_string(i);
        myRule[member] = getRuleFacts(params);
        myRule["ms"].push_back("");
        
        i++;
    }
    
    return myRule;
}

vector<string> Parse::evaluateRule(string rule)
{
    vector<string> temp;
    string assoc, param, mems;
    stringstream stream(rule);
    
    getline(stream, assoc, '(');
    
    temp.push_back(assoc);
    getline(stream, assoc, ')');
    stringstream tream(param);
    
    while(getline(tream, mems, ','))
        temp.push_back(mems);
    
    return temp;
    
}

vector<string> Parse::getInference(string inf)
{
    vector<string> temp = evaluateRule(inf);
    return temp;
}

Parse::~Parse()
{
    
}

