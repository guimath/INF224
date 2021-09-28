#include <iostream>
using namespace std;

#define STEP 4

#include "Multimedia.h"

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
    
    Image *file1 = new Image ("image_test", "arco.jpg", 400, 100);
    Video *file2 = new Video ("video_test", "woof.mp4", 14);
    
    cout << "file1" << endl;
    file1->infos_out(cout);

    cout <<  endl << "file2" << endl;
    file2->infos_out(cout);

    return 0;
}

#endif

