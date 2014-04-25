#include "stdafx.h"
#include "include/Engine.h"
#include "include/PawnEntityObject.h"

Engine::Engine() {

}

Engine::~Engine() {

}

void Engine::Init() {
    mWindow.create(sf::VideoMode(1024,768,32), "FGEngine - PREALPHA");
    PawnEntityObject *player = new PawnEntityObject();
    player->Load("pl.png");
    mObjectManager.Add("player", player);
    mMapManager.LoadMap();
    GameLoop();
    mWindow.close();
}

void Engine::GameLoop() {
    sf::Event mEvent;
    sf::Clock mClock;
    while(mWindow.isOpen()) {
        while(mWindow.pollEvent(mEvent)) {
            switch(mEvent.type) {
                case sf::Event::Closed:
                    mWindow.close();
                    break;
                case sf::Event::KeyPressed:
                    HandleInput(mEvent.key.code, true);
                    break;
                case sf::Event::KeyReleased:
                    HandleInput(mEvent.key.code, false);
                    break;
            }
        }
        mWindow.clear();
        mMapManager.DrawMap(mWindow);
        mObjectManager.UpdateAll(mClock.restart().asSeconds());
        mObjectManager.DrawAll(mWindow);
        mWindow.display();
    }
}

void Engine::HandleInput(sf::Keyboard::Key key, bool isPressed) {
    if(key == sf::Keyboard::A) PressedA = isPressed;
    if(key == sf::Keyboard::D) PressedD = isPressed;
    if(key == sf::Keyboard::W) PressedW = isPressed;
    if(key == sf::Keyboard::S) PressedS = isPressed;
}

bool Engine::ReturnInputStatus(sf::Keyboard::Key key) {
    if(key == sf::Keyboard::A) return PressedA;
    if(key == sf::Keyboard::D) return PressedD;
    if(key == sf::Keyboard::W) return PressedW;
    if(key == sf::Keyboard::S) return PressedS;
}


sf::RenderWindow Engine::mWindow;
ObjectManager Engine::mObjectManager;
bool Engine::PressedA,Engine::PressedS,Engine::PressedD,Engine::PressedW;
MapManager Engine::mMapManager;
