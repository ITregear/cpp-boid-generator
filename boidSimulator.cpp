/*
TODO: Setup script to create single instance of boid
TODO: Create functions that enforce the three core rules
TODO: #1 Separation: steer to avoid crowding flockmates
TODO: #2 Alignment: steer towards the average heading of local flockmates
TODO: #3 Cohesion: steer to move towards the averge position (COM) of local flockmates
TODO: Refactor into object so multiple boids can be initialised (may be better to store in array)
TODO: Create visualisation of boid objects, so live flocking can be simulated
TODO: If previous goals easy, extend simulation to 3D
*/

/*
Each boid will need a position and a velocity.
These are vectors

*/

#include <iostream>
#include <utility>
#include <chrono>
#include <random>

class Boid {
public: 
    // Public methods, accessible by other scopes

    // Constructor initializes the pos and vel, so values are not undefined when get later
    Boid(float px, float py, float vx, float vy)
        : posX(px), posY(py), velX(vx), velY(vy) {}

    std::pair<float, float> getPosition() const {
        return {posX, posY};
    }
    std::pair<float, float> getVelocity() const {
        return {velX, velY};
    }


private:
    // Private methods, only accessible by each object instance of this class
    float posX, posY;
    float velX, velY;
};


int main() {
    
    // Setting up FPS timer
    const int FPS = 60;
    const std::chrono::milliseconds frameDuration(1000 / FPS);
    auto previousTime = std::chrono::steady_clock::now();

    // Reserving memory required for total number of boids
    const int numberOfBoids = 2;
    std::vector<Boid> boids;
    boids.reserve(numberOfBoids);

    // Creating random number generator
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_real_distribution<> distr(-100.0, 100.0);

    // Initializing boids
    // Assuming boids are initialized stationary

    for (int i = 0; i < numberOfBoids; i++) {
        float posX = distr(eng);
        float posY = distr(eng);
        float velX = distr(eng);
        float velY = distr(eng);
        boids.emplace_back(posX, posY, velX, velY);
    }

    while (1) {
        auto currentTime = std::chrono::steady_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - previousTime);

        if (elapsedTime >= frameDuration) {
            // Update Boid state, and simulate here
            // This runs at FPS defined rate

            for (Boid& boid : boids) {
                // Update boids here

                std::pair<float, float> boidPos = boid.getPosition();
                std::pair<float, float> boidVel = boid.getVelocity();

                std::cout << "Boid Pos: " << boidPos.first << ", " << boidPos.second;
                std::cout << std::endl;
            }

            previousTime = currentTime;
        }
    }
}