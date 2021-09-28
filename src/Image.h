#ifndef DEF_IMAGE
#define DEF_IMAGE

#include <string>
#include <iostream>
#include <tuple>

#include "Multimedia.h"
/**
	A class that represents an image file 
	
	@author guimath
*/

class Image : public Multimedia 
{
    private :

    /** The Length x Width dimensions */
    std::tuple<int, int> m_dimensions;

    public :
    
    /**
        constructor that takes in no params and initializes 
        class
    */    
    Image();

    /**
        constructor that takes in all infos of the file
        
        @param name The name of the file
        @param path The path to the file
        @param length The length of the image
        @param width The width of the image
    */    
    Image(std::string name, std::string path, int length, int width);
    
    /**
        destructor
    */    
    ~Image();
    
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
        getter of length and width instance

        @return A tuple containing length and width
    */    
    std::tuple<int, int> get_dimensions() const;

    /**
        setter of dimensions instance

        @param length The length of the image
        @param width The width of the image
    */    
    void set_dimensions(int length, int width);
};


Image::Image()
{
    m_dimensions = {0,0};
}

Image::Image(std::string name, std::string path, int length, int width)
{
    set_name(name);
    set_path(path);
    m_dimensions = {length, width};
}

Image::~Image()
{

}

void Image::open(void) const 
{   
    std::string chain = "imagej "+ get_path() + " &";

    system(chain.c_str());
}

//override
void Image::infos_out(std::ostream & out) const 
{
    out << "File : " << get_path() << std::endl;
    out << "Name : " << get_name() << std::endl;
    out << "dimensions (LxW) : " << get<0>(m_dimensions) << "x" << get<1>(m_dimensions) << std::endl;
}


std::tuple<int, int> Image::get_dimensions() const
{
    return m_dimensions;
}

void Image::set_dimensions(int length, int width)
{
    m_dimensions = {length, width};
}



#endif

