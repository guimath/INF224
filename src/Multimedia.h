#ifndef DEF_MULTIMEDIA
#define DEF_MULTIMEDIA

#include <string>
#include <iostream>

/**
	An abstract base class that represents a Multimedia file 
	
	@author guimath
*/

class Multimedia 
{
    private :

    /** The name of the multimedia file */
    std::string m_name;

    /** The path to the multimedia file */
    std::string m_path;

    public :
    
    /**
        constructor that takes in no params and initializes 
        name as "multimedia" and path as "NA".
    */    
    Multimedia();

    /**
        constructor that takes in name and path 
        
        @param name The name of the file
        @param path The path to the file
    */    
    Multimedia(std::string name, std::string path);
    
    /**
        destructor
    */    
    ~Multimedia();

    /**
        Function that prints to given output infos about file
        
        @param out The outstream where infos will be printed
    */    
    void infos_out(std::ostream & out) const;

    /**
        getter of name instance

        @return The name of the multimedia file
    */    
    std::string get_name() const;

    /**
        getter of path instance

        @return The path to the multimedia file
    */    
    std::string get_path() const;

    /**
        setter of path instance

        @param path The new path to the multimedia file
    */    
    void set_path(std::string path);

    /**
        setter of name instance

        @param name The new name to the multimedia file
    */    
    void set_name(std::string name);   

    
    /**
       Function to open the file 
    */
    virtual void open(void) const {}
};

#endif