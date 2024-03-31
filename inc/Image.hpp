#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <iostream>
#include <memory>
#include <vector>
#include <array>
#include <opencv2/opencv.hpp>

class Image
{
public:
    virtual void readImage(const std::string& filename) = 0;
    virtual void resizeImage(const unsigned int width, const unsigned height) = 0;
    virtual void printAscii() = 0;
    virtual ~Image() {}
};

#endif