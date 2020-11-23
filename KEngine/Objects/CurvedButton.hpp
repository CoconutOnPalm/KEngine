#ifndef CURVEDBUTTON_HPP_INCLUDED
#define CURVEDBUTTON_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "ObjectParent.hpp"
#include "../Data/Data.hpp"

#include <iostream>
#include <cstdlib>

namespace ke
{

class CurvedButton : public GuiObject
{
public:

    CurvedButton();

    CurvedButton( const sf::Vector2f& size,
                  const sf::Vector2f& position,
                  const sf::Texture* texture,
                  const std::wstring& text = L"",
                  unsigned int character_size = 20,
                  int text_position = MIDDLE_MIDDLE,
                  const sf::Color& object_color = sf::Color::Transparent,
                  const sf::Color& text_color = sf::Color::White,
                  float outline_thickness = 0,
                  const sf::Color& outline_color = sf::Color::Transparent,
                  float rotation = 0,
                  unsigned int text_style = sf::Text::Regular,
                  const sf::Vector2f& text_shift = sf::Vector2f(0, 0),
                  int font = Arial,
                  bool active = true );

    CurvedButton( const sf::Vector2f& size,
                  const sf::Vector2f& position,
                  const std::string& texture_path = "",
                  const std::wstring& text = L"",
                  unsigned int character_size = 20,
                  int text_position = MIDDLE_MIDDLE,
                  const sf::Color& object_color = sf::Color::Transparent,
                  const sf::Color& text_color = sf::Color::White,
                  float outline_thickness = 0,
                  const sf::Color& outline_color = sf::Color::Transparent,
                  float rotation = 0,
                  unsigned int text_style = sf::Text::Regular,
                  const sf::Vector2f& text_shift = sf::Vector2f(0, 0),
                  int font = Arial,
                  bool active = true );

    virtual ~CurvedButton();

    CurvedButton(CurvedButton& other);
    CurvedButton& operator= (CurvedButton& other);

    void create( const sf::Vector2f& size,
                 const sf::Vector2f& position,
                 const sf::Texture* texture,
                 const std::wstring& text = L"",
                 unsigned int character_size = 20,
                 int text_position = MIDDLE_MIDDLE,
                 const sf::Color& object_color = sf::Color::Transparent,
                 const sf::Color& text_color = sf::Color::White,
                 float outline_thickness = 0,
                 const sf::Color& outline_color = sf::Color::Transparent,
                 float rotation = 0,
                 unsigned int text_style = sf::Text::Regular,
                 const sf::Vector2f& text_shift = sf::Vector2f(0, 0),
                 int font = Arial,
                 bool active = true );

    void create( const sf::Vector2f& size,
                 const sf::Vector2f& position,
                 const std::string& texture_path = "",
                 const std::wstring& text = L"",
                 unsigned int character_size = 20,
                 int text_position = MIDDLE_MIDDLE,
                 const sf::Color& object_color = sf::Color::Transparent,
                 const sf::Color& text_color = sf::Color::White,
                 float outline_thickness = 0,
                 const sf::Color& outline_color = sf::Color::Transparent,
                 float rotation = 0,
                 unsigned int text_style = sf::Text::Regular,
                 const sf::Vector2f& text_shift = sf::Vector2f(0, 0),
                 int font = Arial,
                 bool active = true );


    void setPosition(const sf::Vector2f& position);
    void setPosition(float x, float y);
    sf::Vector2f getPosition() const;

    void setSize(const sf::Vector2f& size);
    void setSize(float size_x, float size_y);
    sf::Vector2f getSize() const;

    void move(const sf::Vector2f& offset);
    void move(float offset_x, float offset_y);

    void setText(const std::wstring& text = L"");
    std::wstring getText() const;

    sf::RectangleShape* getTextureShape();
    sf::RectangleShape* getColorShape();
    sf::CircleShape* getLeftCircle();
    sf::CircleShape* getRightCircle();
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
    bool isClicked(sf::Mouse::Button button, const sf::Vector2f& mousePosition, sf::Event& event) const;

    bool isActive() const;
    void setActiveStatus(bool status = true);


    float update(const sf::Vector2f& mousePosition, sf::Event& event, sf::Mouse::Button button, sf::View* view);

    void render(sf::RenderWindow *window);

private:

    void updateShape();
    void updateText();

    sf::RectangleShape t_shape; // texture
    sf::RectangleShape c_shape; // colour
    sf::CircleShape c_circle_L;
    sf::CircleShape c_circle_R;
    sf::Text text;
    int text_font;

    sf::Vector2f shapeCentre;
    sf::Vector2f text_shift;

    bool active;
    int origin;

    sf::Texture texture;
    std::string texture_path;

    int text_position;
};

}

#endif // CURVEDBUTTON_HPP_INCLUDED
