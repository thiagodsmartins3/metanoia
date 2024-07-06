#include "window.hpp"
#include "exceptions.hpp"

Window::Window() {
	Width(800);
	Heigth(600);
	FrameRate(60);
	IsVSyncEnable(true);
	Title("");

	window = new sf::RenderWindow(sf::VideoMode(Width(), Heigth()), "");
	window->setVerticalSyncEnabled(IsVSyncEnable());
	window->setFramerateLimit(FrameRate());
}

Window::Window(unsigned int width, unsigned int heigth, 
			   std::string& title, unsigned int frameRate = 60,
			   bool isVSyncEnable = false) {
	Width(width);
	Heigth(heigth);
	FrameRate(frameRate);
	IsVSyncEnable(isVSyncEnable);
	Title(title);

	window = new sf::RenderWindow(sf::VideoMode(Width(), Heigth()), title);
	window->setVerticalSyncEnabled(IsVSyncEnable());
	window->setFramerateLimit(FrameRate());
}

Window::~Window() {
	delete window;
}

void Window::run(std::function<Spriter*()> func) {
	mainLoop(func);
}

unsigned int Window::Width() const {
	return width;
}

unsigned int Window::Heigth() const {
	return heigth;
}

unsigned int Window::FrameRate() const {
	return frameRate;
}

bool Window::IsVSyncEnable() const {
	return isVSyncEnable;
}

std::string Window::Title() const {
	return title;
}

void Window::Width(unsigned int width) {
	this->width = width;
}

void Window::Heigth(unsigned int heigth) {
	this->heigth = heigth;
}

void Window::FrameRate(unsigned int frameRate) {
	this->frameRate = frameRate;
}

void Window::IsVSyncEnable(bool isVSyncEnable) {
	this->isVSyncEnable = isVSyncEnable;
}

void Window::Title(std::string title) {
	this->title = title;
}

void Window::mainLoop(std::function<Spriter*()> func) {
	while (window->isOpen()) {
		sf::Event event;

		while (window->pollEvent(event)) {
			eventHandler(event);
		}

		window->clear();
		window->draw(*func()->Sprite());
		window->display();
	}
}

void Window::eventHandler(sf::Event event) {
	switch (event.type)
	{
	case sf::Event::Closed:
		window->close();
		break;
	case sf::Event::Resized:
		break;
	default:
		break;
	}
}