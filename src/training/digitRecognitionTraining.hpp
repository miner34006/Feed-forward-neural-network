//
// Created by Богдан Полянок on 29.10.2017.
//

#ifndef COURSE_PROJECT_RECOGNITIONTRAINING_HPP
#define COURSE_PROJECT_RECOGNITIONTRAINING_HPP

#include "training.hpp"

class DigitRecognitionTraining: public Training{
public:
  DigitRecognitionTraining(const std::shared_ptr<NeuralNetwork> &neuralNetwork,
                      const double &learningRate,
                      const double &momentum);

  void trainSet(const double &minError) override;
  void trainSet() override;

private:
  std::vector<double> createExpectedAnswer(const size_t &trainDigit) const;
  bool moreThanMinError(const std::vector<double> &error, const double &minEror) const;
};

#endif //COURSE_PROJECT_RECOGNITIONTRAINING_HPP
