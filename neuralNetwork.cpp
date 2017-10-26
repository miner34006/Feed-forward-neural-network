//
// Created by Богдан Полянок on 01.10.2017.
//

#include "neuralNetwork.hpp"

NeuralNetwork::NeuralNetwork(const std::vector<int> &neuronsPerLayer, const bool& hasBias):
  layers_({})
{
  if (neuronsPerLayer.size() <= 2){
    throw std::invalid_argument("Number of layers must be more than 2");
  }
  NeuralNetwork::createLayers(neuronsPerLayer, hasBias);
}

void NeuralNetwork::setInputData(const std::vector<double> &data)
{
  layers_.front()->setInputData(data);
}

std::shared_ptr<Layer> NeuralNetwork::operator[](const size_t &layerNumber)
{
  return layers_.at(layerNumber);
}

void NeuralNetwork::passDataForward(const size_t &fromLayer, const size_t &toLayer)
{
  std::shared_ptr<Layer> &from = layers_.at(fromLayer);
  std::shared_ptr<Layer> &to = layers_.at(toLayer);

  for (size_t i = 0; i < to->getNeuronQuantity(); i++){
    double sum = 0;
    for (size_t j = 0; j < from->getNeuronQuantity(); j++){
      const double input = (*from)[j]->getOutput();
      const double weight = (*from)[j]->getWeight(i);
      sum = sum + (input * weight);
    }
    if (from->hasBias()){
      sum += from->getBias()->getWeight(i);
    }

    (*to)[i]->setInput(sum);
    (*to)[i]->activation();
  }
}

double NeuralNetwork::feedForward(const std::vector<double> &data)
{
  NeuralNetwork::setInputData(data);
  for (size_t i = 0; i < layers_.size() - 1; i++){
    passDataForward(i, i + 1);
  }
  const double answer = (*layers_.back())[0]->getOutput();
  return answer;
}

void NeuralNetwork::backPropagation(const double &expect, const double &learningRate, const double &momentum)
{
  for (auto j = layers_.rbegin(); j != layers_.rend(); j++){
    (*j)->error(expect, learningRate, momentum, *(j-1));
  }
}

void NeuralNetwork::createLayers(const std::vector<int> &neuronPerLayer, const bool& hasBias)
{
  layers_.push_back(std::make_shared<InputLayer>(neuronPerLayer.front(), hasBias));

  for (size_t i = 1; i < neuronPerLayer.size() - 1; i++){
    layers_.push_back(std::make_shared<HiddenLayer>(neuronPerLayer.at(i), hasBias));
  }

  layers_.push_back(std::make_shared<OutputLayer>(neuronPerLayer.back()));

  NeuralNetwork::setWeights();
}

void NeuralNetwork::setWeights()
{
  for (auto layer = layers_.begin(); layer != layers_.end() - 1; layer++){
    (*layer)->setWeights(*(layer + 1));
  }
}
