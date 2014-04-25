#include "stdafx.h"
#include "include/MapManager.h"

MapManager::MapManager() {

}

MapManager::~MapManager() {

}

void MapManager::LoadMap() {
    if(!mBGTexture.loadFromFile("mapbg.png")) {
        assert(mBGTexture.loadFromFile("mapbg.png"));
    }
    mBG.setTexture(mBGTexture);
    mBG.setOrigin(mBG.getGlobalBounds().width/2,mBG.getGlobalBounds().height/2);
    if(!mGroundTexture.loadFromFile("mapground.png")) {
        assert(mGroundTexture.loadFromFile("mapground.png"));
    }
    for(int i=1;i<10;i++) {
        mGround[i].setTexture(mGroundTexture);
        mGround[i].setOrigin(mGround[i].getGlobalBounds().width/2,mGround[i].getGlobalBounds().height/2);
        if(i==1) {
            mGround[i].setPosition(mGround[i].getGlobalBounds().width/2,768-mGround[i].getGlobalBounds().height/2);
        } else {
            mGround[i].setPosition(mGround[i].getGlobalBounds().width/2 + mGround[i-1].getGlobalBounds().width,768-mGround[i].getGlobalBounds().height/2);
        }
    }


}

void MapManager::DrawMap(sf::RenderWindow& dWindow) {
    for(int i=1;i<10;i++)
        dWindow.draw(mGround[i]);
}

void MapManager::UpdateMap(float dT) {

}
