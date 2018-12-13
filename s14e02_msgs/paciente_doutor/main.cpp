#include "medico.h"
#include "paciente.h"
#include <map>
#include <sstream>
#include <iostream>
using namespace std;

class Controller{
	map<string, Doctor> rDoc;
	map<string, Patient> rPat;
	map<string, User*> rUsers;
	
public:
	Controller()
	{
	}

	void shell(string line){
		stringstream ss(line);
		string op;
		ss >> op;
		if(op == "addDoc"){//_dot1 _dot2 _dot3 ...
			string name;
			while(ss >> name){

				if(rUsers.find(name) == rUsers.end()){
					rDoc[name] = Doctor(name);
					rUsers[name] = &rDoc[name];
				}
			}
		} else if(op == "addPat"){//_dot1 _dot2 _dot3 ...
			string name;
			while(ss >> name){
				if(rPat.find(name) == rPat.end())
					rPat[name] = Patient(name);
			}
		} else if(op == "show"){
			cout << "Medicos" << endl;
			for(auto par : rDoc)
				cout << "  " << par.second << endl;
			cout << "Paciente" << endl;
			for(auto par : rPat)
				cout << "  " << par.second << endl;
		} else if(op == "tie"){// _med _pac _pac ...
			string medName;
			ss >> medName;

			auto it = rDoc.find(medName);
			if(it == rDoc.end()){
				cout << "medico nao existe" << endl;
				return;
			}
			string pacName;
			Doctor *med = &it->second;
			while(ss >> pacName){
				auto itPat = rPat.find(pacName);
				if(itPat == rPat.end()){
					cout << "paciente " << pacName << " nao existe";
				}else{
					med->addPatient(&itPat->second);
				}
			}
		} else{
			cout << "comando invalido" << endl;
		}
	}
	void exec(){
		string line;
		while(true){
			getline(cin, line);
			if(line == "end")
				return;
			shell(line);
		}
	}
};


int main()
{
	Controller controller;
	controller.exec();
 
	return 0;
}

/*
addPat alice edson bruno
addDoc zibia woshi kywy
tie zibia edson bruno
tie woshi alice edson
tie kywy zeca alice edison edson brunu
show
untie woshi
*/
