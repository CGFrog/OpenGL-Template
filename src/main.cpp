#include "GraphicsEngine/GraphicsEngine.hpp"
#include <iostream>
int main(){
    std::cout << "Main Initialized" << std::endl;
    GraphicsEngine graphicsEngine = GraphicsEngine();
    graphicsEngine.setup();
    graphicsEngine.run();
    graphicsEngine.loop();
    
    return 0;
}
