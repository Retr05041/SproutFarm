#include "TileMapper.hpp"

TileMapper::TileMapper(Rectangle size, Rectangle position, int mapWidth, int mapHeight, std::string tileMapPath) : m_oTileDest(position), m_oTileSrc(size), m_mapWidth(mapWidth), m_mapHeight(mapHeight), m_tileMapPath(tileMapPath) {
    const char *cstr = tileMapPath.c_str();
    m_oTileSprite = LoadTexture(cstr);
}

TileMapper::~TileMapper() {
    UnloadTexture(m_oTileSprite);
}

void TileMapper::draw() {
    for (int i = 0; i < m_tileMap.size(); i++) {
        if (m_tileMap.at(i) != 0) {
            m_oTileDest.x = m_oTileDest.width * float(i % m_mapWidth); // we use modulo to get the remainder of i divided by the map width to get the x position
            m_oTileDest.y = m_oTileDest.height * float(i / m_mapWidth); // we use division to get the quotient of i divided by the map width to get the y position
            // Where in the image its pulling from?
            m_oTileSrc.x = m_oTileSrc.width * float((m_tileMap.at(i)-1) % int(m_oTileSprite.width/int(m_oTileSrc.width)));
            m_oTileSrc.y = m_oTileSrc.height * float((m_tileMap.at(i)-1) / int(m_oTileSprite.width/int(m_oTileSrc.width)));

            DrawTexturePro(m_oTileSprite, m_oTileSrc, m_oTileDest, Vector2{m_oTileDest.width, m_oTileDest.height}, 0.0, WHITE);
        }
    }
}

void TileMapper::loadMap() {
    m_tileMap.resize(m_mapWidth * m_mapHeight);
    for (int i = 0; i < m_tileMap.size(); i++) {
        m_tileMap.at(i) = 1;
    }
}