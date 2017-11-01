//
// Created by Богдан Полянок on 28.10.2017.
//

#include "imageConverter.hpp"


ImageConverter::ImageConverter(const std::string &fileName):
  image_(cv::imread(fileName, cv::IMREAD_GRAYSCALE)){
    std::ifstream imageFile;
    imageFile.open(fileName);
    if (!imageFile){
      throw std::invalid_argument("Invalid image;");
    }

    vecImage_ = makeVectorPerformance();
}

cv::Mat ImageConverter::getImage() const
{
  return image_;
}

std::vector<double> ImageConverter::getVecImage() const
{
  return vecImage_;
}

void ImageConverter::setImage(const std::string &fileName)
{
  std::ifstream imageFile;
  imageFile.open(fileName);
  if (!imageFile){
    throw std::invalid_argument("Invalid image;");
  }

  image_ = cv::imread(fileName, cv::IMREAD_GRAYSCALE);
  vecImage_ = makeVectorPerformance();
}

std::vector<double> ImageConverter::makeVectorPerformance() const
{
  enum Color{
    WHITE = 0,
    BLACK = 1
  };

  std::vector<double> image = {};
  for (size_t i = 0; i < 10; i++){
    for (size_t j = 0; j < 10; j++){
      cv::Scalar intensity = getImage().at<uchar>(i, j);

      Color color = WHITE;
      if (!intensity[0]){
        color = BLACK;
      }
      image.push_back((double)color);
    }
  }
  return image;
}

std::ostream& operator<<(std::ostream &out, const ImageConverter &imageConverter)
{
  std::vector<double> vecImage = imageConverter.getVecImage();
  for (size_t i = 0; i < 10; i++) {
    for (size_t j = 0; j < 10; j++) {
      char sym = '-';
      if (vecImage[i * 10 + j]){
        sym = '*';
      }
      out << sym << " ";
    }
    out << "\n";
  }
  return out;
}