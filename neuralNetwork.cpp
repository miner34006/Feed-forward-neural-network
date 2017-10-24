//
// Created by Богдан Полянок on 01.10.2017.
//

#include "neuralNetwork.hpp"

NeuralNetwork::NeuralNetwork(const double& learningRate, const double& momentum, const std::vector<int> &neuronPerLayer):
  learningRate_(learningRate),
  momentum_(momentum),
  layers_({})
{
  if (neuronPerLayer.size() <= 2){
    throw std::invalid_argument("Number of layers must be more than 2");
  }
  NeuralNetwork::createLayers(neuronPerLayer);
}

void NeuralNetwork::setInputData(const std::vector<double> &data)
{
  layers_.front()->setInputData(data);
}

std::shared_ptr<Layer> NeuralNetwork::operator[](const size_t &layerNumber)
{
  return layers_.at(layerNumber);
}

void NeuralNetwork::forceData(const size_t &fromLayer, const size_t &toLayer)
{
  Layer *from = layers_.at(fromLayer).get();
  Layer *to = layers_.at(toLayer).get();

  for (size_t i = 0; i < to->getNeuronQuantity(); i++){
    double sum = 0;
    for (size_t j = 0; j < from->getNeuronQuantity(); j++){
      const double input = (*from)[j]->getOutput();
      const double weight = (*from)[j]->getWeight(i);
      sum = sum + (input * weight);
    }
    (*to)[i]->setInput(sum);
    (*to)[i]->activation();
  }
}

bool NeuralNetwork::predict()
{
  forceData(0, 1);
  forceData(1, 2);
  const double answer = (*layers_.at(2))[0]->getOutput();
  return answer > 0.5;
}

void NeuralNetwork::trainLayers(const bool& expect)
{
  for (auto j = layers_.rbegin(); j != layers_.rend(); j++){
    (*j)->error(0, learningRate_, momentum_);
  }
  std::cout << "ERROR-" << pow((0 - (*layers_[2])[0]->getOutput()), 2) << "\n\n";
}

void NeuralNetwork::train(const size_t& repeat)
{
  std::vector<double> first({0, 0});
  std::vector<double> second({0, 1});
  std::vector<double> third({1, 0});
  std::vector<double> fourth({1, 1});

  for (size_t i = 0; i < repeat; i++){
    setInputData(first);
    if (predict() == false){

    } else {
      for (auto j = layers_.rbegin(); j != layers_.rend(); j++){
        (*j)->error(0, learningRate_, momentum_);
      }
      std::cout << "ERROR-" << pow((0 - (*layers_[2])[0]->getOutput()), 2) << "\n";
    }
    setInputData(second);
    if (predict() == true){

    } else {
      for (auto j = layers_.rbegin(); j != layers_.rend(); j++){
        (*j)->error(1, learningRate_, momentum_);
      }
      std::cout << "ERROR-" << pow((1 - (*layers_[2])[0]->getOutput()), 2) << "\n";
    }
    setInputData(third);
    if (predict() == true){

    } else {
      for (auto j = layers_.rbegin(); j != layers_.rend(); j++){
        (*j)->error(1, learningRate_, momentum_);
      }
      std::cout << "ERROR-" << pow((1 - (*layers_[2])[0]->getOutput()), 2) << "\n";
    }
    setInputData(fourth);
    if (predict() == false){

    } else {
      for (auto j = layers_.rbegin(); j != layers_.rend(); j++){
        (*j)->error(0, learningRate_, momentum_);
      }
      std::cout << "ERROR-" << pow((0 - (*layers_[2])[0]->getOutput()), 2) << "\n";
    }
  }
}

void NeuralNetwork::createLayers(const std::vector<int> &neuronPerLayer)
{
  layers_.push_back(std::make_shared<InputLayer>(neuronPerLayer.front()));

  for (size_t i = 1; i < neuronPerLayer.size() - 1; i++){
    layers_.push_back(std::make_shared<HiddenLayer>(neuronPerLayer.at(i)));
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
