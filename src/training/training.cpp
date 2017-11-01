//
// Created by Богдан Полянок on 27.10.2017.
//

#include "training.hpp"
#include "../neuralNetwork/neuralNetwork.hpp"


Training::Training(const std::shared_ptr<NeuralNetwork> &neuralNetwork,
                   const double &learningRate,
                   const double &momentum):
    neuralNetwork_(neuralNetwork),
    learningRate_(learningRate),
    momentum_(momentum)
{}

double Training::trainSingle(const std::vector<double> &trainData, const std::vector<double> &expectedAnswer)
{
  try {
    neuralNetwork_->feedForward(trainData);
    const double error = neuralNetwork_->getError(expectedAnswer);
    neuralNetwork_->backPropagation(expectedAnswer, learningRate_, momentum_);
    return error;
  }
  catch (const std::invalid_argument &exception){
    std::string message("\nInvalid neural network configuration training;\n\tWhat:");
    throw std::logic_error(message + exception.what());
  }
}

void Training::train(const size_t &epochCount)
{
  for (size_t i = 0; i < epochCount; i++) {
    trainSet();
  }
}

void Training::autoTrain(const double &minError)
{
  trainSet(minError);
}