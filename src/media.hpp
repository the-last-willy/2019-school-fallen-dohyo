#pragma once

namespace sf {
	class Music;
	class Texture;
}

/// @brief Music identifiers.
namespace media { namespace Music { enum ID {
	mainTheme,
};}}

/// @brief Texture identifiers.
namespace media { namespace Texture { enum ID {
	background,
	platform,
	playerA,
	playerB,
	titleScreen,
};}}

	template <typename Resource, typename Identifier>
class ResourceHolder;

using MusicHolder = ResourceHolder<sf::Music, media::Music::ID>;
using TextureHolder = ResourceHolder<sf::Texture, media::Texture::ID>;
