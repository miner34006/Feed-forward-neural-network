//
// Created by Богдан Полянок on 30.09.2017.
//

#ifndef COURSE_PROJECT_INPUTLAYER_HPP
#define COURSE_PROJECT_INPUTLAYER_HPP

#include "../neuron/neuron.hpp"
#include "layer.hpp"

class InputLayer: public Layer{
public:
  explicit InputLayer(const size_t& neuronQuantity, const bool& hasBias);

  friend std::ostream& operator<<(std::ostream& out, const InputLayer& layer);

  void setWeights(const std::shared_ptr<Layer> &nextLayer) override;
  void setInputData(const std::vector<double>& data) override;

  double getTotalImpulse(const size_t &toNeuron) const override;

  bool hasBias() const override;
  std::shared_ptr<Neuron> getBias() const override;

  void changeWeights(const double& learningRate, const double& alpha, const std::shared_ptr<Layer>& nextLayer);

private:
  std::shared_ptr<Neuron> bias_;
};

std::ostream& operator<<(std::ostream& out, const InputLayer& layer);

#endif //COURSE_PROJECT_INPUTLAYER_HPP
