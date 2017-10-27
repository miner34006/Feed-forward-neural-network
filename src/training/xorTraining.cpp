//
// Created by Богдан Полянок on 27.10.2017.
//

#include "xorTraining.hpp"

#include "../neuralNetwork/neuralNetwork.hpp"

XORTraining::XORTraining(const std::shared_ptr<NeuralNetwork> &neuralNetwork,
                         const double &learningRate,
                         const double &momentum):
  Training(neuralNetwork, learningRate, momentum)
{}

void XORTraining::trainSingle(const std::vector<double> &trainData)
{
  neuralNetwork_->feedForward({trainData[0], trainData[1]});
  neuralNetwork_->backPropagation(trainData[2], learningRate_, momentum_);
}

void XORTraining::trainSet()
{
  trainSingle({0, 0, 0});
  trainSingle({0, 1, 1});
  trainSingle({1, 0, 1});
  trainSingle({1, 1, 0});
}
