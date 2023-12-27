// Header file for Player Class

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "raylib.h"
#include "stdio.h"
#include <string>

/**
 * @brief Player class
 * 
 * @details Handles all player related functions
*/
class Player {
    public:
        Player(Rectangle size, Rectangle position, float speed, std::string spritePath);
        ~Player();
        void draw();
        void input();
        void update(int frameCounter);
        float getPlayerDestX() { return m_oPlayerDest.x; }
        float getPlayerDestY() { return m_oPlayerDest.y; }
        float getPlayerDestWidth() { return m_oPlayerDest.width; }
        float getPlayerDestHeight() { return m_oPlayerDest.height; }
    private:
        Rectangle m_oPlayerSrc;
        Rectangle m_oPlayerDest;
        float m_playerSpeed;
        Texture2D m_oPlayerSprite;

        bool m_playerMoving;
        int m_playerDirection;
        bool m_playerUp, m_playerDown, m_playerLeft, m_playerRight;
        int m_playerFrame;
};

#endif