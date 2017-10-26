//
// Created by Богдан Полянок on 26.10.2017.
//

#include "xorTrainer.hpp"

#include "neuralNetwork.hpp"


XORTrainer::XORTrainer(const std::shared_ptr<NeuralNetwork> &neuralNetwork, const double &learningRate, const double &momentum):
  neuralNetwork_(neuralNetwork),
  learningRate_(learningRate),
  momentum_(momentum)
{}

void XORTrainer::trainSingle(const std::vector<double> &trainData)
{
  neuralNetwork_->feedForward({trainData[0], trainData[1]});
  neuralNetwork_->backPropagation(trainData[2], learningRate_, momentum_);
}

void XORTrainer::train(const size_t &epochCount)
{
  for (size_t i = 0; i < epochCount; i++) {
    trainSingle({0, 0, 0});
    trainSingle({1, 1, 0});
    trainSingle({0, 1, 1});
    trainSingle({1, 0, 1});
  }
}