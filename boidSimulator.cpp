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
    
    const int FPS = 60;
    const std::chrono::milliseconds frameDuration(1000 / FPS);

    auto previousTime = std::chrono::steady_clock::now();

    while (1) {
        auto currentTime = std::chrono::steady_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - previousTime);

        if (elapsedTime >= frameDuration) {
            // Update Boid state, and simulate here
            // This runs at FPS defined rate

            previousTime = currentTime;
        }
    }
}