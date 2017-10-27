//
// Created by Богдан Полянок on 27.10.2017.
//

#include "training.hpp"


Training::Training(const std::shared_ptr<NeuralNetwork> &neuralNetwork,
                   const double &learningRate,
                   const double &momentum):
    neuralNetwork_(neuralNetwork),
    learningRate_(learningRate),
    momentum_(momentum)
{}

void Training::train(const size_t &epochCount)
{
  for (size_t i = 0; i < epochCount; i++) {
    trainSet();
  }
}