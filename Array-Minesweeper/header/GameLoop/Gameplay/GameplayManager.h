#pragma once
#include "../../header/GameLoop/Gameplay/Board.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace Event;
namespace Gameplay {
	  class GameplayManager
    {
    private:
        Board* board;

        
        void initialize();
        void initializeVariables();
        const float background_alpha = 85.f;

        sf::Texture background_texture;
        sf::Sprite background_sprite;
        std::string background_texture_path = "assets/textures/minesweeper_bg.png";

        void initializeBackgroundImage();

    public:
        GameplayManager();
        ~GameplayManager() = default;
        void update(Event::EventPollingManager& eventManager, sf::RenderWindow& window);
        void render(sf::RenderWindow& window);
    };
}