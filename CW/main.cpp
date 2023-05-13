#include <iostream>
#include <conio.h>

#define WINDOW_WIDTH 32
#define WINDOW_HEIGHT 24

#include "GameCore/cell.h"
#include "SFML/Graphics.hpp"
#include "GameCore/Field.h"
#include "Entities/Player.h"
#include "Control/Controller.h"

const int H = 12;
const int W = WINDOW_WIDTH;

using namespace sf;

String Tile[H]{
        "WWWWWWWWWWWWWWWWWWWWWWWW",
        "W                      W",
        "W                      W",
        "W                      W",
        "W                      W",
        "W                      W",
        "W                      W",
        "W                      W",
        "W                      W",
        "W                      W",
        "W                      W",
        "WWWWWWWWWWWWWWWWWWWWWWWW"
};

int main() {

    Cell cell;
    RenderWindow window(VideoMode(cell.get_size() * WINDOW_WIDTH, cell.get_size() * WINDOW_HEIGHT), "Test");
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
    Player player(t1);
    Controller controller(&player);
    s2.setTexture(t2);
    s2.setTextureRect(IntRect(679, 170, cell.get_size(), cell.get_size()));

    s3.setTexture(t3);
    s3.setTextureRect(IntRect(521, 397, cell.get_size(), cell.get_size()));


    Clock clock;

    while (window.isOpen()) {

        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time/800;
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) window.close();
        }
        window.clear(Color::Black);
        controller.control();

        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++) {
                if (j == 0 || j == W-1 || i == 0 || i == H-1 && Tile[i][j] == 'W') {
                    s2.setPosition(j * cell.get_size(), i * cell.get_size());
                    window.draw(s2);
                }

            }
        player.update(time);
        window.draw(player.sprite);
        window.display();
    }

    return 0;

}
