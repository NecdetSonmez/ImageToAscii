#ifndef OPENCVIMAGE_HPP
#define OPENCVIMAGE_HPP

#include "Image.hpp"
#include <opencv2/core/mat.hpp>
#include <string>

class OpenCvImage : public Image 
{
public:
    void readImage(const std::string& filename) override;
    void resizeImage(const unsigned int width, const unsigned height) override;
    void printAscii() override;

private:
    cv::Mat m_image;
};

#endif // OPENCVIMAGE_HPP