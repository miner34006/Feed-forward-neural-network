//
// Created by Богдан Полянок on 01.10.2017.
//

#include "neuralNetwork.hpp"

NeuralNetwork::NeuralNetwork(const size_t &hiddenLayerQuantity):
  layers_({})
{
  layers_.push_back(std::make_shared<InputLayer>());

  for (size_t i = 0; i < hiddenLayerQuantity; i++){
    layers_.push_back(std::make_shared<HiddenLayer>());
  }

  layers_.push_back(std::make_shared<OutputLayer>());

  for (size_t i = 0; i < layers_.size(); i++){
    if (i == 0){
      layers_.at(i)->setNextLayer(layers_.at(i + 1));
    }
    if ((i != 0) && (i != layers_.size() - 1)){
      layers_.at(i)->setPreviousLayer(layers_.at(i - 1));
      layers_.at(i)->setNextLayer(layers_.at(i + 1));
    }
    if (i == layers_.size() - 1){
      layers_.at(i)->setPreviousLayer(layers_.at(i - 1));
    }
  }
}

NeuralNetwork::NeuralNetwork(const std::vector<std::shared_ptr<Layer>> &layers):
  layers_(layers)
{}

void NeuralNetwork::setNeuronQuantity(const size_t &layerNumber, const size_t& neuronQuantity)
{
  if ((layerNumber < 0) || (layerNumber >= layers_.size())){
    throw std::invalid_argument("Invalid layerNumber;");
  } else if (neuronQuantity < 0){
    throw std::invalid_argument("Invalid neuronQuantity;");
  }
  layers_.at(layerNumber)->setNeuronQuantity(neuronQuantity);
}

void NeuralNetwork::setWeights()
{
  for (auto i = layers_.begin(); i != layers_.end(); i++){
    (*i)->setWeights();
  }
}

void NeuralNetwork::setInputData(const std::vector<float> &data)
{
  layers_.at(0)->setInputData(data);
}

std::shared_ptr<Layer> NeuralNetwork::getInputLayer() const
{
  return layers_.at(0);
}

std::shared_ptr<Layer> NeuralNetwork::getOutputLayer() const
{
  return layers_.at(layers_.size() - 1);
}

std::shared_ptr<Layer> NeuralNetwork::getLayer(const size_t &layerNumber) const
{
  if ((layerNumber < 0) || (layerNumber >= layers_.size())){
    throw std::out_of_range("layerNumber out of range;");
  }
  return layers_.at(layerNumber);
}

std::shared_ptr<Layer> NeuralNetwork::operator[](const size_t &layerNumber)
{
  if ((layerNumber < 0) || (layerNumber >= layers_.size())){
    throw std::out_of_range("layerNumber out of range;");
  }
  return layers_.at(layerNumber);
}