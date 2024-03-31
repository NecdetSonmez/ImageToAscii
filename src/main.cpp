#include <iostream>
#include <memory>
#include <vector>
#include <array>
#include <string>
#include <opencv2/opencv.hpp>

#include "OpenCvImage.hpp"


int main(int argc, char* argv[])
{
    if(argc < 4) 
    {
        std::cout << "Usage: ./ImageToAscii <filepath> <width> <height>" << std::endl;
        return -1;
    }
    
    std::vector<std::string> args(argv + 1, argv + argc);
    std::string inputString = args[0];
    const int width = std::stoi(args[1]);
    const int height = std::stoi(args[2]);

    OpenCvImage image;
    image.readImage(inputString);
    image.resizeImage(width, height);
    image.printAscii();

    return 0;
}