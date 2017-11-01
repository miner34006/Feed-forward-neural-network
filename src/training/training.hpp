//
// Created by Богдан Полянок on 27.10.2017.
//

#ifndef COURSE_PROJECT_TRAINING_HPP
#define COURSE_PROJECT_TRAINING_HPP

#include <string>
#include <vector>
#include <memory>

class NeuralNetwork;

class Training{
public:
  Training(const std::shared_ptr<NeuralNetwork> &neuralNetwork,
           const double &learningRate,
           const double &momentum);

  void autoTrain(const double &minError);
  void train(const size_t& epochCount);

protected:
  std::shared_ptr<NeuralNetwork> neuralNetwork_;

  double learningRate_;
  double momentum_;

  double trainSingle(const std::vector<double> &trainData, const std::vector<double> &expectedAnswer);

  virtual void trainSet(const double &minError) = 0;
  virtual void trainSet() = 0;
};

#endif //COURSE_PROJECT_TRAINING_HPP
