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
    Doctor(std::string name);
    void addPatient(Patient *pat);
    std::string getName() const;

    void rmPatient(std::string nome){
        for(size_t i = 0; i < m_patient.size(); i++){
            if(m_patient[i]->getName() == nome){

            }
        }
    }

    friend std::ostream &operator<<(std::ostream &out, const Doctor &doc)
    {
        size_t length = doc.m_patient.size();
        if (length == 0)
        {
            out << doc.m_name << " has no patients right now";
            return out;
        }

        out << doc.m_name << " is seeing patients: ";
        for (unsigned int count = 0; count < length; ++count)
            out << doc.m_patient[count]->getName() << ' ';

        return out;
    }
};


#endif
