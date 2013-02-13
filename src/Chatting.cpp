//
//  Chatting.cpp
//  SpacebrewoFX2
//
//  Created by Ryan Bartley on 2/12/13.
//
//

#include "Chatting.h"

void Chatting::threadedChatting() {
    
    writing = true;
    while (cin >> s && isThreadRunning()) {
        chat += s;
        cout << s << " is what i'm putting into " << chat << endl;
    }
    writing = false;
    cout << "I've written writing to " << endl;
    
}

string Chatting::getChat() {
    cout << "I'm sending out what i have for chat which is " << chat << endl;
    return chat;
}

bool Chatting::getThreadDone() {
    //cout << "I'm being accessed as to whether thread is done." << endl;
    return writing;
}
