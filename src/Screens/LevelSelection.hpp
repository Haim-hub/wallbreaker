#ifndef LEVEL_SELECTION_HPP
#define LEVEL_SELECTION_HPP

#include "Screen.hpp"
#include "Gui/Menu.hpp"

class LevelSelection: public Screen
{
public:
	LevelSelection();
private:
	// override
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	Menu m_menu;
};

#endif // LEVEL_SELECTION_HPP
