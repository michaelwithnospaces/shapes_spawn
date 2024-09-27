#include "raylib.h"
#include "Circle.h"
#include "Rectangles.h"
#include "Vector.h"
#include "globals.h"

#include <vector>
#include <iostream>
#include <memory>
#include <sstream>
#include <fstream>
#include <string>

int main (int argc, char * argv[]) 
{
    int wWidth, wHeight;
    std::string line;

    std::string font;
    int f_r, f_g, f_b;

    std::vector<std::shared_ptr<Shape>> shapes;

    std::ifstream inputFile("/home/michael/COMP4300/assignment1/config.txt");

    if (!inputFile.is_open())
    {
        std::cout << "Error: Could not open file" << std::endl;
        return 1;
    }

    while(getline(inputFile, line))
    {
        std::stringstream s(line);
        std::string word;
        
        s >> word;

        if (word == "Window")
        {
            s >> wWidth >> wHeight;
        }
        else if (word == "Font")
        {
            s >> font >> FONTSIZE >> f_r >> f_g >> f_b;
            TEXTCOLOR = {static_cast<unsigned char>(f_r), static_cast<unsigned char>(f_g), static_cast<unsigned char>(f_b), 255};
        }
        else if (word == "Circle")
        {
            std::string name;
            float px, py, sx, sy, rad;
            int r, g, b;
            s >> name >> px >> py >> sx >> sy >> r >> g >> b >> rad;

            std::shared_ptr<Shape> ptrCircle = std::make_shared<Circle>(rad);
            ptrCircle->setFillColor({static_cast<unsigned char>(r), static_cast<unsigned char>(g), static_cast<unsigned char>(b), 255});
            ptrCircle->setPosition(px, py);
            ptrCircle->setSpeed(sx, sy);
            ptrCircle->name = name;

            shapes.push_back(ptrCircle);
        } 
        else if (word == "Rectangle")
        {
            std::string name;
            float px, py, sx, sy, w, h;
            int r, g, b;
            s >> name >> px >> py >> sx >> sy >> r >> g >> b >> w >> h;

            std::shared_ptr<Shape> ptrRectangle = std::make_shared<Rectangles>(w, h);
            ptrRectangle->setFillColor({static_cast<unsigned char>(r), static_cast<unsigned char>(g), static_cast<unsigned char>(b), 255});
            ptrRectangle->setPosition(px, py);
            ptrRectangle->setSpeed(sx, sy);
            ptrRectangle->name = name;

            shapes.push_back(ptrRectangle); 
        }

    }

    inputFile.close();

    InitWindow(wWidth, wHeight, "Assignment 1 - Michael Nguyen");

    SetTargetFPS(FPS);

    FONT = LoadFont(font.c_str());
    
    while (!WindowShouldClose()) {
        // Draw
        BeginDrawing();
        ClearBackground(GRAY);

        for (auto& shape : shapes) 
        {
            shape->checkWallCollision();
            shape->draw();
        }
        
        DrawTextEx(FONT, "My First Assignment", {0.0f, wHeight - 20.0f}, static_cast<float>(FONTSIZE), 2.0f, TEXTCOLOR);
        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}