//
// Created by Богдан Полянок on 28.10.2017.
//

#ifndef COURSE_PROJECT_imageConverter_HPP
#define COURSE_PROJECT_imageConverter_HPP

#include <opencv2/opencv.hpp>
#include <istream>
#include <vector>
#include <string>

class ImageConverter{
public:
  explicit ImageConverter(const std::string &fileName);

  friend std::ostream& operator<<(std::ostream& out, const ImageConverter& imageConverter);

  cv::Mat getImage() const;
  void setImage(const std::string &fileName);

  std::vector<double> getVecImage() const;

private:
  cv::Mat image_;
  std::vector<double > vecImage_;

  std::vector<double> makeVectorPerformance() const;
};

std::ostream& operator<<(std::ostream& out, const ImageConverter& imageConverter);

#endif //COURSE_PROJECT_imageConverter_HPP
