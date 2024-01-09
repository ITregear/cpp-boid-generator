# cpp-boid-generator

## Goal

The goal was to build a simple boid simulation, in C++. [Boids](https://en.wikipedia.org/wiki/Boids) (bird-oids) are a demonstration of emergent complex behaviour, where basic flocking can be simulated with just three simple rules applied to objects that can move in 2D or 3D space.

1. Separation (boids steer away from nearby boids)
2. Alignment (boids steer towards average heading of nearby boids)
3. Cohesion (boids steer towards centre of mass of nearby boids)

## Project Status

'boidSimulator.cpp' is unfinished, and there are no plans to complete it. It was quickly realised that visualisation was not trivial, and so as part of the [12-progamming-challenge](https://github.com/ITregear/programming-language-challenge), it was decided to continue the boid simulation in C#, with Unity for visuals. This will be continued in [unity-boid-simulation](https://github.com/ITregear/unity-boid-simulation).

## Acknowledgments

Both the article by Ben Eater, as well as it's cited article by Conrad Parker were helpful in implementation.

* [Boids Algorithm Demonstration](https://eater.net/boids)
* [Boids Pseudocode](http://www.kfish.org/boids/pseudocode.html)