#ifndef CITY_H
#define CITY_H

#include "interfaces/icity.hh"

namespace StudentSide
{

class City : public Interface::ICity
{
public:
    City();
    ~City();
    void setBackground(QImage& basicbackground, QImage& bigbackground);
};

}

#endif // CITY_H
