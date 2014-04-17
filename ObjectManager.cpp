#include "stdafx.h"
#include "include/ObjectManager.h"

ObjectManager::ObjectManager() {

}

ObjectManager::~ObjectManager() {

}

void ObjectManager::Add(std::string name, VisibleObject* object) {
    mGameObjects.insert(std::pair<std::string,VisibleObject*>(name,object));
}

void ObjectManager::Remove(std::string name) {
    std::map<std::string, VisibleObject*>::iterator itr = mGameObjects.find(name);
    if(itr != mGameObjects.end()) {
        delete itr->second;
        mGameObjects.erase(name);
    }
}

VisibleObject* ObjectManager::Get(std::string name) const {
    std::map<std::string, VisibleObject*>::const_iterator itr = mGameObjects.find(name);
    if(itr == mGameObjects.end()) {
        return NULL;
    }
    return itr->second;
}

int ObjectManager::GetObjectCount() {
    return mGameObjects.size();
}

void ObjectManager::DrawAll(sf::RenderWindow& dWindow) {
    std::map<std::string, VisibleObject*>::iterator itr = mGameObjects.begin();
    while(itr != mGameObjects.end()) {
        itr->second->Draw(dWindow);
        itr++;
    }
}

void ObjectManager::UpdateAll(float dT) {
    std::map<std::string, VisibleObject*>::iterator itr = mGameObjects.begin();
    while(itr != mGameObjects.end()) {
        itr->second->Update(dT);
        itr++;
    }
}
