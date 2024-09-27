// Circle.cpp

#include "Circle.h"

Circle::Circle(int rad) : m_radius (rad) {};

void Circle::draw() 
{
    m_position.x += FPS * m_sx;
    m_position.y += FPS * m_sy;

    Vector2 textSize = MeasureTextEx(FONT, name.c_str(), static_cast<float>(FONTSIZE), 2.0);

    Vector2f textCenter(textSize);
    textCenter.x = textCenter.x - (textCenter.x / 2.0);
    textCenter.y = textCenter.y - (textCenter.y / 2.0);

    float textLocationX = m_position.x - textCenter.x;
    float textLocationY = m_position.y - textCenter.y;

    DrawCircleV(toRaylibVector2(), m_radius, m_color);
    DrawTextEx(FONT, name.c_str(), {textLocationX, textLocationY}, static_cast<float>(FONTSIZE), 2.0f, TEXTCOLOR);
}

void Circle::checkWallCollision() {
    if ((m_position.x - m_radius) <= 0 || (m_position.x + m_radius) >= static_cast<float>(GetScreenWidth())) 
    {
        m_sx = -m_sx;

    }
    if ((m_position.y - m_radius) <= 0 || (m_position.y + m_radius) >= static_cast<float>(GetScreenHeight()))
    {
        m_sy = -m_sy;
    }
}