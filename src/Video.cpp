#include "Video.h"


void Video::update_open_prg(void) 
{
    m_OPEN_PRG = "mpv ";
    std::string chain = "which feh > /dev/null 2>&1"; // > dev/null to hide output
    if (system(chain.c_str())){
            
        m_OPEN_PRG = "xdg-open ";
    }
    
    //std::cout << "Using " << m_OPEN_PRG << "to open videos" << endl;
}

Video::Video():m_duration(0)
{
    update_open_prg();
}

Video::Video(std::string name, std::string path, int duration)
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
    std::string chain = m_OPEN_PRG + get_path() + HIDE_PRINT;
    system(chain.c_str());
}

void Video::infos_out(std::ostream & out) const
{
    Multimedia::infos_out(out);
    out << "duration : " << m_duration << std::endl;
}

int Video::get_duration() const
{
    return m_duration;
}

void Video::set_duration(int duration)
{
    m_duration = duration;
}