#pragma once

#include "ofMain.h"
#include "ofxSpacebrew.h"
#include <iostream>
#include <string>
#include "crypto.h"
#include "Chatting.h"

class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    
    Spacebrew::Connection spacebrew;
    
    void onMessage( Spacebrew::Message& m );
   
    bool                writing;
    string              s;
    vector<string>      ryanWritten;
    vector<string>      omerWritten;
    bool                omerReceived;
    bool                ryanReceived;
    Chatting            chat;
    bool                hasRun;

    
};
