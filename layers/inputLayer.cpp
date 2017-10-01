//
// Created by Богдан Полянок on 30.09.2017.
//

#include "inputLayer.hpp"

using layerPtr = InputLayer::layerPtr;

InputLayer::InputLayer():
  Layer({}),
  nextLayer_(nullptr)
{}

InputLayer::InputLayer(const std::vector<std::shared_ptr<Neuron>> &neurons):
  Layer(neurons),
  nextLayer_(nullptr)
{}

void InputLayer::setPreviousLayer(layerPtr /* layer */)
{}

layerPtr InputLayer::getPreviousLayer() const
{
  return nullptr;
}

void InputLayer::setNextLayer(layerPtr layer)
{
  nextLayer_ = layer;
}

layerPtr InputLayer::getNextLayer() const
{
  return nextLayer_;
}

void InputLayer::setWeights()
{
  const size_t linksQuantity = getNextLayer()->getNeuronQuantity();
  for (const std::shared_ptr<Neuron>& i: neurons_){
    i->setWeights(linksQuantity);
  }
}