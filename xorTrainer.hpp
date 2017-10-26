//
// Created by Богдан Полянок on 26.10.2017.
//

#ifndef COURSE_PROJECT_XORTRAINER_HPP
#define COURSE_PROJECT_XORTRAINER_HPP

#include <iostream>
#include <memory>
#include <vector>


class NeuralNetwork;

class XORTrainer{
public:
  XORTrainer(const std::shared_ptr<NeuralNetwork> &neuralNetwork, const double &learningRate, const double &momentum);

  void train(const size_t& epochCount);
  void trainSingle(const std::vector<double> &trainData);

private:
  std::shared_ptr<NeuralNetwork> neuralNetwork_;

  double learningRate_;
  double momentum_;
};

#endif //COURSE_PROJECT_XORTRAINER_HPP
