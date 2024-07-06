#ifndef SPRITER_HPP
#define SPRITER_HPP

#include <SFML/Graphics.hpp>
#include <string>

class Spriter {
public:
	Spriter();
	~Spriter();
	void loadTexture(std::string file, sf::IntRect sizePosition);

	sf::Sprite* Sprite() const;
	void Sprite(sf::Sprite* sprite);

private:
	sf::Sprite* sprite;
	sf::Texture* texture;
};

#endif