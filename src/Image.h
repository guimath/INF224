#ifndef DEF_IMAGE
#define DEF_IMAGE

#include <string>
#include <iostream>
#include <tuple>

#include "Multimedia.h"

/**
 *	@brief A class that represents an image file 
 *	
 *	@author guimath
 */
class Image : public Multimedia 
{
    private :

    /** The Length x Width dimensions */
    std::tuple<int, int> m_dimensions;

    /** The name of the program with which 
     * images should be red */
    std::string m_OPEN_PRG;

    /**
     * @brief check what image program are available 
     * and picks best one
     * 
     */
    void update_open_prg(void) ;

    public :
    
    /**
     * @brief Construct a new Image object
     * 
     */
    Image();


    /**
     * @brief Construct a new Image object
     * 
     * @param name The name of the file
     * @param path The path of the file
     * @param length The length of the image
     * @param width The width of the image
     */
    Image(std::string name, std::string path, int length, int width);
    
    /**
     * @brief Destroy the Image object
     * 
     */
    ~Image();
    
    /**
     * @brief open the image
     * 
     */
    void open(void) const override;

    /**
     * @brief prints infos of the object to the given output
     * 
     * @param out outstream where info will be printed
     */
    void infos_out(std::ostream & out) const override;

    /**
     * @brief Get the dimensions instance
     * 
     * @return A tuple containing length and width
     */
    std::tuple<int, int> get_dimensions() const;

    /**
     * @brief Set the dimensions instance
     * 
     * @param length The length of the image
     * @param width The width of the image
     */
    void set_dimensions(int length, int width);
};


void Image::update_open_prg(void) 
{
    m_OPEN_PRG = "feh ";
    std::string chain = "which feh > /dev/null 2>&1"; // > dev/null to hide output
    if (system(chain.c_str())){
        
        m_OPEN_PRG = "imagej ";
        chain = "which imagej > /dev/null 2>&1";
        if (system(chain.c_str())){
            
            m_OPEN_PRG = "xdg-open ";
        }
        
    }
    //std::cout << "Using " << m_OPEN_PRG << "to open images"<< endl;
}

Image::Image()
{
    m_dimensions = {0,0};
    update_open_prg();
}

Image::Image(std::string name, std::string path, int length, int width)
{
    set_name(name);
    set_path(path);
    m_dimensions = {length, width};
    
    update_open_prg();

}

Image::~Image()
{

}

void Image::open(void) const 
{   
    std::string chain = m_OPEN_PRG + get_path() + HIDE_PRINT;;
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

