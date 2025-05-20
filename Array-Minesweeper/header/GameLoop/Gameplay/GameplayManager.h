#pragma once
#include "../../header/GameLoop/Gameplay/Board.h"
#include "../../header/Event/EventPollingManager.h"
#include "../../header/UI/GameplayUI.h"
#include "../../../header/Time/TimeManager.h" 
#include <SFML/Graphics.hpp>
#include <iostream>

namespace Gameplay {
    using namespace Event;
    using namespace Time;
    using namespace UI;
    enum class GameResult {
        NONE,
        WON,
        LOST
    };
	  class GameplayManager
    {
    private:
        Board* board;

        GameResult game_result;
        GameplayUI* gameplay_ui;

        void initialize();
        void initializeVariables();
        const float background_alpha = 85.f;

        sf::Texture background_texture;
        sf::Sprite background_sprite;
        std::string background_texture_path = "assets/textures/minesweeper_bg.png";


        int getRemainingMinesCount() const;


        const float max_level_duration = 150.0f;
        const float game_over_time = 11.0f;
        float remaining_time;

        void updateRemainingTime();
        void processTimeOver();

        void handleGameplay(EventPollingManager& eventManager, sf::RenderWindow& window);
        void initializeBackgroundImage();

        


        void gameWon();
        void gameLost();

        bool hasGameEnded();
    public:
        GameplayManager();
        ~GameplayManager() = default;

        void checkGameWin();
        void processGameResult();

        void update(Event::EventPollingManager& eventManager, sf::RenderWindow& window);
        void render(sf::RenderWindow& window);

        void setGameResult(GameResult gameResult);
    };
}