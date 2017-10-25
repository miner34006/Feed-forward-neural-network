#include <iostream>
#include <vector>
#include <ctime>

#include "layers/layer.hpp"
#include "neuron.hpp"
#include <random>
#include "neuralNetwork.hpp"

int main() {
  srand((unsigned)time(NULL));

  NeuralNetwork neuralNetwork(0.005, 0.5, {3, 2, 3});

  neuralNetwork.setInputData({1, 0, 1});

  neuralNetwork.forceData(0, 1);
  neuralNetwork.forceData(1, 2);

  std::cout << *neuralNetwork[0];
  std::cout << *neuralNetwork[1];
  std::cout << *neuralNetwork[2];

  return 0;
}