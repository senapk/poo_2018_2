#include "medico.h"

Doctor::Doctor(std::string name):
    m_name(name)
{
}

void Doctor::addPatient(Patient *pat)
{
    // Our doctor will add this patient
    m_patient.push_back(pat);

    // and the patient will also add this doctor
    pat->addDoctor(this);
}



std::string Doctor::getName() const { return m_name; }
