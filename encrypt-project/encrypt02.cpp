#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main ()
{
    string filename;
    char ch;
    fstream fps;
    fstream fpt;

    cout <<"Enter file Name, Location and Extension: ";
    getline(cin, filename);
    fps.open(filename, fstream::in);
    if (!fps)
    {
        cout <<"\nError Occurred, Openning the source file !";
        return 0;
    }

    fpt.open("tmp.txt", fstream::out);
    if (!fpt)
    {
        cout <<"\nError Occurred, Openning/Creating the tmp file!";
        return 0;
    }

    while (fps.get(ch))
    {
        fpt.put(ch);
    }

    fps.close();
    fpt.close();
    fps.open(filename, fstream::out);
    if (!fps)
    {
        cout <<"\nError Occurred, Openning the source file !";
        return 0;
    }

    fpt.open("tmp.txt", fstream::in);
    if (!fpt)
    {
        cout <<"\n Error Occurred, Openning the tmp file !";
        return 0;
    }

    while (fpt.get(ch))
    {
        fps.put(ch);
    }

    fps.close();
    fpt.close();
    cout <<"\nFile '"<<filename<<"' Encrypted Successfully!";
}