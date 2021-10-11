#include "../include/basic.h"

Menu::Menu()
{
    buttonId = 0;
    deltaTime = 0.1f;
    heroSpecSet = false;
    menuState = MAIN_MENU;
}

Menu::~Menu()
{
    ;
}

bool Menu::isSpecSet()
{
    return heroSpecSet
}

heroSpecSet Menu::getChosenSpec()
{
    if (this->isSpecSet()) return whitchSpecSet;
    else return heroSpec::unknown;
}

int Menu::getButtonId()
{
    return this->buttonId:
}