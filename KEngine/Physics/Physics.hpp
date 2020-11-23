#pragma once

#include "../Objects/ObjectParent.hpp"
#include "../Algorithms/Algor.hpp"
#include "../Data/Data.hpp"
#include <SFML/Graphics.hpp>

#include <iostream>
#include <cstdlib>
#include <map>
#include <cmath>


namespace ke
{

class GuiObject;

class Physics
{
public:

    Physics();

    Physics(GuiObject* object);

    Physics( GuiObject* object,
             long double mass,
             float fricton );

    ~Physics();

    void setTarget(GuiObject* object);

    void addForce(const std::string& name, float newtons, float angle);
    void addMomentaryForce(float newtons, float angle);
    void addMomentaryForce(const sf::Vector2f& force);
    sf::Vector2f getTotalForce() const;
    const std::map<std::string, sf::Vector2f>* getForceList() const;
    bool removeForce(const std::string& name);
    void clearForces();

    bool findForce(const std::string& name) const;


    void setSpeed(float px_per_frame, float angle);
    void setSpeed(const sf::Vector2f& px_per_frame);
    sf::Vector2f getSpeed() const;

    void stopObject();

    void setMaxSpeed(float px_per_frame);
    float getMaxSpeed() const;

    sf::Vector2f calculateSpeed();

    void setMass(long double mass);
    long double getMass() const;


    void setFriction(float fricton);
    float getFriction() const;

    void update(const float dt);


private:

    GuiObject* object;

    std::map<std::string, sf::Vector2f> forces;

    sf::Vector2f speed;
    sf::Vector2f total_force;
    long double mass;
    float fricton;

    float max_speed;

    sf::Vector2f last_position;
    //float air_resistance;
};

bool areColliding_RectangleRectangle(GuiObject* object1, GuiObject* object2);
bool areColliding_CircleCircle(GuiObject* object1, GuiObject* object2);
bool areColliding_RectangleCircle(GuiObject* rectangle, GuiObject* circle);

enum Walls {RIGHT, TOP, LEFT, BOTTOM};
bool BounceFromView(int wall, GuiObject* object, sf::View* view, float energy_loss_prc = 0);

bool BounceFromObject(GuiObject* movable_object, GuiObject* stable_object, float collision_mistake_tollerance, const float dt, float energy_loss_prc = 0);

//bool BoundFromBorder()

}
