#include "game.hpp"
#include <SFML/Window/WindowStyle.hpp>
#include <iostream>

Game* Game::m_instance = nullptr;

Game* Game::getInstance() {
  if (m_instance == nullptr) {
    m_instance = new Game();
  }
  return m_instance;
}


Game::Game() : window(sf::VideoMode(800, 600), "Hello, world", sf::Style::Close) {
  
}

Game::~Game() {}

void Game::loop() {
  while (window.isOpen()) {
    render();
    update();
  }
}

void Game::render() {
  window.clear();

  // render stuff

  window.display();
}

void Game::update() {
  
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      closeEvent();
    }
  }
}

int Game::exec() {
  loop();
  return 0;
}

void Game::closeEvent() {
  std::cout << "Window closed!\n";
  window.close();
}