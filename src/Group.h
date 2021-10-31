#ifndef DEF_GROUP
#define DEF_GROUP

#include "Multimedia.h"

#include <list>
#include <memory>

/**
 *	@brief A class that represents a group of multimedia files 
 *	
 *	@author guimath
 */
class Group : public std::list< std::shared_ptr< Multimedia > >
{
private:
    /** Group name */
    std::string m_name;

public:
    /**
     * @brief Construct a new Group object
     * 
     * @param name The name of the group
     */
    Group(std::string name);

    /**
     * @brief Get the name instance
     * 
     * @return the name instance
     */
    std::string get_name() const;

    /**
     * @brief Set the name instance
     * 
     * @param name the new name of group
     */
    void set_name(std::string name);

    /**
     * @brief prints infos of the object to the given output
     * 
     * @param out outstream where info will be printed
     */
    void infos_out(std::ostream &out);
};

#endif