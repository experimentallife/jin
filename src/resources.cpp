#include "../include/basic.h"

const std::string Resources::graphicsDirectory = "../resources/images/";

const std::string Resources::fontsDirectory = "../resources/fonts/";

const std::string Resources::levelsDirectory = "../resources/levels/";


std::string Resources::getMenuBackgroundFont()
{
    return Resources::fontsDirectory + "ShipporiAntiqueB1.otf";
}

std::string Resources::getLevel1Map()
{
    return Resources::levelsDirectory + "level_01.txt";
}

std::string Resources::getLevel2Map()
{
    return Resources::levelsDirectory + "level_02.txt";
}

std::string Resources::getLevel3Map()
{
    return Resources::levelsDirectory + "level_03.txt";
}

std::string Resources::getExitDoorsTexture()
{
    return Resources::graphicsDirectory  + "closed_doors.png";
}

std::string Resources::getBackground5Texture()
{
    return Resources::graphicsDirectory  + "backg5.png";
}

std::string Resources::getBrick1Texture()
{
    return Resources::graphicsDirectory  + "brick_1.png";
}

std::string Resources::getCoinTexture()
{
    return Resources::graphicsDirectory  + "coin.png";
}

std::string Resources::getFireballTexture()
{
    return Resources::graphicsDirectory  + "fireball.png";
}

std::string Resources::getHeartTexture()
{
    return Resources::graphicsDirectory  + "heart.png";
}

std::string Resources::getLava11Texture()
{
    return Resources::graphicsDirectory  + "lava_1.png";
}

std::string Resources::getLava2Texture()
{
    return Resources::graphicsDirectory  + "lava_2.png";
}

std::string Resources::getMarble1Texture()
{
    return Resources::graphicsDirectory  + "marble_1.png";
}

std::string Resources::getVillainTexture()
{
    return Resources::graphicsDirectory  + "Villain.png";
}

std::string Resources::getWarlockTexture()
{
    return Resources::graphicsDirectory  + "warlock_of.png";
}

std::string Resources::getWater1Texture()
{
    return Resources::graphicsDirectory  + "water_1.png";
}

std::string Resources::getZombieTexture()
{
    return Resources::graphicsDirectory  + "Zombie.png";
}
