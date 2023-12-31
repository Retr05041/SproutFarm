// Header file for the TileMapper class.

#ifndef TILEMAPPER_HPP
#define TILEMAPPER_HPP

#include "raylib.h"
#include "stdio.h"
#include <string>
#include <vector>

class TileMapper {
    public:
        TileMapper(Rectangle size, Rectangle position, int mapWidth, int mapHeight, std::string tileMapPath);
        ~TileMapper();
        void draw();
        void loadMap();
    private:
        Texture2D m_oTileSprite;
        Rectangle m_oTileDest;
        Rectangle m_oTileSrc;
        std::vector<int> m_tileMap;
        std::string m_tileMapPath;
        std::string m_tileMapName;
        int m_mapWidth;
        int m_mapHeight;
};

#endif
