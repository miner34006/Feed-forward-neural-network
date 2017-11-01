//
// Created by Богдан Полянок on 27.10.2017.
//

#include "xorTraining.hpp"

#include "../neuralNetwork/neuralNetwork.hpp"

#include <string>
#include <iostream>

XORTraining::XORTraining(const std::shared_ptr<NeuralNetwork> &neuralNetwork,
                         const double &learningRate,
                         const double &momentum):
  Training(neuralNetwork, learningRate, momentum)
{}

void XORTraining::trainSet(const double &minError)
{
  if (minError >= 1){
    throw std::invalid_argument("Invalid minError;");
  }

  double error1 = 1;
  double error2 = 1;
  double error3 = 1;
  double error4 = 1;

  while ((error1 > minError) || (error2 > minError) || (error3 > minError) || (error4 > minError)){
    error1 = trainSingle({0, 0}, {0});
    error2 = trainSingle({0, 1}, {1});
    error3 = trainSingle({1, 0}, {1});
    error4 = trainSingle({1, 1}, {0});
  }
}

void XORTraining::trainSet()
{
  trainSingle({0, 0}, {0});
  trainSingle({0, 1}, {1});
  trainSingle({1, 0}, {1});
  trainSingle({1, 1}, {0});
}