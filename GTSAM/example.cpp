#include <gtsam/nonlinear/NonlinearFactorGraph.h>
#include <gtsam/geometry/Pose2.h>
#include <gtsam/slam/BetweenFactor.h>

using namespace std;
using namespace gtsam;
// using namespace gtsamexamples;

int main(int argc, char** argv) {
// Create an empty nonlinear factor graph
NonlinearFactorGraph graph;

// Add a Gaussian prior on pose x_1
Pose2 priorMean(0.0, 0.0, 0.0);
noiseModel::Diagonal::shared_ptr priorNoise =
  noiseModel::Diagonal::Sigmas(Vector3(0.3, 0.3, 0.1));
graph.add(PriorFactor<Pose2>(1, priorMean, priorNoise));

// Add two odometry factors
Pose2 odometry(2.0, 0.0, 0.0);
noiseModel::Diagonal::shared_ptr odometryNoise =
  noiseModel::Diagonal::Sigmas(Vector3(0.2, 0.2, 0.1));
graph.add(BetweenFactor<Pose2>(1, 2, odometry, odometryNoise));
graph.add(BetweenFactor<Pose2>(2, 3, odometry, odometryNoise));

}