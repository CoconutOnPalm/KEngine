#include "ObjectParent.hpp"

namespace ke
{

//MouseButon GuiObject::MB;
Pos GuiObject::TP;
Pos GuiObject::OR;
Font GuiObject::FONT;
TextScope GuiObject::TS;

sf::Font GuiObject::arial;
sf::Font GuiObject::arial_uni;
sf::Font GuiObject::calibri;
sf::Font GuiObject::comic_sans;
sf::Font GuiObject::courier_new;
sf::Font GuiObject::times_new_roman;
sf::Font GuiObject::trebuchet_MS;
sf::Font GuiObject::verdana;


bool GuiObject::fonts_inited = false;


void GuiObject::Init()
{
    arial.loadFromFile("KEngine/Fonts/arial.ttf");
    arial_uni.loadFromFile("KEngine/Fonts/ARIALUNI.ttf");
    calibri.loadFromFile("KEngine/Fonts/calibri.ttf");
    comic_sans.loadFromFile("KEngine/Fonts/comic.ttf");
    courier_new.loadFromFile("KEngine/Fonts/cour.ttf");
    times_new_roman.loadFromFile("KEngine/Fonts/times.ttf");
    trebuchet_MS.loadFromFile("KEngine/Fonts/trebuc.ttf");
    verdana.loadFromFile("KEngine/Fonts/verdana.ttf");

    fonts_inited = true;
}



GuiObject::GuiObject()
{
    if (!fonts_inited)
        throw_error("GuiObject constructor", "failed to initialize fonts - call GuiObject::Init() first", "ERROR");

    /*arial.loadFromFile("KEngine/Fonts/arial.ttf");
    arial_uni.loadFromFile("KEngine/Fonts/ARIALUNI.ttf");
    calibri.loadFromFile("KEngine/Fonts/calibri.ttf");
    comic_sans.loadFromFile("KEngine/Fonts/comic.ttf");
    courier_new.loadFromFile("KEngine/Fonts/cour.ttf");
    times_new_roman.loadFromFile("KEngine/Fonts/times.ttf");
    trebuchet_MS.loadFromFile("KEngine/Fonts/trebuc.ttf");
    verdana.loadFromFile("KEngine/Fonts/verdana.ttf");*/

    /*arial.loadFromFile("Fonts/arial.ttf"); // for testing
    arial_uni.loadFromFile("Fonts/ARIALUNI.ttf");
    calibri.loadFromFile("Fonts/calibri.ttf");
    comic_sans.loadFromFile("Fonts/comic.ttf");
    courier_new.loadFromFile("Fonts/cour.ttf");
    times_new_roman.loadFromFile("Fonts/times.ttf");
    trebuchet_MS.loadFromFile("Fonts/trebuc.ttf");
    verdana.loadFromFile("Fonts/verdana.ttf");*/
}

GuiObject::~GuiObject()
{

}



Physics* GuiObject::physics()
{
    ///default physics initializers for classes that don't support physics

    return nullptr;
}



//-------------------------                                                         -------------------------//
//+++                                                                                                     +++//
//==============               F U N C T I O N S ,   W I T H   G U I O B J E C T               ==============//
//+++                                                                                                     +++//
//-------------------------                                                         -------------------------//


bool SmoothColorChange(GuiObject* object, bool tf_argumet, sf::Vector2f& mousePosition, const sf::Color& target_color, const sf::Color& basic_color, const float intensity, const float dt)
{
    /** \brief changes color of the object smoothly
     *
     * \param object        GuiObject child that is going to be changed
     * \param tf_argument   true - changes to specified color
                            false - changes back to basic color
     * \param mousePosition if object is invaded by the mouse
     * \param target_color  the color that will be put on the object at the end of the change
     * \param basic_color   the color before the change
     * \param intensity     the speed of changes
     * \param dt            delta time - used to change the color independently from the user's fps
     * \return the same as tf_argument
     *
     */


    float ratio_r = target_color.r - basic_color.r;
    float ratio_g = target_color.g - basic_color.g;
    float ratio_b = target_color.b - basic_color.b;
    float ratio_a = target_color.a - basic_color.a;

    if (tf_argumet)
    {
        sf::Color temp = object->getFillColor();


        if (object->getFillColor().r + (ratio_r * intensity * dt) >= 0 && object->getFillColor().r + (ratio_r * intensity * dt) <= 255)
            temp.r = static_cast<sf::Uint8>(object->getFillColor().r + (ratio_r * intensity * dt));
        if (object->getFillColor().g + (ratio_g * intensity * dt) >= 0 && object->getFillColor().g + (ratio_g * intensity * dt) <= 255)
            temp.g = static_cast<sf::Uint8>(object->getFillColor().g + (ratio_g * intensity * dt));
        if (object->getFillColor().b + (ratio_b * intensity * dt) >= 0 && object->getFillColor().b + (ratio_b * intensity * dt) <= 255)
            temp.b = static_cast<sf::Uint8>(object->getFillColor().b + (ratio_b * intensity * dt));
        if (object->getFillColor().a + (ratio_a * intensity * dt) >= 0 && object->getFillColor().a + (ratio_a * intensity * dt) <= 255)
            temp.a = static_cast<sf::Uint8>(object->getFillColor().a + (ratio_a * intensity * dt));



        if      (ratio_r < 0 && temp.r < target_color.r) temp.r = target_color.r;
        else if (ratio_r > 0 && temp.r > target_color.r) temp.r = target_color.r;

        if      (ratio_g < 0 && temp.g < target_color.g) temp.g = target_color.g;
        else if (ratio_g > 0 && temp.g > target_color.g) temp.g = target_color.g;

        if      (ratio_b < 0 && temp.b < target_color.b) temp.b = target_color.b;
        else if (ratio_b > 0 && temp.b > target_color.b) temp.b = target_color.b;

        if      (ratio_a < 0 && temp.a < target_color.a) temp.a = target_color.a;
        else if (ratio_a > 0 && temp.a > target_color.a) temp.a = target_color.a;


        if      (temp.r < 0) temp.r = 0;
        else if (temp.r > 255) temp.r = 255;

        if      (temp.g < 0) temp.g = 0;
        else if (temp.g > 255) temp.g = 255;

        if      (temp.b < 0) temp.b = 0;
        else if (temp.b > 255) temp.b = 255;

        if      (temp.a < 0) temp.a = 0;
        else if (temp.a > 255) temp.a = 255;


        object->setFillColor(temp);

        return true;
    }
    else
    {
        sf::Color temp = object->getFillColor();



        if (object->getFillColor().r - (ratio_r * intensity * dt) / 2 >= 0 && object->getFillColor().r - (ratio_r * intensity * dt) / 2 <= 255)
            temp.r = static_cast<sf::Uint8>(object->getFillColor().r - (ratio_r * intensity * dt) / 2);
        if (object->getFillColor().g - (ratio_g * intensity * dt) / 2 >= 0 && object->getFillColor().g - (ratio_g * intensity * dt) / 2 <= 255)
            temp.g = static_cast<sf::Uint8>(object->getFillColor().g - (ratio_g * intensity * dt) / 2);
        if (object->getFillColor().b - (ratio_b * intensity * dt) / 2 >= 0 && object->getFillColor().b - (ratio_b * intensity * dt) / 2 <= 255)
            temp.b = static_cast<sf::Uint8>(object->getFillColor().b - (ratio_b * intensity * dt) / 2);
        if (object->getFillColor().a - (ratio_a * intensity * dt) >= 0 && object->getFillColor().a - (ratio_a * intensity * dt) <= 255)
            temp.a = static_cast<sf::Uint8>(object->getFillColor().a - (ratio_a * intensity * dt));



        if      (ratio_r < 0 && temp.r > basic_color.r) temp.r = basic_color.r;
        else if (ratio_r > 0 && temp.r < basic_color.r) temp.r = basic_color.r;

        if      (ratio_g < 0 && temp.g > basic_color.g) temp.g = basic_color.g;
        else if (ratio_g > 0 && temp.g < basic_color.g) temp.g = basic_color.g;

        if      (ratio_b < 0 && temp.b > basic_color.b) temp.b = basic_color.b;
        else if (ratio_b > 0 && temp.b < basic_color.b) temp.b = basic_color.b;

        if      (ratio_a < 0 && temp.a > basic_color.a) temp.a = basic_color.a;
        else if (ratio_a > 0 && temp.a < basic_color.a) temp.a = basic_color.a;




        if      (temp.r < 0) temp.r = 0;
        else if (temp.r > 255) temp.r = 255;

        if      (temp.g < 0) temp.g = 0;
        else if (temp.g > 255) temp.g = 255;

        if      (temp.b < 0) temp.b = 0;
        else if (temp.b > 255) temp.b = 255;

        if      (temp.a < 0) temp.a = 0;
        else if (temp.a > 255) temp.a = 255;



        object->setFillColor(temp);


        return false;
    }
}



bool SmoothOutlineColorChange(GuiObject* object, bool tf_argumet, sf::Vector2f& mousePosition, const sf::Color& target_color, const sf::Color& basic_color, const float intensity, const float dt)
{
    /** \brief changes outline color of the object smoothly
     *
     * \param object        GuiObject child that is going to be changed
     * \param tf_argument   true - changes to specified color
                            false - changes back to basic color
     * \param mousePosition if object is invaded by the mouse
     * \param target_color  the color that will be put on the object at the end of the change
     * \param basic_color   the color before the change
     * \param intensity     the speed of changes
     * \param dt            delta time - used to change the color independently from the user's fps
     * \return the same as tf_argument
     *
     */


    float ratio_r = target_color.r - basic_color.r;
    float ratio_g = target_color.g - basic_color.g;
    float ratio_b = target_color.b - basic_color.b;
    float ratio_a = target_color.a - basic_color.a;

    if (tf_argumet)
    {
        sf::Color temp = object->getOutlineColor();


        if (object->getOutlineColor().r + (ratio_r * intensity * dt) >= 0 && object->getOutlineColor().r + (ratio_r * intensity * dt) <= 255)
            temp.r = static_cast<sf::Uint8>(object->getOutlineColor().r + (ratio_r * intensity * dt));
        if (object->getOutlineColor().g + (ratio_g * intensity * dt) >= 0 && object->getOutlineColor().g + (ratio_g * intensity * dt) <= 255)
            temp.g = static_cast<sf::Uint8>(object->getOutlineColor().g + (ratio_g * intensity * dt));
        if (object->getOutlineColor().b + (ratio_b * intensity * dt) >= 0 && object->getOutlineColor().b + (ratio_b * intensity * dt) <= 255)
            temp.b = static_cast<sf::Uint8>(object->getOutlineColor().b + (ratio_b * intensity * dt));
        if (object->getOutlineColor().a + (ratio_a * intensity * dt) >= 0 && object->getOutlineColor().a + (ratio_a * intensity * dt) <= 255)
            temp.a = static_cast<sf::Uint8>(object->getOutlineColor().a + (ratio_a * intensity * dt));



        if      (ratio_r < 0 && temp.r < target_color.r) temp.r = target_color.r;
        else if (ratio_r > 0 && temp.r > target_color.r) temp.r = target_color.r;

        if      (ratio_g < 0 && temp.g < target_color.g) temp.g = target_color.g;
        else if (ratio_g > 0 && temp.g > target_color.g) temp.g = target_color.g;

        if      (ratio_b < 0 && temp.b < target_color.b) temp.b = target_color.b;
        else if (ratio_b > 0 && temp.b > target_color.b) temp.b = target_color.b;

        if      (ratio_a < 0 && temp.a < target_color.a) temp.a = target_color.a;
        else if (ratio_a > 0 && temp.a > target_color.a) temp.a = target_color.a;


        if      (temp.r < 0) temp.r = 0;
        else if (temp.r > 255) temp.r = 255;

        if      (temp.g < 0) temp.g = 0;
        else if (temp.g > 255) temp.g = 255;

        if      (temp.b < 0) temp.b = 0;
        else if (temp.b > 255) temp.b = 255;

        if      (temp.a < 0) temp.a = 0;
        else if (temp.a > 255) temp.a = 255;


        object->setOutlineColor(temp);

        return true;
    }
    else
    {
        sf::Color temp = object->getOutlineColor();



        if (object->getOutlineColor().r - (ratio_r * intensity * dt) / 2 >= 0 && object->getOutlineColor().r - (ratio_r * intensity * dt) / 2 <= 255)
            temp.r = static_cast<sf::Uint8>(object->getOutlineColor().r - (ratio_r * intensity * dt) / 2);
        if (object->getOutlineColor().g - (ratio_g * intensity * dt) / 2 >= 0 && object->getOutlineColor().g - (ratio_g * intensity * dt) / 2 <= 255)
            temp.g = static_cast<sf::Uint8>(object->getOutlineColor().g - (ratio_g * intensity * dt) / 2);
        if (object->getOutlineColor().b - (ratio_b * intensity * dt) / 2 >= 0 && object->getOutlineColor().b - (ratio_b * intensity * dt) / 2 <= 255)
            temp.b = static_cast<sf::Uint8>(object->getOutlineColor().b - (ratio_b * intensity * dt) / 2);
        if (object->getOutlineColor().a - (ratio_a * intensity * dt) >= 0 && object->getOutlineColor().a - (ratio_a * intensity * dt) <= 255)
            temp.a = static_cast<sf::Uint8>(object->getOutlineColor().a - (ratio_a * intensity * dt));



        if      (ratio_r < 0 && temp.r > basic_color.r) temp.r = basic_color.r;
        else if (ratio_r > 0 && temp.r < basic_color.r) temp.r = basic_color.r;

        if      (ratio_g < 0 && temp.g > basic_color.g) temp.g = basic_color.g;
        else if (ratio_g > 0 && temp.g < basic_color.g) temp.g = basic_color.g;

        if      (ratio_b < 0 && temp.b > basic_color.b) temp.b = basic_color.b;
        else if (ratio_b > 0 && temp.b < basic_color.b) temp.b = basic_color.b;

        if      (ratio_a < 0 && temp.a > basic_color.a) temp.a = basic_color.a;
        else if (ratio_a > 0 && temp.a < basic_color.a) temp.a = basic_color.a;




        if      (temp.r < 0) temp.r = 0;
        else if (temp.r > 255) temp.r = 255;

        if      (temp.g < 0) temp.g = 0;
        else if (temp.g > 255) temp.g = 255;

        if      (temp.b < 0) temp.b = 0;
        else if (temp.b > 255) temp.b = 255;

        if      (temp.a < 0) temp.a = 0;
        else if (temp.a > 255) temp.a = 255;



        object->setOutlineColor(temp);


        return false;
    }
}



bool SmoothTextColorChange(GuiObject* object, bool tf_argumet, sf::Vector2f& mousePosition, const sf::Color& target_color, const sf::Color& basic_color, const float intensity, const float dt)
{
    /** \brief changes color of the object's text smoothly
     *
     * \param object        GuiObject child that is going to be changed
     * \param tf_argument   true - changes to specified color
                            false - changes back to basic color
     * \param mousePosition if object is invaded by the mouse
     * \param target_color  the color that will be put on the object at the end of the change
     * \param basic_color   the color before the change
     * \param intensity     the speed of changes
     * \param dt            delta time - used to change the color independently from the user's fps
     * \return the same as tf_argument
     *
     */


    float ratio_r = target_color.r - basic_color.r;
    float ratio_g = target_color.g - basic_color.g;
    float ratio_b = target_color.b - basic_color.b;
    float ratio_a = target_color.a - basic_color.a;

    if (tf_argumet)
    {
        sf::Color temp = object->getTextColor();


        if (object->getTextColor().r + (ratio_r * intensity * dt) >= 0 && object->getTextColor().r + (ratio_r * intensity * dt) <= 255)
            temp.r = static_cast<sf::Uint8>(object->getTextColor().r + (ratio_r * intensity * dt));
        if (object->getTextColor().g + (ratio_g * intensity * dt) >= 0 && object->getTextColor().g + (ratio_g * intensity * dt) <= 255)
            temp.g = static_cast<sf::Uint8>(object->getTextColor().g + (ratio_g * intensity * dt));
        if (object->getTextColor().b + (ratio_b * intensity * dt) >= 0 && object->getTextColor().b + (ratio_b * intensity * dt) <= 255)
            temp.b = static_cast<sf::Uint8>(object->getTextColor().b + (ratio_b * intensity * dt));
        if (object->getTextColor().a + (ratio_a * intensity * dt) >= 0 && object->getTextColor().a + (ratio_a * intensity * dt) <= 255)
            temp.a = static_cast<sf::Uint8>(object->getTextColor().a + (ratio_a * intensity * dt));



        if      (ratio_r < 0 && temp.r < target_color.r) temp.r = target_color.r;
        else if (ratio_r > 0 && temp.r > target_color.r) temp.r = target_color.r;

        if      (ratio_g < 0 && temp.g < target_color.g) temp.g = target_color.g;
        else if (ratio_g > 0 && temp.g > target_color.g) temp.g = target_color.g;

        if      (ratio_b < 0 && temp.b < target_color.b) temp.b = target_color.b;
        else if (ratio_b > 0 && temp.b > target_color.b) temp.b = target_color.b;

        if      (ratio_a < 0 && temp.a < target_color.a) temp.a = target_color.a;
        else if (ratio_a > 0 && temp.a > target_color.a) temp.a = target_color.a;


        if      (temp.r < 0) temp.r = 0;
        else if (temp.r > 255) temp.r = 255;

        if      (temp.g < 0) temp.g = 0;
        else if (temp.g > 255) temp.g = 255;

        if      (temp.b < 0) temp.b = 0;
        else if (temp.b > 255) temp.b = 255;

        if      (temp.a < 0) temp.a = 0;
        else if (temp.a > 255) temp.a = 255;


        object->setTextColor(temp);

        return true;
    }
    else
    {
        sf::Color temp = object->getTextColor();



        if (object->getTextColor().r - (ratio_r * intensity * dt) / 2 >= 0 && object->getTextColor().r - (ratio_r * intensity * dt) / 2 <= 255)
            temp.r = static_cast<sf::Uint8>(object->getTextColor().r - (ratio_r * intensity * dt) / 2);
        if (object->getTextColor().g - (ratio_g * intensity * dt) / 2 >= 0 && object->getTextColor().g - (ratio_g * intensity * dt) / 2 <= 255)
            temp.g = static_cast<sf::Uint8>(object->getTextColor().g - (ratio_g * intensity * dt) / 2);
        if (object->getTextColor().b - (ratio_b * intensity * dt) / 2 >= 0 && object->getTextColor().b - (ratio_b * intensity * dt) / 2 <= 255)
            temp.b = static_cast<sf::Uint8>(object->getTextColor().b - (ratio_b * intensity * dt) / 2);
        if (object->getTextColor().a - (ratio_a * intensity * dt) >= 0 && object->getTextColor().a - (ratio_a * intensity * dt) <= 255)
            temp.a = static_cast<sf::Uint8>(object->getTextColor().a - (ratio_a * intensity * dt));



        if      (ratio_r < 0 && temp.r > basic_color.r) temp.r = basic_color.r;
        else if (ratio_r > 0 && temp.r < basic_color.r) temp.r = basic_color.r;

        if      (ratio_g < 0 && temp.g > basic_color.g) temp.g = basic_color.g;
        else if (ratio_g > 0 && temp.g < basic_color.g) temp.g = basic_color.g;

        if      (ratio_b < 0 && temp.b > basic_color.b) temp.b = basic_color.b;
        else if (ratio_b > 0 && temp.b < basic_color.b) temp.b = basic_color.b;

        if      (ratio_a < 0 && temp.a > basic_color.a) temp.a = basic_color.a;
        else if (ratio_a > 0 && temp.a < basic_color.a) temp.a = basic_color.a;




        if      (temp.r < 0) temp.r = 0;
        else if (temp.r > 255) temp.r = 255;

        if      (temp.g < 0) temp.g = 0;
        else if (temp.g > 255) temp.g = 255;

        if      (temp.b < 0) temp.b = 0;
        else if (temp.b > 255) temp.b = 255;

        if      (temp.a < 0) temp.a = 0;
        else if (temp.a > 255) temp.a = 255;



        object->setTextColor(temp);


        return false;
    }
}



bool SmoothMove(GuiObject* object, const sf::Vector2f& destination, const sf::Vector2f& start_position, const float speed, const float dt)
{
    /** \brief moves object smoothly
     *
     * \param object            GuiObject child will be moved
     * \param destination       positon where object is moved
     * \param start_position    the last stable object position, but you can use object.getPosition() if you want
     * \param speed             px / frame speed of movement
     * \param dt                delta time - used to change the color independently from the user's fps
     * \return if object was moved - true
     *
     */


    if (destination != start_position)
    {
        sf::Vector2f temp;


        const float X = destination.x - start_position.x,
                    Y = destination.y - start_position.y;

        float angle = (atan(X / Y));

        if (Y > 0)
        {
            temp.x = sin(angle) * speed * dt;
            temp.y = cos(angle) * speed * dt;

            if (Y == 0)
                temp.x = sin(angle) * speed * -dt;
        }
        else
        {
            temp.x = sin(angle) * speed * -dt;
            temp.y = cos(angle) * speed * -dt;

            if (Y == 0)
                temp.x = sin(angle) * speed * dt;
        }

        object->move(temp);


        if      (destination.x - start_position.x > 0 && object->getPosition().x > destination.x)
            object->setPosition(destination.x, object->getPosition().y);
        else if (destination.x - start_position.x < 0 && object->getPosition().x < destination.x)
            object->setPosition(destination.x, object->getPosition().y);

        if      (destination.y - start_position.y > 0 && object->getPosition().y > destination.y)
            object->setPosition(object->getPosition().x, destination.y);
        else if (destination.y - start_position.y < 0 && object->getPosition().y < destination.y)
            object->setPosition(object->getPosition().x, destination.y);

        return true;

    }
    else return false;
}


bool SmoothScale(GuiObject* object, const float target_scale, const float speed, const float dt, const float basic_scale)
{
    /** \brief scales object smoothly
     *
     * \param object        GuiObject child will be moved
     * \param target_scale  targeted scale
     * \param basic_scale   previous scale of the object
     * \param speed         px / frame speed of movement
     * \param dt            delta time - used to change the color independently from the user's fps
     * \return if object was scaled - true
     *
     */

    if (target_scale != basic_scale)
    {
        float amp = target_scale - basic_scale;

        object->scale(sf::Vector2f(1 + amp * speed * dt, 1 + amp * speed * dt));

        if (amp > 0 && object->getScale().x > target_scale)
        {
            object->setScale(sf::Vector2f(target_scale, target_scale));
            object->setScale(sf::Vector2f(target_scale, target_scale));
        }
        if (amp < 0 && object->getScale().x < target_scale)
        {
            object->setScale(sf::Vector2f(target_scale, target_scale));
            object->setScale(sf::Vector2f(target_scale, target_scale));
        }
        return true;
    }
    else
        return false;
}



bool ViewHolding(sf::View* view, sf::Mouse::Button button, const sf::Vector2f& mousePosition, sf::Event& event, const sf::Vector2f& top_left_barrier_cord, const sf::Vector2f& bottom_right_barrier_cord)
{
    /** \brief ! use one at time - static members !
                moves sf::View when user is "holding" it (like a map)
                don't really use with KEngine Slider, they don't like each other
     *
     * \param view                      sf::View that you want to make "mappy"
     * \param button                    holding this button will move the view
     * \param mousePosition             set relative to view
     * \param event                     sf::Event
     * \param top_left_barrier_cord     coordinates of top left corner of the "map"
     * \param bottom_right_barrier_cord coordinates of bottom right corner of the "map"
     * \return if button is pressed - true
     *
     */


    static bool holded;
    static sf::Vector2f viev_speed;
    static sf::Vector2f startPos;

    if (sf::Event::MouseButtonPressed && event.key.code == button)
    {
        holded = true;
        startPos = sf::Vector2f(mousePosition);
    }

    if (sf::Mouse::isButtonPressed(button) && holded)
    {
        viev_speed.x = mousePosition.x - startPos.x;
        viev_speed.y = mousePosition.y - startPos.y;
        view->move(-viev_speed.x, -viev_speed.y);
    }
    else holded = false;


    if (view->getCenter().x - view->getSize().x / 2 < top_left_barrier_cord.x) view->setCenter(top_left_barrier_cord.x + view->getSize().x / 2, view->getCenter().y);
    if (view->getCenter().y - view->getSize().y / 2 < top_left_barrier_cord.y) view->setCenter(view->getCenter().x, top_left_barrier_cord.y + view->getSize().y / 2);

    if (view->getCenter().x + view->getSize().x / 2 > bottom_right_barrier_cord.x) view->setCenter(bottom_right_barrier_cord.x - view->getSize().x / 2, view->getCenter().y);
    if (view->getCenter().y + view->getSize().y / 2 > bottom_right_barrier_cord.y) view->setCenter(view->getCenter().x, bottom_right_barrier_cord .y - view->getSize().y / 2);

    return holded;
}



bool isOutsideTheView(GuiObject* object, sf::View* view, const sf::Vector2f& shift)
{
    /** \brief checks if the given object is outside the view
     *
     * \param object    object that is being checked
     * \param view      the view here works like a collision detection line
     * \param shift     shift in pixels
     * \return if is outside - true
     *
     */


    if (object->getShapeCentre().x + object->getSize().x * object->getScale().x / 2 + shift.x < view->getCenter().x - view->getSize().x / 2)
        return true;
    if (object->getShapeCentre().x - object->getSize().x * object->getScale().x / 2 - shift.x > view->getCenter().x + view->getSize().x / 2)
        return true;
    if (object->getShapeCentre().y + object->getSize().y * object->getScale().y / 2 + shift.y < view->getCenter().y - view->getSize().y / 2)
        return true;
    if (object->getShapeCentre().y - object->getSize().y * object->getScale().y / 2 - shift.y > view->getCenter().y + view->getSize().y / 2)
        return true;
    return false;
}


bool isQuittingTheView(GuiObject* object, sf::View* view)
{
    /** \brief checks if the given object is trying to quit the view (collides with its barriers)
     *
     * \param object    object that is being checked
     * \param view      the view here works like a collision detection line
     * \return if is quitting - true
     *
     */

    if (object->getShapeCentre().x - object->getSize().x / 2 < view->getCenter().x * object->getScale().x - view->getSize().x / 2)
        return true;
    if (object->getShapeCentre().x + object->getSize().x / 2 > view->getCenter().x * object->getScale().x + view->getSize().x / 2)
        return true;
    if (object->getShapeCentre().y - object->getSize().y / 2 < view->getCenter().y * object->getScale().y - view->getSize().y / 2)
        return true;
    if (object->getShapeCentre().y + object->getSize().y / 2 > view->getCenter().y * object->getScale().y + view->getSize().y / 2)
        return true;
    return false;
}


bool HoldObject(GuiObject* object, sf::Mouse::Button button, const sf::Vector2f& mousePosition)
{
    /** \brief sets centre of the given object to position of the mouse, laggy, don't really use it a lot
     *
     * \param object            object that is being held
     * \param button            mouse button
     * \param mousePosition     position of the mouse cursor
     * \return if held - true
     *
     */

    if (sf::Mouse::isButtonPressed(button) && object->isInvaded(mousePosition))
        object->setPositionByCentre(sf::Vector2f(mousePosition.x , mousePosition.y));
}


}
