#ifndef INPUTBUTTON_HPP_INCLUDED
#define INPUTBUTTON_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "ObjectParent.hpp"
#include "../Data/Data.hpp"
#include "Button.hpp"

#include <iostream>
#include <cstdlib>
#include <memory>
#include <string>

//class ke::Button;

namespace ke
{

class InputButton : public GuiObject
{
public:

    InputButton();

    InputButton( const sf::Vector2f& size,
                 const sf::Vector2f& position,
                 int origin,
                 const sf::Texture* texture,
                 const std::wstring& default_text = L"",
                 int text_scope = Everything,
                 unsigned int max_number_of_characters = 20,
                 unsigned int max_number_of_lines = 1,
                 unsigned int character_size = 20,
                 int text_position = MIDDLE_MIDDLE,
                 const sf::Color& object_color = sf::Color::Transparent,
                 const sf::Color& text_color = sf::Color::White,
                 const sf::Color& default_text_color = sf::Color::White,
                 float outline_thickness = 0,
                 const sf::Color& outline_color = sf::Color::Transparent,
                 unsigned int text_style = sf::Text::Regular,
                 const sf::Vector2f& text_shift = sf::Vector2f(0, 0),
                 int font = Arial,
                 bool active = true );

    InputButton( const sf::Vector2f& size,
                 const sf::Vector2f& position,
                 int origin,
                 const std::string& texture_path,
                 const std::wstring& default_text = L"",
                 int text_scope = Everything,
                 unsigned int max_number_of_characters = 20,
                 unsigned int max_number_of_lines = 1,
                 unsigned int character_size = 20,
                 int text_position = MIDDLE_MIDDLE,
                 const sf::Color& object_color = sf::Color::Transparent,
                 const sf::Color& text_color = sf::Color::White,
                 const sf::Color& default_text_color = sf::Color::White,
                 float outline_thickness = 0,
                 const sf::Color& outline_color = sf::Color::Transparent,
                 unsigned int text_style = sf::Text::Regular,
                 const sf::Vector2f& text_shift = sf::Vector2f(0, 0),
                 int font = Arial,
                 bool active = true );

    virtual ~InputButton();

    InputButton(InputButton& other);
    InputButton& operator= (InputButton& other);

    void create( const sf::Vector2f& size,
                 const sf::Vector2f& position,
                 int origin,
                 const sf::Texture* texture,
                 const std::wstring& default_text = L"",
                 int text_scope = Everything,
                 unsigned int max_number_of_characters = 20,
                 unsigned int max_number_of_lines = 1,
                 unsigned int character_size = 20,
                 int text_position = MIDDLE_MIDDLE,
                 const sf::Color& object_color = sf::Color::Transparent,
                 const sf::Color& text_color = sf::Color::White,
                 const sf::Color& default_text_color = sf::Color::White,
                 float outline_thickness = 0,
                 const sf::Color& outline_color = sf::Color::Transparent,
                 unsigned int text_style = sf::Text::Regular,
                 const sf::Vector2f& text_shift = sf::Vector2f(0, 0),
                 int font = Arial,
                 bool active = true );

    void create( const sf::Vector2f& size,
                 const sf::Vector2f& position,
                 int origin,
                 const std::string& texture_path,
                 const std::wstring& default_text = L"",
                 int text_scope = Everything,
                 unsigned int max_number_of_characters = 20,
                 unsigned int max_number_of_lines = 1,
                 unsigned int character_size = 20,
                 int text_position = MIDDLE_MIDDLE,
                 const sf::Color& object_color = sf::Color::Transparent,
                 const sf::Color& text_color = sf::Color::White,
                 const sf::Color& default_text_color = sf::Color::White,
                 float outline_thickness = 0,
                 const sf::Color& outline_color = sf::Color::Transparent,
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

    void setDefautText(const std::wstring& default_text);
    std::wstring getDefautText() const;

    void setTextScope(int text_scope);
    int getTextScope() const;

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
    void setDefaultTextColor(const sf::Color& text_color);
    const sf::Color& getTextColor() const;
    const sf::Color& getDefaultTextColor() const;

    void setOutlineColor(const sf::Color& outline_color = sf::Color::Transparent);
    const sf::Color& getOutlineColor() const;

    void setOutlineThickness(float outline_thickness = 0);
    float getOutlineThickness() const;

    void setTextPosition(int position, const sf::Vector2f& text_shift = sf::Vector2f(0, 0));
    int getTextPosition() const;

    void setTextStyle(int style);
    unsigned int getTextStyle() const;

    void setFont(int font);
    int getFont() const;

    void setCharacterSize(unsigned int char_size);
    unsigned int getCharacterSize() const;

    Button* getObject();

    bool isInvaded(const sf::Vector2f& mousePosition) const;
    bool isClicked(sf::Mouse::Button button, const sf::Vector2f& mousePosition, sf::Event& event) const;

    bool isActive() const;
    void setActiveStatus(bool status = true);


    void setEPS(bool status); // Entering Possibility Status
    bool getEPS() const;

    size_t getCharNum();
    unsigned int getLineNum();


    void setMaxCharacterNum(unsigned int max_char_num);
    unsigned int getMaxCharacterNum() const;

    void setMaxLineNum(unsigned int max_line_num);
    unsigned int getMaxLineNum() const;


    float update(const sf::Vector2f& mousePosition, sf::Event& event, sf::Mouse::Button button, sf::View* view);

    void render(sf::RenderWindow *window);

private:

    std::unique_ptr<Button> object;

    int text_scope;

    std::wstring imp_text;
    std::wstring def_text;
    sf::Color text_color;
    sf::Color def_text_color;

    bool possible_to_ent;

    unsigned int no_lines;

    unsigned int max_char;
    unsigned int max_lines;

};

}

#endif // INPUTBUTTON_HPP_INCLUDED
