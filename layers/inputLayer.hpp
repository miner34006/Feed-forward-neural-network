//
// Created by Богдан Полянок on 30.09.2017.
//

#ifndef COURSE_PROJECT_INPUTLAYER_HPP
#define COURSE_PROJECT_INPUTLAYER_HPP

#include "../neuron.hpp"
#include "layer.hpp"

class InputLayer: public Layer{
public:
  explicit InputLayer(const size_t& neuronQuantity, const bool& hasBias);

  void setWeights(const std::shared_ptr<Layer> &nextLayer) override;
  void setInputData(const std::vector<double>& data) override;

  bool hasBias() const override;
  std::shared_ptr<Neuron> getBias() const override;

  void error(const double &expected,
             const double& learningRate,
             const double& alpha,
             const std::shared_ptr<Layer>& nextLayer) override;

private:
  std::shared_ptr<Neuron> bias_;
};

#endif //COURSE_PROJECT_INPUTLAYER_HPP
