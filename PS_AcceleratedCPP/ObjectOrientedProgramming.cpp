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

