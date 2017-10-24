//
// Created by Богдан Полянок on 30.09.2017.
//

#ifndef COURSE_PROJECT_NEURALNETWORK_HPP
#define COURSE_PROJECT_NEURALNETWORK_HPP

#include <vector>
#include <memory>
#include <math.h>

#include "layers/inputLayer.hpp"
#include "layers/hiddenLayer.hpp"
#include "layers/outputLayer.hpp"

class NeuralNetwork{
public:
  NeuralNetwork(const double& learningRate, const double& momentum, const std::vector<int> &neuronPerLayer);

  std::shared_ptr<Layer> operator [](const size_t& index);

  void setInputData(const std::vector<double>& data);

  void forceData(const size_t& fromLayer, const size_t& toLayer);
  bool predict();

  void train(const size_t& repeat);
  void trainLayers(const bool& expect);

private:
  double learningRate_;
  double momentum_;

  std::vector<std::shared_ptr<Layer>> layers_;

  void createLayers(const std::vector<int> &neuronPerLayer);
  void setWeights();
};

#endif //COURSE_PROJECT_NEURALNETWORK_HPP
