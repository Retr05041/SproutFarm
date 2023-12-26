#include "Player.hpp"

Player::Player(Rectangle position, Rectangle size, float speed, std::string spritePath) : m_oPlayerSrc(position), m_oPlayerDest(size), m_playerSpeed(speed) {
    const char *cstr = spritePath.c_str();
    m_oPlayerSprite = LoadTexture(cstr);
}

Player::~Player() {
    UnloadTexture(m_oPlayerSprite);
}

void Player::draw() {
    DrawTexturePro(m_oPlayerSprite, m_oPlayerSrc, m_oPlayerDest, Vector2{m_oPlayerDest.width, m_oPlayerDest.height}, 0.0, WHITE);
}

void Player::input() {
    if (IsKeyDown(KEY_RIGHT)) {
        m_oPlayerDest.x += m_playerSpeed;
    }
    if (IsKeyDown(KEY_LEFT)) {
        m_oPlayerDest.x -= m_playerSpeed;
    }
    if (IsKeyDown(KEY_UP)) {
        m_oPlayerDest.y -= m_playerSpeed;
    }
    if (IsKeyDown(KEY_DOWN)) {
        m_oPlayerDest.y += m_playerSpeed;
    }
}

void Player::update() {
    input();
}