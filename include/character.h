#ifndef CHARACTER_H_
#ifndef CHARACTER_H_

class Character : public Moveable
{
    protected:
        std::string name;
        int health;

        sf::Vector2f movement;
        sf::Vector2f lastMovement;

        float moveSpeed;
        float jumpSpeed;
        float gravity;
        bool faceRight, isJumping, isFalling, isColliding;

    public:
        Character();
        virtual ~Character();

        virtual void draw(sf::RenderWindow &);
        virtual bool collision(Entity *);
        virtual void update(float);

        int getHealth();
        sf::Vector2f getLastMovement();
        bool isFacingRigth();
        void move(sf::Vector2f);

        void setX(float);
        void setY(float);
        void setName(const std::string &);
        void setHealth(int);
        void setCollisionState(bool);
};

#endif