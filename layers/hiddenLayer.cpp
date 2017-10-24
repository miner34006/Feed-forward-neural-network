//
// Created by Богдан Полянок on 30.09.2017.
//

#include "hiddenLayer.hpp"

using layerPtr = HiddenLayer::layerPtr;

HiddenLayer::HiddenLayer(const size_t &neuronQuantity):
  Layer(neuronQuantity)
{}

void HiddenLayer::error(const double& expected, const double& learningRate, const double& alpha)
{
//  for (size_t i = 0; i < getNeuronQuantity(); i++){
//    const double sigDx = neurons_.at(i)->getOutput() * (1 - neurons_.at(i)->getOutput());
//
//    double sum = 0;
//    for (size_t j = 0; j < nextLayer_->getNeuronQuantity(); j++){
//      const double delta = (*nextLayer_)[j]->getWeightDelta() * neurons_.at(i)->getWeight(j);
//      sum += delta;
//    }
//    const double weightDelta = sigDx * sum;
//    neurons_.at(i)->setWeightDelta(weightDelta);
//
//    for (size_t j = 0; j < nextLayer_->getNeuronQuantity(); j++){
//      const double delta = (*nextLayer_)[j]->getWeightDelta();
//      const double gradient = neurons_.at(i)->getOutput() * delta;
//
//      const double deltaW = learningRate * gradient + alpha * neurons_.at(i)->getPreviousDelta(j);
//      neurons_.at(i)->setPreviousDelta(j, deltaW);
//      neurons_.at(i)->setWeight(j, neurons_.at(i)->getWeight(j) + deltaW);
//    }
//  }
}
