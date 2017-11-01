//
// Created by Богдан Полянок on 29.10.2017.
//

#include "digitRecognitionTraining.hpp"

#include "../imageConverter/imageConverter.hpp"
#include "../neuralNetwork/neuralNetwork.hpp"


DigitRecognitionTraining::DigitRecognitionTraining(const std::shared_ptr<NeuralNetwork> &neuralNetwork,
                                         const double &learningRate,
                                         const double &momentum):
  Training(neuralNetwork, learningRate, momentum)
{}

void DigitRecognitionTraining::trainSet(const double &minError)
{
  if (minError >= 1){
    throw std::invalid_argument("Invalid minError;");
  }

  std::vector<double> error(10, 1);

  ImageConverter imageConverter;
  std::string imagePath("/Users/miner34006/Documents/c++/Clion/Course project/trainData/");

  while (moreThanMinError(error, minError)) {
    for (size_t trainDigit = 0; trainDigit < 10; trainDigit++){
      std::vector<double> expectedAnswer = createExpectedAnswer(trainDigit);

      for (size_t digitVariable = 1; digitVariable < 6; digitVariable ++){
        imageConverter.setImage(imagePath + std::to_string(trainDigit) + "/" + std::to_string(digitVariable) + ".bmp");
        error[trainDigit] = trainSingle(imageConverter.getVecImage(), expectedAnswer);
      }
    }
  }
}

void DigitRecognitionTraining::trainSet()
{
  ImageConverter imageConverter;
  std::string imagePath("/Users/miner34006/Documents/c++/Clion/Course project/trainData/");
  for (size_t trainDigit = 0; trainDigit < 10; trainDigit++){
    std::vector<double> expectedAnswer = createExpectedAnswer(trainDigit);

    for (size_t digitVariable = 1; digitVariable < 6; digitVariable ++){
      imageConverter.setImage(imagePath + std::to_string(trainDigit) + "/" + std::to_string(digitVariable) + ".bmp");
      trainSingle(imageConverter.getVecImage(), expectedAnswer);
    }
  }
}

std::vector<double> DigitRecognitionTraining::createExpectedAnswer(const size_t &trainDigit) const
{
  std::vector<double> expectedAnswer = {};
  for (size_t i = 0; i < 10; i ++){
    if (i == trainDigit){
      expectedAnswer.push_back(1);
    } else {
      expectedAnswer.push_back(0);
    }
  }
  return expectedAnswer;
}

bool DigitRecognitionTraining::moreThanMinError(const std::vector<double> &error, const double &minEror) const
{
  bool moreThanMinError = false;
  for (const double& err: error){
    if (err > minEror){
      moreThanMinError = true;
      return moreThanMinError;
    }
  }
  return moreThanMinError;
}