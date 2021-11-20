cmake_minimum_required(VERSION 3.20)
project(untitled4)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(untitled4 main.cpp headers/Map.h headers/Tile.h source/GameField.cpp headers/GameField.h headers/Coordinate.h headers/ElementsDefinition.h source/GameStatePlaying.cpp headers/GameStatePlaying.h source/GameLogic.cpp headers/GameLogic.h source/GameObject.cpp headers/GameObject.h source/EnemyGhost.cpp headers/EnemyGhost.h headers/TextureManager.h source/TextureManager.cpp source/AnimationSprite.cpp headers/AnimationSprite.h headers/Game.h headers/GameState.h source/Game.cpp headers/GameStateMenu.h headers/RenderManager.h source/GameStateMenu.cpp headers/Animation.h source/Animation.cpp headers/Movement.h headers/Enemy.h headers/Player.h headers/EnemyGhostWhite.h source/EnemyGhostWhite.cpp headers/EnemiesWave.h source/EnemiesWave.cpp source/Spawner.cpp headers/Spawner.h source/GameStateGameOver.cpp headers/GameStateGameOver.h)

target_link_libraries(untitled4 sfml-graphics sfml-audio)
