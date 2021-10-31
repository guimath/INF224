#ifndef __FILEPROCSYS_H__
#define __FILEPROCSYS_H__

#include <memory>
#include <string>
#include <map>

#include "Image.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"

class FileProcSys
{
private:
    /* map containing all the files */
    std::map<std::string, std::shared_ptr<Multimedia>> file_map;
    /* map containing all the groups */ 
    std::map<std::string, std::shared_ptr<Group>> group_map;
public:

    FileProcSys();

    /**
     * @brief Construct a new Image object and adds it to map
     * 
     * @param name The name of the file
     * @param path The path of the file
     * @param length The length of the image
     * @param width The width of the image
     */
    std::shared_ptr<Image> create_image(std::string name, std::string path, float length, float width);
    
    /**
     * @brief Construct a new Video object
     *
     * @param name The name of the file
     * @param path The path to the file
     * @param duration The length of the video
     */    
    std::shared_ptr<Video> create_video(std::string name, std::string path, int duration);

    /**
     * @brief Construct a new Film object and adds it to map
     * 
     * @param name The name of the file
     * @param path The path to the file
     * @param duration The total duration of the video
     * @param chapter_durations a pointer containing the different durations of each chapter
     * @param chapter_nb The number of chapters
     */
    std::shared_ptr<Film> create_film(std::string name, std::string path, int duration, int * chapter_durations, int chapter_nb);
    
    /**
     * @brief Construct a new Group object
     * 
     * @param name The name of the group
     */
    std::shared_ptr<Group> create_group(std::string name);

    /**
     * @brief displays infos for a given file or group
     * 
     * @param name The name of the file/group
     * @param os outstream where info will be printed
     * @return true if object was found
     * @return false if no matching object
     */
    bool infos_out(std::string name, std::ostream& out);

    /**
     * @brief Opens a file 
     * 
     * @param name The name of the file to be opened
     * @return true if object was found
     * @return false if no matching object
     */
    bool open(std::string name);

    /**
     * @brief Get the file with given name
     * 
     * @param name The name of the file
     * @return The file object 
     */
    std::shared_ptr<Multimedia> get_file(std::string name);

    /**
     * @brief Get the group with given name
     * 
     * @param name The name of the group
     * @return The group object
     */
    std::shared_ptr<Group> get_group(std::string name);
};


#endif // __FILEPROCSYS_H__