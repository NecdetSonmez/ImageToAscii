#include "OpenCvImage.hpp"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

void OpenCvImage::readImage(const std::string& filename) 
{
    m_image = cv::imread(filename, cv::IMREAD_COLOR);
    if (m_image.empty()) 
    {
        std::cerr << "Could not read the image: " << filename << std::endl;
    }

    cv::cvtColor(m_image, m_image, cv::COLOR_BGR2GRAY);
}

void OpenCvImage::resizeImage(const unsigned int width, const unsigned int height)
{
    cv::resize(m_image, m_image, cv::Size(width, height));
}

void OpenCvImage::printAscii()
{
    const std::array<const char, 4> dataTable = {' ', '.', 'o', '@'};
    for (int i = 0; i < m_image.rows; i++)
    {
        for (int j = 0; j < m_image.cols; j++)
        {
            const unsigned char pixel = m_image.at<uchar>(j, i);
            const unsigned char range = 64;
            unsigned char level = pixel / range;
            std::cout << dataTable[level];
        }
        std::cout << std::endl;
    }
}