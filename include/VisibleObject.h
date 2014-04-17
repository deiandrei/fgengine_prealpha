#ifndef VISIBLEOBJECT_H_INCLUDED
#define VISIBLEOBJECT_H_INCLUDED
class VisibleObject {
    public:
        VisibleObject();
        ~VisibleObject();
        virtual void Load(std::string filename);
        virtual void Draw(sf::RenderWindow& dWindow);
        virtual void Update(float dT);
        bool IsLoaded();
        sf::Sprite mSprite;
        sf::Texture mTexture;
        bool mIsLoaded;
        std::string mFilename;

};


#endif // VISIBLEOBJECT_H_INCLUDED
