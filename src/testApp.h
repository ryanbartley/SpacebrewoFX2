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
   
    
    
    //These are the vectors that will store the strings
    vector<string>      ryanWritten;
    vector<string>      omerWritten;
    //This is the string you're writing into
    string              s;
    //These are the logic barriers
    bool                omerReceived;
    bool                ryanReceived;
    bool                writing;
    bool                hasRun;

    
};
