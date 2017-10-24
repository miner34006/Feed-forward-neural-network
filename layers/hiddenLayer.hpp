//
// Created by Богдан Полянок on 30.09.2017.
//

#ifndef COURSE_PROJECT_HIDDENLAYER_HPP
#define COURSE_PROJECT_HIDDENLAYER_HPP

#include "layer.hpp"

class HiddenLayer: public Layer{
public:
  explicit HiddenLayer(const size_t& neuronQuantity);
  void error(const double& expected, const double& learningRate, const double& alpha) override;
};

#endif //COURSE_PROJECT_HIDDENLAYER_HPP
