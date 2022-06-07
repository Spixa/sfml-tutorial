#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

class Game {
  private:
    sf::RenderWindow window;
    sf::Event event;

    static Game* m_instance;
  private:
    Game();
    ~Game();

    void loop();
    void render();
    void update();

    void closeEvent();
  public:
    Game(const Game& other) = delete;
    Game& operator=(const Game& other) = delete;

    int exec();

    static Game* getInstance();
};


#endif