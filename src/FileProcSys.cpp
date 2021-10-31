#include "FileProcSys.h"

using namespace std;

FileProcSys::FileProcSys() 
{
    // pass
}


std::shared_ptr<Image> FileProcSys::create_image(string name, string path, float length, float width)
{
    shared_ptr<Image> temp (new Image(name, path, length, width));
    file_map[name]=temp;
    return temp;
}

std::shared_ptr<Video> FileProcSys::create_video(string name, string path, int duration)
{
    shared_ptr<Video> temp (new Video(name, path, duration));
    file_map[name]=temp;
    return temp;
}

std::shared_ptr<Film> FileProcSys::create_film(string name, string path, int duration, int * chapter_durations, int chapter_nb)
{
    shared_ptr<Film> temp (new Film(name, path, duration, chapter_durations, chapter_nb));
    file_map[name]=temp;
    return temp;
}

shared_ptr<Group> FileProcSys::create_group(string name)
{
    shared_ptr<Group> temp (new Group(name));
    group_map[name]=temp;
    return temp;
}

bool FileProcSys::infos_out(string name, ostream& out) 
{
    if (file_map.find(name)!=file_map.end()){
        file_map[name]->infos_out(out);
        return true;
    }
    else if (group_map.find(name)!=group_map.end()){
        group_map[name]->infos_out(out);
        return true;
    }
    else return false;
}

bool FileProcSys::open(string name) 
{
    if (file_map.find(name)!=file_map.end()){
        file_map[name]->open();
        return true;
    }
    /*else if (group_map.find(name)!=group_map.end()){
        group_map[name]->open();
        return true;
    }*/
    else return false;
}

std::shared_ptr<Multimedia> FileProcSys::get_file(std::string name) 
{
    if (file_map.find(name)!=file_map.end()){
        return file_map[name];
    }
    else return nullptr;
}

std::shared_ptr<Group> FileProcSys::get_group(std::string name) 
{
    if (group_map.find(name)!=group_map.end()){
        return group_map[name];
    }
    else return nullptr;
}