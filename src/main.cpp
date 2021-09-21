#include "Multimedia.h"
#include <iostream>
using namespace std;

#define STEP 3

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
int main(int argc, const char* argv[])
{
    cout << endl << "Testing Step " << STEP << endl << endl;
}

#endif

