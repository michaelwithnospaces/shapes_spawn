// Shape.h

#ifndef SHAPE_H
#define SHAPE_H

#include "raylib.h"
#include "Vector.h"
#include "globals.h"
#include <string>

class Shape 
{
public:
    void setPosition(float xPos, float yPos);
    void setFillColor(Color color);
    void setSpeed(float sx, float sy);
    Vector2 toRaylibVector2() const;
    virtual void draw() = 0;
    virtual void checkWallCollision() = 0;
    std::string name;

protected:
    Vector2f m_position;
    float m_sx;
    float m_sy;
    Color m_color;
};

#endif