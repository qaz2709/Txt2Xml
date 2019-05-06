#include "src.h"

Txt2Xml::Txt2Xml(std::string txtpath, std::string xmlpath)
{
   txtPath_ = txtpath;
   xmlPath_ = xmlpath;
}

void Txt2Xml::readtxt()
{
    assert(txtPath_.data() != nullptr);
    // 1. Open the txt
    std::fstream fp;
    fp.open(txtPath_, std::ios::in);
    assert(fp.is_open());

    // 2 .find the begin of i line
    std::string tempString;
    int count = 0;
    while (!fp.eof()) {
        getline(fp, tempString);
        // choose the begin of line is 'i'
        if( tempString.size() != 0 && tempString.at(0) == 'i')
        {
            // parse the parameters
            getfisheyedata(tempString, count);
            count++;
        }
    } // end of while

    fp.close();

}

void Txt2Xml::writexml()
{
    assert(xmlPath_.data() != nullptr);

    TiXmlDocument doc;
    TiXmlElement * RootElement = new TiXmlElement( "Root" );
    for(size_t i = 0; i < 4; i++)
    {
        TiXmlElement * father = new TiXmlElement( "POSITION" );

        // write all fisheye data each
        //IMAGETYPE
        TiXmlElement * IMAGETYPE= new TiXmlElement( "IMAGETYPE" );
        father->LinkEndChild(IMAGETYPE);
        TiXmlText * IMAGETYPETEXT = new TiXmlText(std::to_string(fisheyeData_[i].IMAGETYPE).data());
        IMAGETYPE->LinkEndChild(IMAGETYPETEXT);

        //CROPMODE
        TiXmlElement * CROPMODE= new TiXmlElement( "CROPMODE" );
        father->LinkEndChild(CROPMODE);
        TiXmlText * CROPMODETEXT = new TiXmlText(std::to_string(fisheyeData_[i].CROPMODE).data());
        CROPMODE->LinkEndChild(CROPMODETEXT);

        //HFOV
        TiXmlElement * HFOV= new TiXmlElement( "HFOV" );
        father->LinkEndChild(HFOV);
        std::cout << std::to_string(fisheyeData_[0].HFOV) << std::endl;
        TiXmlText * HFOVTEXT = new TiXmlText(std::to_string(fisheyeData_[i].HFOV).data());
        HFOV->LinkEndChild(HFOVTEXT);

        //VFOV
        TiXmlElement * VFOV= new TiXmlElement( "VFOV" );
        father->LinkEndChild(VFOV);
        TiXmlText * VFOVTEXT = new TiXmlText(std::to_string(fisheyeData_[i].VFOV).data());
        VFOV->LinkEndChild(VFOVTEXT);

        //Alpha
        TiXmlElement * Alpha= new TiXmlElement( "Alpha" );
        father->LinkEndChild(Alpha);
        TiXmlText * AlphaTEXT = new TiXmlText(std::to_string(fisheyeData_[i].Alpha).data());
        Alpha->LinkEndChild(AlphaTEXT);

        //Beta
        TiXmlElement * Beta= new TiXmlElement( "Beta" );
        father->LinkEndChild(Beta);
        TiXmlText * BetaTEXT = new TiXmlText(std::to_string(fisheyeData_[i].Beta).data());
        Beta->LinkEndChild(BetaTEXT);

        //Gamma
        TiXmlElement * Gamma= new TiXmlElement( "Gamma" );
        father->LinkEndChild(Gamma);
        TiXmlText * GammaTEXT = new TiXmlText(std::to_string(fisheyeData_[i].Gamma).data());
        Gamma->LinkEndChild(GammaTEXT);

        //ShiftX
        TiXmlElement * ShiftX= new TiXmlElement( "ShiftX" );
        father->LinkEndChild(ShiftX);
        TiXmlText * ShiftXTEXT = new TiXmlText(std::to_string(fisheyeData_[i].ShiftX).data());
        ShiftX->LinkEndChild(ShiftXTEXT);

        //ShiftY
        TiXmlElement * ShiftY= new TiXmlElement( "ShiftY" );
        father->LinkEndChild(ShiftY);
        TiXmlText * ShiftYTEXT = new TiXmlText(std::to_string(fisheyeData_[i].ShiftY).data());
        ShiftY->LinkEndChild(ShiftYTEXT);

        //ShearX
        TiXmlElement * ShearX= new TiXmlElement( "ShearX" );
        father->LinkEndChild(ShearX);
        TiXmlText * ShearTEXT = new TiXmlText(std::to_string(fisheyeData_[i].ShearX).data());
        ShearX->LinkEndChild(ShearTEXT);

        //ShearY
        TiXmlElement * ShearY= new TiXmlElement( "ShearY" );
        father->LinkEndChild(ShearY);
        TiXmlText * ShearYTEXT = new TiXmlText(std::to_string(fisheyeData_[i].ShearY).data());
        ShearY->LinkEndChild(ShearYTEXT);

        //CROPLEFT
        TiXmlElement * CROPLEFT= new TiXmlElement( "CROPLEFT" );
        father->LinkEndChild(CROPLEFT);
        TiXmlText * CROPLEFTTEXT = new TiXmlText(std::to_string(fisheyeData_[i].CROPLEFT).data());
        CROPLEFT->LinkEndChild(CROPLEFTTEXT);

        //CROPRIGHT
        TiXmlElement * CROPRIGHT= new TiXmlElement( "CROPRIGHT" );
        father->LinkEndChild(CROPRIGHT);
        TiXmlText * CROPRIGHTTEXT = new TiXmlText(std::to_string(fisheyeData_[i].CROPRIGHT).data());
        CROPRIGHT->LinkEndChild(CROPRIGHTTEXT);

        //CROPTOP
        TiXmlElement * CROPTOP= new TiXmlElement( "CROPTOP" );
        father->LinkEndChild(CROPTOP);
        TiXmlText * CROPTOPTEXT = new TiXmlText(std::to_string(fisheyeData_[i].CROPTOP).data());
        CROPTOP->LinkEndChild(CROPTOPTEXT);

        //CROPBOTTOM
        TiXmlElement * CROPBOTTOM= new TiXmlElement( "CROPBOTTOM" );
        father->LinkEndChild(CROPBOTTOM);
        TiXmlText * CROPBOTTOMTEXT = new TiXmlText(std::to_string(fisheyeData_[i].CROPBOTTOM).data());
        CROPBOTTOM->LinkEndChild(CROPBOTTOMTEXT);

        //CircleX
        TiXmlElement * CircleX= new TiXmlElement( "CircleX" );
        father->LinkEndChild(CircleX);
        TiXmlText * CircleXTEXT = new TiXmlText(std::to_string(fisheyeData_[i].CircleX).data());
        CircleX->LinkEndChild(CircleXTEXT);

        //CircleY
        TiXmlElement * CircleY= new TiXmlElement( "CircleY" );
        father->LinkEndChild(CircleY);
        TiXmlText * CircleYTEXT = new TiXmlText(std::to_string(fisheyeData_[i].CircleY).data());
        CircleY->LinkEndChild(CircleYTEXT);

        //CircleR
        TiXmlElement * CircleR= new TiXmlElement( "CircleR" );
        father->LinkEndChild(CircleR);
        TiXmlText * CircleRTEXT = new TiXmlText(std::to_string(fisheyeData_[i].CircleR).data());
        CircleR->LinkEndChild(CircleRTEXT);

        //YAW
        TiXmlElement * YAW= new TiXmlElement( "YAW" );
        father->LinkEndChild(YAW);
        TiXmlText * YAWTEXT = new TiXmlText(std::to_string(fisheyeData_[i].YAW).data());
        YAW->LinkEndChild(YAWTEXT);

        //PITCH
        TiXmlElement * PITCH= new TiXmlElement( "PITCH" );
        father->LinkEndChild(PITCH);
        TiXmlText * PITCHTEXT = new TiXmlText(std::to_string(fisheyeData_[i].PITCH).data());
        PITCH->LinkEndChild(PITCHTEXT);

        //ROLL
        TiXmlElement * ROLL= new TiXmlElement( "ROLL" );
        father->LinkEndChild(ROLL);
        TiXmlText * ROLLTEXT = new TiXmlText(std::to_string(fisheyeData_[i].ROLL).data());
        ROLL->LinkEndChild(ROLLTEXT);

        RootElement->LinkEndChild(father);
    }

    doc.LinkEndChild( RootElement );
    doc.SaveFile(xmlPath_.data());
}

void Txt2Xml::getfisheyedata(std::string data, int n)
{
    std::istringstream temp(data);

    while (!temp.eof())
    {
        std::string substr;
        temp >> substr;
        if(substr.size() != 0)
        {
            std::string numberstring;
            switch (substr.at(0))
            {
                case 'y':
                    numberstring = substr.substr(1, substr.length() - 1);
                    fisheyeData_[n].YAW = std::atof(numberstring.data());
                    break;
                case 'r':
                    numberstring = substr.substr(1, substr.length() - 1);
                    fisheyeData_[n].ROLL = atof(numberstring.data());
                    break;
                case 'p':
                    numberstring = substr.substr(1, substr.length() - 1);
                    fisheyeData_[n].PITCH = atof(numberstring.data());
                    break;
                case 'v':
                    numberstring = substr.substr(1, substr.length() - 1);
                    fisheyeData_[n].HFOV = atof(numberstring.data());
                    break;
                case 'a':
                    numberstring = substr.substr(1, substr.length() - 1);
                    fisheyeData_[n].Alpha = atof(numberstring.data());
                    break;
                case 'b':
                    numberstring = substr.substr(1, substr.length() - 1);
                    fisheyeData_[n].Beta = atof(numberstring.data());
                    break;
                case 'c':
                    numberstring = substr.substr(1, substr.length() - 1);
                    fisheyeData_[n].Gamma = atof(numberstring.data());
                    break;
                case 'd':
                    numberstring = substr.substr(1, substr.length() - 1);
                    fisheyeData_[n].ShiftX = atof(numberstring.data());
                    break;
                case 'e':
                    numberstring = substr.substr(1, substr.length() - 1);
                    fisheyeData_[n].ShiftY = atof(numberstring.data());
                    break;
                case 'g':
                    numberstring = substr.substr(1, substr.length() - 1);
                    fisheyeData_[n].ShearX = atof(numberstring.data());
                    break;
                case 't':
                    numberstring = substr.substr(1, substr.length() - 1);
                    fisheyeData_[n].ShearY = atof(numberstring.data());
                    break;
                case 'C':
                    numberstring = substr.substr(1, substr.length() - 1);
                    int start = 0, end;
                    // left
                    end =  numberstring.find(',', start);
                    fisheyeData_[n].CROPLEFT = atoi(numberstring.substr(start,end).data());
                    start = end + 1;
                    // right
                    end =  numberstring.find(',', start);
                    fisheyeData_[n].CROPRIGHT = atoi(numberstring.substr(start,end).data());
                    start = end + 1;
                    // top
                    end =  numberstring.find(',', start);
                    fisheyeData_[n].CROPTOP = atoi(numberstring.substr(start,end).data());
                    start = end + 1;
                    // down
                    end =  numberstring.length();
                    fisheyeData_[n].CROPBOTTOM = atoi(numberstring.substr(start,end).data());
                    break;
            } // end of switch

        }
    } // end of read line while

}
