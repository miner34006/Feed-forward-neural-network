//
// Created by Богдан Полянок on 30.09.2017.
//

#ifndef COURSE_PROJECT_NEURALNETWORK_HPP
#define COURSE_PROJECT_NEURALNETWORK_HPP

#include <vector>
#include <memory>
#include <cmath>

class Layer;
class InputLayer;
class HiddenLayer;
class OutputLayer;

class NeuralNetwork{
public:
  NeuralNetwork(const std::vector<int> &neuronsPerLayer, const bool& hasBias);

  friend std::ostream& operator<<(std::ostream& out, const NeuralNetwork& neuralNetwork);
  std::shared_ptr<Layer> operator [](const size_t& index);

  size_t getLayersCount() const;

  std::vector<double> feedForward(const std::vector<double> &data);
  void backPropagation(const std::vector<double> &expectedAnswer, const double &learningRate, const double &momentum);

  double getError(const std::vector<double> &expectedAnswer) const;

private:
  std::shared_ptr<InputLayer> inputLayer_;
  std::vector<std::shared_ptr<HiddenLayer>> hiddenLayers_;
  std::shared_ptr<OutputLayer> outputLayer_;

  void createLayers(const std::vector<int> &neuronPerLayer, const bool& hasBias);
  void setWeights();

  void setInputData(const std::vector<double>& data);
  void passDataForward(const size_t& fromLayer, const size_t& toLayer);
};

std::ostream& operator<<(std::ostream& out, const NeuralNetwork& neuralNetwork);

#endif //COURSE_PROJECT_NEURALNETWORK_HPP
