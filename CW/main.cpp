#include <iostream>
#include <conio.h>

#include "GameCore/cell.h"
#include "SFML/Graphics.hpp"
#include "GameCore/Field.h"

const int H = 12;
const int W = 12;

using namespace sf;

String Tile[H]{
    "WWWWWWWWWWWW",
    "W          W",
    "W          W",
    "W          W",
    "W          W",
    "W          W",
    "W          W",
    "W          W",
    "W          W",
    "W          W",
    "W          W",
    "WWWWWWWWWWWW"
};


int main() {

    Cell cell;
    RenderWindow window(VideoMode(cell.get_size() * H, cell.get_size() * W), "Test");
    /*
     t1 for Mario Texture
     t2 & t3 for Walls Texture
    */
    Texture t1, t2, t3;
    t1.loadFromFile("C:/Users/User/CLionProjects/Course_Work_2/Images/Sprites/mario.png");
    t2.loadFromFile("C:/Users/User/CLionProjects/Course_Work_2/Images/Sprites/mario2.png");
    t3.loadFromFile("C:/Users/User/CLionProjects/Course_Work_2/Images/Sprites/mario2.png");
    /*
     s1 for Mario Sprite
     s2 & s3 for Walls Sprite
    */
    Sprite s1, s2, s3;
    s1.setTexture(t1);
    s1.setTextureRect(IntRect(70, 178, 50, 60));
    s1.setPosition(150, 150);

    s2.setTexture(t2);
    s2.setTextureRect(IntRect(679, 170, cell.get_size(), cell.get_size()));

    s3.setTexture(t3);
    s3.setTextureRect(IntRect(521, 397, cell.get_size(), cell.get_size()));


    Clock clock;

    float frame = 0;

    while (window.isOpen()) {

        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) window.close();
        }
        window.clear(Color::Black);

        if (Keyboard::isKeyPressed(Keyboard::A)) {
            s1.move(-0.1, 0);
            frame += 0.005;
            if (frame > 3) frame -= 3;
            s1.setTextureRect(IntRect(70 * int(frame), 178, 50, 70));
        }

        if (Keyboard::isKeyPressed(Keyboard::D)) {
            s1.move(0.1, 0);
            frame += 0.005;
            if (frame > 3) frame -= 3;
            s1.setTextureRect(IntRect(70 * int(frame) + 50, 178, -50, 60));
        }

        if(Keyboard::isKeyPressed(Keyboard::W)){
            s1.move(0, -0.1);
            frame += 0.005;
            if (frame > 3) frame -= 3;
            s1.setTextureRect(IntRect(70 * int(frame), 178, 50, 60));
        }

        if(Keyboard::isKeyPressed(Keyboard::S)){
            s1.move(0, 0.1);
            frame += 0.005;
            if (frame > 3) frame -= 3;
            s1.setTextureRect(IntRect(70 * int(frame) + 50, 178, -50, 60));
        }

        if(Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::W)){
            s1.move(-0.001, -0.001);
            frame += 0.005;
            if (frame > 3) frame -= 3;
            s1.setTextureRect(IntRect(70 * int(frame), 178, 50, 60));
        }

        if(Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::S)){
            s1.move(-0.001, 0.001);
            frame += 0.005;
            if (frame > 3) frame -= 3;
            s1.setTextureRect(IntRect(70 * int(frame), 178, 50, 60));
        }

        if(Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::W)){
            s1.move(0.001, -0.001);
            frame += 0.005;
            if (frame > 3) frame -= 3;
            s1.setTextureRect(IntRect(70 * int(frame) + 50, 178, -50, 60));
        }

        if(Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::S)){
            s1.move(0.001, 0.001);
            frame += 0.005;
            if (frame > 3) frame -= 3;
            s1.setTextureRect(IntRect(70 * int(frame) + 50, 178, -50, 60));
        }

        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++) {
                if (j == 0 || j == W-1 || i == 0 || i == H-1 && Tile[i][j] == 'W') {
                    s2.setPosition(j * cell.get_size(), i * cell.get_size());
                    window.draw(s2);
                }

            }

        window.draw(s1);
        window.display();
    }

    return 0;

}
