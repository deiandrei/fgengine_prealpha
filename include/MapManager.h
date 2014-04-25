#ifndef MAPMANAGER_H_INCLUDED
#define MAPMANAGER_H_INCLUDED
class MapManager {
    public:
        MapManager();
        ~MapManager();
        void LoadMap();
        void DrawMap(sf::RenderWindow& dWindow);
        void UpdateMap(float dT);
        sf::Texture mBGTexture,mGroundTexture;
        sf::Sprite mBG[10],mGround[10];
};


#endif // MAPMANAGER_H_INCLUDED
