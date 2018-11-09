#include "paciente.h"
#include "medico.h"

void Patient::addDoctor(Doctor *doc)
{
	for(auto * doctor : m_doctor)
		if(doctor->getName() == doc->getName())
			return;
	m_doctor.push_back(doc);
}

void Patient::rmDoctor(std::string docId){
	for(size_t i = 0; i < m_doctor.size(); i++){
		if(m_doctor[i]->getName() == docId){
			m_doctor.erase(m_doctor.begin() + i);
			return;
		}
	}
}
 
std::ostream& operator<<(std::ostream &out, const Patient &pat)
{
	unsigned int length = pat.m_doctor.size();

	out << pat.m_name << "[ ";
	for (unsigned int count = 0; count < length; ++count)
		out << pat.m_doctor[count]->getName() << ' ';
	out << "]";
	return out;
}