#include <iostream>
#include <vector>

#include "src/training/xorTraining.hpp"
#include "src/training/digitRecognitionTraining.hpp"

#include "src/neuralNetwork/neuralNetwork.hpp"
#include "src/imageConverter/imageConverter.hpp"

void func(const double& number){
  if (number >= 0.5){
    std::cout << "true " << "(" << number << ")";
  }
  if (number < 0.5){
    std::cout << "false " << "(" << number << ")";
  }
}

int main(){
  srandom((unsigned)time(nullptr));

  const bool hasBias = true;
  std::shared_ptr<NeuralNetwork> neuralNetwork(new NeuralNetwork({100, 10, 10}, hasBias));

  //std::cout << neuralNetwork->feedForward(converter.getVecImage());

//  double data = neuralNetwork->feedForward({0, 0});
//  std::cout << "false xor false = "; func(data); std::cout << "\n";
//
//  data = neuralNetwork->feedForward({0, 1});
//  std::cout << "false xor true = ";  func(data); std::cout << "\n";
//
//  data = neuralNetwork->feedForward({1, 0});
//  std::cout << "true xor false = ";  func(data); std::cout << "\n";
//
//  data = neuralNetwork->feedForward({1, 1});
//  std::cout << "true xor true = ";   func(data); std::cout << "\n";

  //std::cout << *neuralNetwork;

  //std::cout << "\n\n";

  //XORTraining xorTrainer(neuralNetwork, 0.05, 0.99);
  DigitRecognitionTraining digitTraining(neuralNetwork, 0.1, 0.9);

  //xorTrainer.autoTrain(0.1);
  //xorTrainer.train(50000);
  //digitTraining.train(1000);
  digitTraining.autoTrain(0.0001);
  std::cout << "TRAINING\n\n\n";


  ImageConverter imageConverter;
  std::string imagePath("/Users/miner34006/Documents/c++/Clion/Course project/trainData/newData/");
  for (size_t trainDigit = 9; trainDigit != -1; trainDigit--) {
    imageConverter.setImage(imagePath + std::to_string(trainDigit)  + ".bmp");
    std::cout << "Put " << trainDigit << " image | Answer = " << neuralNetwork->feedForward(imageConverter.getVecImage())[0] << "\n";
  }

//  data = neuralNetwork->feedForward({0, 0});
//  std::cout << "false xor false = "; func(data); std::cout << "\n";
//
//  data = neuralNetwork->feedForward({0, 1});
//  std::cout << "false xor true = ";  func(data); std::cout << "\n";
//
//  data = neuralNetwork->feedForward({1, 0});
//  std::cout << "true xor false = ";  func(data); std::cout << "\n";
//
//  data = neuralNetwork->feedForward({1, 1});
//  std::cout << "true xor true = ";   func(data); std::cout << "\n";

  //std::cout << *neuralNetwork;
  //std::cout << neuralNetwork->feedForward(converter.getVecImage());

  return 0;
}