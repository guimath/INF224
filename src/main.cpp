#include <iostream>
using namespace std;

#define STEP 5

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
    
    Film * file1 = new Film ("first video", VID_PATH, 14, chapter_durations,3);
    // diplaying infos
    file1 ->infos_out(cout);
    return 0;
} 
#endif 
 