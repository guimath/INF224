#include "Film.h"

using namespace std;

Film::Film()
{
    m_chapter_durations = nullptr;
    m_chapter_nb = 0;
}

Film::Film(std::string name, 
           std::string path, 
           int duration, 
           int* chapter_durations, 
           int chapter_nb)
    :Video(name, path, duration)
    
{
    m_chapter_nb = chapter_nb;

    for (int i=0; i<chapter_nb; i++){
        * (m_chapter_durations+i) = *(chapter_durations+i); // copies whats pointed
    }
}

Film::~Film()
{
    delete[] m_chapter_durations;
}

int * Film::get_chapter_durations(void) const 
{
    return m_chapter_durations;
}

int Film::get_chapter_nb() const
{
    return m_chapter_nb;
}

void Film::set_chapter_durations(int* chapter_durations, int chapter_nb)
{
    m_chapter_nb = chapter_nb;
    * m_chapter_durations = *chapter_durations;
}

void Film::infos_out(std::ostream & out) const
{
    Video::infos_out(out);
    for (int i=0; i < m_chapter_nb;i++)
    {
        out << "chapter " << i+1 << " : " << *(m_chapter_durations +i)<< std::endl;
    }
}