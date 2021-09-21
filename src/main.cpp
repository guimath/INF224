#include "Multimedia.h"
#include <iostream>
using namespace std;

#define STEP 3

#if STEP == 3
int main(int argc, const char* argv[])
{
    cout << endl << "Testing Step " << STEP << endl << endl;
    
    // Creating instances 
    Multimedia *fichier1 = new Multimedia("music_test", "/test1.mp3");
    Multimedia *fichier2 = new Multimedia("image_test","/test2.png");
    Multimedia *fichier3 = new Multimedia();

    fichier3->set_name("video_test");
    fichier3->set_path("/test3.mp4");
    cout << "fichier1" << endl;
    fichier1->infos_out(cout);

    cout << endl << "fichier2" << endl;
    fichier2->infos_out(cout);

    cout << endl << "fichier3" << endl;
    fichier3->infos_out(cout);
    return 0;
}

#elif STEP == 4
int main(int argc, const char* argv[])
{
    cout << endl << "Testing Step " << STEP << endl << endl;
}

#endif

