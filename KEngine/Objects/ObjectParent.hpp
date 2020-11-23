#pragma once

#include "../Data/Data.hpp"
#include "../Physics/Physics.hpp"
#include "../Algorithms/Algor.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>


namespace ke
{
class Physics;

class GuiObject
{
public:

    static void Init();

    GuiObject();
    virtual ~GuiObject();


    ///////////////////////

    virtual void setPosition(const sf::Vector2f& position) = 0;
    virtual void setPosition(float x, float y) = 0;
    virtual sf::Vector2f getPosition() const = 0;

    virtual void setSize(const sf::Vector2f& size) = 0;
    virtual void setSize(float size_x, float size_y) = 0;
    virtual sf::Vector2f getSize() const = 0;

    virtual void move(const sf::Vector2f& offset) = 0;
    virtual void move(float offset_x, float offset_y) = 0;

    virtual void setScale(const sf::Vector2f& factors) = 0;
    virtual void setScale(float factor_x, float factor_y) = 0;
    virtual void scale(const sf::Vector2f& factors) = 0;
    virtual sf::Vector2f getScale() const = 0;

    virtual void setPositionByCentre(const sf::Vector2f& position) = 0;
    virtual sf::Vector2f getShapeCentre() const = 0;

    virtual void setTexture(const sf::Texture* texture) = 0;
    virtual void setTexture(const std::string& texture_path) = 0;
    virtual const sf::Texture* getTexture() const = 0;

    virtual void setFillColor(const sf::Color& color = sf::Color::Transparent) = 0;
    virtual const sf::Color& getFillColor() const = 0;

    virtual void setTextColor(const sf::Color& text_color = sf::Color::White) = 0;
    virtual const sf::Color& getTextColor() const = 0;

    virtual void setOutlineColor(const sf::Color& outline_color = sf::Color::Transparent) = 0;
    virtual const sf::Color& getOutlineColor() const = 0;

    virtual void setOutlineThickness(float outline_thickness = 0) = 0;
    virtual float getOutlineThickness() const = 0;

    //virtual void setTextPosition(int position, const sf::Vector2f& text_shift = sf::Vector2f(0, 0)) = 0;
    //virtual int getTextPosition() const = 0;


    virtual bool isInvaded(const sf::Vector2f& mousePosition) const = 0;
    virtual bool isClicked(sf::Mouse::Button button, const sf::Vector2f& mousePosition, sf::Event& event) const = 0;

    virtual bool isActive() const = 0;
    virtual void setActiveStatus(bool status = true) = 0;


    virtual float update(const sf::Vector2f& mousePosition, sf::Event& event, sf::Mouse::Button button, sf::View* view) = 0;

    virtual void render(sf::RenderWindow *window) = 0;


    /*virtual void initPhysics();
    virtual void initPhysics(long double mass, float friction);

    virtual void deletePhysics();

    virtual void updatePhysics(const float dt);*/

    virtual Physics* physics();


//protected:

    //static MouseButon MB;
    static Pos TP;  // text position
    static Pos OR;  // origin
    static Font FONT; // origin
    static TextScope TS; // text scope

    static sf::Font arial;
    static sf::Font arial_uni;
    static sf::Font calibri;
    static sf::Font comic_sans;
    static sf::Font courier_new;
    static sf::Font times_new_roman;
    static sf::Font trebuchet_MS;
    static sf::Font verdana;

private:

    static bool fonts_inited;

};

//////////////////////////////////////////////////////////////////////////

//======----------                 ----------======//
// F U N C T I O N S   W I T H   G U I O B J E C T //
//======----------                 ----------======//


bool SmoothColorChange(GuiObject* object, bool tf_argumet, sf::Vector2f& mousePosition, const sf::Color& target_color, const sf::Color& basic_color, const float intensity, const float dt);
bool SmoothOutlineColorChange(GuiObject* object, bool tf_argumet, sf::Vector2f& mousePosition, const sf::Color& target_color, const sf::Color& basic_color, const float intensity, const float dt);
bool SmoothTextColorChange(GuiObject* object, bool tf_argumet, sf::Vector2f& mousePosition, const sf::Color& target_color, const sf::Color& basic_color, const float intensity, const float dt);
bool SmoothMove(GuiObject* object, const sf::Vector2f& destination, const sf::Vector2f& start_position, const float speed, const float dt);
bool SmoothScale(GuiObject* object, const float target_scale, const float speed, const float dt, const float basic_scale = 1);

bool ViewHolding(sf::View* view, sf::Mouse::Button button, const sf::Vector2f& mousePosition, sf::Event& event, const sf::Vector2f& top_left_barrier_cord = sf::Vector2f(0, 0), const sf::Vector2f& bottom_right_barrier_cord = sf::Vector2f(0, 0));

bool isOutsideTheView(GuiObject* object, sf::View* view, const sf::Vector2f& shift = sf::Vector2f(0, 0));
bool isQuittingTheView(GuiObject* object, sf::View* view);

bool HoldObject(GuiObject* object, sf::Mouse::Button button, const sf::Vector2f& mousePosition);

}
