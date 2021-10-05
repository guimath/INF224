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
{
    Video(name, path, duration);
    * m_chapter_durations = *chapter_durations; // copies whats pointed
    m_chapter_nb = chapter_nb;
}

int * Film::get_chapters(void) const 
{
    
}
