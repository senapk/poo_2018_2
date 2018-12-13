#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

class Entry {
    bool favorited;
public:
    Entry(){
        favorited = false;
    }
    virtual ~Entry(){
    }
    virtual string getId() = 0; //virtual puro
    virtual void setFavorited(bool value){
        favorited = value;
    }
    virtual bool isFavorited(){
        return favorited;
    }
    virtual string toString(){
        return (isFavorited() ? "@ " : "- ") + getId();
    };
};

class Fone {
public:
    string id;
    string number;

    Fone(string id = "", string number = ""){
        this->id = id;
        this->number = number;
    }

    static bool validate(string number) {
        string data = "1234567890()- ";
        for(auto c : number)
            if(data.find(c) == string::npos)
                return false;
        return true;
    }
};

class Note : public Entry { 
    string id;
    vector<string> itens;
public:
    Note(string id = "")
        :id(id)
    {}
    string getId(){
        return id;
    }
    void addItem(string item){
        itens.push_back(item);
    }
    string toString(){
        string saida = Entry::toString() + " N [ ";
        for(auto item : itens){
            saida += item + " ";
        }
        return saida + "]";
    }
};

class Contato : public Entry {
    string id;
    vector<Fone> fones;
public:
    Contato(string id = ""){
        this->id = id;
    }
    string getName(){
        return id;
    }
    string getId(){
        return id;
    }
    void addFone(Fone fone){
        if(!Fone::validate(fone.number))
            throw string("fone " + fone.number + " invalido");
        fones.push_back(fone);
    }
    void rmFone(size_t indice){
        if(indice < 0 || indice >= fones.size())
            throw string("indice " + to_string(indice) + " nao existe");
        fones.erase(fones.begin() + indice);
    }
    vector<Fone> getFones(){
        vector<Fone> resp;
        for(auto fone: fones)
            resp.push_back(fone);
        return resp;
    }
    string toString(){
        string saida = Entry::toString() + " C ";
        int i = 0;
        for(auto fone : getFones())
            saida += "[" + to_string(i++) + ":" + fone.id + ":" + fone.number + "]";
        return saida;
    }
};

class Agenda {
    map<string, Entry*> m_entries;
    map<string, Entry*> m_favorites;

public:
    void addEntry(Entry * entry){
        string id = entry->getId();
        if(m_entries.count(entry->getId()) == 1)
            throw string("entry " + id + " ja existe");
        m_entries[id] = entry;
    }

    void rmEntry(string id) {
        auto it = m_entries.find(id);
        delete(it->second);
        if(m_entries.erase(id))
            m_favorites.erase(id);
    }

    void favorite(string idEntry){
        auto it = m_entries.find(idEntry);
        if(it != m_entries.end()){
            Entry& entry = *it->second;
            if(!entry.isFavorited()){
                entry.setFavorited(true);
                m_favorites[idEntry] = &entry;
            }
        }else{
            throw "fail: entry " + idEntry + " nao existe";
        }
    }

    void unfavorite(string idEntry){
        auto it = m_favorites.find(idEntry);
        if(it != m_favorites.end()){
            it->second->setFavorited(false);
            m_favorites.erase(it);
        }
    }

    vector<Entry*> getFavorited(){
        vector<Entry*> favorited;
        for(auto& par : m_favorites)
            favorited.push_back(par.second);
        return favorited;
    }

    Entry * getEntry(string id){
        if(m_entries.count(id))
            return m_entries[id];
        throw string("  entry " + id + " nao existe");
    }

    vector<Entry*> getEntries(){
        vector<Entry*> resp;
        for(auto& par : m_entries)
            resp.push_back(par.second);
        return resp;
    }

    vector<Entry*> search(string pattern){
        vector<Entry*> resp;
        for(auto& par : m_entries)
            if(par.second->toString().find(pattern) != string::npos)
                resp.push_back(par.second);
        return resp;
    }

    string toString(){
        string saida = "";
        for(auto& par : m_entries)
            saida += par.second->toString() + "\n";
        return saida;
    }
};


class AgendaMaster : public Agenda{
public:
    AgendaMaster()
    {
    }
    template<typename T>
    T * getType(string id){
        T * cont = dynamic_cast<T*>(getEntry(id));
        if(cont == nullptr)
            throw string("") + "fail: " + id + " nao possui essa operacao";    
        return cont;
    }
};

class Controller {

    AgendaMaster agenda;
public:

    void shell(string line){
        stringstream ss(line);
        string op;
        ss >> op;
Entry*
        if(op == "addContato"){
            string name, id_number;
            ss >> name;
            Contato * pcont;
            try{
                pcont = agenda.getType<Contato>(name);
            }catch(string e){
                agenda.addEntry(new Contato(name));
                pcont = agenda.getType<Contato>(name);
            }
            while(ss >> id_number){
                string id, fone;
                stringstream ssfone(id_number);
                getline(ssfone, id, ':');
                ssfone >> fone;
                pcont->addFone(Fone(id, fone));
            }
        }else if(op == "addNote"){
            string name, item;
            ss >> name;
            Note * pnote;
            try{
                pnote = agenda.getType<Note>(name);
            }catch(string e){
                agenda.addEntry(new Note(name));
                pnote = agenda.getType<Note>(name);
            }
            while(ss >> item){
                pnote->addItem(item);
            }
        }
        else if(op == "rmFone"){
            string id;
            int indice;
            ss >> id >> indice;
            //agenda.getType<Contato>(id)->rmFone(indice);
            Entry * entry = agenda.getEntry(id);
            Contato * cont = dynamic_cast<Contato*>(entry);//instance_of(Contato)
            if(cont != nullptr){
                cont->rmFone(indice);
            }

        }
        else if(op == "rmEntry"){
            string id;
            ss >> id;
            agenda.rmEntry(id);
        }
        else if(op == "agenda"){
            cout << agenda.toString();
        }
        else if(op == "search"){
            string pattern;
            ss >> pattern;
            auto resp = agenda.search(pattern);
            for(auto entry : resp)
                cout << entry->toString() << endl;
        }
        else if(op == "fav"){
            string id;
            ss >> id;
            agenda.favorite(id);
        }
        else if(op == "unfav"){
            string id;
            ss >> id;
            agenda.unfavorite(id);
        }
        else if(op == "favorited"){
            auto favs = agenda.getFavorited();
            for(auto entry : favs)
                cout << entry->toString() << endl;
        }
        else
            cout << "comando invalido" << endl;
    }

    void exec() {
        string line = "";
        while(true){
            getline(cin, line);
            cout << "$" << line << endl;
            if(line == "end")
                return;
            try {
                shell(line);
            } catch(const string& e) {
                cout << e << endl;
            }
        }
    }
};

int main()
{
    Controller controller;
    controller.exec();
    return 0;
}
