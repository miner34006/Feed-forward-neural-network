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
  NeuralNetwork(const std::vector<int> &neuronsPerLayer, const bool& hasBias);

  std::shared_ptr<Layer> operator [](const size_t& index);

  double feedForward(const std::vector<double> &data);
  void backPropagation(const double &expect, const double &learningRate, const double &momentum);

private:
  std::vector<std::shared_ptr<Layer>> layers_;

  void createLayers(const std::vector<int> &neuronPerLayer, const bool& hasBias);
  void setWeights();

  void setInputData(const std::vector<double>& data);
  void passDataForward(const size_t& fromLayer, const size_t& toLayer);
};

#endif //COURSE_PROJECT_NEURALNETWORK_HPP
