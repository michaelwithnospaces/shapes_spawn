#include "Rectangles.h"

Vector2 Rectangles::sizeToRaylibVector2() const 
{
    return (Vector2){m_size.x, m_size.y};
}

Rectangles::Rectangles(float length, float height) 
{
    m_size.x = length;
    m_size.y = height;
};

void Rectangles::draw() 
{
    m_position.x += FPS * m_sx;
    m_position.y += FPS * m_sy;

    Vector2 textSize = MeasureTextEx(FONT, name.c_str(), static_cast<float>(FONTSIZE), 2.0);

    Vector2f textCenter(textSize);
    textCenter.x = textCenter.x - (textCenter.x / 2.0);
    textCenter.y = textCenter.y - (textCenter.y / 2.0);

    float textLocationX = m_position.x + (m_size.x / 2.0) - textCenter.x;
    float textLocationY = m_position.y + (m_size.y / 2.0) - textCenter.y;

    DrawRectangleV(toRaylibVector2(), sizeToRaylibVector2(), m_color);
    DrawTextEx(FONT, name.c_str(), {textLocationX, textLocationY}, static_cast<float>(FONTSIZE), 2.0f, TEXTCOLOR);
}

void Rectangles::checkWallCollision() {
    if (m_position.x <= 0 || m_position.x + m_size.x >= static_cast<float>(GetScreenWidth())) 
    {
        m_sx = -m_sx;
    }
    if (m_position.y <= 0 || m_position.y + m_size.y >= static_cast<float>(GetScreenHeight())) 
    {
        m_sy = -m_sy;
    }
}