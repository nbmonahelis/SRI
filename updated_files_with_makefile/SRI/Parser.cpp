#include "Parser.h"

Parser::Parser(){
}

Parser::~Parser(){
}

/*void Parser::addLine(stringstream & p_ss)
{
    string line = "";
    getline(p_ss,line,'#');
    lines.push_back(line);
}*/

bool Parser::getType(string s)
{
    string str = s.substr(0,4);
    
    if (str == "FACT")
        return true;
    else if (str == "RULE")
        return false;
    else
        return false;
}

bool Parser::getGate(string s)
{
    int str = s.find(" AND ");
    if (str > 999999)
        return false;
    else
        return true;
}

string Parser::getFactAssoc(string s)
{
    int spaceIndex = s.find(" ");
    int paranIndex = s.find("(");
    
    string strtemp = s.substr(spaceIndex, paranIndex);
    return strtemp;
}

string Parser::getRuleAssoc(string s)
{
    int spaceIndex = s.find(" ");
    int paranIndex = s.find("(");
    
    string strtemp = s.substr(spaceIndex, paranIndex - spaceIndex);
    return strtemp;
}

string Parser::getInferAssoc(string s)
{
    int spaceIndex = s.find(" ");
    int paranIndex = s.find("(");
    
    string strtemp = s.substr(spaceIndex+1, (paranIndex -spaceIndex)-1);
    
    return strtemp;
}


vector<string> Parser::addFact(string assoc)
{
    
    stringstream associationStream(assoc);
    vector<string> mems;
    
    string members;
    string junk;
    
    getline(associationStream, members,'(');
    getline(associationStream, junk, ')');
    stringstream newerStream(junk);
    
    mems.push_back(members);
    
    while(getline(newerStream, junk, ','))
        mems.push_back(junk);
    
    return mems;
}

map<string, vector<string>> Parser::addRule(string assoc)
{
    stringstream associationStream(assoc);
    map<string, vector<string>> myRule;
    string head;
    string operators;
    string junk;
    string mems;
    int i = 1;

    
    getline(associationStream, head, ':');
    
    vector<string> root = parseRule(head);
    myRule["association"].push_back(root[0]);
    
    for(int i = 1; i < root.size(); i++)
        myRule["mems"].push_back(root[i]);
    
    getline(associationStream, junk, ' ');
    getline(associationStream, operators, ' ');
    myRule["operators"].push_back(operators);
    
    while(getline(associationStream, mems, ' '))
    {
        string member = "member";
        member += to_string(i);
        
        myRule[member] = parseRule(mems);
        myRule["end"].push_back("");
        
        i++;
    }
    
    return myRule;
}

vector<string> Parser::parseRule(string assoc)
{
    stringstream associationStream(assoc);
    vector<string> mems;
    string relation; //aka the association of the rule
    string elements; 
    string member;
    
    getline(associationStream, relation, '(');
    mems.push_back(relation);
    
    getline(associationStream, elements, ')');
    stringstream iss(elements);
    
    while(getline(iss, member, ','))
        mems.push_back(member);
    
    return mems;
    
}

vector<string> Parser::inference(string assoc)
{
    vector<string> association = parseRule(assoc);
    return association;
}
