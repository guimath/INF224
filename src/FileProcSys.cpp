#include "FileProcSys.h"

using namespace std;
using namespace cppu;

FileProcSys::FileProcSys() 
{

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


bool FileProcSys::process_request(TCPConnection& cnx, const string& request, string& response) 
{
    // request type <target> <action>
    
    // parsing request :
    string target = request.substr(0, request.find(" "));
    string action = request.substr(request.find(" ")+1);
    
    //cout << "[debug] target = " << target << endl;
    //cout << "[debug] action = " << action << endl;

    stringstream answer;

    // locking in case multiple clients (add writeMode=true if changing infos)
    TCPLock lock(cnx);

    actions_map["open"] = [&](){
        if (open(target)) answer << "Opening file \"" << target << "\"";
        else              answer << "file \"" << target << "\" not found";
    };

    actions_map["infos"] = [&](){
        if (!infos_out(target, answer)) answer << "file \"" << target << "\" not found";
    };

    // processing request
    if (actions_map.find(action)!=actions_map.end()) actions_map[action]();
    else answer << "incorrect action, actions are : open, infos.";

    // response 
    response = answer.str();
    replace(response.begin(), response.end(), '\n', ' '); // removing line breaks (used in com)

    // keeping connection open
    return true;
}