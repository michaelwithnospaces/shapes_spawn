// Shape.cpp

#include "Shape.h"

Vector2 Shape::toRaylibVector2() const 
{
    return (Vector2){m_position.x, m_position.y};
}

void Shape::setPosition(float xPos, float yPos) 
{
    m_position.x = xPos;
    m_position.y = yPos;
};

void Shape::setFillColor(Color color)
{
    m_color = color;
}

void Shape::setSpeed(float sx, float sy)
{
    m_sx = sx;
    m_sy = sy;
}