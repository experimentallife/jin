#ifndef ENTITY_H_
#define ENTITY_H_

class Entity
{
    protected:
        bool dead;
        bool canMove;
        int ID;

        sf::Clock clock;
        sf::Texture * texture;
        sf::Sprite sprite;
        sf::Vector2i coords;
        sf::Vector2f coordsFlt;

    public:
        Entity();
        virtual ~Entity();

        int getID() { return this->ID }
        sf::Clock getClock() { return this->clock; }
        sf::Texture * getTexture() { return this->texture; }
        sf::Sprite getSprite() { return this->sprite; }
        sf::Vector2i getCoords();
        sf::Vector2f getPosition();

        void setTexture(sf::Texture*);
        void setCoords(sf::Vector2i);
        void setPosition(sf::Vector2f);

        bool isStable();
        bool isMoveable();
        bool isDead();
        void destroy();

        virtual bool checkCollision(Entity *);
        virtual bool collision(Entity *) = 0;
        virtual void update(float) = 0;
}

#endif