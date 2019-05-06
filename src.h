#include <string>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <assert.h>
#include "Tinyxml/tinyxml.h"

class Txt2Xml
{
    struct Fisheye
    {
        int IMAGETYPE = 3;
        int CROPMODE = 1;
        double HFOV = 0;
        double VFOV = 140;
        double Alpha = 0;
        double Beta = 0;
        double Gamma = 0;
        double ShiftX = 0;
        double ShiftY = 0;
        double ShearX = 0;
        double ShearY = 0;
        int CROPLEFT = 0;
        int CROPRIGHT = 0;
        int CROPTOP = 0;
        int CROPBOTTOM = 0;
        double CircleX = 0;
        double CircleY = 0;
        double CircleR = 0;
        double YAW = 0;
        double PITCH = 0;
        double ROLL = 0;
    };
public:
    Txt2Xml(std::string txtpath, std::string xmlpath);
    void readtxt();
    void writexml();

private:
    void getfisheyedata(std::string data, int n);

    Fisheye fisheyeData_[4];
    std::string txtPath_;
    std::string xmlPath_;
};
