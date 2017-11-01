#define BOOST_TEST_MAIN

#include <boost/test/included/unit_test.hpp>

#include "../src/neuron/neuron.hpp"
#include "../src/layers/layer.hpp"
#include "../src/neuralNetwork/neuralNetwork.hpp"

BOOST_AUTO_TEST_SUITE(testNeuralNetwork)

  BOOST_AUTO_TEST_CASE(testGetNeuronQuantity)
  {
    NeuralNetwork neuralNetwork({1, 2, 4}, false);

    BOOST_CHECK_EQUAL(neuralNetwork[0]->getNeuronQuantity(), 1);
    BOOST_CHECK_EQUAL(neuralNetwork[1]->getNeuronQuantity(), 2);
    BOOST_CHECK_EQUAL(neuralNetwork[2]->getNeuronQuantity(), 4);
  }

  BOOST_AUTO_TEST_CASE(testSetInputData)
  {
    NeuralNetwork neuralNetwork({3, 2, 4}, false);
    neuralNetwork.feedForward({0, 1, 2});

    BOOST_CHECK_CLOSE((*neuralNetwork[0])[0]->getInput(), 0, 0.1);
    BOOST_CHECK_CLOSE((*neuralNetwork[0])[1]->getInput(), 1, 0.1);
    BOOST_CHECK_CLOSE((*neuralNetwork[0])[2]->getInput(), 2, 0.1);
  }

  BOOST_AUTO_TEST_CASE(testForceDataFrom1To2)
  {
    NeuralNetwork neuralNetwork({2, 2, 2}, false);
    (*neuralNetwork[0])[0]->setWeight(0, 0.5);
    (*neuralNetwork[0])[0]->setWeight(1, 0.1);
    (*neuralNetwork[0])[1]->setWeight(0, 0.2);
    (*neuralNetwork[0])[1]->setWeight(1, 1);

    neuralNetwork.feedForward({1, 1});

    BOOST_CHECK_CLOSE((*neuralNetwork[1])[0]->getInput(), 0.7, 0.1);
    BOOST_CHECK_CLOSE((*neuralNetwork[1])[1]->getInput(), 1.1, 0.1);

    BOOST_CHECK_CLOSE((*neuralNetwork[1])[0]->getOutput(), 0.668, 0.1);
    BOOST_CHECK_CLOSE((*neuralNetwork[1])[1]->getOutput(), 0.750, 0.1);
  }

  BOOST_AUTO_TEST_CASE(testForceDataFrom2To3)
  {
    NeuralNetwork neuralNetwork({2, 2, 2}, false);
    (*neuralNetwork[0])[0]->setWeight(0, 0.5);
    (*neuralNetwork[0])[0]->setWeight(1, 0.1);
    (*neuralNetwork[0])[1]->setWeight(0, 0.2);
    (*neuralNetwork[0])[1]->setWeight(1, 1);

    (*neuralNetwork[1])[0]->setWeight(0, 0.3);
    (*neuralNetwork[1])[0]->setWeight(1, 0.4);
    (*neuralNetwork[1])[1]->setWeight(0, 0.1);
    (*neuralNetwork[1])[1]->setWeight(1, 0.9);

    neuralNetwork.feedForward({1, 1});
    BOOST_CHECK_CLOSE((*neuralNetwork[2])[0]->getInput(), 0.275, 1);
    BOOST_CHECK_CLOSE((*neuralNetwork[2])[1]->getInput(), 0.942, 1);

    BOOST_CHECK_CLOSE((*neuralNetwork[2])[0]->getOutput(), 0.568, 1);
    BOOST_CHECK_CLOSE((*neuralNetwork[2])[1]->getOutput(), 0.719, 1);
  }

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(testNeuron)

  BOOST_AUTO_TEST_CASE(testSetGetInput)
  {
    Neuron neuron;
    neuron.setInput(1);
    BOOST_CHECK_CLOSE(neuron.getInput(), 1, 0.1);
  }

  BOOST_AUTO_TEST_CASE(testSetGetOutput)
  {
    Neuron neuron;
    neuron.setOutput(1);
    BOOST_CHECK_CLOSE(neuron.getOutput(), 1, 0.1);
  }

  BOOST_AUTO_TEST_CASE(testActivation1)
  {
    Neuron neuron;
    neuron.setInput(1);
    neuron.activation();
    BOOST_CHECK_CLOSE(neuron.getOutput(), 0.731, 0.1);
  }

  BOOST_AUTO_TEST_CASE(testActivation2)
  {
    Neuron neuron;
    neuron.setInput(10);
    neuron.activation();
    BOOST_CHECK_CLOSE(neuron.getOutput(), 0.999, 0.1);
  }

  BOOST_AUTO_TEST_CASE(testSetGetWeight)
  {
    Neuron neuron;
    neuron.setWeights(4);

    neuron.setWeight(0, 0);
    neuron.setWeight(1, 1);
    neuron.setWeight(2, 2);
    neuron.setWeight(3, 3);

    BOOST_CHECK_CLOSE(neuron.getWeight(0), 0, 0.1);
    BOOST_CHECK_CLOSE(neuron.getWeight(1), 1, 0.1);
    BOOST_CHECK_CLOSE(neuron.getWeight(2), 2, 0.1);
    BOOST_CHECK_CLOSE(neuron.getWeight(3), 3, 0.1);
  }

BOOST_AUTO_TEST_SUITE_END()
