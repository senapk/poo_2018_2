#ifndef MEDICO_H
#define MEDICO_H

#include <iostream>
#include <string>
#include <vector>
#include "paciente.h"


class Doctor
{
private:
	std::string m_name;
	std::vector<Patient *> m_patient;
 
public:
	Doctor(std::string name):
		m_name(name)
	{
	}
 
	void addPatient(Patient *pat)
	{
		// Our doctor will add this patient
		m_patient.push_back(pat);
		
		// and the patient will also add this doctor
		pat->addDoctor(this);
	}
 
 
	friend std::ostream& operator<<(std::ostream &out, const Doctor &doc);
 
	std::string getName() const { return m_name; }
};











#endif