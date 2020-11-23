#ifndef BAR_HPP_INCLUDED
#define BAR_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "ObjectParent.hpp"
#include "../Data/Data.hpp"
#include "CurvedButton.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Button.hpp"

#include <iostream>
#include <cstdlib>
#include <memory>

//class ke::Circle;
//class ke::CurvedButton;

//class ke::Rectangle;
//class ke::Button;

namespace ke
{

class PercentageBar : public GuiObject
{
public:

    PercentageBar();

    PercentageBar( const sf::Vector2f& size,
                   float button_radius,
                   const sf::Vector2f& position,
                   const sf::Texture* button_texture,
                   const sf::Texture* object_texture,
                   const sf::Color& button_color = sf::Color::Transparent,
                   const sf::Color& object_color = sf::Color::Transparent,
                   float button_outline_thickness = 0,
                   const sf::Color& button_outline_color = sf::Color::Transparent,
                   float object_outline_thickness = 0,
                   const sf::Color& object_outline_color = sf::Color::Transparent,
                   bool active = true );

    PercentageBar( const sf::Vector2f& size,
                   float button_radius,
                   const sf::Vector2f& position,
                   const std::string& button_texture_path,
                   const std::string& object_texture_path,
                   const sf::Color& button_color = sf::Color::Transparent,
                   const sf::Color& object_color = sf::Color::Transparent,
                   float button_outline_thickness = 0,
                   const sf::Color& button_outline_color = sf::Color::Transparent,
                   float object_outline_thickness = 0,
                   const sf::Color& object_outline_color = sf::Color::Transparent,
                   bool active = true );

    virtual ~PercentageBar();

    PercentageBar(PercentageBar& other);
    PercentageBar& operator= (PercentageBar& other);


    void create( const sf::Vector2f& size,
                 float button_radius,
                 const sf::Vector2f& position,
                 const sf::Texture* button_texture,
                 const sf::Texture* object_texture,
                 const sf::Color& button_color = sf::Color::Transparent,
                 const sf::Color& object_color = sf::Color::Transparent,
                 float button_outline_thickness = 0,
                 const sf::Color& button_outline_color = sf::Color::Transparent,
                 float object_outline_thickness = 0,
                 const sf::Color& object_outline_color = sf::Color::Transparent,
                 bool active = true );

    void create( const sf::Vector2f& size,
                 float button_radius,
                 const sf::Vector2f& position,
                 const std::string& button_texture_path,
                 const std::string& object_texture_path,
                 const sf::Color& button_color = sf::Color::Transparent,
                 const sf::Color& object_color = sf::Color::Transparent,
                 float button_outline_thickness = 0,
                 const sf::Color& button_outline_color = sf::Color::Transparent,
                 float object_outline_thickness = 0,
                 const sf::Color& object_outline_color = sf::Color::Transparent,
                 bool active = true );


    void setPosition(const sf::Vector2f& position);
    void setPosition(float x, float y);
    sf::Vector2f getPosition() const;

    void setSize(const sf::Vector2f& size);
    void setSize(float size_x, float size_y);
    sf::Vector2f getSize() const;

    void setButtonRadius(float radius);
    float getButtonRadius() const;

    void move(const sf::Vector2f& offset);
    void move(float offset_x, float offset_y);


    void setScale(const sf::Vector2f& factors);
    void setScale(float factor_x, float factor_y);
    void setButtonScale(const sf::Vector2f& factors);
    void setButtonScale(float factor_x, float factor_y);
    void scale(const sf::Vector2f& factors);
    void scaleButton(const sf::Vector2f& factors);
    sf::Vector2f getScale() const;
    sf::Vector2f getButtonScale() const;

    void setPositionByCentre(const sf::Vector2f& position);
    sf::Vector2f getShapeCentre() const;
    sf::Vector2f getButtonCentre() const;

    void setTexture(const sf::Texture* texture);
    void setButtonTexture(const sf::Texture* texture);
    void setTexture(const std::string& texture_path);
    void setButtonTexture(const std::string& texture_path);
    const sf::Texture* getTexture() const;
    const sf::Texture* getButtonTexture() const;

    void setFillColor(const sf::Color& color = sf::Color::Transparent);
    void setButtonColor(const sf::Color& color = sf::Color::Transparent);
    const sf::Color& getFillColor() const;
    const sf::Color& getButtonColor() const;

    void setTextColor(const sf::Color& text_color = sf::Color::White);
    const sf::Color& getTextColor() const;

    void setOutlineColor(const sf::Color& outline_color = sf::Color::Transparent);
    void setOutlineButtonColor(const sf::Color& outline_color = sf::Color::Transparent);
    const sf::Color& getOutlineColor() const;
    const sf::Color& getOutlineButtonColor() const;

    void setOutlineThickness(float outline_thickness = 0);
    void setOutlineButtonThickness(float outline_thickness = 0);
    float getOutlineThickness() const;
    float getOutlineButtonThickness() const;



    bool isInvaded(const sf::Vector2f& mousePosition) const;
    bool isButtonInvaded(const sf::Vector2f& mousePosition) const;
    bool isClicked(sf::Mouse::Button button, const sf::Vector2f& mousePosition, sf::Event& event) const;
    bool isButtonClicked(sf::Mouse::Button button, const sf::Vector2f& mousePosition, sf::Event& event) const;

    bool isActive() const;
    void setActiveStatus(bool status = true);


    Circle* getColorButton();
    Circle* getTextureButton();
    CurvedButton* getObject();


    void setPercent(float percent);
    float getPercent() const;


    bool isHolded() const;
    float getShift() const;


    float update(const sf::Vector2f& mousePosition, sf::Event& event, sf::Mouse::Button button, sf::View* view);

    void render(sf::RenderWindow *window);


private:

    std::unique_ptr<Circle> t_button;
    std::unique_ptr<Circle> c_button;
    std::unique_ptr<CurvedButton> object;

    float shift;
    bool holded;

    float catchDiff;
};



////////////////////////////////////////////////////////////////////////////////////////////
//========================================================================================//
////////////////////////////////////////////////////////////////////////////////////////////



class PointBar : public GuiObject
{
public:

    PointBar();

    PointBar( const sf::Vector2f& size,
              const sf::Vector2f& position,
              const sf::Texture* texture,
              float points = 0,
              float max_points = 100,
              int origin = MIDDLE_MIDDLE,
              const sf::Color& object_color = sf::Color::Transparent,
              const sf::Color& bar_color = sf::Color::Black,
              float object_outline_thickness = 0,
              float bar_outline_thickness = 0,
              const sf::Color& object_outline_color = sf::Color::Transparent,
              const sf::Color& bar_outline_color = sf::Color::Transparent,
              bool active = true );

    PointBar( const sf::Vector2f& size,
              const sf::Vector2f& position,
              const std::string& texture_path,
              float points = 0,
              float max_points = 100,
              int origin = MIDDLE_MIDDLE,
              const sf::Color& object_color = sf::Color::Transparent,
              const sf::Color& bar_color = sf::Color::Black,
              float object_outline_thickness = 0,
              float bar_outline_thickness = 0,
              const sf::Color& object_outline_color = sf::Color::Transparent,
              const sf::Color& bar_outline_color = sf::Color::Transparent,
              bool active = true );

    virtual ~PointBar();


    PointBar(PointBar& other);
    PointBar& operator= (PointBar& other);


    void create( const sf::Vector2f& size,
                 const sf::Vector2f& position,
                 const sf::Texture* texture,
                 float points = 0,
                 float max_points = 100,
                 int origin = MIDDLE_MIDDLE,
                 const sf::Color& object_color = sf::Color::Transparent,
                 const sf::Color& bar_color = sf::Color::Black,
                 float object_outline_thickness = 0,
                 float bar_outline_thickness = 0,
                 const sf::Color& object_outline_color = sf::Color::Transparent,
                 const sf::Color& bar_outline_color = sf::Color::Transparent,
                 bool active = true );

    void create( const sf::Vector2f& size,
                 const sf::Vector2f& position,
                 const std::string& texture_path,
                 float points = 0,
                 float max_points = 100,
                 int origin = MIDDLE_MIDDLE,
                 const sf::Color& object_color = sf::Color::Transparent,
                 const sf::Color& bar_color = sf::Color::Black,
                 float object_outline_thickness = 0,
                 float bar_outline_thickness = 0,
                 const sf::Color& object_outline_color = sf::Color::Transparent,
                 const sf::Color& bar_outline_color = sf::Color::Transparent,
                 bool active = true );


    void setPosition(const sf::Vector2f& position);
    void setPosition(float x, float y);
    sf::Vector2f getPosition() const;

    void setSize(const sf::Vector2f& size);
    void setSize(float size_x, float size_y);
    sf::Vector2f getSize() const;
    sf::Vector2f getBarSize() const;

    void move(const sf::Vector2f& offset);
    void move(float offset_x, float offset_y);

    void setScale(const sf::Vector2f& factors);
    void setScale(float factor_x, float factor_y);
    void scale(const sf::Vector2f& factors);
    sf::Vector2f getScale() const;

    void setPositionByCentre(const sf::Vector2f& position);
    sf::Vector2f getShapeCentre() const;

    void setTexture(const sf::Texture* texture);
    void setTexture(const std::string& texture_path);
    const sf::Texture* getTexture() const;

    void setFillColor(const sf::Color& color = sf::Color::Transparent);
    void setBarFillColor(const sf::Color& color = sf::Color::Transparent);
    const sf::Color& getFillColor() const;
    const sf::Color& getBarFillColor() const;

    void setTextColor(const sf::Color& text_color = sf::Color::White);
    const sf::Color& getTextColor() const;

    void setOutlineColor(const sf::Color& outline_color = sf::Color::Transparent);
    void setBarOutlineColor(const sf::Color& outline_color = sf::Color::Transparent);
    const sf::Color& getOutlineColor() const;
    const sf::Color& getBarOutlineColor() const;

    void setOutlineThickness(float outline_thickness = 0);
    void setBarOutlineThickness(float outline_thickness = 0);
    float getOutlineThickness() const;
    float getBarOutlineThickness() const;



    bool isInvaded(const sf::Vector2f& mousePosition) const;
    bool isBarInvaded(const sf::Vector2f& mousePosition) const;
    bool isClicked(sf::Mouse::Button button, const sf::Vector2f& mousePosition, sf::Event& event) const;
    bool isBarClicked(sf::Mouse::Button button, const sf::Vector2f& mousePosition, sf::Event& event) const;

    bool isActive() const;
    void setActiveStatus(bool status = true);


    Rectangle* getBar();
    Button* getObject();


    void addPoint();
    void subtractPoint();

    void addPoints(float count);
    void subtractPoints(float count);

    void setPointCount(float count);
    float getPointCount() const;

    void setMaxPointCount(float max_count);
    float getMaxPointCount() const;

    float update(const sf::Vector2f& mousePosition, sf::Event& event, sf::Mouse::Button button, sf::View* view);

    void render(sf::RenderWindow *window);


private:

    std::unique_ptr<Rectangle> bar;
    std::unique_ptr<Button> object;

    float pts;
    float max_pts;
};

}

#endif // BAR_HPP_INCLUDED
