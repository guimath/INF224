#include "Video.h"

using namespace std;

void Video::update_open_prg(void) 
{
    m_OPEN_PRG = "mpv ";
    string chain = "which feh > /dev/null 2>&1"; // > dev/null to hide output
    if (system(chain.c_str())){
            
        m_OPEN_PRG = "xdg-open ";
    }
    
    //cout << "Using " << m_OPEN_PRG << "to open videos" << endl;
}

Video::Video():m_duration(0)
{
    update_open_prg();
}

Video::Video(string name, string path, int duration)
    :Multimedia(name, path),
    m_duration(duration)
{
    update_open_prg();
}

Video::~Video()
{

}

void Video::open() const 
{
    string chain = m_OPEN_PRG + get_path() + HIDE_PRINT;
    system(chain.c_str());
}

void Video::infos_out(ostream & out) const
{
    Multimedia::infos_out(out);
    out << "duration : " << m_duration << endl;
}

int Video::get_duration() const
{
    return m_duration;
}

void Video::set_duration(int duration)
{
    m_duration = duration;
}