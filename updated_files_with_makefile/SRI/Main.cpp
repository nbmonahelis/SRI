/****MAIN*****/
/*1)Enter either FACT, RULE, LOAD, etc followed by the input: 
example: FACT Father(Allen, Margaret)
now it will ask you to enter a command again.
2)enter the corresponding Roman number. For FACT, enter i, for RULE, enter ii, etc(just look up in the menu)
*/
#include "common.h"
//#include "SRI.h"
#include "SRI.cpp"
#include "KnowledgeBase.cpp"
#include "RuleBase.cpp"
#include "Parser.cpp"
//#include "KnowledgeBase.h"
//#include "RuleBase.h"

void menu()
{
    SRI * sriobj = new SRI();
   // KnowledgeBase *kb = new KnowledgeBase();
   // RuleBase *rb = new RuleBase();
    
    string command, command1, command2; //command
    string input;
    ofstream fout;
    bool exit = false;
    
    while(!exit){
        cout<<"(i)FACT"<<endl;
        cout<<"(ii)RULE"<<endl;
        cout<<"(iii)LOAD"<<endl;
        cout<<"(iv)DUMP"<<endl;
        cout<<"(v)DROP"<<endl;
        cout<<"(vi)INFERENCE"<<endl;
        cout<<"(vii)QUIT"<<endl;
        cout<<"-------------"<<endl;
        cout<<"Enter your command: "<<endl;
        getline(cin, input);
        stringstream str(input);
        getline(str, command, ' ');//catch the first command entered
        getline(str, command1);
        command2 = input;
        
        if(command2 == "i"){
            cout<<"Fact entered: "<<command1<<endl; //pring the fact entered on console
            sriobj->addFact(command1);
            
        }
        else if(command2 == "ii"){
            cout<<"Rule entered: "<<command1<<endl;
            sriobj->addRule(command1);
            
        }
        
        else if(command2 == "iii"){
            cout<<"LOADING"<<endl;
            sriobj->load(command1);
        }
        else if(command2 == "iv"){
            sriobj->dump(command1);
            cout<<"DUMPING KB AND RB"<<endl;
        }
        
        else if(command2 == "v"){
            cout<<"DROPPING"<<endl;
            sriobj->drop(command1);
            
        }
        else if(command2 == "vi"){
            cout<<"Issuing a query"<<endl;
            sriobj->inference(command1);
        }
        else if(command == "vii"){
            cout<<"CIAO BAMBINO"<<endl;
            break;
        }
        
    }
}
int main(){
    menu();
}
