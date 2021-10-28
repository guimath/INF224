#include "Image.h"
#include<tuple>

using namespace std;

void Image::update_open_prg(void) 
{
    m_OPEN_PRG = "feh ";
    string chain = "which feh > /dev/null 2>&1"; // > dev/null to hide output
    if (system(chain.c_str())){
        
        m_OPEN_PRG = "imagej ";
        chain = "which imagej > /dev/null 2>&1";
        if (system(chain.c_str())){
            
            m_OPEN_PRG = "xdg-open ";
        }
        
    }
    //cout << "Using " << m_OPEN_PRG << "to open images"<< endl;
}

Image::Image():m_dimensions({0,0})
{
    update_open_prg();
}

Image::Image(string name, string path, int length, int width)
    :Multimedia(name, path),
    m_dimensions({length, width})
{
    update_open_prg();
}

Image::~Image()
{

}

void Image::open(void) const 
{   
    string chain = m_OPEN_PRG + get_path() + HIDE_PRINT;;
    system(chain.c_str());
    
}

//override
void Image::infos_out(ostream & out) const 
{
    Multimedia::infos_out(out);
    out << "dimensions (LxW) : " << get<0>(m_dimensions) << "x" << get<1>(m_dimensions) << endl;
}


tuple<int, int> Image::get_dimensions() const
{
    return m_dimensions;
}

void Image::set_dimensions(int length, int width)
{
    m_dimensions = {length, width};
}