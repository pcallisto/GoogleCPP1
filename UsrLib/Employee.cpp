#include "stdafx.h"
#include "Employee.h"
#include "Person.h"
#include "PhysicalAddress.h"
#include "ElectronicAddress.h"

void Employee::greet()
{
    Person::greet();

    std::cout << "By the way, I work in " << mDepartment << endl;
}