// Blob.cpp


#include <iostream>
#include <vector>
#include "Blob.h"
#include "Point2i.h"


// Constructors
Blob::Blob()
{
    valsCalc = false;
}
Blob::Blob(int size)
{
    points.resize(size);
    
    valsCalc = false;
}
Blob::Blob(const Point2i point)
{
    points.resize(1);
    points.at(1) = point;
    
    valsCalc = false;
}
Blob::Blob(const int x, const int y)
{
    points.resize(1);
    points.at(1) = Point2i(x, y);
    
    valsCalc = false;
}
Blob::Blob(const Point2i pointArr[], int size)
{
    points.resize(size);
    for(int i = 0; i < size; i++)
        points.at(i) = pointArr[i];
    
    valsCalc = false;
}
Blob::Blob(const Blob & copy)
{
    points.resize(copy.points.size());
    for(int i = 0; i < copy.points.size(); i++)
        points.at(i) = copy.points.at(i);
    
    valsCalc = false;
}

// Deconstructor
Blob::~Blob(){}


// Method to add a Poin2i to pointsusing an x, y cordinate. valsCalc needs to be
// false to recalculate all the values.
void Blob::addPoint(const int x, const int y)
{
    points.push_back(Point2i(x, y));
    valsCalc = false;
}


// Method to add a Point2i to points using a Point2i object. valsCalc needs to be
// false to recalculate all the values.
void Blob::addPoint(const Point2i & var)
{
    points.push_back(var);
    valsCalc = false;
}


// Method to find the average x point between all the points.
void Blob::averageX()
{
    int avg = 0;
    for(int i = 0; i < points.size(); i++)
        avg += points.at(i).x;
    if(points.size() > 0)
    	aveX = avg / points.size();
    else
        aveX = -1;
}


// Method to find the average y point between all the points.
void Blob::averageY()
{
    int avg = 0;
    for(int i = 0; i < points.size(); i++)
        avg += points.at(i).y;
    if(points.size() > 0)
        aveY = avg / points.size();
    else
        aveY = -1;
}


// Method to find the width of a blob in pixels.
void Blob::calcWidth()
{
    int minX = 0, maxX = 0;
    
    for(int i = 1; i < points.size(); i++)
    {
        if(points[i].x < points[maxX].x)
            minX = i;
        if(points[i].x > points[minX].x)
            maxX = i;
    }
    
    if(points[maxX].y > points[minX].y)
        wid = points[maxX].x - points[minX].x;
    else
        wid = -1 * (points[maxX].x - points[minX].x);
 }


// Method to find the height of a blob in pixels.
void Blob::calcHeight()
{
    float minY = -1, maxY = -1;
    
    for(int i = 0; i < points.size(); i++)
    {
        if(points[i].y < minY || minY == -1)
            minY = points[i].y;
        if(points[i].y > maxY || maxY == -1)
            maxY = points[i].y;
    }
    
    hei = maxY - minY;
}


//Function to see if values need to be recalculated.
void Blob::calculate()
{
    if(valsCalc)
        return;
    else
    {
        averageY();
        averageX();
        calcWidth();
        calcHeight();
        
        valsCalc = true;
    }
}

float Blob::topRowsAverageX(int rows)
{
    float minY = -1, ave, numPoints;
    
    for(int i = 0; i < points.size(); i++)
    {
        if(points[i].y < minY || minY == -1)
            minY = points[i].y;
    }
    
    if(minY == -1)
        return -1;
    else
        for(int i = 0; i < points.size(); i++)
            if(points[i].y >= minY + rows)
            {
                ave += points[i].x;
                numPoints++;
            }
    
    return ave / numPoints;
}


float Blob::botRowsAverageX(int rows)
{
    float maxY = -1, ave, numPoints;
    
    for(int i = 0; i < points.size(); i++)
    {
        if(points[i].y > maxY || maxY == -1)
            maxY = points[i].y;
    }
    
    if(maxY == -1)
        return -1;
    else
        for(int i = 0; i < points.size(); i++)
            if(points[i].y >= maxY - rows)
            {
                ave += points[i].x;
                numPoints++;
            }
    
    return ave / numPoints;
}


// Method to return the average Point2i in all points.
Point2i Blob::average()
{
    calculate();
    return Point2i(aveX, aveY);
}


//Method to return the width in pixels.
float Blob::width()
{
    calculate();
    return wid;
}


// Method to return the height in pixels.
float Blob::height()
{
    calculate();
    return hei;
}


//Method to return the area of the blob in pixels.
float Blob::area()
{
    return points.size();
}


// Return a Point2i object in the points vector at i.
Point2i Blob::operator [] (int i)
{
    if(i < points.size())
        return points[i];
    
    return Point2i(-1, -1);
}


// Operator to set this to arr.
void Blob::operator = (Blob arr)
{
    points = arr.points;
    aveX = arr.aveX;
    aveY = arr.aveY;
    wid = arr.wid;
    hei = arr.hei;
    valsCalc = arr.valsCalc;
}


// Operator to set this to this + arr.
void Blob::operator += (Blob arr)
{
	for(int i = 0; i < arr.points.size(); i++)
		points.push_back(arr.points.at(i));
    valsCalc = false;
}


// Method to return the size of the points vector.
int Blob::size()
{
    return points.size();
}
