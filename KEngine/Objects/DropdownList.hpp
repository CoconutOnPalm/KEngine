#ifndef DROPDOWNLIST_HPP_INCLUDED
#define DROPDOWNLIST_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "ObjectParent.hpp"
#include "../Data/Data.hpp"
#include "Button.hpp"

#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <algorithm>

//class ke::Button;

namespace ke
{

class DropdownList // not GuiObject because DropdownList is made with Buttons and if you want to do some GuiObject functions just take is form getSelected() or getMembers() :)
{
public:

    DropdownList();

    DropdownList( const sf::Vector2f& size,
                  const sf::Vector2f& position,
                  const sf::Texture* default_texture,
                  const std::wstring& default_text = L"",
                  unsigned int default_character_size = 20,
                  int default_text_position = MIDDLE_MIDDLE,
                  const sf::Color& default_object_color = sf::Color::Transparent,
                  const sf::Color& default_text_color = sf::Color::White,
                  float default_outline_thickness = 0,
                  const sf::Color& default_outline_color = sf::Color::Transparent,
                  unsigned int default_text_style = sf::Text::Regular,
                  const sf::Vector2f& default_text_shift = sf::Vector2f(0, 0),
                  int default_font = Arial,
                  bool expanded = false,
                  bool acitve = true );

    DropdownList( const sf::Vector2f& size,
                  const sf::Vector2f& position,
                  const std::string& default_texture_path,
                  const std::wstring& default_text = L"",
                  unsigned int default_character_size = 20,
                  int default_text_position = MIDDLE_MIDDLE,
                  const sf::Color& default_object_color = sf::Color::Transparent,
                  const sf::Color& default_text_color = sf::Color::White,
                  float default_outline_thickness = 0,
                  const sf::Color& default_outline_color = sf::Color::Transparent,
                  unsigned int default_text_style = sf::Text::Regular,
                  const sf::Vector2f& default_text_shift = sf::Vector2f(0, 0),
                  int default_font = Arial,
                  bool expanded = false,
                  bool acitve = true );

    virtual ~DropdownList();


    void create( const sf::Vector2f& size,
                 const sf::Vector2f& position,
                 const sf::Texture* default_texture,
                 const std::wstring& default_text = L"",
                 unsigned int default_character_size = 20,
                 int default_text_position = MIDDLE_MIDDLE,
                 const sf::Color& default_object_color = sf::Color::Transparent,
                 const sf::Color& default_text_color = sf::Color::White,
                 float default_outline_thickness = 0,
                 const sf::Color& default_outline_color = sf::Color::Transparent,
                 unsigned int default_text_style = sf::Text::Regular,
                 const sf::Vector2f& default_text_shift = sf::Vector2f(0, 0),
                 int default_font = Arial,
                 bool expanded = false,
                 bool acitve = true );

    void create( const sf::Vector2f& size,
                 const sf::Vector2f& position,
                 const std::string& default_texture_path,
                 const std::wstring& default_text = L"",
                 unsigned int default_character_size = 20,
                 int default_text_position = MIDDLE_MIDDLE,
                 const sf::Color& default_object_color = sf::Color::Transparent,
                 const sf::Color& default_text_color = sf::Color::White,
                 float default_outline_thickness = 0,
                 const sf::Color& default_outline_color = sf::Color::Transparent,
                 unsigned int default_text_style = sf::Text::Regular,
                 const sf::Vector2f& default_text_shift = sf::Vector2f(0, 0),
                 int default_font = Arial,
                 bool expanded = false,
                 bool acitve = true );


    void addMember( const sf::Texture* texture,
                    const std::wstring& text = L"",
                    unsigned int character_size = 20,
                    int text_position = MIDDLE_MIDDLE,
                    const sf::Color& object_color = sf::Color::Transparent,
                    const sf::Color& text_color = sf::Color::White,
                    float outline_thickness = 0,
                    const sf::Color& outline_color = sf::Color::Transparent,
                    unsigned int text_style = sf::Text::Regular,
                    const sf::Vector2f& text_shift = sf::Vector2f(0, 0),
                    int font = Arial );

    void addMember( const std::string& texture_path,
                    const std::wstring& text = L"",
                    unsigned int character_size = 20,
                    int text_position = MIDDLE_MIDDLE,
                    const sf::Color& object_color = sf::Color::Transparent,
                    const sf::Color& text_color = sf::Color::White,
                    float outline_thickness = 0,
                    const sf::Color& outline_color = sf::Color::Transparent,
                    unsigned int text_style = sf::Text::Regular,
                    const sf::Vector2f& text_shift = sf::Vector2f(0, 0),
                    int font = Arial );

    void deleteList();
    void removeMember(unsigned int member_number);

    void setMemberAsActive(unsigned int member_number);

    void swapMembers(unsigned int mn_1, unsigned int mn_2);

    std::vector<std::unique_ptr<Button>>* getMembers();
    Button* getSelected();

    void updateMembersPosition();

    bool isActive() const;
    void setActiveStatus(bool status = true);


    bool isExpanded() const;
    void setExpandedStatus(bool status);


    void update(const sf::Vector2f& mousePosition, sf::Event& event, sf::Mouse::Button button, sf::View* view);


    void render(sf::RenderWindow* window);


private:

    std::unique_ptr<Button> selected;
    std::vector<std::unique_ptr<Button>> members;

    std::vector<float> member_pos;

    bool expaned;

    int m_pos_itr; // iterator to member position (in for loops is constructor and addMember)

    bool def_active;

    sf::Vector2f def_pos;
    sf::Color def_color;
    sf::Color def_text_color;
    sf::Color def_out_color;
    float def_out_thick;
    unsigned int def_text_style;
    int def_font;
};

}

#endif // DROPDOWNLIST_HPP_INCLUDED
