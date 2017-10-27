//
// Created by Богдан Полянок on 30.09.2017.
//

#include "outputLayer.hpp"

#include "../neuron.hpp"


OutputLayer::OutputLayer(const size_t &neuronQuantity):
  Layer(neuronQuantity)
{}

void OutputLayer::changeWeights(const double& expected, const double& learningRate, const double& alpha)
{
  for (size_t i = 0; i < getNeuronQuantity(); i++){
    const double output = neurons_.at(i)->getOutput();
    const double error = expected - output;
    const double sigDx = output * (1 - output);
    neurons_.at(i)->setWeightDelta(error * sigDx);
  }
}