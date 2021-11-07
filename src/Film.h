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
    int * m_chapter_durations=nullptr;

    /** number of chapters */
    int m_chapter_nb;

    public:

    /**
     * @brief Construct a new Film object
     * 
     * @param name The name of the file
     * @param path The path to the file
     * @param duration The total duration of the video
     * @param chapter_durations a pointer containing the different durations of each chapter
     * @param chapter_nb The number of chapters
     */
    Film(std::string name="", 
           std::string path="", 
           int duration=0, 
           int* chapter_durations=nullptr, 
           int chapter_nb=0);

    /**
     * @brief Destroy the Film object
     * 
     */
    ~Film();

    /**
     * @brief Get the chapter_durations instance
     * 
     * @return the chapter_durations instance
     */
    int * get_chapter_durations() const;

    /**
     * @brief Get the chapter_nb instance
     * 
     * @return The chapter_nb instance
     */
    int get_chapter_nb() const;

    /**
     * @brief Set the chapter_durations instance
     * 
     * @param chapter_durations a ptr containing all chapter durations
     * @param chapter_nb the number of chapters
     */
    void set_chapter_durations(int* chapter_durations, int chapter_nb);

    /**
     * @brief prints infos of the object to the given output
     * 
     * @param out outstream where info will be printed
     */
    void infos_out(std::ostream & out) const override;
    
};

#endif