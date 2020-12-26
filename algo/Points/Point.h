//
// Created by 李炬成 on 2020/12/25.
//
#ifndef GLS__FLS_POINT_H
#define GLS__FLS_POINT_H
#include<iostream>
#include<math.h>
class Point {
private:
    double x,y;
    int id;
    bool active;
    inline double _distance(const Point& p) const{
        double dx = this->x - p.x;
        double dy = this->y - p.y;
        return pow(dx,2)+pow(dy,2);
    };
public:
    Point(int id,double x,double y,bool active) : id(id), x(x), y(y), active(active){}
    inline int getId()     const   {return id;}
    inline double getX()   const   {return x;}
    inline double getY()   const   {return y;}
    inline bool isActive() const {return active;}
    inline void setActive(bool active)     { this->active = active;}
    inline double distance(const Point& p) { return sqrt(_distance(p));}
};

#endif //GLS__FLS_POINT_H
