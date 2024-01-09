/*
Achieved:
TODO: Setup script to create single instance of boid
TODO: Create functions that enforce the three core rules
TODO: #1 Separation: steer to avoid crowding flockmates
TODO: #2 Alignment: steer towards the average heading of local flockmates
TODO: #3 Cohesion: steer to move towards the averge position (COM) of local flockmates
TODO: Refactor into object so multiple boids can be initialised (may be better to store in array)
Unimplemented:
TODO: Create visualisation of boid objects, so live flocking can be simulated
TODO: If previous goals easy, extend simulation to 3D
*/

/*
Ivan Tregear
09/01/2024
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

    // Calculates new vector based on rules
    void update(float deltaTime, const std::vector<Boid>& allBoids) {

        std::pair<float, float> alignment = align(allBoids);
        std::pair<float, float> cohesion = cohere(allBoids);
        std::pair<float, float> separation = separate(allBoids);

        velX += (alignment.first + cohesion.first + separation.first);
        velY += (alignment.second + cohesion.second + separation.second);

        // Update position based on currently velocity
        posX += velX * deltaTime;
        posY += velY * deltaTime;
    }

    // Getter functions to retrieve position and velocity variables
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

    const float ALIGNMENT_RADIUS = 50.0f;
    const float COHESION_RADIUS = 50.0f;
    const float SEPARATION_RADIUS = 20.0f;
    const float MAX_FORCE = 0.05f;
    const float MAX_SPEED = 2.0f;

    std::pair<float, float> align(const std::vector<Boid>& allBoids) {
        // Alignment rule logic

        std::pair<float, float> averageVelocity(0.0f, 0.0f);
        int count = 0;
        for (const Boid& other : allBoids) {
            if (&other != this) {
                averageVelocity.first += other.velX;
                averageVelocity.second += other.velY;
                count++;
            }
        }
        if (count > 0) {
            averageVelocity.first /= count;
            averageVelocity.second /= count;
        }
        return averageVelocity;
    }

    std::pair<float, float> cohere(const std::vector<Boid>& allBoids) {
        // Cohesion rule logic

        std::pair<float, float> centerOfMass(0.0f, 0.0f);
        int count = 0;
        for (const Boid& other : allBoids) {
            if (&other != this) {
                centerOfMass.first += other.posX;
                centerOfMass.second += other.posY;
                count++;
            }
        }
        if (count > 0) {
            centerOfMass.first /= count;
            centerOfMass.second /= count;
        }
        return {centerOfMass.first - posX, centerOfMass.second - posY};
    }

    std::pair<float, float> separate(const std::vector<Boid>& allBoids) {
        // Separation rule logic

        std::pair<float, float> avoidanceVector(0.0f, 0.0f);
        int count = 0;

        for (const Boid& other : allBoids) {
            if (&other != this) {
                avoidanceVector.first += posX - other.posX;
                avoidanceVector.first += posY - other.posY;
                count++;
            }
        }
        if (count > 0) {
            avoidanceVector.first /= count;
            avoidanceVector.second /= count;
        }
        return avoidanceVector;
    }
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
            float deltaTime = std::chrono::duration<float, std::chrono::seconds::period>(elapsedTime).count();

            int index = 0;
            for (Boid& boid : boids) {
                // Update boids here
                boid.update(deltaTime, boids);

                if (index == 0) {
                    auto position = boid.getPosition();
                    std::cout << "Boid Pos: X=" << position.first << ", Y=" << position.second << std::endl;
                }
                index++;
            }

            previousTime = currentTime;
        }
    }
}