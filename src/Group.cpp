#include "Group.h"

using namespace std;


Group::Group(string group_name):list<shared_ptr<Multimedia>>()
{
    m_group_name = group_name;
}

string Group::get_group_name() const
{
    return m_group_name;
}

void Group::set_group_name(string group_name) 
{
    m_group_name = group_name;
}

void Group::infos_out(ostream &out) 
{
    out << "info for group named \"" << m_group_name << "\" :" << endl;
    int i =1;
    for (Group :: iterator file = this->begin(); file != this->end(); file++){
        out <<  endl << "file n°" << i++ << endl;  
        
        (*file)->infos_out(out);
    }
}
