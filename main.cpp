#include <iostream>
#include <string>
#include "src.h"

using namespace std;

int main(int argc, char **argv)
{
    string txtPath = "./data/Up1.txt";
    string xmlPath = "./data/result.xml";

    if(argc > 1)
    {
        cout << "argv0 = " << argv[0] << endl;
        cout << "argv1 = " << argv[1] << endl;
        cout << "argv2 = " << argv[2] << endl;
        txtPath = argv[1];
        xmlPath = argv[2];
    }

    Txt2Xml txt2xml(txtPath, xmlPath);
    txt2xml.readtxt();
    txt2xml.writexml();

	return 0;
}
