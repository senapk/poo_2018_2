#include "medico.h"

std::ostream& operator<<(std::ostream &out, const Doctor &doc)
{
    unsigned int length = doc.m_patient.size();
    out << doc.m_name << "[ ";
    for (unsigned int count = 0; count < length; ++count)
            out << doc.m_patient[count]->getName() << ' ';
    out << "]";
    return out;
}