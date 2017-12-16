#include "mazegame.h"
#include <iostream>

#ifdef WIN32
    #define PATH_SEPERATOR '\\'
#else
    #define PATH_SEPERATOR '/'
#endif

using namespace std;


int main(int argc, char* argv[])
{
    std::string argvString(argv[0]);
    std::string basePath = argvString.substr(0,argvString.find_last_of(PATH_SEPERATOR));

    std::cout << basePath << std::endl;
    MazeGame mazeGame(basePath);
    mazeGame.run();
}
