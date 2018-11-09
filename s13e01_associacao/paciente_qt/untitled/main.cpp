#include "medico.h"
#include "paciente.h"
#include <iostream>


int main()
{
    // Create a Patient outside the scope of the Doctor
    Patient *p1 = new Patient("Dave");
    Patient *p2 = new Patient("Frank");
    Patient *p3 = new Patient("Betsy");

    Doctor *d1 = new Doctor("James");
    Doctor *d2 = new Doctor("Scott");

    d1->addPatient(p1);

    d2->addPatient(p1);
    d2->addPatient(p3);

    std::cout << *d1 << '\n';
    std::cout << *d2 << '\n';
    std::cout << *p1 << '\n';
    std::cout << *p2 << '\n';
    std::cout << *p3 << '\n';

    delete p1;
    delete p2;
    delete p3;

    delete d1;
    delete d2;

    return 0;
}








