#ifndef DEF_VIDEO
#define DEF_VIDEO


#include <string>
#include <iostream>
#include <tuple>

#include "Multimedia.h"
/**
	A class that represents an Video file 
	
	@author guimath
*/

class Video : public Multimedia 
{
    private :

    /** The duration of the video */
    int m_duration;

    public :
    
    /**
        constructor that takes in no params and initializes 
        class
    */    
    Video();

    /**
        constructor that takes in all infos of the file
        
        @param name The name of the file
        @param path The path to the file
        @param duration The length of the video
    */    
    Video(std::string name, std::string path, int duration);
    
    /**
        destructor
    */    
    ~Video();
    
    /**
       Function to open the file 
    */
    void open(void) const ;

    /**
        Function that prints to given output infos about file
        
        @param out The outstream where infos will be printed
    */    
    void infos_out(std::ostream & out) const;
    
    /**
        getter of duration instance

        @return The duration of the video
    */    
    int get_duration() const;

    /**
        setter of duration instance

        @param duration The duration of the video
    */    
    void set_duration(int duration);
};


Video::Video()
{
    m_duration = 0;
}

Video::Video(std::string name, std::string path, int duration)
{
    set_name(name);
    set_path(path);
    m_duration = duration;
}

Video::~Video()
{

}

void Video::open(void) const 
{   
    std::string chain = "mpv "+ get_path() + " &";

    system(chain.c_str());
}

//override
void Video::infos_out(std::ostream & out) const 
{
    out << "File : " << get_path() << std::endl;
    out << "Name : " << get_name() << std::endl;
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



#endif

