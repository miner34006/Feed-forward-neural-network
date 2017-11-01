//
// Created by Богдан Полянок on 30.09.2017.
//

#ifndef COURSE_PROJECT_NEURON_HPP
#define COURSE_PROJECT_NEURON_HPP

#include <vector>
#include <cmath>
#include <iostream>


class Neuron{
public:
  friend std::ostream& operator<<(std::ostream& out, const Neuron& neuron);

  void activation();

  void setInput(const double& input);
  void setOutput(const double& output);
  void setWeightDelta(const double& output);
  void setPreviousDelta(const size_t& index, const double& delta);
  void setWeight(const size_t& index, const double& value);
  void setWeights(const size_t& nextLayerNeuronQuantity);

  double getInput() const;
  double getOutput() const;
  double getWeightDelta() const;
  double getPreviousDelta(const size_t& index) const;
  double getWeight(const size_t& index) const;

  double countWeightDelta(const std::vector<double> &nextLayerWeightDelta) const;
  void changeWeights(const double& learningRate, const double& momentum, const std::vector<double> &nextLayerWeightDelta);

private:
  double input_;
  double output_;
  double weightDelta_;

  std::vector<double> forwardWeights_;
  std::vector<double> previousWeightDelta;
};

std::ostream& operator<<(std::ostream& out, const Neuron& neuron);

#endif //COURSE_PROJECT_NEURON_HPP
