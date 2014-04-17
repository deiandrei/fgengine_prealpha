#include "stdafx.h"
#include "include/VisibleObject.h"

VisibleObject::VisibleObject() {

}

VisibleObject::~VisibleObject() {

}

bool VisibleObject::IsLoaded() {
    return mIsLoaded;
}

void VisibleObject::Load(std::string filename) {
    if(!mTexture.loadFromFile(filename)) {
        mIsLoaded = false;
        mFilename = "";
        assert(mIsLoaded);
    } else {
        mIsLoaded = true;
        mFilename = filename;
        mSprite.setTexture(mTexture);
        mSprite.setOrigin(mSprite.getGlobalBounds().width/2,mSprite.getGlobalBounds().height/2);
    }
}

void VisibleObject::Draw(sf::RenderWindow& dWindow) {
    if(IsLoaded()) {
        dWindow.draw(mSprite);
    }
}

void VisibleObject::Update(float dT) {

}
