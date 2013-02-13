//
//  Chatting.h
//  SpacebrewoFX2
//
//  Created by Ryan Bartley on 2/12/13.
//
//

#pragma once

#include <iostream>
#include "ofMain.h"


class Chatting : public ofThread {
    
    string s;
    bool writing;
    string chat;
    
public:
    
    void threadedChatting();
    string getChat();
    bool getThreadDone();

    
};