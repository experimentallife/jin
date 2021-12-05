#ifndef RESOURCES_H_
#define RESOURCES_H_
#include <string>

class Resources
{
public:
    static const std::string graphicsDirectory;
    static const std::string fontsDirectory;
    static const std::string levelsDirectory;

    static std::string getMenuBackgroundFont();

    static std::string getLevel1Map();
    static std::string getLevel2Map();
    static std::string getLevel3Map();

    static std::string getExitDoorsTexture();
    static std::string getBackground5Texture();
    static std::string getBrick1Texture();
    static std::string getCoinTexture();
    static std::string getFireballTexture();
    static std::string getHeartTexture();
    static std::string getLava11Texture();
    static std::string getLava2Texture();
    static std::string getMarble1Texture();
    static std::string getVillainTexture();
    static std::string getWarlockTexture();
    static std::string getWater1Texture();
    static std::string getZombieTexture();
};

#endif