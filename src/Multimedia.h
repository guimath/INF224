#ifndef DEF_MULTIMEDIA
#define DEF_MULTIMEDIA

#include <string>
#include <iostream>

#define HIDE_PRINT " > /dev/null 2>&1"

/**
 * @brief An abstract base class that represents a Multimedia file
 * 
 * @author guimath
 */
class Multimedia 
{
    protected :

    /** The name of the multimedia file */
    std::string m_name;

    /** The path to the multimedia file */
    std::string m_path;

    public :

    /**
     * @brief Construct a new Multimedia object
     * 
     * @param name The name of the file
     * @param path The path to the file
     */
    Multimedia(std::string name="", std::string path="");
    
    /**
     * @brief Destroy the Multimedia object
     * 
     */
    ~Multimedia();

    /**
     * @brief prints infos of the object to the given output
     * 
     * @param out outstream where info will be printed
     */ 
    virtual void infos_out(std::ostream & out) const;

    /**
     * @brief Get the name instance
     * 
     * @return the name of the file 
     */
    std::string get_name() const;

    /**
     * @brief Get the path instance
     * 
     * @return The path to the file
     */
    std::string get_path() const;

    /**
     * @brief Set the path instance
     * 
     * @param path The path to the file
     */
    void set_path(std::string path);

    /**
     * @brief Set the name instance
     * 
     * @param name The name of the file
     */
    void set_name(std::string name);   

    
    /**
     * @brief virtual function to open the file
     * 
     */
    virtual void open(void) const {}
};

#endif