#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    
    //change these to the settings you need for your session
    string host = "54.235.186.86";
    string name = "ryan";
    string description = "It's amazing";
    
    
    //these are the settings that spacebrew will publish
    spacebrew.addPublish("ryanChat", Spacebrew::TYPE_STRING);
    spacebrew.addSubscribe("forOmerChat", Spacebrew::TYPE_STRING);
    spacebrew.connect(host, name, description);
    Spacebrew::addListener(this, spacebrew);
    
    writing = false;
    hasRun = true;
    
    ofBackground(0);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofEnableSmoothing();
    ofSetCircleResolution(100);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    //This flashes the background when you've received a text
    if ( !omerReceived || !ryanReceived) {
        ofBackgroundGradient(ofColor(0,0,0), ofColor(50,50,50));
        omerReceived = true;
        ryanReceived = true;
    } else {
        ofBackgroundGradient(ofColor(100,0,0), ofColor(150,150,150));
    }
    
    
    ofSetColor(255);
    //This adjusts the text that is received downward
    int j = 0;
    
    //These are the loops that output the text to the screen
    for (vector<string>::iterator i = omerWritten.begin(); i != omerWritten.end(); ++i) {
        ofDrawBitmapString( *i, ofGetWidth() / 3.0f, ofGetHeight() / 2.0f + j);
        cout << *i << endl;
        j+=20;
    }
    
    j = 0;
    for (vector<string>::iterator i = ryanWritten.begin(); i != ryanWritten.end(); ++i) {
        ofDrawBitmapString( *i, ofGetWidth() / 2.0f, ofGetHeight() / 2.0f + j);
        j+=20;
         cout << *i << endl;
    }
}

void testApp::onMessage( Spacebrew::Message & m ) {
  
    //This receives the message and pushes the info into the vector
    if (m.name == "forOmerChat") {
        omerWritten.push_back(m.valueString());
        omerReceived = true;
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    //This receives the keys from your keyboard and you can type until you want
    //to send by pressing the enter or return key
    if (key != OF_KEY_RETURN) {
        s += key;
    } else if (key == OF_KEY_RETURN) {
        ryanWritten.push_back(s);
        spacebrew.sendString("ryanChat", s);
        s = "";
        ryanReceived = true;
    }
    
}



