#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <functional>
#include "spriter.hpp"

class Window {
public:
	Window();
	Window(unsigned int width, unsigned int heigth, 
		   std::string& title, unsigned int frameRate, 
		   bool isVSyncEnable);
	~Window();
	void run(std::function<Spriter*()> func);

public:
	unsigned int Width() const;
	unsigned int Heigth() const;
	unsigned int FrameRate() const;
	bool IsVSyncEnable() const;
	std::string Title() const;

	void Width(unsigned int width);
	void Heigth(unsigned int heigth);
	void FrameRate(unsigned int frameRate);
	void IsVSyncEnable(bool isVSyncEnable);
	void Title(std::string title);
	                                  
private:
	void mainLoop(std::function<Spriter*()> func);
	void eventHandler(sf::Event event);

private:
	sf::RenderWindow* window;
	unsigned int width;
	unsigned int heigth;
	unsigned int frameRate;
	bool isVSyncEnable;
	std::string title;
};

#endif