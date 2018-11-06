#include "medico.h"

std::ostream& operator<<(std::ostream &out, const Doctor &doc)
{
    unsigned int length = doc.m_patient.size();
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