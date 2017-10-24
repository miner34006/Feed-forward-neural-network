//
// Created by Богдан Полянок on 30.09.2017.
//

#ifndef COURSE_PROJECT_INPUTLAYER_HPP
#define COURSE_PROJECT_INPUTLAYER_HPP

#include "layer.hpp"

class InputLayer: public Layer{
public:
  explicit InputLayer(const size_t& neuronQuantity);

  void setInputData(const std::vector<double>& data) override;

  void error(const double &expected, const double& learningRate, const double& alpha) override;
};

#endif //COURSE_PROJECT_INPUTLAYER_HPP
