#ifndef MEDICO_H
#define MEDICO_H

#include <iostream>
#include <string>
#include <vector>
#include "paciente.h"


class Doctor : public User
{
private:
	std::string m_name;
	std::vector<Patient *> m_patient;
 
public:
	Doctor(std::string name = ""):
		User(m_name), m_name(name)
	{
	}
 
	void addPatient(Patient *pat)
	{
		//verifica se nao possui esse pat
		// Our doctor will add this patient
		m_patient.push_back(pat);
		
		// and the patient will also add this doctor
		pat->addDoctor(this);
	}

	void rmPatient(std::string patId)
	{
		for(size_t i = 0; i < m_patient.size(); i++){
			if(m_patient[i]->getName() == patId){
				m_patient[i]->rmDoctor(getName());
				m_patient.erase(m_patient.begin() + i);
				return;
			}
		}
	}
 
	friend std::ostream& operator<<(std::ostream &out, const Doctor& doc);
 
	std::string getName() const { return m_name; }

	virtual User * getDest(string idDest){
		for(auto * pac : m_patient)
			if(pac->getName == idDest)
				return pac;	
		return nullptr;
	}
};











#endif