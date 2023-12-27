#include "Player.hpp"

/**
 * @brief Player constructor
 * 
 * @param size Size of player sprite (first frame)
 * @param position Position of player sprite on window
 * @param speed Speed of player
 * @param spritePath Path to player sprite
*/
Player::Player(Rectangle size, Rectangle position, float speed, std::string spritePath) : m_oPlayerSrc(size), m_oPlayerDest(position), m_playerSpeed(speed) {
    const char *cstr = spritePath.c_str();
    m_oPlayerSprite = LoadTexture(cstr);
}

/**
 * @brief Player destructor
*/
Player::~Player() {
    UnloadTexture(m_oPlayerSprite);
}

/**
 * @brief Draws player to screen
*/
void Player::draw() {
    DrawTexturePro(m_oPlayerSprite, m_oPlayerSrc, m_oPlayerDest, Vector2{m_oPlayerDest.width, m_oPlayerDest.height}, 0.0, WHITE);
}

/**
 * @brief Handles all user input for player and aids in animation direction
*/
void Player::input() {
    if (IsKeyDown(KEY_W)) {
        m_playerMoving = true;
        m_playerDirection = 1;
        m_playerUp = true;
    }
    if (IsKeyDown(KEY_S)) {
        m_playerMoving = true;
        m_playerDirection = 0;
        m_playerDown = true;
    }
    if (IsKeyDown(KEY_A)) {
        m_playerMoving = true;
        m_playerDirection = 2;
        m_playerLeft = true;
    }
    if (IsKeyDown(KEY_D)) {
        m_playerMoving = true;
        m_playerDirection = 3;
        m_playerRight = true;
    }
}

/**
 * @brief Handles all movement and animation for player based on input
 * 
 * @param frameCounter Global frame counter for animation
*/
void Player::update(int frameCounter) {

    m_oPlayerSrc.x = m_oPlayerSrc.width * float(m_playerFrame); // 48 * Frame int to get X shift

    if (m_playerMoving) {
        // Move player based on direction
        if (m_playerUp) {m_oPlayerDest.y -= m_playerSpeed;}
        if (m_playerDown) {m_oPlayerDest.y += m_playerSpeed;}
        if (m_playerLeft) {m_oPlayerDest.x -= m_playerSpeed;}
        if (m_playerRight) {m_oPlayerDest.x += m_playerSpeed;}
        // Shift right by 48 pixels every 8 frames
        if (frameCounter % 8 == 1) {m_playerFrame++;} // 8 global frames per player frame
    } else if (frameCounter % 45 == 1) { // Make him idle every 45 frames
        m_playerFrame++;
    }
    

    if (m_playerFrame > 3) {m_playerFrame = 0;}
    if (!m_playerMoving && m_playerFrame > 1) {m_playerFrame = 0;} // If idle, only use first 2 frames

    m_oPlayerSrc.x = m_oPlayerSrc.width * float(m_playerFrame); // Update again for Idle frames
    m_oPlayerSrc.y = m_oPlayerSrc.height * float(m_playerDirection); // 48 * Direction int to get Y shift

    m_playerMoving = false;
    m_playerUp = m_playerDown = m_playerLeft = m_playerRight = false;
}