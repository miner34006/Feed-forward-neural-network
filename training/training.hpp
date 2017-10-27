//
// Created by Богдан Полянок on 27.10.2017.
//

#ifndef COURSE_PROJECT_TRAINING_HPP
#define COURSE_PROJECT_TRAINING_HPP

#include <vector>
#include <memory>

class NeuralNetwork;

class Training{
public:
  Training(const std::shared_ptr<NeuralNetwork> &neuralNetwork,
           const double &learningRate,
           const double &momentum);

  virtual void trainSingle(const std::vector<double> &trainData) = 0;
  virtual void trainSet() = 0;

  void train(const size_t& epochCount);

protected:
  std::shared_ptr<NeuralNetwork> neuralNetwork_;

  double learningRate_;
  double momentum_;
};

#endif //COURSE_PROJECT_TRAINING_HPP
