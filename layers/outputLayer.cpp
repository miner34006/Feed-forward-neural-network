//
// Created by Богдан Полянок on 30.09.2017.
//

#include "outputLayer.hpp"

using layerPtr = OutputLayer::layerPtr;

OutputLayer::OutputLayer():
  Layer({}),
  previousLayer_(nullptr)
{}

OutputLayer::OutputLayer(const std::vector<std::shared_ptr<Neuron>> &neurons):
  Layer(neurons),
  previousLayer_(nullptr)
{}

void OutputLayer::setPreviousLayer(layerPtr layer)
{
  previousLayer_ = layer;
}

layerPtr OutputLayer::getPreviousLayer() const
{
  return previousLayer_;
}

void OutputLayer::setNextLayer(layerPtr layer)
{}

layerPtr OutputLayer::getNextLayer() const
{
  return nullptr;
}

void OutputLayer::setWeights()
{}