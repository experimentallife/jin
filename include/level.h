#ifndef LEVEL_H_
#define LEVEL_H_

class Level
{
    protected:
        float startX;
        float startY;
        bool isCompleted;

        std::string levelName;

        sf::View camera;
        sf::Clock clock;
        sf::Texture background;
        sf::RenderWindow & window;

    public:
        Level(sf::RenderWindow &, );
};

#ifndef