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
    Boid testBoid(1, 3, 0, 3.2);

    std::pair<float, float> position = testBoid.getPosition();
    std::pair<float, float> velocity = testBoid.getVelocity();

    std::cout << "Boid Position: (" << position.first << ", " << position.second << ")";
    std::cout << std::endl;
    std::cout << "Boid Velocity: (" << velocity.first << ", " << velocity.second << ")";

}