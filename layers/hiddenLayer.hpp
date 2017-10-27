//
// Created by Богдан Полянок on 30.09.2017.
//

#ifndef COURSE_PROJECT_HIDDENLAYER_HPP
#define COURSE_PROJECT_HIDDENLAYER_HPP

#include "layer.hpp"
#include "../neuron.hpp"

class HiddenLayer: public Layer{
public:
  explicit HiddenLayer(const size_t& neuronQuantity, const bool& hasBias);
  void setWeights(const std::shared_ptr<Layer> &nextLayer) override;

  double getTotalImpulse(const size_t &toNeuron) const override;

  bool hasBias() const override;
  std::shared_ptr<Neuron> getBias() const override;

  void changeWeights(const double& learningRate, const double& momentum, const std::shared_ptr<Layer>& nextLayer);

private:
  std::shared_ptr<Neuron> bias_;
};

#endif //COURSE_PROJECT_HIDDENLAYER_HPP
