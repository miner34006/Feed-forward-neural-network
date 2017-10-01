//
// Created by Богдан Полянок on 30.09.2017.
//

#ifndef COURSE_PROJECT_OUTPUTLAYER_HPP
#define COURSE_PROJECT_OUTPUTLAYER_HPP

#include "layer.hpp"

class OutputLayer: public Layer{
public:
  using layerPtr = Layer::layerPtr ;

  OutputLayer();
  explicit OutputLayer(const std::vector<std::shared_ptr<Neuron>>& neurons);

  void setPreviousLayer(layerPtr layer) override;
  layerPtr getPreviousLayer() const override;

  void setNextLayer(layerPtr layer) override;
  layerPtr getNextLayer() const override;

  void setWeights() override;

private:
  layerPtr previousLayer_;
};

#endif //COURSE_PROJECT_OUTPUTLAYER_HPP
