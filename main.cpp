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

void xorDemonstration(){
  const bool hasBias = true;
  std::shared_ptr<NeuralNetwork> neuralNetwork(new NeuralNetwork({2, 2, 1}, hasBias));

  double data = neuralNetwork->feedForward({0, 0})[1];
  std::cout << "false xor false = "; func(data); std::cout << "\n";

  data = neuralNetwork->feedForward({0, 1})[1];
  std::cout << "false xor true = ";  func(data); std::cout << "\n";

  data = neuralNetwork->feedForward({1, 0})[1];
  std::cout << "true xor false = ";  func(data); std::cout << "\n";

  data = neuralNetwork->feedForward({1, 1})[1];
  std::cout << "true xor true = ";   func(data); std::cout << "\n";

  XORTraining xorTraining(neuralNetwork, 0.05, 0.99);
  xorTraining.autoTrain(0.000001);
  //xorTraining.train(50000);
  std::cout << "TRAINING\n\n\n";

  data = neuralNetwork->feedForward({0, 0})[1];
  std::cout << "false xor false = "; func(data); std::cout << "\n";

  data = neuralNetwork->feedForward({0, 1})[1];
  std::cout << "false xor true = ";  func(data); std::cout << "\n";

  data = neuralNetwork->feedForward({1, 0})[1];
  std::cout << "true xor false = ";  func(data); std::cout << "\n";

  data = neuralNetwork->feedForward({1, 1})[1];
  std::cout << "true xor true = ";   func(data); std::cout << "\n";
}

void digitRecognitionDemostration(){
  const bool hasBias = true;
  std::shared_ptr<NeuralNetwork> neuralNetwork(new NeuralNetwork({100, 10, 10}, hasBias));

  ImageConverter imageConverter;
  std::string imagePath("/Users/miner34006/Documents/c++/Clion/Course project/trainData/newData/");

  for (size_t trainDigit = 9; trainDigit != -1; trainDigit--) {
    imageConverter.setImage(imagePath + std::to_string(trainDigit)  + ".bmp");
    const std::vector<double> answer = neuralNetwork->feedForward(imageConverter.getVecImage());
    std::cout << "Put " << trainDigit << " image | Answer = " <<  answer[0] << " (" << answer[1] << ")" <<"\n";  }

  DigitRecognitionTraining digitTraining(neuralNetwork, 0.2, 0.9);
  //digitTraining.train(1000);
  digitTraining.autoTrain(0.0001);
  std::cout << "TRAINING\n\n\n";

  for (size_t trainDigit = 9; trainDigit != -1; trainDigit--) {
    imageConverter.setImage(imagePath + std::to_string(trainDigit)  + ".bmp");
    const std::vector<double> answer = neuralNetwork->feedForward(imageConverter.getVecImage());
    std::cout << "Put " << trainDigit << " image | Answer = " <<  answer[0] << " (" << answer[1] << ")" <<"\n";
  }
}

int main(){
  srandom((unsigned)time(nullptr));

  xorDemonstration();
  //digitRecognitionDemostration();

  return 0;
}