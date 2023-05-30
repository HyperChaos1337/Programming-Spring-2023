cmake_minimum_required(VERSION 3.23)
project(TestCW)

set(CMAKE_CXX_STANDARD 20)

include_directories(source)
include_directories(source/TinyXML)

add_executable(TestCW

        source/TinyXML/tinystr.cpp
        source/TinyXML/tinystr.h
        source/TinyXML/tinyxml.cpp
        source/TinyXML/tinyxml.h
        source/TinyXML/tinyxmlerror.cpp
        source/TinyXML/tinyxmlparser.cpp

        source/Animation/Animation.h source/Animation/Animation.cpp
        source/Animation/AnimationManager.h source/Animation/AnimationManager.cpp

        source/Attributes/Attributes.h source/Attributes/Attributes.cpp
        source/Attributes/CharMenu.h source/Attributes/CharMenu.cpp
        source/Attributes/HealthBar.h source/Attributes/HealthBar.cpp

        source/Entities/Coin.h source/Entities/Coin.cpp
        source/Entities/Star.h source/Entities/Star.cpp

        source/Game/Game.h source/Game/Game.cpp
        source/Game/Level.h source/Game/Level.cpp

        source/FileManagement/File.cpp source/FileManagement/File.cpp
        source/FileManagement/LevelFile.h source/FileManagement/LevelFile.cpp
        source/FileManagement/PlayerFile.h source/FileManagement/PlayerFile.cpp
        source/FileManagement/AnimationFile.h source/FileManagement/AnimationFile.cpp
        source/FileManagement/BGFile.h source/FileManagement/BGFile.cpp
        source/FileManagement/MusicFile.h source/FileManagement/MusicFile.cpp

        main.cpp source/Entities/Bullet.h source/Entities/Bullet.cpp source/Entities/Entity.h source/Entities/Entity.cpp source/Entities/Enemy.h source/Entities/Enemy.cpp source/Entities/Player.h source/Entities/Player.cpp)

set(SFML_DIR "C:\\Users\\User\\CLionProjects\\lib\\sfml\\GCC 7.3.0 MinGW (SEH) - 64-bit\\SFML-2.5.1\\lib\\cmake\\SFML")
target_link_libraries(TestCW sfml-graphics sfml-audio)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.5 REQUIRED graphics network audio window system)