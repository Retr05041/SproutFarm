#include "raylib.h"
#include "Player/Player.hpp"
#include "World/CustomCamera.hpp"

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 480;
bool isRunning = true;
int frameCounter = 0;
Color backgroundColor = {147, 211, 196, 255};
Texture2D grassSprite;
Player *player;
CustomCamera *playerCamera;

void drawScene() {
    DrawTexture(grassSprite, 100, 50, WHITE);
    player->draw();
}

/**
 * @brief Input function
 * 
 * @details Handles all input for respective objects
*/
void input() {
    player->input();
}

/**
 * @brief Update function
 * 
 * @details Handles all updating
*/
void update() {
    isRunning = !WindowShouldClose();
    player->update(frameCounter);
    frameCounter++;
    playerCamera->update(Vector2{player->getPlayerDestX()-(player->getPlayerDestWidth()/2), player->getPlayerDestY()-(player->getPlayerDestHeight()/2)});

    // if (frameCounter > 60) {frameCounter = 1;} - Keep for later? Overflow?
}

/**
 * @brief Render function
 * 
 * @details Handles all rendering for game
*/
void render() {
    BeginDrawing();
    ClearBackground(backgroundColor);    
    playerCamera->begin();

    drawScene();
        
    playerCamera->end();
    EndDrawing();
}

/**
 * @brief Init function
 * 
 * @details Initializes all variables and objects

*/
void init() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "SproutFarm");
    SetExitKey(0);
    SetTargetFPS(60);

    grassSprite = LoadTexture("res/Tilesets/Grass.png");
    player = new Player({0, 0, 48, 48}, {200, 200, 100, 100}, 3.0, "res/Characters/Basic_Charakter_Spritesheet.png");
    playerCamera = new CustomCamera(Vector2{SCREEN_WIDTH/2, SCREEN_HEIGHT/2}, Vector2{player->getPlayerDestX()-(player->getPlayerDestWidth()/2), player->getPlayerDestY()-(player->getPlayerDestHeight()/2)}, 0.0, 1.5);
}

/**
 * @brief Quit function
 * 
 * @details Deallocates all memory and quits game
*/
void quit() {
    UnloadTexture(grassSprite);
    delete player;
    delete playerCamera;
    CloseWindow();
}

/**
 * @brief Main function
 * 
 * @details Main game loop
*/
int main(int argc, char const *argv[]) {
    init();

    while (isRunning) {
        input();
        update();
        render();
    }

    quit();
    return 0;
}



/*
Possibly better animation idea: Shift source down 48 (48x48 grid spritesheet) or x depending on
Which direction they are going. Easier way?







*/