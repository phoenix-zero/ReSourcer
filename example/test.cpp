#include <iostream>
#include "../ReSourcer_Lib/resourcer.hpp"
#ifdef GRAPHIC
#include <SFML/Graphics.hpp>
#endif

int main()
{
#ifndef GRAPHIC
	std::cout << ReSourcer::getItemText("text");
#else
	sf::RenderWindow win(sf::VideoMode(600,600),"HelloWorld");
	sf::Event e;
	while(win.isOpen())
	{
		if(win.pollEvent(e))
			if(e.type == e.Closed)
				win.close();
		win.clear();
		sf::Texture texture;
		texture.loadFromMemory(ReSourcer::rawItem("img"),ReSourcer::itemSize("img"));
		sf::Sprite sprite;
		sprite.setTexture(texture, true);
		win.draw(sprite);
		win.display();
	}
#endif
	return 0;
}
