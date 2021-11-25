#include "Film.h"

using namespace std;

Film::Film(string name, 
           string path, 
           int duration, 
           int* chapter_durations, 
           int chapter_nb)
    :Video(name, path, duration)
    
{
    m_chapter_nb = chapter_nb;
    m_chapter_durations = new int [m_chapter_nb]; // Allocating memory

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
    // making an accessible array 
    int * temp = new int [m_chapter_nb];
    // copying new infos
    for (int i=0; i<m_chapter_nb; i++){
        * (temp+i) = *(m_chapter_durations+i);
    }
    return temp;
}

int Film::get_chapter_nb() const
{
    return m_chapter_nb;
}

void Film::set_chapter_durations(int* chapter_durations, int chapter_nb)
{
    if (m_chapter_nb != chapter_nb){
        m_chapter_nb = chapter_nb; //updating
        
        delete[] m_chapter_durations; //deleting and recreating because size changed
        m_chapter_durations = new int [m_chapter_nb];
    }
    
    // copying new infos
    for (int i=0; i < m_chapter_nb; i++){
        * (m_chapter_durations+i) = *(chapter_durations+i);
    }
}

void Film::infos_out(ostream & out) const
{
    Video::infos_out(out);
    for (int i=0; i < m_chapter_nb;i++)
    {
        out << "chapter " << i+1 << " : " << *(m_chapter_durations +i)<< endl;
    }
}