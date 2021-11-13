#ifndef HERO_H_
#define HERO_H_

class Hero : public Character
{
    public:
        Hero();
        virtual ~Hero();

        Hero * getHero();
};

#endif