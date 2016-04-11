#include "stdafx.h"
#include <string>
#include "Person.h"
#include "Employee.h"


int main()
{
    Person p( "test", "ertr", "ertert", 23, Sex::eMale );

    p.greet();

    Person p2( "Tony", "T", "Topper", 33, Sex::eFemale );
    p2.greet();

    Employee e1("Pamela", "E", "Estherline", 65, Sex::eFemale);
    e1.greet();

    Employee e( "John", "P", "Popper", 33, Sex::eMale,
                {"123","Melody Ln"," ","Chicago","Illinois","USA","12234"},
                {"pdiddy@yomama.com"});
    e.greet();
    Person p4;
    p4.mFirstName = "DefaultyCtorNoPtr";
    
    p4.greet();

    auto u = [](const Person& p)
    {
        cout << p.mFirstName << endl;
    };
    u(e);

    Person& pr2 = p;
    try {
        Employee& er2 = dynamic_cast<Employee&>(pr2);
        cout << er2.mDepartment << endl;
    }
    catch (const bad_cast& e)
    {
        cout << "Cannot cast this!" << endl;
    }

    Person* pp2= &p;
    Employee* ep = dynamic_cast<Employee*>(pp2);
    if (ep)
        cout << ep->mDepartment << endl;
    else
        cout << "Failed to cast pointer" << endl;


    Person* pp;
    pp = new Person();
    auto* phyAddr = new PhysicalAddress("123", "123rd st", "suite102", "123town", "nv", "usa", "123 321");
    pp->mpAddress = phyAddr;
    auto* eAddr = new ElectronicAddress("123@jujubeas.com");
    pp->mpEAddress = eAddr;

    pp->greet();


    delete pp;

    getchar();
    return 0;
}

