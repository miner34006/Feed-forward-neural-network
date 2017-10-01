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
  Neuron() = default;
  explicit Neuron(const size_t& nextLayerNeuronQuantity);
  Neuron(const float &input, const std::vector<float>& forwardWeights);

  friend std::ostream& operator<<(std::ostream& out, const Neuron& neuron);

  float activation() const;

  void setInput(const float& input);
  void setOutput(const float& output);

  float getInput() const;
  float getOutput() const;

  void setWeights(const size_t& nextLayerNeuronQuantity);
  std::vector<float> getWeights();

private:
  std::vector<float> forwardWeights_;

  float input_;
  float output_;
};

std::ostream& operator<<(std::ostream& out, const Neuron& neuron);

#endif //COURSE_PROJECT_NEURON_HPP
