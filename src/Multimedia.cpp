#include "Multimedia.h"

using namespace std;

Multimedia::Multimedia(string name, string path):m_name(name), m_path(path)
{

} 

void Multimedia::infos_out(ostream & out) const
{
    // see https://gcc.gnu.org/onlinedocs/libstdc++/manual/streambufs.html#io.streambuf.buffering 
    // (endl might not be best idea)
    out << "File : " << m_path << endl;
    out << "Name : " << m_name << endl;
}

string Multimedia::get_name() const 
{
    return m_name;
}

string Multimedia::get_path() const 
{
    return m_path;
}

void Multimedia::set_name(string name)
{
    m_name = name;
}

void Multimedia::set_path(string path)
{
    m_path = path;
}


