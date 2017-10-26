//
// Created by Богдан Полянок on 30.09.2017.
//

#include "outputLayer.hpp"


OutputLayer::OutputLayer(const size_t &neuronQuantity):
  Layer(neuronQuantity)
{}

bool OutputLayer::hasBias() const
{
  return false;
}

std::shared_ptr<Neuron> OutputLayer::getBias() const
{
  return nullptr;
}

void OutputLayer::error(const double& expected,
                        const double& learningRate,
                        const double& alpha,
                        const std::shared_ptr<Layer>& nextLayer)
{
  for (size_t i = 0; i < getNeuronQuantity(); i++){
    const double output = neurons_.at(i)->getOutput();
    const double error = expected - output;
    const double sigDx = output * (1 - output);
    neurons_.at(i)->setWeightDelta(error * sigDx);
  }
}