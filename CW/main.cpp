#include <iostream>
#include <conio.h>

#include "/Game Core/cell.h"
#include "SFML/Graphics.hpp"

const int H = 12;
const int W = 12;

using namespace sf;

String Map[H] = {
        "BBBBBBBBBBBB",
        "B          B",
        "B          B",
        "B          B",
        "B          B",
        "B          B",
        "B          B",
        "B          B",
        "B          B",
        "B          B",
        "B          B",
        "BBBBBBBBBBBB",
};

int main(){

    Cell cell;
    RenderWindow window(VideoMode(cell.get_size()*H, cell.get_size()*W), "Test");

    RectangleShape rectangle(Vector2f(32, 32));
    while(window.isOpen()){

        Event event;
        while (window.pollEvent(event)){
            if(event.type == Event::Closed) window.close();
        }
        window.clear(Color::White);

        for(int i = 0; i < H; i++)
            for(int j = 0; j < W; j++){
                if(Map[i][j] == 'B') rectangle.setFillColor(Color::Black);
                if(Map[i][j] == ' ') continue;
                rectangle.setPosition(j*cell.get_size(),i*cell.get_size());
                window.draw(rectangle);

        }

        window.display();
    }
    return 0;
}
