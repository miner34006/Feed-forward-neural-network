//
// Created by Богдан Полянок on 30.09.2017.
//

#ifndef COURSE_PROJECT_NEURALNETWORK_HPP
#define COURSE_PROJECT_NEURALNETWORK_HPP

#include <vector>
#include <memory>

#include "layers/inputLayer.hpp"
#include "layers/hiddenLayer.hpp"
#include "layers/outputLayer.hpp"

class NeuralNetwork{
public:
  explicit NeuralNetwork(const size_t& hiddenLayerQuantity=1);
  explicit NeuralNetwork(const std::vector<std::shared_ptr<Layer>>& layers);

  void setNeuronQuantity(const size_t& layerNumber, const size_t& neuronQuantity);
  void setWeights();

  void setInputData(const std::vector<float>& data);

  std::shared_ptr<Layer> getInputLayer() const;
  std::shared_ptr<Layer> getOutputLayer() const;
  std::shared_ptr<Layer> getLayer(const size_t& layerNumber) const;

  std::shared_ptr<Layer> operator [](const size_t& index);

private:
  std::vector<std::shared_ptr<Layer>> layers_;
};

#endif //COURSE_PROJECT_NEURALNETWORK_HPP
