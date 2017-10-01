//
// Created by Богдан Полянок on 30.09.2017.
//

#ifndef COURSE_PROJECT_INPUTLAYER_HPP
#define COURSE_PROJECT_INPUTLAYER_HPP

#include "layer.hpp"

class InputLayer: public Layer{
public:
  using layerPtr = Layer::layerPtr;

  InputLayer();
  explicit InputLayer(const std::vector<std::shared_ptr<Neuron>> &neurons);

  void setNextLayer(layerPtr layer) override;
  layerPtr getNextLayer() const override;

  void setPreviousLayer(layerPtr layer) override;
  layerPtr getPreviousLayer() const override;

  void setWeights() override;

private:
  layerPtr nextLayer_;
};

#endif //COURSE_PROJECT_INPUTLAYER_HPP
