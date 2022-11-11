#include"title.hpp"

#include"game.hpp"
#include"machine.hpp"

#include"generic.hpp"

TitleState::TitleState(Context& context, StateMachine& stateMachine)
    : State{context, stateMachine}

    , _backgroundSprite{}
{
    loadTextures();
    initialiseBackground(_context.textures());
}

void TitleState::handle(sf::Event const& event) {
    if(sf::Event::KeyPressed == event.type) {
        _stateMachine.clear();
        _stateMachine.push<GameState>();
    }
}

void TitleState::update() {}

void TitleState::draw() {
    auto& canvas = _context.canvas();
    canvas.draw(_backgroundSprite);
}

void TitleState::initialiseBackground(TextureHolder& textures) {
    auto& backgroundTexture = textures.get(media::Texture::titleScreen);
    _backgroundSprite.setTexture(backgroundTexture);
}

void TitleState::loadTextures() {
    auto& textures = _context.textures();

    textures.load(
        media::Texture::titleScreen, 
        "media/texture/titleScreen.png"
    );
}
