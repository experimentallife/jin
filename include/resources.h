#ifndef RESOURCES_H_
#define RESOURCES_H_
#include <string>

class Resources
{
    public:
        static std::string getMenuBackgroundTexture();
        static std::string getMenuBackgroundFont();
        static std::string getHeroTexture();
        static std::string getBackgroundTexture();

        static const std::string graphicsDirectory;
        static const std::string fontsDirectory;
};

#endif