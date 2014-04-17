#ifndef OBJECTMANAGER_H_INCLUDED
#define OBJECTMANAGER_H_INCLUDED
#include "VisibleObject.h"

class ObjectManager {
    public:
        ObjectManager();
        ~ObjectManager();
        void Add(std::string name, VisibleObject* object);
        void Remove(std::string name);
        VisibleObject* Get(std::string name) const;
        int GetObjectCount();
        void DrawAll(sf::RenderWindow& dWindow);
        void UpdateAll(float dT);

    private:
        std::map<std::string,VisibleObject*> mGameObjects;
};


#endif // OBJECTMANAGER_H_INCLUDED
