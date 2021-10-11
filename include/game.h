#ifndef GAME_H_
#define GAME_H_

enum GameState { MENU = 0, GAME = 1, END = 2 }

class Game
{
    protected:
        sf::RenderWindow window;
        GameState state;
        int lastPoints;
        float lastTime;

    public:
        Game();
        ~Game();

        sf::RenderWindow & getWindow();
        GameState getState();
        void setState(GameState);

        void run();
        void updateScore(int, float);
}