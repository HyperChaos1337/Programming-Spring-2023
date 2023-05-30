#ifndef TESTCW_GAME_H
#define TESTCW_GAME_H

#define WIDTH 1024
#define HEIGHT 768

#define BUTTON_WIDTH 112
#define BUTTON_HEIGHT 19

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <list>
#include <sstream>

#include "Level.h"

#include "Animation/AnimationManager.h"

#include "Entities/Entity.h"
#include "Entities/Bullet.h"
#include "Entities/Player.h"
#include "Entities/Enemy.h"
#include "Entities/Coin.h"
#include "Entities/Star.h"

#include "Attributes/HealthBar.h"
#include "Attributes/Attributes.h"
#include "Attributes/CharMenu.h"

#include "FileManagement/LevelFile.h"
#include "FileManagement/PlayerFile.h"
#include "FileManagement/AnimationFile.h"
#include "FileManagement/BGFile.h"
#include "FileManagement/MusicFile.h"

using namespace sf;

class Game{
public:

    LevelFile levelFile;
    AnimationFile animationFile;
    PlayerFile playerFile;
    Attributes attributes;
    BGFile bgFile;
    MusicFile musicFile;

    void run_game();

    void char_menu();
    void level_menu();
    void main_menu();
    void end_level_menu();

};

#endif