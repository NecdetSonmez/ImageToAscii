#include <iostream>
#include <memory>
#include <vector>
#include <array>
#include <string>
#include <opencv2/opencv.hpp>

#include "OpenCvImage.hpp"


int main(int argc, char* argv[])
{
    if(argc < 4) {
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
    
//    cv::Mat image = cv::imread(inputString, cv::IMREAD_COLOR);
//    if(image.empty()) {
//        std::cout << "Could not open or find the image" << std::endl;
//        return -1;
//    }
//
//    cv::Mat grayImage;
//    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);
//
//    std::cout << grayImage.rows << " " << grayImage.cols << std::endl;
//    std::string depthString;
//    switch (grayImage.depth()) {
//        case CV_8U: depthString = "8-bit unsigned"; break;
//        case CV_8S: depthString = "8-bit signed"; break;
//        case CV_16U: depthString = "16-bit unsigned"; break;
//        case CV_16S: depthString = "16-bit signed"; break;
//        case CV_32S: depthString = "32-bit signed"; break;
//        case CV_32F: depthString = "32-bit float"; break;
//        case CV_64F: depthString = "64-bit float"; break;
//        default: depthString = "Unknown";
//    }
//    std::cout << "Depth (type): " << depthString << std::endl;
//
//    std::array<char, 4> dataTable = {'.', 'o', 'O', '@'};
//    // Resize to 100x100
//    cv::Mat resizedImage;
//    cv::resize(grayImage, resizedImage, cv::Size(100, 100));
//
//    for (int i = 0; i < resizedImage.rows; i++)
//    {
//        for (int j = 0; j < resizedImage.cols; j++)
//        {
//            const unsigned char pixel = resizedImage.at<uchar>(j, i);
//            const unsigned char range = 64;
//            unsigned char level = pixel / range;
//            std::cout << dataTable[level];
//        }
//        std::cout << std::endl;
//    }

    return 0;
}