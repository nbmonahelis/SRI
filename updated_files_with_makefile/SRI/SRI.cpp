#include "SRI.h"
#include "KnowledgeBase.h"
#include "RuleBase.h"
#include "Parser.h"
#include "common.h"

SRI::SRI()
{
    kb = new KnowledgeBase();
    rb = new RuleBase();
    
}

void SRI::inputLine(stringstream & inputStream)
{
    string command; 
    string predicate;
    string junk;
    
    getline(inputStream, command, ' '); //grab the command for the input
    getline(inputStream, junk, '#'); //ignore the comments
    
    stringstream predicatestream(junk);
    getline(predicatestream, predicate);
    
}

void SRI::addFact(string factToAdd)
{
    vector<string> fact = parse->addFact(factToAdd); //send the fact input to parser
    kb->addFact(fact); //add it to the kb
}

void SRI::drop(string param)
{
	/*if(kb->FactDictionary.find(param)!=kb->FactDictionary.end())
    {
        cout<<"param dropped: "<<param<<endl;
        kb->FactDictionary.erase(param);
    }
if(rb->RuleDictionary.find(param)!= rb->RuleDictionary.end())
        rb->RuleDictionary.erase(param);
    cout<<"Dropped rules"<<endl;*/
vector<string> fact = parse->addFact(param);
kb->dropFact(fact);
 
}

void SRI::addRule(string ruleToAdd){
    
    map<string, vector<string> > rule = parse->addRule(ruleToAdd); //send the rule input to parser
    rb->addRule(rule); //add it to tho rb
}

void SRI::dump(string command1)
{
    ofstream out;
    //open file
    out.open("dump.sri");
    kb->dumpFact(out, command1);
    
}

void SRI::load(string fileName)
{
   cout<<"Loading from "<<fileName<<endl;
   string line;		// empty string to load the input file's contents
   string left;
   string ruleDetector;
   ifstream readFile(fileName);

   while(getline(readFile,line)){	// read from input file, put contents into line
		stringstream iss(line); //put the contents of line into an ss
		getline(iss,left,')');	// read from ss object, put contents into left side until ')'
		getline(iss,ruleDetector,' ');
		stringstream iss2(line);
		stringstream iss3(left);
                if(ruleDetector ==":-") addRule(line);
                else addFact(line);
     }
}

void SRI::inference(string assoc)
{
    cout<<"Inference"<<endl;
    vector<string> statements = parse->inference(assoc);
    string relation = statements[0]; //aka the association
    statements.erase(statements.begin());
    
    string inferenceStatement;
    
    stringstream associationStream(assoc);
    
    getline(associationStream,inferenceStatement,')');
    
    getline(associationStream,inferenceStatement, ' ');
    
    getline(associationStream,inferenceStatement);
    
    if(kb->exists(relation)) //if we found the relation within the knowledge base
    {
        vector<map<string,string> > member = inferenceFact(relation, statements); //call inference fact on the fact
        
        for(int i = 0; i < member.size(); i++)
        {
            for(int j = 0; j < statements.size(); j++)
            {
                string found = statements[j];
                cout<< found << ": " << member[i][found] << "\n";
            }
        }
    }
   else if(!kb->exists(relation)){
         cout<<"Fact is not found."<<endl;
   }
    
}

vector<map<string,string> > SRI::inferenceFact(string assoc, vector<string> & mems)
{
    bool found = true;

    vector<vector<string> > members = kb->findFact(assoc); //get the members of the fact
    
    int totalMembers = mems.size(); //get the total number so we can match them
    
    vector< map<string,string> > ourFacts; //temp vector to hold the facts with this association
    
    for(int i = 0; i < members.size(); i++)
    {
        
        if(totalMembers != members[i].size())
            continue;
        
        map<string,string> factMap; //map of the facts that we found
        
        for(int j = 0; j < totalMembers; j++)
        {
            
            string index = mems[j];
            string fact = members[i][j];
            
            if(factMap.find(index) == factMap.end()) //match the fact with the members
                factMap[index] = fact;
            else
            {
                if(factMap[index] != fact) //break if we can't find it
                {
                    found = false;
                    break;
                }
            }
        }
        
        if(found) //add it to our vector
            ourFacts.push_back(factMap);
    }
    return ourFacts; //return it
}

//still need to implement 
vector<map<string,string> > SRI::inferenceRule(string assoc, vector<string> & mems)
{
    vector<map<string, string> > x;
    
    return x;
}

SRI::~SRI(){
    delete(kb);
    delete(rb);
    delete(parse);
}

