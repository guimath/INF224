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
    std::string m_group_name;

public:
    /**
     * @brief Construct a new Group object
     * 
     * @param group_name The name of the group
     */
    Group(std::string group_name);

    /**
     * @brief Get the group_name instance
     * 
     * @return the group_name instance
     */
    std::string get_group_name() const;

    /**
     * @brief Set the group_name instance
     * 
     * @param group_name the new name of group
     */
    void set_group_name(std::string group_name);

    /**
     * @brief prints infos of the object to the given output
     * 
     * @param out outstream where info will be printed
     */
    void infos_out(std::ostream &out);
};

#endif