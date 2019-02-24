// Blob.cpp

//#inlcude <vector>
#include <iostream>
#include "Blob.h"
#include "Point2i.h"


// Constructors
Blob::Blob(){}
Blob::Blob(int size)
{
    points.resize(size);
}
Blob::Blob(const Point2i point)
{
    points.resize(1);
    points.at(1) = point;
}
Blob::Blob(const int x, const int y)
{
    points.resize(1);
    points.at(1) = Point2i(x, y);
}
Blob::Blob(const Point2i pointArr[], int size)
{
    points.resize(size);
    for(int i = 0; i < size; i++)
        points.at(i) = pointArr[i];
}
Blob::Blob(const Blob & copy)
{
    points.resize(copy.points.size());
    for(int i = 0; i < copy.points.size(); i++)
        points.at(i) = copy.points.at(i);
}

// Deconstructor
Blob::~Blob(){}


// Method to add a Poin2i to pointsusing an x, y cordinate.
void Blob::addPoint(const int x, const int y)
{
    points.push_back(Point2i(x, y));
}


// Method to add a Point2i to points using a Point2i object.
void Blob::addPoint(const Point2i & var)
{
    points.push_back(var);
}


// Method to find the average x point between all the points.
int Blob::averageX()
{
    int avg = 0;
    for(int i = 0; i < points.size(); i++)
        avg += points.at(i).x;
    if(points.size() > 0) 
    	return avg / points.size();
    else
        return -1;
}


// Method to the average y point between all the points.
int Blob::averageY()
{
    int avg = 0;
    for(int i = 0; i < points.size(); i++)
        avg += points.at(i).y;
    if(points.size() > 0)
    	return avg / points.size();
    else
	return -1;
}


// Method to find the average Point2i in all points.
Point2i Blob::average()
{
    return Point2i(averageX(), averageY());
}


//Method to return the area of the blob in pixels.
float Blob::area()
{
    return points.size();
}


// Method to return the width of a blob in pixels.
float Blob::width()
{
    float minX = -1, maxX = -1;
    
    for(int i = 0; i < points.size(); i++)
    {
        if(points[i].x < minX || minX == -1)
            minX = points[i].x;
        if(points[i].x > maxX || maxX == -1)
            maxX = points[i].x;
    }
    
    return maxX - minX;
}


// Method to return the height of a blob in pixels.
float Blob::height()
{
    float minY = -1, maxY = -1;
    
    for(int i = 0; i < points.size(); i++)
    {
        if(points[i].y < minY || minY == -1)
            minY = points[i].y;
        if(points[i].y > maxY || maxY == -1)
            maxY = points[i].y;
    }
    
    return maxY - minY;
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
}


// Operator to set this to this + arr.
void Blob::operator += (Blob arr)
{
	for(int i = 0; i < arr.points.size(); i++)
		points.push_back(arr.points.at(i));
}


// Method to return the size of the points vector.
int Blob::size()
{
    return points.size();
}
