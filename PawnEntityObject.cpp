#include "stdafx.h"
#include "include/PawnEntityObject.h"
#include "include/Engine.h"

PawnEntityObject::PawnEntityObject() {

}

PawnEntityObject::~PawnEntityObject() {

}

void PawnEntityObject::Update(float dT) {
    float rotation = mSprite.getRotation();
    sf::Vector2f movement;
    if(mIsLoaded) {
        if (Engine::ReturnInputStatus(sf::Keyboard::A)) {
            movement.x -= 100;
            mSprite.setRotation(270);
        }

        if (Engine::ReturnInputStatus(sf::Keyboard::D)) {
            movement.x += 100;
            mSprite.setRotation(90);
        }

        if (Engine::ReturnInputStatus(sf::Keyboard::W)) {
            movement.y -= 100;
            mSprite.setRotation(0);
        }

        if (Engine::ReturnInputStatus(sf::Keyboard::S)) {
            movement.y += 100;
            mSprite.setRotation(180);
        }
        if (Engine::ReturnInputStatus(sf::Keyboard::A) && Engine::ReturnInputStatus(sf::Keyboard::W)) {
            mSprite.setRotation(315);
        }
        if (Engine::ReturnInputStatus(sf::Keyboard::A) && Engine::ReturnInputStatus(sf::Keyboard::S)) {
            mSprite.setRotation(225);
        }
        if (Engine::ReturnInputStatus(sf::Keyboard::D) && Engine::ReturnInputStatus(sf::Keyboard::W)) {
            mSprite.setRotation(45);
        }
        if (Engine::ReturnInputStatus(sf::Keyboard::D) && Engine::ReturnInputStatus(sf::Keyboard::S)) {
            mSprite.setRotation(135);
        }
        mSprite.move(movement * dT);

    }
}
