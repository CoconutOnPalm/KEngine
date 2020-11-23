#ifndef SWITCH_HPP_INCLUDED
#define SWITCH_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "ObjectParent.hpp"
#include "../Data/Data.hpp"
#include "CurvedButton.hpp"
#include "Circle.hpp"

#include <iostream>
#include <cstdlib>
#include <memory>

//class ke::Circle;
//class ke::CurvedButton;

namespace ke
{

class Switch : public GuiObject
{
public:

    Switch();

    Switch( const sf::Vector2f& size,
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

    Switch( const sf::Vector2f& size,
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

    virtual ~Switch();

    Switch(Switch& other);
    Switch& operator= (Switch& other);

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

    void setDefaultFillColor(const sf::Color& def_color);
    const sf::Color& getDefaultFillColor() const;

    void setTextColor(const sf::Color& text_color = sf::Color::White);
    const sf::Color& getTextColor() const;

    void setDefaultTextColor(const sf::Color& def_text_color);
    const sf::Color& getDefaultTextColor() const;

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


    void setSignal(bool signal);
    bool getSignal() const;


    bool isMoving() const;


    float update(const sf::Vector2f& mousePosition, sf::Event& event, sf::Mouse::Button button, sf::View* view);
    void SSC_click_update(const sf::Vector2f& mousePosition, sf::Event& event, sf::Mouse::Button button);
    float SmoothSignalChange(const sf::Vector2f& mousePosition, sf::Mouse::Button button, float speed, float dt);

    void render(sf::RenderWindow *window);


private:

    std::unique_ptr<Circle> t_button;
    std::unique_ptr<Circle> c_button;
    std::unique_ptr<CurvedButton> object;

    bool signal;
    bool moving;
};

}

#endif // SWITCH_HPP_INCLUDED
