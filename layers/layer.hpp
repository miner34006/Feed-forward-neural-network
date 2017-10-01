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
  using layerPtr = std::shared_ptr<Layer>;

  friend std::ostream& operator<<(std::ostream& out, const Layer& layer);

  explicit Layer(const size_t& neuronQuantity);
  explicit Layer(const std::vector<std::shared_ptr<Neuron>>& neurons);
  virtual ~Layer() = default;

  virtual void setPreviousLayer(layerPtr layer) = 0;
  virtual layerPtr getPreviousLayer() const = 0;

  virtual void setNextLayer(layerPtr layer) = 0;
  virtual layerPtr getNextLayer() const = 0;

  virtual void setNeuronQuantity(const size_t& neuronQuantity);
  virtual size_t getNeuronQuantity() const;

  virtual void setWeights() = 0;

  void setInputData(const std::vector<float>& data);

protected:
  std::vector<std::shared_ptr<Neuron>> neurons_;
};

std::ostream& operator<<(std::ostream& out, const Layer& layer);

#endif //COURSE_PROJECT_LAYER_HPP
