#include "Coordinate.h"

//Coordinate Coordinate::operator=(Coordinate cdnt)
//{
//    return Coordinate(cdnt.x, cdnt.y);
//}

Coordinate Coordinate::operator+(Coordinate& cdnt)
{
    return Coordinate(x + cdnt.x, y + cdnt.y);
}

Coordinate Coordinate::operator-(Coordinate& cdnt)
{
    return Coordinate(x - cdnt.x, y - cdnt.y);
}

bool Coordinate::operator==(const Coordinate cdnt)
{
    return (x == cdnt.x && y == cdnt.y) ? true : false;
}

bool Coordinate::operator>(Coordinate cdnt)
{
    return (x > cdnt.x && y > cdnt.y) ? true : false;
}

bool Coordinate::operator<(Coordinate cdnt)
{
    return (x < cdnt.x && y < cdnt.y) ? true : false;
}

bool Coordinate::equalX(Coordinate cdnt)
{
    return (x == cdnt.x) ? true : false;
}

bool Coordinate::equalY(Coordinate cdnt)
{
    return (y == cdnt.y) ? true : false;
}

int Coordinate::index(int x, int y, int xm)
{
    return y * xm + x;
}

int Coordinate::index(Coordinate cdnt, int xm)
{
    return cdnt.y * xm + cdnt.x;
}
