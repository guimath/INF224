#include "Multimedia.h"
#include "Image.h"
#include "Video.h"  
#include "Film.h"
#include "Group.h"   
#include "FileProcSys.h" 
#include "CppSocket.h"
#include "TcpServer.h"

using namespace std;
using namespace cppu;

#define IMG_PATH  "res/first_img.jpg"
#define IMG_PATH2 "res/first_img.jpg"
#define VID_PATH  "res/first_vid.mp4"
#define VID_PATH2 "res/first_vid.mp4"
#define MOV_PATH  "res/first_vid.mp4"

// select step to test
#define STEP 11

#if STEP == 3
int main(int argc, const char* argv[])
{
    cout << endl << "Testing Step " << STEP << endl << endl;
    
    // Creating instances 
    Multimedia *file1 = new Multimedia("first_vid", VID_PATH);
    Multimedia *file2 = new Multimedia("first_img", IMG_PATH);
    Multimedia *file3 = new Multimedia();

    file3->set_name("second_vid");
    file3->set_path(VID_PATH);
    cout << "file n°1" << endl;
    file1->infos_out(cout);

    cout << endl << "file n°2" << endl;
    file2->infos_out(cout);

    cout << endl << "file n°3" << endl;
    file3->infos_out(cout);

    return 0;
}

#elif STEP == 4

int main(int argc, const char* argv[])
{
    cout << endl << "Testing Step " << STEP << endl << endl;
    
    Image *file1 = new Image ("first_img", IMG_PATH, 400, 100);
    Video *file2 = new Video ("first_vid", VID_PATH, 14);
    
    cout << endl << "file n°1" << endl;
    file1->infos_out(cout);

    cout <<  endl << "file n°2" << endl;
    file2->infos_out(cout);

    return 0;
}

#elif STEP == 5

int main(int argc, const char* argv[])  
{
    cout << endl << "Testing Step " << STEP << endl << endl;

    //creating tab
    Multimedia ** file = new Multimedia * [4];
    file[0] = new Image ("first_img", IMG_PATH, 400, 100);
    file[1] = new Video ("first_vid", VID_PATH, 14);
    file[2] = new Image("second_img", IMG_PATH2, 800, 100);
    file[3] = new Video("second_vid", VID_PATH2, 203);
 
    // diplaying infos
    for (int i=0; i<4; i++)
    {
        cout <<  endl << "file n°" << i+1 << endl;  
        file[i]->infos_out(cout);
    }
    return 0;
} 

#elif STEP == 6

int main(int argc, const char* argv[])  
{
    cout << endl << "Testing Step " << STEP << endl << endl;

    int * chapter_durations = new int [3] {12, 5, 76};
    
    //testing constructor and display info
    Film * file1 = new Film ("first_mov", MOV_PATH, 14, chapter_durations,3);
    delete[] chapter_durations; // checking that ptr is not shared.
    
    cout <<  "Before modifing chapter duration :" << endl;  
    file1 ->infos_out(cout);

    //testing modifer
    chapter_durations = new int[4] {5, 5, 5, 5};
    file1->set_chapter_durations(chapter_durations, 4);

    cout << endl << "After modifing chapter duration :" << endl;  
    file1 ->infos_out(cout);

    return 0;
} 

#elif STEP == 7  

int main(int argc, const char* argv[])  
{
    cout << endl << "Testing Step " << STEP << endl << endl;

    int * chapter_durations = new int [3] {12, 5, 76};
    
    //creating tab
    Multimedia ** file = new Multimedia * [3];
    file[0] = new Image ("first_img", IMG_PATH, 400, 100);
    file[1] = new Video ("first_vid", VID_PATH, 14);
    file[2] = new Film ("first_mov", MOV_PATH, 14, chapter_durations,3);
    
    // diplaying infos
    for (int i=0; i<3; i++)
    {
        cout <<  endl << "file n°" << i+1 << endl;  
        file[i]->infos_out(cout);
    }
    delete [] file;

    return 0;
}

#elif STEP == 8 || STEP == 9

int main(int argc, const char* argv[])  
{
    cout << endl << "Testing Step " << STEP << endl << endl;

    int * chapter_durations = new int [3] {12, 5, 76};

    //creating multimedia objs
    shared_ptr<Multimedia> img0 (new Image ("first_img", IMG_PATH, 400, 100));
    shared_ptr<Multimedia> vid0 (new Video ("first_vid", VID_PATH, 14));
    shared_ptr<Multimedia> img1 (new Image ("second_img", IMG_PATH2, 400, 100));
    shared_ptr<Multimedia> vid1 (new Video ("second_vid", VID_PATH2, 14));
    shared_ptr<Multimedia> mov1 (new Film ("first_mov", MOV_PATH, 14, chapter_durations,3));

    // creating groups and filling
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

    return 0;
}

#elif STEP == 10

int main(int argc, const char* argv[])  
{
    cout << endl << "Testing Step " << STEP << endl << endl;

    int * chapter_durations = new int [3] {12, 5, 76};

    // create fps
    FileProcSys * fps = new FileProcSys();

    // adding files
    fps->create_image("first_img", IMG_PATH, 400, 100);
    fps->create_video("first_vid", VID_PATH, 14);
    fps->create_image("second_img", IMG_PATH, 400, 100);
    fps->create_video("second_vid", VID_PATH, 14);
    fps->create_film ("first_mov", MOV_PATH, 14, chapter_durations,3);

    // adding groups
    shared_ptr<Group> test_group1 = fps->create_group("first_grp");
    shared_ptr<Group> test_group2 = fps->create_group("second_grp");

    // filling groups
    test_group1->push_back(fps->get_file("first_img"));
    test_group1->push_back(fps->get_file("first_vid"));
    test_group1->push_back(fps->get_file("first_mov"));

    test_group2->push_back(fps->get_file("second_img"));
    test_group2->push_back(fps->get_file("second_vid"));
    test_group2->push_back(fps->get_file("first_mov"));

    // testing fps 
    fps->infos_out("first_grp", cout);
    cout << endl;

    fps->infos_out("second_grp", cout);
    fps->open("first_img");

    return 0;
}


#elif STEP == 11 //client serveur


int main(int argc, const char* argv[])  
{
    cout << endl << "Testing Step " << STEP << endl << endl;

    int * chapter_durations = new int [3] {12, 5, 76};

    // create fps
    FileProcSys * fps = new FileProcSys();

    // adding files
    fps->create_image("first_img", IMG_PATH, 400, 100);
    fps->create_video("first_vid", VID_PATH, 14);
    fps->create_image("second_img", IMG_PATH2, 400, 100);
    fps->create_video("second_vid", VID_PATH2, 14);
    fps->create_film ("first_mov", MOV_PATH, 14, chapter_durations,3);

    // adding groups
    shared_ptr<Group> test_group1 = fps->create_group("first_grp");
    shared_ptr<Group> test_group2 = fps->create_group("second_grp");

    // filling groups
    test_group1->push_back(fps->get_file("first_img"));
    test_group1->push_back(fps->get_file("first_vid"));
    test_group1->push_back(fps->get_file("first_mov"));

    test_group2->push_back(fps->get_file("sec_img"));
    test_group2->push_back(fps->get_file("sec_vid"));
    test_group2->push_back(fps->get_file("first_mov"));

    // preparing serv 
    shared_ptr<TCPServer> server(new TCPServer());
    server->setCallback(*fps, &FileProcSys::process_request);

    // starting serv
    int status = server->run(3331);
    if (status<0) {
        cerr << "Can't bind on port 3331 " << endl;
        return 1;
    }

    return 0;
}


#else 

int main(int argc, const char* argv[])  
{
    cerr << endl << "Step " << STEP << " is not a valid step." << endl;
    return 0;
}
#endif 




