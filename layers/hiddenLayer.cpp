//
// Created by Богдан Полянок on 30.09.2017.
//

#include "hiddenLayer.hpp"

using layerPtr = HiddenLayer::layerPtr;

HiddenLayer::HiddenLayer():
  Layer({}),
  previousLayer_(nullptr),
  nextLayer_(nullptr)
{}

HiddenLayer::HiddenLayer(const std::vector<std::shared_ptr<Neuron>> &neurons):
  Layer(neurons),
  previousLayer_(nullptr),
  nextLayer_(nullptr)
{}

void HiddenLayer::setPreviousLayer(layerPtr layer)
{
  previousLayer_ = layer;
}

layerPtr HiddenLayer::getPreviousLayer() const
{
  return previousLayer_;
}

void HiddenLayer::setNextLayer(layerPtr layer)
{
  nextLayer_ = layer;
}

layerPtr HiddenLayer::getNextLayer() const
{
  return nextLayer_;
}

void HiddenLayer::setWeights()
{
  const size_t linksQuantity = getNextLayer()->getNeuronQuantity();
  for (const std::shared_ptr<Neuron>& i: neurons_){
    i->setWeights(linksQuantity);
  }
}
