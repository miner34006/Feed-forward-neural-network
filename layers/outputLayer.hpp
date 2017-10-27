//
// Created by Богдан Полянок on 30.09.2017.
//

#ifndef COURSE_PROJECT_OUTPUTLAYER_HPP
#define COURSE_PROJECT_OUTPUTLAYER_HPP

#include "layer.hpp"

class OutputLayer: public Layer{
public:
  explicit OutputLayer(const size_t& neuronQuantity);

  void changeWeights(const double& expected, const double& learningRate, const double& alpha);
};

#endif //COURSE_PROJECT_OUTPUTLAYER_HPP
