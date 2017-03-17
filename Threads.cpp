//
//  Threads.cpp
//  SRI
//
//  Created by Babbie Monahelis on 3/15/17.
//  Copyright © 2017 Babbie Monahelis. All rights reserved.
//

#include "Threads.hpp"

ThreadContainer::ThreadContainer()
{
    //constructor 
}

void ThreadContainer::insert(thread * ourThreadToAdd)
{
    threadList.push_back(ourThreadToAdd);
    
    cout << "Just inserted thread: " << ourThreadToAdd->get_id() << "\n";
}

void ThreadContainer::executeThreads()
{
    for (int i = 0; i < threadList.size(); i++)
    {
        if (threadList[i]->joinable())
        {
            cout << "Executed thread "<< threadList[i]->get_id() << endl;
            threadList[i]->join();
        } 
    }
    
}

ThreadContainer::~ThreadContainer()
{
    for (int i = 0; i < threadList.size(); i++)
        delete (threadList[i]);
}

