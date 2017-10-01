#include <iostream>
#include <vector>

#include "layers/layer.hpp"
#include "neuron.hpp"
#include "neuralNetwork.hpp"

int main() {
  NeuralNetwork network;

  network.setNeuronQuantity(0, 5);
  network.setNeuronQuantity(1, 3);
  network.setNeuronQuantity(2, 1);

  network.setWeights();

  std::cout << *network[0];
  std::cout << *network[1];
  std::cout << *network[2];


  return 0;
}