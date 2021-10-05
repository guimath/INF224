#ifndef DEF_FILM
#define DEF_FILM

#include <string>
#include <iostream>

#include "Video.h"
 
/**
 *	@brief A class that represents an Film file 
 *	
 *	@author guimath
 */
class Film : public Video
{
    private:

    /** array containing all chapter durations */
    int * m_chapter_durations;

    /** number of chapters */
    int m_chapter_nb;

    public:

    /**
     * @brief Construct a new Film object
     * 
     */
    Film();

    /**
     * @brief Construct a new Film object
     * 
     * @param name The name of the file
     * @param path The path to the file
     * @param duration The total duration of the video
     */
    Film(std::string name, 
           std::string path, 
           int duration, 
           int* chapter_durations, 
           int chapter_nb);

    /**
     * @brief Destroy the Film object
     * 
     */
    ~Film() {}

    int * get_chapters(void)const;
};

#endif