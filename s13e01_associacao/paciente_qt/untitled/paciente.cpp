#include "paciente.h"
#include "medico.h"



std::ostream& operator<<(std::ostream &out, const Patient &pat)
{
    size_t length = pat.m_doctor.size();
    if (length == 0)
    {
        out << pat.getName() << " has no doctors right now";
        return out;
    }

    out << pat.m_name << " is seeing doctors: ";
    for (unsigned int count = 0; count < length; ++count)
        out << pat.m_doctor[count]->getName() << ' ';

    return out;
}

void Patient::rmDoctor(std::string name){
    auto it = std::find(m_doctor.begin(), m_doctor.end(), )



    for(size_t i = 0; i < m_doctor.size(); i++){
        if(m_doctor[i]->getName() == name){
            auto it = m_doctor.begin();
            std::advance(it, i);
            this->m_doctor.erase(it);
            return;
        }
    }
}
