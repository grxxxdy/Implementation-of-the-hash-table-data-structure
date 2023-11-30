#include <string>
#include <cmath>

using namespace std;

struct Data
{
    /*string name;
    string subject;
    int micQuality;*/

    char name;
    char subject;
    int micQuality;


    Data()
    {
        /*string temp = to_string((1 + rand() % 100));
        name = "Teacher " + temp;
        subject = "Subject " + temp;
        micQuality = 1 + rand() % 100;*/

        name = '1';
        subject = '1';
        micQuality = 1 + rand() % 100;
    }
};

struct Element
{
    Data value;
    long long int key;
};