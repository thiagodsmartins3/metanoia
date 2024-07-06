#include "spriter.hpp"
#include "exceptions.hpp"

Spriter::Spriter() {
	sprite = new sf::Sprite();
	texture = new sf::Texture();
}

Spriter::~Spriter() {
	delete sprite;
	delete texture;
}

sf::Sprite* Spriter::Sprite() const {
	return sprite;
}

void Spriter::Sprite(sf::Sprite* sprite) {
	this->sprite = sprite;
}

void Spriter::loadTexture(std::string file, sf::IntRect sizePosition = sf::IntRect(10, 10, 32, 32)) {
	if (!texture->loadFromFile(file, sizePosition)) {
		throw Exceptions(Exceptions::ExceptionError::loadTextureFailure);
	}

	sprite->setTexture(*texture);
}