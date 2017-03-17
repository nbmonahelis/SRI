//
//  Threads.hpp
//  SRI
//
//  Created by Babbie Monahelis on 3/15/17.
//  Copyright © 2017 Babbie Monahelis. All rights reserved.
//

#ifndef Threads_hpp
#define Threads_hpp

#include "common.h"

class ThreadContainer
{
    
public:
    
    vector <thread *> threadList; //our list of threads to access
    ThreadContainer();
    void executeThreads(); 
    void insert(thread *); //insert a thread into our list
    ~ThreadContainer();
    
};

#endif /* Threads_hpp */
