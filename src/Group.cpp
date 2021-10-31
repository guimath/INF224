#include "Group.h"

using namespace std;


Group::Group(string name):list<shared_ptr<Multimedia>>()
{
    m_name = name;
}

string Group::get_name() const
{
    return m_name;
}

void Group::set_name(string name) 
{
    m_name = name;
}

void Group::infos_out(ostream &out) 
{
    out << "info for group named \"" << m_name << "\" :" << endl;
    int i =1;
    for (Group :: iterator file = this->begin(); file != this->end(); file++){
        out <<  endl << "file n°" << i++ << endl;  
        
        (*file)->infos_out(out);
    }
}
