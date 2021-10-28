#ifndef DEF_VIDEO
#define DEF_VIDEO


#include <string>
#include <iostream>
#include <tuple>

#include "Multimedia.h"

/**
 *	@brief A class that represents a video file 
 *	
 *	@author guimath
 */
class Video : public Multimedia 
{
    private :

    /** The duration of the video */
    int m_duration;

    /** The name of the program with which 
     * images should be red */
    std::string m_OPEN_PRG;

    /**
     * @brief check what image program are available 
     * and picks best one
     * 
     */
    void update_open_prg();

    public :
    
    /**
     * @brief Construct a new Video object
     * 
     */
    Video();

    /**
     * @brief Construct a new Video object
     *
     * @param name The name of the file
     * @param path The path to the file
     * @param duration The length of the video
     */    
    Video(std::string name, std::string path, int duration);
    
    /**
     * @brief Destroy the Video object
     * 
     */
    ~Video();
    
    /**
     * @brief open the video
     * 
     */
    void open() const override;

    /**
     * @brief prints infos of the object to the given output
     * 
     * @param out outstream where info will be printed
     */
    void infos_out(std::ostream & out) const override;
    
    /**
     * @brief Get the duration instance
     * 
     * @return The duration
     */
    int get_duration() const;

    /**
     * @brief Set the duration instance
     * 
     * @param duration The duration
     */
    void set_duration(int duration);
};


#endif
