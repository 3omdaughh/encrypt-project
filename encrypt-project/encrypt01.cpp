#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

int main ()
{
    char filename[30];
    char ch;
    fstream fps;
    fstream fpt;

    cout <<"Enter file Name, Location and Extension: ";
    gets(filename);
    fps.open(filename,fstream::in);
    if (!fps)
    {
        cout <<"\nError Occurred, Openning the source file !";
        return 0;
    }

    fpt.open("tmp.txt,fstream::out");
    if (!fpt)
    {
        cout <<"\nError Occurred, Openning/Creating the tmp file!";
        return 0;
    }

    while (fps>>noskipws>>ch)
    {
        ch=ch+100;
        fpt<<ch;
    }

    fps.close();
    fpt.close();
    fps.open(filename,fstream::out);
    if (!fps)
    {
        cout <<"\nError Occurred, Openning the source file !";
        return 0;
    }

    fpt.open("tmp.txt",fstream::in);
    if (!fpt)
    {
        cout <<"\n Error Occurred, Openning the tmp file !";
        return 0;
    }

    while (fpt>>noskipws>>ch)
    {
        fps<<ch;
    }

    fps.close();
    fpt.close();
    cout <<"\nFile '"<<filename<<"' Encrypted Successfully!";
    cout << endl;
    return 0;

}