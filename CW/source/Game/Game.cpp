#include "Game.h"

void Game::end_level_menu(){

    RenderWindow end_menu(VideoMode(WIDTH, HEIGHT), "Congratulations!");

    Image icon;
    icon.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/images/icon.png");
    end_menu.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    Font font, font2;
    font.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/fonts/PressStart2P-vaV7.ttf");
    font2.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/fonts/LoftygoalsRegular-9Y5Xy.otf");
    Text title1, title2, title3, title4, title5;
    title1.setFont(font); title2.setFont(font), title3.setFont(font), title4.setFont(font2), title5.setFont(font);
    title1.setString("LEVEL COMPLETED"); title2.setString("PRESS ANY KEY TO CONTINUE");
    title3.setString("ENEMIES DEFEATED: " + std::to_string(attributes.enemies) + '\n' + '\n'+
    "COINS COLLECTED: " + std::to_string(attributes.coins));
    title4.setString("Total Score: ");
    title5.setString(std::to_string(attributes.score));
    title1.setCharacterSize(52); title2.setCharacterSize(30), title3.setCharacterSize(25);
    title4.setCharacterSize(50), title5.setCharacterSize(25);
    title1.setPosition(125, 50); title2.setPosition(125, 650), title3.setPosition(125, 330);
    title4.setPosition(500, 500), title5.setPosition(840, 524);

    Music music;
    music.openFromFile("C:/Users/User/CLionProjects/TestCW/files/soundtrack/lvl_clear.flac");
    music.play();

    Event event;
    while (end_menu.isOpen()){
        while (end_menu.pollEvent(event)) {
            if (event.type == Event::Closed){
                end_menu.close();
                level_menu();
            }
            if(event.type == Event::KeyPressed || event.type == Event::MouseButtonPressed){
                sleep(seconds(1));
                attributes.score = 0;
                attributes.coins = 0;
                attributes.enemies = 0;
                end_menu.close();
                level_menu();
            }
        }
        end_menu.clear(Color::Black);
        end_menu.draw(title1);
        end_menu.draw(title2);
        end_menu.draw(title3);
        end_menu.draw(title4);
        end_menu.draw(title5);
        end_menu.display();
    }

}

void Game::main_menu(){

    RenderWindow menu(VideoMode(WIDTH, HEIGHT), "Main Menu");
    Font font1, font2;

    Image icon;
    icon.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/images/icon.png");
    menu.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    font1.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/fonts/PressStart2P-vaV7.ttf");
    font2.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/fonts/LoftygoalsRegular-9Y5Xy.otf");

    Text title1, title2, title3;

    title1.setFont(font1);
    title1.setString("COURSE WORK 2023/2");
    title1.setCharacterSize(52);
    title1.setPosition(50, 100);

    title2.setFont(font2);
    title2.setString("by HyperChaos1337");
    title2.setCharacterSize(52);
    title2.setPosition(650, 150);

    title3.setFont(font1);
    title3.setString("SAINT-PETERSBURG ETU \"LETI\", MAY-JUNE 2023");
    title3.setCharacterSize(20);
    title3.setPosition(10, HEIGHT-36);

    Texture button1, button2;
    button1.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/images/button1.png");
    button2.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/images/button2.png");
    Sprite button1_sprite(button1), button2_sprite(button2);
    button1_sprite.setPosition((HEIGHT-BUTTON_HEIGHT)/2, (WIDTH-BUTTON_WIDTH)/2);
    button2_sprite.setPosition((HEIGHT-BUTTON_HEIGHT)/2+45, (WIDTH-BUTTON_WIDTH)/2+70);
    bool isMenu = true;

    while (isMenu){

        Event event;
        while (menu.pollEvent(event)) {
            if (event.type == Event::Closed){
                menu.close();
                exit(0);
            }
        }
        button1_sprite.setColor(Color::White);
        button2_sprite.setColor(Color::White);
        if(IntRect((HEIGHT+BUTTON_WIDTH+50)/2, (WIDTH-2*BUTTON_HEIGHT-6)/2,
                   BUTTON_WIDTH, BUTTON_HEIGHT).contains(Mouse::getPosition(menu))){
            button1_sprite.setColor(Color::Green);
            if(Mouse::isButtonPressed(Mouse::Left)){
                isMenu = false;
                sleep(seconds(0.25));
                menu.close();
                char_menu();
            }
        }
        if(IntRect((HEIGHT+BUTTON_WIDTH+65)/2, (WIDTH-2*BUTTON_HEIGHT+134)/2,
                   BUTTON_WIDTH-22, BUTTON_HEIGHT).contains(Mouse::getPosition(menu))){
            button2_sprite.setColor(Color::Red);
            if(Mouse::isButtonPressed(Mouse::Left)) exit(0);
        }
        if(Keyboard::isKeyPressed(Keyboard::Escape)) exit(0);
        menu.draw(button1_sprite);
        menu.draw(button2_sprite);
        menu.draw(title1);
        menu.draw(title2);
        menu.draw(title3);
        menu.display();
    }
}

void Game::level_menu(){

    RenderWindow level_menu(VideoMode(WIDTH, HEIGHT), "Level Select");

    Image icon;
    icon.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/images/icon.png");
    level_menu.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    Font font;
    font.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/fonts/PressStart2P-vaV7.ttf");
    Text text, option;
    text.setFont(font), option.setFont(font);
    text.setString("SELECT LEVEL"), option.setString("ESC - RETURN TO PREVIOUS MENU");
    text.setCharacterSize(30), option.setCharacterSize(15);
    text.setPosition(325, 50), option.setPosition(275, 100);

    Music music;
    music.openFromFile("C:/Users/User/CLionProjects/TestCW/files/soundtrack/level_select.flac");
    music.play();
    music.setLoop(true);

    Texture level_button1, level_button2, level_button3, level_button4;
    level_button1.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/images/lvl1_button.png");
    level_button2.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/images/lvl2_button.png");
    level_button3.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/images/lvl3_button.png");
    level_button4.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/images/lvl4_button.png");

    Sprite level_button1_sprite(level_button1), level_button2_sprite(level_button2);
    Sprite level_button3_sprite(level_button3), level_button4_sprite(level_button4);

    level_button1_sprite.setPosition(100, 150);
    level_button2_sprite.setPosition(620, 146);
    level_button3_sprite.setPosition(95, 450);
    level_button4_sprite.setPosition(610, 448);

    Image lvl1_image, lvl2_image, lvl3_image, lvl4_image;
    lvl1_image.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/images/lvl1_bg.png");
    lvl2_image.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/images/lvl2_bg.png");
    lvl3_image.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/images/lvl3_bg.png");
    lvl4_image.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/images/lvl4_bg.png");

    Texture lvl1_bg, lvl2_bg, lvl3_bg, lvl4_bg;
    lvl1_bg.loadFromImage(lvl1_image);
    lvl2_bg.loadFromImage(lvl2_image);
    lvl3_bg.loadFromImage(lvl3_image);
    lvl4_bg.loadFromImage(lvl4_image);

    Sprite lvl1_bg_sprite(lvl1_bg), lvl2_bg_sprite(lvl2_bg), lvl3_bg_sprite(lvl3_bg), lvl4_bg_sprite(lvl4_bg);

    lvl1_bg_sprite.setScale(0.5f, 0.5f);
    lvl1_bg_sprite.setPosition(100, 225);

    lvl2_bg_sprite.setScale(0.27f, 0.255f);
    lvl2_bg_sprite.setPosition(605, 223.2);

    lvl3_bg_sprite.setScale(0.376f, 0.38f);
    lvl3_bg_sprite.setPosition(100, 535);

    lvl4_bg_sprite.setScale(0.41f, 0.375f);
    lvl4_bg_sprite.setPosition(605, 535);

    bool isMenu = true;

    while (isMenu) {
        Event event;
        while (level_menu.pollEvent(event)) {
            if (event.type == Event::Closed){
                level_menu.close();
                music.stop();
                char_menu();
            }

            level_button1_sprite.setColor(Color::White);
            level_button2_sprite.setColor(Color::White);
            level_button3_sprite.setColor(Color::White);
            level_button4_sprite.setColor(Color::White);
            if(IntRect(100, 225, 300, 200).contains(Mouse::getPosition(level_menu))){
                level_button1_sprite.setColor(Color::Green);
                if(Mouse::isButtonPressed(Mouse::Left)){
                    levelFile.set_filename("C:/Users/User/CLionProjects/TestCW/files/lvl1.tmx");
                    bgFile.set_filename("C:/Users/User/CLionProjects/TestCW/files/images/lvl1_bg.png");
                    musicFile.set_filename("C:/Users/User/CLionProjects/TestCW/files/soundtrack/lvl1.ogg");
                    isMenu = false;
                    sleep(seconds(0.25));
                    level_menu.close();
                    music.stop();
                    run_game();
                }
            }
            if(IntRect (605, 233, 324, 200).contains(Mouse::getPosition(level_menu))){
                level_button2_sprite.setColor(Color::Green);
                if(Mouse::isButtonPressed(Mouse::Left)){
                    levelFile.set_filename("C:/Users/User/CLionProjects/TestCW/files/lvl2.tmx");
                    bgFile.set_filename("C:/Users/User/CLionProjects/TestCW/files/images/lvl2_bg.png");
                    musicFile.set_filename("C:/Users/User/CLionProjects/TestCW/files/soundtrack/lvl2.ogg");
                    isMenu = false;
                    sleep(seconds(0.25));
                    level_menu.close();
                    music.stop();
                    run_game();
                }
            }
            if(IntRect(100, 535, 301, 304).contains(Mouse::getPosition(level_menu))){
                level_button3_sprite.setColor(Color::Green);
                if(Mouse::isButtonPressed(Mouse::Left)){
                    levelFile.set_filename("C:/Users/User/CLionProjects/TestCW/files/lvl3.tmx");
                    bgFile.set_filename("C:/Users/User/CLionProjects/TestCW/files/images/lvl3_bg.png");
                    musicFile.set_filename("C:/Users/User/CLionProjects/TestCW/files/soundtrack/lvl3.ogg");
                    isMenu = false;
                    sleep(seconds(0.25));
                    level_menu.close();
                    music.stop();
                    run_game();
                }
            }
            if(IntRect(605, 535, 320, 250).contains(Mouse::getPosition(level_menu))){
                level_button4_sprite.setColor(Color::Green);
                if(Mouse::isButtonPressed(Mouse::Left)){
                    levelFile.set_filename("C:/Users/User/CLionProjects/TestCW/files/lvl4.tmx");
                    bgFile.set_filename("C:/Users/User/CLionProjects/TestCW/files/images/lvl4_bg.png");
                    musicFile.set_filename("C:/Users/User/CLionProjects/TestCW/files/soundtrack/lvl4.ogg");
                    isMenu = false;
                    sleep(seconds(0.25));
                    level_menu.close();
                    music.stop();
                    run_game();
                }
            }
        }

        if(Keyboard::isKeyPressed(Keyboard::Escape)){
            sleep(seconds(1));
            level_menu.close();
            music.stop();
            char_menu();
        }

        level_menu.draw(level_button1_sprite);
        level_menu.draw(level_button2_sprite);
        level_menu.draw(level_button3_sprite);
        level_menu.draw(level_button4_sprite);
        level_menu.draw(lvl1_bg_sprite);
        level_menu.draw(lvl2_bg_sprite);
        level_menu.draw(lvl3_bg_sprite);
        level_menu.draw(lvl4_bg_sprite);
        level_menu.draw(text);
        level_menu.draw(option);
        level_menu.display();
    }
}

void Game::char_menu(){

    RenderWindow char_menu(VideoMode(WIDTH, HEIGHT), "Character Select");

    Font font;
    font.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/fonts/PressStart2P-vaV7.ttf");
    Text text, option;

    Image icon;
    icon.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/images/icon.png");
    char_menu.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    text.setFont(font), option.setFont(font);
    text.setString("SELECT CHARACTER"), option.setString("ESC - RETURN TO PREVIOUS MENU");
    text.setCharacterSize(30), option.setCharacterSize(15);
    text.setPosition(280, 50), option.setPosition(300, 700);

    Texture char_button2, char_button3;
    char_button2.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/images/char_button2.png");
    char_button3.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/images/char_button3.png");

    Sprite char_button2_sprite(char_button2), char_button3_sprite(char_button3);
    char_button2_sprite.setPosition(100, 150);
    char_button3_sprite.setPosition(90, 450);

    Texture char_icon1, char_icon2;
    char_icon1.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/images/mario&luigi.png");
    char_icon2.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/images/mario&luigi.png");

    Sprite char_icon1_sprite(char_icon1), char_icon2_sprite(char_icon2);
    char_icon1_sprite.setTextureRect(IntRect(187,0,15,27));
    char_icon2_sprite.setTextureRect(IntRect(187,199,15,31));
    char_icon1_sprite.setScale(5, 5);
    char_icon2_sprite.setScale(5, 5);
    char_icon1_sprite.setPosition(600,150);
    char_icon2_sprite.setPosition(595,450);

    Music music;
    music.openFromFile("C:/Users/User/CLionProjects/TestCW/files/soundtrack/character_select.flac");
    music.play();
    music.setLoop(true);

    bool isMenu = true;
    while(isMenu){
        Event event;
        while (char_menu.pollEvent(event)) {
            if (event.type == Event::Closed){
                char_menu.close();
                music.stop();
                main_menu();
            }
        }

        char_button2_sprite.setColor(Color::White);
        char_icon1_sprite.setTextureRect(IntRect(187,0,15,27));
        char_icon1_sprite.setScale(5, 5);

        char_button3_sprite.setColor(Color::White);
        char_icon2_sprite.setTextureRect(IntRect(187,199,15,31));
        char_icon2_sprite.setScale(5,5);

        if(IntRect(140, 180, BUTTON_WIDTH, BUTTON_HEIGHT).contains(Mouse::getPosition(char_menu))){
            char_button2_sprite.setColor(Color::Green);
            char_icon1_sprite.setTextureRect(IntRect(187,81,15,27));
            char_icon1_sprite.setScale(5, 5);
            if(Mouse::isButtonPressed(Mouse::Left)){
                playerFile.set_filename("C:/Users/User/CLionProjects/TestCW/files/images/mario&luigi.png");
                animationFile.set_filename("C:/Users/User/CLionProjects/TestCW/files/anim_mario.xml");
                isMenu = false;
                sleep(seconds(0.25));
                char_menu.close();
                music.stop();
                level_menu();
            }
        }

        if(IntRect(130, 485, BUTTON_WIDTH, BUTTON_HEIGHT).contains(Mouse::getPosition(char_menu))){
            char_button3_sprite.setColor(Color::Green);
            char_icon2_sprite.setTextureRect(IntRect(187,280,15,31));
            char_icon2_sprite.setScale(5, 5);
            if(Mouse::isButtonPressed(Mouse::Left)){
                playerFile.set_filename("C:/Users/User/CLionProjects/TestCW/files/images/mario&luigi.png");
                animationFile.set_filename("C:/Users/User/CLionProjects/TestCW/files/anim_luigi.xml");
                isMenu = false;
                sleep(seconds(0.25));
                char_menu.close();
                music.stop();
                level_menu();
            }
        }

        if(Keyboard::isKeyPressed(Keyboard::Escape)){
            isMenu = false;
            sleep(seconds(0.25));
            char_menu.close();
            music.stop();
            main_menu();
        }
        char_menu.clear(Color::Black);
        char_menu.draw(text);
        char_menu.draw(char_button2_sprite);
        char_menu.draw(char_button3_sprite);
        char_menu.draw(char_icon1_sprite);
        char_menu.draw(char_icon2_sprite);
        char_menu.draw(option);
        char_menu.display();
    }


}

void Game::run_game(){
    ///////////// инициализация ///////////////////////////
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Game");
    View view( FloatRect(0, 0, 450, 280) );

    Image icon;
    icon.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/images/icon.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    Level lvl;
    lvl.LoadFromFile(levelFile.get_filename());
    Texture enemy_t, megaman_t, bullet_t, bg, coin_t, star_t;

    bg.loadFromFile(bgFile.get_filename());
    coin_t.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/images/coin.png");
    star_t.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/images/mario_objects2.png");
    enemy_t.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/images/enemy.png");
    megaman_t.loadFromFile(playerFile.get_filename());
    bullet_t.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/images/bullet.png");

    Font font;
    font.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/fonts/PressStart2P-vaV7.ttf");
    Text health_amount("", font, 7);
    health_amount.setFillColor(Color::White);
    health_amount.setOutlineColor(Color::Black);
    health_amount.setOutlineThickness(1);


    Music music;
    music.openFromFile(musicFile.get_filename());
    music.play();
    music.setLoop(true);

    Music lvl_completed;
    lvl_completed.openFromFile("C:/Users/User/CLionProjects/TestCW/files/soundtrack/level_completed.flac");

    SoundBuffer coin_sound, stomp_sound, bump_sound, jump_sound, shoot_sound;
    coin_sound.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/soundtrack/coin_collected.wav");
    stomp_sound.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/soundtrack/stomp.wav");
    bump_sound.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/soundtrack/bump.wav");
    jump_sound.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/soundtrack/jump.wav");
    shoot_sound.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/soundtrack/shoot.wav");
    Sound coin_collected(coin_sound), enemy_defeated(stomp_sound), bump(bump_sound);
    Sound jump(jump_sound), shooting(shoot_sound);

    AnimationManager anim;
    anim.loadFromXML(animationFile.get_filename(),megaman_t);
    anim.animList["jump"].loop = false;

    AnimationManager anim2;
    anim2.create("move",bullet_t,7,10,8,8,1,0);
    anim2.create("explode",bullet_t,27,7,18,18,4,0.01,29,false);

    AnimationManager anim3;
    anim3.create("move",enemy_t,0,0,16,16,2,0.002,18);
    anim3.create("dead",enemy_t,58,0,16,16,1,0);

    AnimationManager anim5;
    anim5.create("stay", coin_t, 0, 0, 32, 32, 1, 0, 0, false);

    AnimationManager anim6;
    anim6.create("stay", star_t, 511, 429, 63, 63, 1, 0, 0, false);

    Sprite background(bg);
    background.setOrigin(bg.getSize().x/2,bg.getSize().y/2);

    std::list<Entity*> entities;
    std::list<Entity*>::iterator it;

    std::vector<Object> e = lvl.GetObjects("enemy");
    for (int i=0;i < e.size();i++)
        entities.push_back(new Enemy(anim3, lvl, e[i].rect.left, e[i].rect.top) );
    e = lvl.GetObjects("coin");
    for(int i = 0; i < e.size(); i++)
        entities.push_back(new Coin(anim5, lvl, e[i].rect.left, e[i].rect.top));
    e = lvl.GetObjects("star");
    for(int i = 0; i < e.size(); i++)
        entities.push_back(new Star(anim6, lvl, e[i].rect.left, e[i].rect.top));
    Object pl = lvl.GetObject("player");
    Player Mario(anim, lvl, pl.rect.left, pl.rect.top);

    HealthBar healthBar;

    Clock clock;

    bool showMissionText = true;
    bool jump_state = true;

    Image image;
    image.loadFromFile("C:/Users/User/CLionProjects/TestCW/files/images/missionbg.jpg");
    image.createMaskFromColor(Color::Black);
    Texture texture;
    texture.loadFromImage(image);
    Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(0.3f, 0.3f);

    CharMenu charMenu;

    /////////////////// основной цикл  /////////////////////
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();

        time = time/500;  // здесь регулируем скорость игры

        if (time > 40) time = 40;

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed){
                window.close();
                attributes.score = 0;
                attributes.coins = 0;
                attributes.enemies = 0;
                music.stop();
                main_menu();
            }

            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Space){
                    entities.push_back(new Bullet(anim2, lvl, Mario.x + 18, Mario.y + 18, Mario.dir));
                    shooting.play();
                }
                if(event.key.code == Keyboard::Tab){
                    switch (showMissionText) {
                        case true:
                        {
                            std::ostringstream playerHealth, Score, Coins, Enemies;
                            playerHealth << Mario.Health;
                            Score << attributes.score;
                            Coins << attributes.coins;
                            Enemies << attributes.enemies;
                            std::ostringstream task;
                            task << charMenu.get_text(Mario.x);
                            health_amount.setString("HEALTH: " + playerHealth.str() + '\n' +
                            "SCORE: " + Score.str() + '\n'
                            + "COINS COLLECTED: " + Coins.str() + '\n'
                            + "ENEMIES DEFEATED: " + Enemies.str());
                            health_amount.setPosition(view.getCenter().x + 25, view.getCenter().y + 100);
                            showMissionText = false;
                            break;
                        }
                        case false:
                        {
                            health_amount.setString("");
                            showMissionText = true;
                            break;
                        }
                    }
                }
                if(Mario.STATE != Player::climb && event.key.code == Keyboard::W && jump_state){
                    jump.play();
                    jump_state = false;
                }
            }
        }

        if(!jump_state && event.key.code != Keyboard::W && Mario.STATE != Player::jump) jump_state = true;

        if (Keyboard::isKeyPressed(Keyboard::A)){
            Mario.key["L"]=true;
        }
        if (Keyboard::isKeyPressed(Keyboard::D)){
            Mario.key["R"]=true;
        }
        if (Keyboard::isKeyPressed(Keyboard::W)){
            Mario.key["Up"]=true;
        }
        if (Keyboard::isKeyPressed(Keyboard::S)){
            Mario.key["Down"]=true;
        }
        if (Keyboard::isKeyPressed(Keyboard::Space)){
            Mario.key["Space"]=true;
        }

        if(Keyboard::isKeyPressed(Keyboard::Escape)){
            attributes.score = 0;
            sleep(seconds(1));
            window.close();
            music.stop();
            level_menu();
        }

        if(Mario.Health == 0){
            sleep(seconds(3));
            window.close();
            music.stop();
            char_menu();
        }
        for(it=entities.begin();it!=entities.end();)
        {
            Entity *b = *it;
            b->update(time);
            if (b->life==false)	{ it  = entities.erase(it); delete b;}
            else it++;
        }


        Mario.update(time);
        healthBar.update(Mario.Health);


        for(it=entities.begin();it!=entities.end();it++)
        {

            if ((*it)->Name=="Enemy")
            {
                Entity *enemy = *it;

                if (enemy->Health<=0) continue;

                if  (Mario.getRect().intersects( enemy->getRect() ))
                    if (Mario.dy>0) {
                        enemy->dx=0;
                        Mario.dy=-0.2;
                        enemy->Health=0;
                        attributes.score += 100;
                        attributes.enemies++;
                        enemy_defeated.play();
                    }
                    else if (!Mario.hit) { bump.play(); Mario.Health-=5; Mario.hit=true;
                        if (Mario.dir) Mario.x+=10; else Mario.x-=10;}


                for (std::list<Entity*>::iterator it2=entities.begin(); it2!=entities.end(); it2++){
                    Entity *bullet = *it2;
                    if (bullet->Name=="Bullet")
                        if (bullet->Health>0)
                            if(bullet->getRect().intersects( enemy->getRect() ) ){
                                bump.play();
                                bullet->Health=0;
                                enemy->Health-=5;
                                attributes.score += 5;
                            if(enemy->Health == 0){
                                enemy_defeated.play();
                                attributes.score += 50;
                                attributes.enemies++;
                            }
                            }
                }
            }
            if((*it)->Name == "Coin"){
                Entity *coin = *it;
                if(Mario.getRect().intersects(coin->getRect())){
                    coin->Health = 0;
                    attributes.score += 50;
                    attributes.coins++;
                    coin_collected.play();
                }
            }
            if((*it)->Name == "Star"){
                Entity *star = *it;
                if(Mario.getRect().intersects(star->getRect())){
                    star->Health = 0;
                    music.stop();
                    lvl_completed.play();
                    sleep(seconds(8));
                    window.close();
                    end_level_menu();

                }
            }
        }


        /////////////////////отображаем на экран/////////////////////
        float temp_x = Mario.x; float temp_y = Mario.y;
        if(Mario.x < 245) temp_x = 245;
        if(Mario.x > 11750) temp_x = 11750;
        if(Mario.y > 450) temp_y = 450;
        view.setCenter(temp_x, temp_y);
        window.setView(view);

        background.setPosition(view.getCenter());
        window.draw(background);

        lvl.Draw(window);

        for(it=entities.begin();it!=entities.end();it++)
            (*it)->draw(window);

        Mario.draw(window);
        healthBar.draw(window);

        if(!showMissionText){
            health_amount.setPosition(view.getCenter().x + 25, view.getCenter().y + 100);
            window.draw(sprite);
            window.draw(health_amount);
        }
        window.display();
    }
}