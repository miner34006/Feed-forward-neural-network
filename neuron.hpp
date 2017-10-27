//
// Created by Богдан Полянок on 30.09.2017.
//

#ifndef COURSE_PROJECT_NEURON_HPP
#define COURSE_PROJECT_NEURON_HPP

#include <vector>       /* vector */
#include <cmath>        /* exp */
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include <iostream>

class Neuron{
public:
  friend std::ostream& operator<<(std::ostream& out, const Neuron& neuron);

  void activation();

  void setInput(const double& input);
  void setOutput(const double& output);
  void setWeightDelta(const double& output);
  void setPreviousDelta(const size_t& index, const double& delta);

  double getInput() const;
  double getOutput() const;
  double getWeightDelta() const;
  double getPreviousDelta(const size_t& index);

  void setWeight(const size_t& index, const double& value);
  void setWeights(const size_t& nextLayerNeuronQuantity);
  double getWeight(const size_t& index) const;

private:
  double input_;
  double output_;
  double weightDelta_;

  std::vector<double> forwardWeights_;
  std::vector<double> previousWeightDelta;
};

std::ostream& operator<<(std::ostream& out, const Neuron& neuron);

#endif //COURSE_PROJECT_NEURON_HPP
