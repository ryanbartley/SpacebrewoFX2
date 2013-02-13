#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    string host = "54.235.111.53";
    string name = "ryan writing";
    string description = "It's amazing";
    
    spacebrew.addPublish("ryanChat", Spacebrew::TYPE_STRING);
    spacebrew.addSubscribe("getChat", Spacebrew::TYPE_STRING);
    spacebrew.connect(host, name, description);
    
    Spacebrew::addListener(this, spacebrew);
    std::cout << "I've configured the join server" << std::endl;
    writing = false;
    hasRun = true;
    std::cout << "I've set writing to " << writing << std::endl;
    ofBackground(0);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofEnableSmoothing();
    ofSetCircleResolution(100);
    std::cout << "I'm done with setup" << std::endl;
   
    
}

//--------------------------------------------------------------
void testApp::update(){
//    if(writing && !hasRun) {
//        cout << "I'm starting the thread!" << endl;
//        chat.startThread(true, false);
//        hasRuhello n = true;
//    }
//    if (chat.getThreadDone()) {
//        cout << "I've accessed and found that thread is done and now I'm sending " << chat.getChat() << " to omer" << endl;
//        spacebrew.sendString("ryanChat", chat.getChat());
//        chat.stopThread();
//        
//    }
}

//--------------------------------------------------------------
void testApp::draw(){
    if ( !omerReceived && !ryanReceived) {
        ofBackgroundGradient(ofColor(0,0,0), ofColor(50,50,50));
    } else {
        ofBackgroundGradient(ofColor(100,0,0), ofColor(150,150,150));
    }
    
    
    ofSetColor(255);
    int j = 0;
    for (vector<string>::iterator i = omerWritten.begin(); i != omerWritten.begin(); ++i) {
        ofDrawBitmapString( *i, ofGetWidth() / 3.0f, ofGetHeight() / 2.0f + j);
        j+=20;
    }
    j = 0;
    for (vector<string>::iterator i = ryanWritten.begin(); i != ryanWritten.end(); ++i) {
        ofDrawBitmapString( *i, ofGetWidth() / 2.0f, ofGetHeight() / 2.0f + j);
        j+=20;
    }
}

void testApp::onMessage( Spacebrew::Message & m ) {
    if (m.name == "omersChat") {
        omerWritten.push_back(m.valueString());
        omerReceived = true;
    }
    if (m.name == "ryanChat") {
        ryanWritten.push_back(m.valueString());
        ryanReceived = true;
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if (key != OF_KEY_RETURN) {
        s += key;
    } else if (key == OF_KEY_RETURN) {
        ryanWritten.push_back(s);
        spacebrew.sendString("a new chat", s);
    }
    
}



