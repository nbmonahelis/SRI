#include "KnowledgeBase.h"

KnowledgeBase::KnowledgeBase()
{
    
}

void KnowledgeBase::addFact(vector<string> mems)
{
    string assoc = mems.front(); //stored the association at the front of the vector.
    
    mems.erase(mems.begin()); //delete the association because we don't need it anymore
    
    vector< vector<string> > temp; //holds all of the members for this fact
    temp.push_back(mems);
    
    auto add = FactDictionary.emplace(assoc, temp); //add the fact to the map
    
    if ( !add.second )
    {
        if ((find((*add.first).second.begin(), (*add.first).second.end(), mems) == (*add.first).second.end()))
            (*add.first).second.push_back(mems);
    }
    
}

void KnowledgeBase::dropFact(vector<string> mems)
{
    string assoc = mems.front(); //grab the association
    mems.erase(mems.begin()); //delete it
    
    vector< vector<string> > temp; //what we are going to use to hold the fact members
    
    temp.push_back(mems);
    
    auto iter = find(FactDictionary.at(assoc).begin(), FactDictionary.at(assoc).end(), mems);
    
    if ( iter != FactDictionary.at(assoc).end())
        FactDictionary.at(assoc).erase(iter);
    
}

vector< vector<string> > KnowledgeBase::findFact(string assoc)
{
    bool found; //boolean for the event of finding a fact
    
    if (FactDictionary.count(assoc) == 0)
        found = false;
    else
        found = true;
    
    if (found == true) //if we found it, return it
        return FactDictionary[assoc];
    else
    {
        cout << "No facts of that association exists. \n";
        exit(0); //we didn't find anything
    }
    
}

bool KnowledgeBase::exists(string assoc)
{
    if (FactDictionary.count(assoc) == 0)
        return false;
    else
        return true;
}








