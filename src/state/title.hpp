#pragma once

#include"state.hpp"

#include<SFML/Graphics.hpp>

/**
 * @brief Title screen.
 * @ingroup state
 */
class TitleState : public State {
public:
    TitleState(Context&, StateMachine&);

    void handle(sf::Event const&) override;
    void update() override;
    void draw() override;

    void loadTextures();

private:
    void initialiseBackground(TextureHolder&);

    sf::Sprite _backgroundSprite;
};
