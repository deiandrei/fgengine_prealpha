#include "stdafx.h"
#include "include/PawnEntityObject.h"
#include "include/Engine.h"

PawnEntityObject::PawnEntityObject() {
    mSprite.setPosition(mSprite.getGlobalBounds().width, 768-18);
}

PawnEntityObject::~PawnEntityObject() {

}

void PawnEntityObject::Update(float dT) {
    sf::Vector2f movement;
    if(mIsLoaded) {
        if(Engine::ReturnInputStatus(sf::Keyboard::A)) {
            movement.x -= 300.f;
        }

        if(Engine::ReturnInputStatus(sf::Keyboard::D)) {
            movement.x += 300.f;
        }


    }
    mSprite.move(movement * dT);
}
