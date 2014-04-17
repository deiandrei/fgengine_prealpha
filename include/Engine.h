#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED
#include "ObjectManager.h"
class Engine {
    public:
        Engine();
        ~Engine();
        static void Init();
        static void GameLoop();
        static void HandleInput(sf::Keyboard::Key key, bool isPressed);
        static bool ReturnInputStatus(sf::Keyboard::Key key);

    private:
        static sf::RenderWindow mWindow;
        static ObjectManager mObjectManager;
        static bool PressedA,PressedS,PressedD,PressedW;

};


#endif // ENGINE_H_INCLUDED
