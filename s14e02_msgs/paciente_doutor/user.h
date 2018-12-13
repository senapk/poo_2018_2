#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Msg{
public:
    string from;
    string to;
    string text;
    Msg(string from = "", string to = "", string text = ""):
        from(from), to(to), text(text){}
    friend ostream& operator<<(ostream& os, Msg msg){
        os << "[" << msg.from << ": " << msg.text << "]";
        return os;
    }
};

class User{
public:
    string id;
    vector<Msg> inbox;
    User(string id = ""):
        id(id){
        inbox.push_back(Msg("Admin", this->id, "seja bem vindo"));
    }

    vector<Msg> readInbox(){
        vector<Msg> aux = inbox;
        inbox.clear();
        return aux;
    }

    void sendMsg(string idTo, string text){
        User * dest = this->getDest(idTo);
        if(dest == nullptr)
            throw "destinatario nao existe";
        dest->inbox.push_back(Msg(this->id, idTo, text));
    }
    
    virtual User * getDest(string idDest) = 0;
};