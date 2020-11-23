#ifndef TRIANGLE_HPP_INCLUDED
#define TRIANGLE_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "ObjectParent.hpp"
#include "../Data/Data.hpp"

#include <iostream>
#include <cstdlib>

#define sqrt_3 1.73205080757

namespace ke
{

class EquilTraingle : public GuiObject
{
public:

    EquilTraingle();

    EquilTraingle( float side_length,
                   const sf::Vector2f& position ,
                   int origin = MIDDLE_MIDDLE,
                   const std::wstring& text = L"",
                   unsigned int character_size = 20,
                   int text_position = MIDDLE_MIDDLE,
                   const sf::Color& object_color = sf::Color::Transparent,
                   const sf::Color& text_color = sf::Color::White,
                   float outline_thickness = 0,
                   const sf::Color& outline_color = sf::Color::Transparent,
                   unsigned int text_style = sf::Text::Regular,
                   const sf::Vector2f& text_shift = sf::Vector2f(0, 0),
                   int font = Arial,
                   bool active = true );

    EquilTraingle( float side_length,
                   const sf::Vector2f& position,
                   int origin = MIDDLE_MIDDLE,
                   const sf::Texture* texture = nullptr,
                   bool acitve = true );

    EquilTraingle( float side_length,
                   const sf::Vector2f& position,
                   int origin = MIDDLE_MIDDLE,
                   const std::string& texture_path = "",
                   bool acitve = true );

    virtual ~EquilTraingle();

    EquilTraingle(EquilTraingle& other);
    EquilTraingle& operator= (EquilTraingle& other);

    void create( float side_length,
                 const sf::Vector2f& position,
                 int origin = MIDDLE_MIDDLE,
                 const std::wstring& text = L"",
                 unsigned int character_size = 20,
                 int text_position = MIDDLE_MIDDLE,
                 const sf::Color& object_color = sf::Color::Transparent,
                 const sf::Color& text_color = sf::Color::White,
                 float outline_thickness = 0,
                 const sf::Color& outline_color = sf::Color::Transparent,
                 unsigned int text_style = sf::Text::Regular,
                 const sf::Vector2f& text_shift = sf::Vector2f(0, 0),
                 int font = Arial,
                 bool active = true );

    void create( float side_length,
                 const sf::Vector2f& position,
                 int origin = MIDDLE_MIDDLE,
                 const sf::Texture* texture = nullptr,
                 bool acitve = true );

    void create( float side_length,
                 const sf::Vector2f& position,
                 int origin = MIDDLE_MIDDLE,
                 const std::string& texture_path = "",
                 bool acitve = true );


    void setPosition(const sf::Vector2f& position);
    void setPosition(float x, float y);
    sf::Vector2f getPosition() const;

    void setSize(const sf::Vector2f& size);
    void setSize(float size_x, float size_y);
    sf::Vector2f getSize() const;

    void move(const sf::Vector2f& offset);
    void move(float offset_x, float offset_y);

    void setRadius(float radius);
    float getRadius() const;

    void setSideSize(float a);
    float getSideSize() const;

    void setText(const std::wstring& text);
    std::wstring getText() const;

    sf::CircleShape* getShape();
    sf::Text* getSfText();

    void setOrigin(int origin);
    int getOrigin() const;

    void setRotation(float angle);
    void Rotate(float angle);
    float getRotation() const;

    void setPositionByCentre(const sf::Vector2f& position);
    sf::Vector2f getShapeCentre() const;

    void setScale(const sf::Vector2f& factors);
    void setScale(float factor_x, float factor_y);
    void scale(const sf::Vector2f& factors);
    sf::Vector2f getScale() const;

    void setTexture(const sf::Texture *texture);
    void setTexture(const std::string& texture_path);
    const sf::Texture* getTexture() const;
    std::string getTexturePath() const;

    void setFillColor(const sf::Color& color = sf::Color::Transparent);
    const sf::Color& getFillColor() const;

    void setTextColor(const sf::Color& text_color = sf::Color::White);
    const sf::Color& getTextColor() const;

    void setOutlineColor(const sf::Color& outline_color = sf::Color::Transparent);
    const sf::Color& getOutlineColor() const;

    void setOutlineThickness(float outline_thickness = 0);
    float getOutlineThickness() const;

    void setTextPosition(int position, const sf::Vector2f& text_shift = sf::Vector2f(0, 0));
    int getTextPosition() const;
    sf::Vector2f getTextShift() const;

    void setTextStyle(int style);
    unsigned int getTextStyle() const;

    void setFont(int font);
    int getFont() const;

    void setCharacterSize(unsigned int char_size);
    unsigned int getCharacterSize() const;


    bool isInvaded(const sf::Vector2f& mousePosition) const;
    bool isInvaded_rect(const sf::Vector2f& mousePositon) const;
    bool isClicked(sf::Mouse::Button button, const sf::Vector2f& mousePosition, sf::Event& event) const;

    bool isActive() const;
    void setActiveStatus(bool status = true);


    float update(const sf::Vector2f& mousePosition, sf::Event& event, sf::Mouse::Button button, sf::View* view);

    void render(sf::RenderWindow* window);

private:

    void updateShape();
    void updateText();

    sf::CircleShape shape;
    sf::Text text;
    int text_font;

    float a;

    sf::Vector2f shapeCentre;
    sf::Vector2f text_shift;

    bool active;
    int origin;

    bool texture_on;
    sf::Texture texture;
    std::string texture_path;

    int text_position;
};

}

#endif // TRIANGLE_HPP_INCLUDED
