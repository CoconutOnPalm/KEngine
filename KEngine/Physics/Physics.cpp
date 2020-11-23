#include "Physics.hpp"

namespace ke
{

Physics::Physics()
{
    ///KEngine Physics constructor
    /** Physics is a class that can be initialized inside <br>
             - KEngine Rectangle <br>
             - Kengine Circle <br>
             - Kengine Button <br>
        It can add (let's say) physical behaviour to an object <br>*/

    this->speed = sf::Vector2f(0, 0);
    this->total_force = sf::Vector2f(0, 0);
    this->mass = 1;
    this->fricton = 0;
    this->max_speed = 299'792'458;
    //this->air_resistance = 0;
    last_position.x = 0; last_position.y = 0;
}


Physics::Physics(GuiObject* object)
{
    ///KEngine Physics constructor
    /** Physics is a class that can be initialized inside <br>
             - KEngine Rectangle <br>
             - Kengine Circle <br>
             - Kengine Button <br>
        It can add (let's say) physical behaviour to an object <br>*/

    this->object = object;

    this->speed = sf::Vector2f(0, 0);
    this->total_force = sf::Vector2f(0, 0);
    this->mass = 1;
    this->fricton = 0;
    this->max_speed = 299'792'458;
    //this->air_resistance = 0;
    last_position = object->getShapeCentre();
}


Physics::Physics( GuiObject* object,
                  long double mass,
                  float fricton )
{
    ///KEngine Physics constructor
    /** Physics is a class that can be initialized inside <br>
             - KEngine Rectangle <br>
             - Kengine Circle <br>
             - Kengine Button <br>
        It can add (let's say) physical behaviour to an object <br>*/

    this->object = object;

    this->speed = sf::Vector2f(0, 0);
    this->total_force = sf::Vector2f(0, 0);
    this->mass = mass;
    this->fricton = fricton;
    this->max_speed = 299'792'458;
    //this->air_resistance = air_resistance;
    last_position = object->getShapeCentre();

    if (this->mass == 0) this->mass = 0.000001;
}


Physics::~Physics()
{
    ///KEngine Physics destructor
    /** Physics is a class that can be initialized inside <br>
             - KEngine Rectangle <br>
             - Kengine Circle <br>
             - Kengine Button <br>
        It can add (let's say) physical behaviour to an object <br>*/
}


void Physics::setTarget(GuiObject* object)
{
    ///sets object that it refers to

    this->object = object;
    last_position = object->getShapeCentre();
}


void Physics::addForce(const std::string& name, float newtons, float angle)
{
    ///applies force to the object

    float to_deg = angle * (PI / 180); // form radians to degrees

    this->forces[name] = sf::Vector2f(newtons * cos(to_deg), -newtons * sin(to_deg));
    this->total_force.x +=  newtons * cos(to_deg);
    this->total_force.y += -newtons * sin(to_deg);
}

void Physics::addMomentaryForce(float newtons, float angle)
{
    ///adds force only for one frame

    float to_deg = angle * (PI / 180);

    this->speed.x +=  newtons * cos(to_deg);
    this->speed.y += -newtons * sin(to_deg);
}

sf::Vector2f Physics::getTotalForce() const
{
    ///returns vector of summed up forces applied to the object

    return total_force;
}


const std::map<std::string, sf::Vector2f>* Physics::getForceList() const
{
    ///returns std::map of forces

    return &forces;
}


bool Physics::removeForce(const std::string& name)
{
    ///removes given force

    std::map<std::string, sf::Vector2f>::iterator itr = forces.find(name);
    if (itr != forces.end())
    {
        total_force.x -= itr->second.x;
        total_force.y -= itr->second.y;
        forces.erase(itr);
        return true;
    }
    else
    {
        throw_error("Physics::removeForce(..)", "force not found", "WARNING");
        return 0;
    }
}


void Physics::clearForces()
{
    ///clears all the forces

    total_force.x = 0;
    total_force.y = 0;

    forces.clear();
}


bool Physics::findForce(const std::string& name) const
{
    ///returns true if given force name is found

    auto itr = forces.find(name);
    return itr != forces.end();
}


void Physics::setSpeed(float px_per_frame, float angle)
{
    ///sets object's speed

    float to_deg = angle * (PI / 180);

    this->speed.x =  px_per_frame * cos(to_deg);
    this->speed.y = -px_per_frame * sin(to_deg);
}

void Physics::setSpeed(const sf::Vector2f& px_per_frame)
{
    ///sets object's speed

    this->speed = px_per_frame;
}


sf::Vector2f Physics::getSpeed() const
{
    ///returns object's speed

    return speed;
}


void Physics::stopObject()
{
    ///sets object's speed to 0

    this->speed.x = 0;
    this->speed.y = 0;
}


void Physics::setMaxSpeed(float px_per_frame)
{
    ///sets maximum speed that the object can move

    this->max_speed = px_per_frame;
}

float Physics::getMaxSpeed() const
{
    ///returns maximum speed that the object can move

    return max_speed;
}


sf::Vector2f Physics::calculateSpeed() // use once in frame
{
    ///calculate object's speed
    /** use once per frame */

    sf::Vector2f temp(last_position.x - object->getShapeCentre().x, last_position.y - object->getShapeCentre().y);
    last_position = object->getShapeCentre();
    return -temp;
}


void Physics::setMass(long double mass)
{
    ///sets object's mass

    this->mass = mass;

    if (this->mass == 0) this->mass = 0.000001;
}

long double Physics::getMass() const
{
    ///returns object's mass

    return mass;
}



void Physics::setFriction(float friction)
{
    ///sets object's friction

    this->fricton = friction;
}


float Physics::getFriction() const
{
    ///returns object's friction

    return fricton;
}



void Physics::update(const float dt)
{
    ///updates object
    /** use to achieve some movement */

    sf::Vector2f temp;
    float angle = atan(total_force.y / total_force.x);
    sf::Vector2f deco_friction(cos(angle * PI / 180.0) * fricton, sin(angle * PI / 180.0) * fricton);

    if (total_force.x > 0 && total_force.x - deco_friction.x >= 0) temp.x = (total_force.x - deco_friction.x) / mass;
    else if (total_force.x < 0 && total_force.x + deco_friction.x <= 0) temp.x = (total_force.x + deco_friction.x) / mass;
    else
    {
        if (speed.x > 0 && speed.x - deco_friction.x >= 0) temp.x = -deco_friction.x;
        else if (speed.x < 0 && speed.x + deco_friction.x <= 0) temp.x = deco_friction.x;
        else temp.x = 0;
    }


    if (total_force.y > 0 && total_force.y - deco_friction.y >= 0) temp.y = (total_force.y - deco_friction.y) / mass;
    else if (total_force.y < 0 && total_force.y - deco_friction.y <= 0) (temp.y = total_force.y + deco_friction.y) / mass;
    else
    {
        if (speed.y > 0 && speed.y - deco_friction.y >= 0) temp.y = -deco_friction.y;
        else if (speed.y < 0 && speed.y + deco_friction.y <= 0) temp.y = deco_friction.y;
        else temp.y = 0;
    }

    if ((speed.x + temp.x) * (speed.x + temp.x) + (speed.y + temp.y) * (speed.y + temp.y) <= max_speed * max_speed)
    {
        speed.x += temp.x;
        speed.y += temp.y;

        if (temp.x == 0) speed.x = 0;
        if (temp.y == 0) speed.y = 0;

        object->move(speed.x * dt, speed.y * dt);
    }
}







bool areColliding_RectangleRectangle(GuiObject* object1, GuiObject* object2)
{
    /** \brief Checks if two rectangles (or buttons) are colliding
     *
     * \param object1   first  rectangle
     * \param object2   second rectangle
     * \return if colliding, returns true
     *
     */


    /*if (((object1->getShapeCentre().x - object1->getSize().x * object1->getScale().x / 2 >= object2->getShapeCentre().x - object2->getSize().x * object2->getScale().x / 2 &&
         object1->getShapeCentre().x - object1->getSize().x * object1->getScale().x / 2 <= object2->getShapeCentre().x + object2->getSize().x * object2->getScale().x / 2 )  ||
        (object1->getShapeCentre().x + object1->getSize().x * object1->getScale().x / 2 >= object2->getShapeCentre().x - object2->getSize().x * object2->getScale().x / 2 &&
         object1->getShapeCentre().x + object1->getSize().x * object1->getScale().x / 2 <= object2->getShapeCentre().x + object2->getSize().x * object2->getScale().x / 2 )  ) &&

        ((object1->getShapeCentre().y - object1->getSize().y * object1->getScale().y / 2 >= object2->getShapeCentre().y - object2->getSize().y * object2->getScale().y / 2 &&
         object1->getShapeCentre().y - object1->getSize().y * object1->getScale().y / 2 <= object2->getShapeCentre().y + object2->getSize().y * object2->getScale().y / 2 )  ||
        (object1->getShapeCentre().y + object1->getSize().y * object1->getScale().y / 2 >= object2->getShapeCentre().y - object2->getSize().y * object2->getScale().y / 2 &&
         object1->getShapeCentre().y + object1->getSize().y * object1->getScale().y / 2 <= object2->getShapeCentre().y + object2->getSize().y * object2->getScale().y / 2 )  )    )
         return true;
    else return false;*/

    if ((fabs(object1->getShapeCentre().x - object2->getShapeCentre().x) <= object1->getSize().x * object1->getScale().x / 2 + object2->getSize().x * object2->getScale().x / 2  &&
        fabs(object1->getShapeCentre().y - object2->getShapeCentre().y) <= object1->getSize().y * object1->getScale().y / 2 + object2->getSize().y * object2->getScale().y / 2))
        return true;
    else
        return false;
}


bool areColliding_CircleCircle(GuiObject* object1, GuiObject* object2)
{
    /** \brief Checks if two circles are colliding
     *
     * \param object1   first  circle
     * \param object2   second circle
     * \return if colliding, returns true
     *
     */

    float size1 = object1->getSize().x * object1->getScale().x / 2;
    float size2 = object2->getSize().x * object2->getScale().x / 2;

    if ((size1 + size2) * (size1 + size2) >=
        (object2->getShapeCentre().x - object1->getShapeCentre().x) * (object2->getShapeCentre().x - object1->getShapeCentre().x) + (object2->getShapeCentre().y - object1->getShapeCentre().y) * (object2->getShapeCentre().y - object1->getShapeCentre().y))
        return true; // radius^2 >= (centre2 - centre1)^2
    else
        return false;
}


bool areColliding_RectangleCircle(GuiObject* rectangle, GuiObject* circle)
{
    /** \brief Checks if rectangle and circle are colliding
     *
     * \param rectangle     rectangle of button
     * \param circle        circle
     * \return if colliding, returns true
     *
     */

    float rx = rectangle->getShapeCentre().x - rectangle->getSize().x * rectangle->getScale().x / 2;
    float ry = rectangle->getShapeCentre().y - rectangle->getSize().y * rectangle->getScale().y / 2;

    // temporary variables to set edges for testing
    float testX = circle->getShapeCentre().x;
    float testY = circle->getShapeCentre().y;

    // which edge is closest?
    if (circle->getShapeCentre().x < rx)
        testX = rx;      // test left edge
    else if (circle->getShapeCentre().x > rx + rectangle->getSize().x * rectangle->getScale().x)
        testX = rx + rectangle->getSize().x * rectangle->getScale().x;   // right edge
    if (circle->getShapeCentre().y < ry)
        testY = ry;      // top edge
    else if (circle->getShapeCentre().y > ry + rectangle->getSize().y * rectangle->getScale().x)
        testY = ry + rectangle->getSize().y * rectangle->getScale().y;   // bottom edge

    // get distance from closest edges
    float distX = circle->getShapeCentre().x - testX;
    float distY = circle->getShapeCentre().y - testY;
    float distance = sqrt(distX * distX + distY * distY);

    // if the distance is less than the radius, collision!
    if (distance <= circle->getSize().x * circle->getScale().x / 2)
        return true;
    return false;
}


bool BounceFromView(int wall, GuiObject* object, sf::View* view, float energy_loss_prc)
{
    /** \brief makes object bouncing form view borders
     *
     * \param object            object
     * \param view              view, simple is that
     * \param energy_loss_prc   percent of energy lost after a bounce
     * \return if colliding, returns true
     *
     */

    float width_half = object->getSize().x * object->getScale().x / 2;
    float height_half = object->getSize().y * object->getScale().y / 2;

    switch (wall)
    {
    case RIGHT:
        {
            if (object->getShapeCentre().x + width_half > view->getCenter().x + view->getSize().x / 2)
            {
                object->setPositionByCentre(sf::Vector2f(view->getCenter().x + view->getSize().x / 2 - width_half, object->getShapeCentre().y));
                object->physics()->setSpeed(sf::Vector2f(-object->physics()->getSpeed().x * ((100 - energy_loss_prc) / 100), object->physics()->getSpeed().y));
                return true;
            }
        }
        break;

    case TOP:
        {
            if (object->getShapeCentre().y - height_half < view->getCenter().y - view->getSize().y / 2)
            {
                object->setPositionByCentre(sf::Vector2f(object->getShapeCentre().x, view->getCenter().y - view->getSize().y / 2 + height_half));
                object->physics()->setSpeed(sf::Vector2f(object->physics()->getSpeed().x, -object->physics()->getSpeed().y * ((100 - energy_loss_prc) / 100)));
                return true;
            }
        }
        break;

    case LEFT:
        {
            if (object->getShapeCentre().x - width_half < view->getCenter().x - view->getSize().x / 2)
            {
                object->setPositionByCentre(sf::Vector2f(view->getCenter().x - view->getSize().x / 2 + width_half, object->getShapeCentre().y));
                object->physics()->setSpeed(sf::Vector2f(-object->physics()->getSpeed().x * ((100 - energy_loss_prc) / 100), object->physics()->getSpeed().y));
                return true;
            }
        }
        break;

    case BOTTOM:
        {
            if (object->getShapeCentre().y + height_half > view->getCenter().y + view->getSize().y / 2)
            {
                object->setPositionByCentre(sf::Vector2f(object->getShapeCentre().x, view->getCenter().y + view->getSize().y / 2 - height_half));
                object->physics()->setSpeed(sf::Vector2f(object->physics()->getSpeed().x, -object->physics()->getSpeed().y * ((100 - energy_loss_prc) / 100)));
                return true;
            }
        }
        break;

    default:
        {
            throw "1st argument is bad\n";
            return false;
        }
    }

    return false;
}



bool BounceFromObject(GuiObject* movable_object, GuiObject* stable_object, float collision_mistake_tollerance, const float dt, float energy_loss_prc)
{
    /** \brief makes movable object bouncing form stable object
     *
     * \param movable_object                object that moves after a bounce
     * \param stable_object                 object that does not move after a bounce
     * \param collision_mistake_tollerance  how many pixels can movable object
     * \param dt                            delta time
     * \param energy_loss_prc               percent of energy lost after a bounce
     * \return if colliding, returns true
     *
     */

    float m_width_half = movable_object->getSize().x * movable_object->getScale().x / 2;
    float m_height_half = movable_object->getSize().y * movable_object->getScale().y / 2;

    float s_width_half = stable_object->getSize().x * stable_object->getScale().x / 2;
    float s_height_half = stable_object->getSize().y * stable_object->getScale().y / 2;

    bool ret_val = false;

    float dist [] = {fabs(stable_object->getShapeCentre().y - s_height_half - (movable_object->getShapeCentre().y + m_height_half)),
                     fabs(stable_object->getShapeCentre().y + s_height_half - (movable_object->getShapeCentre().y - m_height_half)),
                     fabs(stable_object->getShapeCentre().x + s_width_half - (movable_object->getShapeCentre().x - m_width_half)),
                     fabs(stable_object->getShapeCentre().x - s_width_half - (movable_object->getShapeCentre().x + m_width_half))};

    float closest_one = *std::min_element(dist, dist + 4);

    int which_wall;

    for (int i = 0; i < 4; i++)
    {
        if (closest_one == dist[i])
        {
            which_wall = i;
            break;
        }
    }

    if (which_wall == 0 && closest_one <= collision_mistake_tollerance && areColliding_RectangleRectangle(movable_object, stable_object))
    {
        //std::cout << "bottom\n";
        movable_object->setPositionByCentre(sf::Vector2f(movable_object->getShapeCentre().x, stable_object->getShapeCentre().y - s_height_half - m_height_half));
        movable_object->physics()->setSpeed(sf::Vector2f(movable_object->physics()->getSpeed().x, -movable_object->physics()->getSpeed().y * ((100 - energy_loss_prc) / 100)));
        if (closest_one > 0)
            movable_object->move(movable_object->physics()->getSpeed().x * dt / movable_object->physics()->getMass(), movable_object->physics()->getSpeed().y * dt / movable_object->physics()->getMass());
        ret_val = true;
    }

    else if (which_wall == 1 && closest_one <= collision_mistake_tollerance && areColliding_RectangleRectangle(movable_object, stable_object))
    {
        //std::cout << "top\n";
        movable_object->setPositionByCentre(sf::Vector2f(movable_object->getShapeCentre().x, stable_object->getShapeCentre().y + s_height_half + m_height_half));
        movable_object->physics()->setSpeed(sf::Vector2f(movable_object->physics()->getSpeed().x, -movable_object->physics()->getSpeed().y * ((100 - energy_loss_prc) / 100)));
        if (closest_one > 0)
            movable_object->move(movable_object->physics()->getSpeed().x * dt / movable_object->physics()->getMass(), movable_object->physics()->getSpeed().y * dt / movable_object->physics()->getMass());
        ret_val = true;
    }

    else if (which_wall == 2 && closest_one <= collision_mistake_tollerance && areColliding_RectangleRectangle(movable_object, stable_object))
    {
        //std::cout << "left\n";
        movable_object->setPositionByCentre(sf::Vector2f(stable_object->getShapeCentre().x + s_width_half + m_width_half, movable_object->getShapeCentre().y));
        movable_object->physics()->setSpeed(sf::Vector2f(-movable_object->physics()->getSpeed().x * ((100 - energy_loss_prc) / 100), movable_object->physics()->getSpeed().y));
        if (closest_one > 0)
            movable_object->move(movable_object->physics()->getSpeed().x * dt / movable_object->physics()->getMass(), movable_object->physics()->getSpeed().y * dt / movable_object->physics()->getMass());
        ret_val = true;
    }

    else if (which_wall == 3 && closest_one <= collision_mistake_tollerance && areColliding_RectangleRectangle(movable_object, stable_object))
    {
        //std::cout << "right\n";
        movable_object->setPositionByCentre(sf::Vector2f(stable_object->getShapeCentre().x - s_width_half - m_width_half, movable_object->getShapeCentre().y));
        movable_object->physics()->setSpeed(sf::Vector2f(-movable_object->physics()->getSpeed().x * ((100 - energy_loss_prc) / 100), movable_object->physics()->getSpeed().y));
        if (closest_one > 0)
            movable_object->move(movable_object->physics()->getSpeed().x * dt / movable_object->physics()->getMass(), movable_object->physics()->getSpeed().y * dt / movable_object->physics()->getMass());
        ret_val = true;
    }

    return ret_val;
}

}
