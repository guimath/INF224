#include <iostream>
using namespace std;

#define STEP 11

#include "Multimedia.h"

#define IMG_PATH "res/arco.jpg"
#define VID_PATH "res/woof.mp4"

#if STEP == 3
int main(int argc, const char* argv[])
{
    cout << endl << "Testing Step " << STEP << endl << endl;
    
    // Creating instances 
    Multimedia *file1 = new Multimedia("music_test", "/test1.mp3");
    Multimedia *file2 = new Multimedia("image_test","/test2.png");
    Multimedia *file3 = new Multimedia();

    file3->set_name("video_test");
    file3->set_path("/test3.mp4");
    cout << "file1" << endl;
    file1->infos_out(cout);

    cout << endl << "file2" << endl;
    file2->infos_out(cout);

    cout << endl << "file3" << endl;
    file3->infos_out(cout);
    return 0;
}

#elif STEP == 4
#include "Image.h"
#include "Video.h"

int main(int argc, const char* argv[])
{
    cout << endl << "Testing Step " << STEP << endl << endl;
    
    Image *file1 = new Image ("image_test", IMG_PATH, 400, 100);
    Video *file2 = new Video ("video_test", VID_PATH, 14);
    
    cout << endl << "file1" << endl;
    file1->infos_out(cout);

    cout <<  endl << "file2" << endl;
    file2->infos_out(cout);

    return 0;
    // method open is declared as abstract (virtual) in multimedia
}

#elif STEP == 5
#include "Image.h"
#include "Video.h"  
int main(int argc, const char* argv[])  
{
    cout << endl << "Testing Step " << STEP << endl << endl;

    //creating tab
    Multimedia ** file = new Multimedia * [4];
    file[0] = new Image ("first image", IMG_PATH, 400, 100);
    file[1] = new Video ("first video", VID_PATH, 14);
    file[2] = new Image("second image","place_holder.jpg",800,100);
    file[3] = new Video("second video","place_holder.mp4",203);
 
    // diplaying infos
    for (int i=0; i<4; i++)
    {
        cout <<  endl << "file n°" << i+1 << endl;  
        file[i]->infos_out(cout);
    }
    return 0;
} 

#elif STEP == 6
#include "Film.h"    

int main(int argc, const char* argv[])  
{
    cout << endl << "Testing Step " << STEP << endl << endl;

    int * chapter_durations = new int [3];
    chapter_durations[0] = 12;
    chapter_durations[1] = 5;
    chapter_durations[2] = 76;
    
    //testing constructor and display info
    Film * file1 = new Film ("first video", VID_PATH, 14, chapter_durations,3);
    delete[] chapter_durations;
    file1 ->infos_out(cout);

    //testing modifer
    chapter_durations = new int[4];
    chapter_durations[0] = 5;
    chapter_durations[1] = 5;
    chapter_durations[2] = 5;
    chapter_durations[3] = 5;
    file1->set_chapter_durations(chapter_durations, 4);
    file1 ->infos_out(cout);

    return 0;
} 

#elif STEP == 7
#include "Image.h"
#include "Video.h"  
#include "Film.h"    

int main(int argc, const char* argv[])  
{
    cout << endl << "Testing Step " << STEP << endl << endl;

    int * chapter_durations = new int [3];
    chapter_durations[0] = 12;
    chapter_durations[1] = 5;
    chapter_durations[2] = 76;
    
    Multimedia ** file = new Multimedia * [3];
    file[0] = new Image ("first image", IMG_PATH, 400, 100);
    file[1] = new Video ("first video", VID_PATH, 14);
    file[2] = new Film ("first video", VID_PATH, 14, chapter_durations,3);
    //testing constructor and display info
    
    // diplaying infos
    for (int i=0; i<3; i++)
    {
        cout <<  endl << "file n°" << i+1 << endl;  
        file[i]->infos_out(cout);
    }
    delete [] file;
}

#elif STEP == 8 || STEP == 9
#include "Image.h"
#include "Video.h"  
#include "Film.h"
#include "Group.h"    
#include <memory>
#include <list>

int main(int argc, const char* argv[])  
{
    cout << endl << "Testing Step " << STEP << endl << endl;

    int * chapter_durations = new int [3];
    chapter_durations[0] = 12;
    chapter_durations[1] = 5;
    chapter_durations[2] = 76;

    shared_ptr<Multimedia> img0 (new Image ("first image", IMG_PATH, 400, 100));
    shared_ptr<Multimedia> vid0 (new Video ("first video", VID_PATH, 14));
    shared_ptr<Multimedia> img1 (new Image ("second image", IMG_PATH, 400, 100));
    shared_ptr<Multimedia> vid1 (new Video ("second video", VID_PATH, 14));
    shared_ptr<Multimedia> mov1 (new Film ("first film", VID_PATH, 14, chapter_durations,3));


    Group * test_group1 = new Group ("first group");
    Group * test_group2 = new Group ("second group");

    test_group1->push_back(img0);
    test_group1->push_back(vid0);
    test_group1->push_back(mov1);

    test_group2->push_back(img1);
    test_group2->push_back(vid1);
    test_group2->push_back(mov1);

    test_group1->infos_out(cout);
    cout << endl;
    test_group2->infos_out(cout);
     

}

#elif STEP == 10
#include "Image.h"
#include "Video.h"  
#include "Film.h"
#include "Group.h"   
#include "FileProcSys.h" 
#include <memory>
#include <list>

int main(int argc, const char* argv[])  
{
    cout << endl << "Testing Step " << STEP << endl << endl;

    int * chapter_durations = new int [3];
    chapter_durations[0] = 12;
    chapter_durations[1] = 5;
    chapter_durations[2] = 76;
    

    // create fps
    FileProcSys * fps = new FileProcSys();

    // adding files
    fps->create_image("first image", IMG_PATH, 400, 100);
    fps->create_video("first video", VID_PATH, 14);
    fps->create_image("second image", IMG_PATH, 400, 100);
    fps->create_video("second video", VID_PATH, 14);
    fps->create_film ("first film", VID_PATH, 14, chapter_durations,3);

    // adding groups
    shared_ptr<Group> test_group1 = fps->create_group("first group");
    shared_ptr<Group> test_group2 = fps->create_group("second group");

    // filling groups
    test_group1->push_back(fps->get_file("first image"));
    test_group1->push_back(fps->get_file("first video"));
    test_group1->push_back(fps->get_file("first film"));

    test_group2->push_back(fps->get_file("second image"));
    test_group2->push_back(fps->get_file("second video"));
    test_group2->push_back(fps->get_file("first film"));

    // testing fps 
    fps->infos_out("first group", cout);
    cout << endl;
    fps->infos_out("second group", cout);
    fps->open("first image");

    /* Question : comment peut-on interdire la création d'objet multimedia hors de la classe de manipulation ?
    reponse : on déclare le constructeur en private et on rajoute la classe FileProcSys en friend
    https://en.wikipedia.org/wiki/Friend_class*/
}


#elif STEP == 11 //client serveur
#include "Image.h"
#include "Video.h"  
#include "Film.h"
#include "Group.h"   
#include "FileProcSys.h" 
#include "CppSocket.h"
#include "TcpServer.h"
#include <memory>
#include <list>
using namespace cppu;

int main(int argc, const char* argv[])  
{
    cout << endl << "Testing Step " << STEP << endl << endl;

    int * chapter_durations = new int [3];
    chapter_durations[0] = 12;
    chapter_durations[1] = 5;
    chapter_durations[2] = 76;
    
    // create fps
    FileProcSys * fps = new FileProcSys();

    // adding files
    fps->create_image("first_img", IMG_PATH, 400, 100);
    fps->create_video("first_vid", VID_PATH, 14);
    fps->create_image("sec_img", IMG_PATH, 400, 100);
    fps->create_video("sec_vid", VID_PATH, 14);
    fps->create_film ("first_film", VID_PATH, 14, chapter_durations,3);

    // adding groups
    shared_ptr<Group> test_group1 = fps->create_group("first_group");
    shared_ptr<Group> test_group2 = fps->create_group("second_group");

    // filling groups
    test_group1->push_back(fps->get_file("first_img"));
    test_group1->push_back(fps->get_file("first_vid"));
    test_group1->push_back(fps->get_file("first_film"));

    test_group2->push_back(fps->get_file("sec_img"));
    test_group2->push_back(fps->get_file("sec_vid"));
    test_group2->push_back(fps->get_file("first_film"));

    // starting serv 
    shared_ptr<TCPServer> server(new TCPServer());
    
    server->setCallback(*fps, &FileProcSys::process_request);

    int status = server->run(3331);

}
#endif 



