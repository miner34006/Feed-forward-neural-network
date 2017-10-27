#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "training/xorTraining.hpp"
#include "neuralNetwork.hpp"

void func(const double& number){
  if (number >= 0.5){
    std::cout << "true " << "(" << number << ")";
  }
  if (number < 0.5){
    std::cout << "false " << "(" << number << ")";
  }
}

int main() {
  srandom((unsigned)time(nullptr));

  const bool hasBias = true;
  std::shared_ptr<NeuralNetwork> neuralNetwork(new NeuralNetwork({2, 2, 1}, hasBias));

  double data = neuralNetwork->feedForward({0, 0});
  std::cout << "false xor false = "; func(data); std::cout << "\n";

  data = neuralNetwork->feedForward({0, 1});
  std::cout << "false xor true = ";  func(data); std::cout << "\n";

  data = neuralNetwork->feedForward({1, 0});
  std::cout << "true xor false = ";  func(data); std::cout << "\n";

  data = neuralNetwork->feedForward({1, 1});
  std::cout << "true xor true = ";   func(data); std::cout << "\n";

  std::cout << "\n\n";

  XORTraining xorTrainer(neuralNetwork, 0.7, 0.7);
  xorTrainer.train(1000);
  std::cout << "TRAINING\n\n\n";

  data = neuralNetwork->feedForward({0, 0});
  std::cout << "false xor false = "; func(data); std::cout << "\n";

  data = neuralNetwork->feedForward({0, 1});
  std::cout << "false xor true = ";  func(data); std::cout << "\n";

  data = neuralNetwork->feedForward({1, 0});
  std::cout << "true xor false = ";  func(data); std::cout << "\n";

  data = neuralNetwork->feedForward({1, 1});
  std::cout << "true xor true = ";   func(data); std::cout << "\n";

  return 0;
}