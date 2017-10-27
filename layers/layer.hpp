//
// Created by Богдан Полянок on 30.09.2017.
//

#ifndef COURSE_PROJECT_LAYER_HPP
#define COURSE_PROJECT_LAYER_HPP

#include <vector>
#include <memory>
#include <iostream>

#include "../neuron.hpp"

class Layer{
public:
  explicit Layer(const size_t& neuronQuantity);
  virtual ~Layer() = default;

  friend std::ostream& operator<<(std::ostream& out, const Layer& layer);
  std::shared_ptr<Neuron> operator [](const size_t& index);
  
  virtual size_t getNeuronQuantity() const;
  virtual double getTotalImpulse(const size_t &toNeuron) const;
  virtual std::shared_ptr<Neuron> getBias() const;

  virtual void setInputData(const std::vector<double>& data);
  virtual void setWeights(const std::shared_ptr<Layer>& nextLayer);

  virtual bool hasBias() const;

protected:
  std::vector<std::shared_ptr<Neuron>> neurons_;
};

std::ostream& operator<<(std::ostream& out, const Layer& layer);

#endif //COURSE_PROJECT_LAYER_HPP
