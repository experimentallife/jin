#include "../include/basic.h"

const std::string Resources::graphicsDirectory = "../resources/images/";
const std::string Resources::fontsDirectory = "../resources/fonts/";

std::string Resources::getMenuBackgroundTexture()
{
    return Resources::graphicsDirectorym + "background.jpg"
}

std::String Resources::getMenuBackgroundFont()
{
    return Resources::fontsDirectory + "font.otf";
}

std::string Resources::getHeroTexture()
{
    return Resources::graphicsDirectory + "hero.png";
}

std::string Resources::getBackgroundTexture()
{
    return Resources::graphicsDirectory + "background.jpg";
}