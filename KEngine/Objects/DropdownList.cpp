#include "DropdownList.hpp"

namespace ke
{

DropdownList::DropdownList()
{
    ///KEngine DropdownList default constructor
    /** KEngine DropdownList is an object that makes you possible to
        choose one option from a list, DO NOT inherits form class
        GuiObject*/

    this->m_pos_itr = 1;

    int j = 1;
    if (members.size() >= member_pos.size())
        for (; m_pos_itr < j + 10; m_pos_itr++)
            member_pos.push_back(selected->getPosition().y + selected->getSize().y * m_pos_itr);
}


DropdownList::DropdownList( const sf::Vector2f& size,
                            const sf::Vector2f& position,
                            const sf::Texture* default_texture,
                            const std::wstring& default_text,
                            unsigned int default_character_size,
                            int default_text_position,
                            const sf::Color& default_object_color,
                            const sf::Color& default_text_color,
                            float default_outline_thickness,
                            const sf::Color& default_outline_color,
                            unsigned int default_text_style,
                            const sf::Vector2f& default_text_shift,
                            int default_font,
                            bool expanded,
                            bool active )
{
    ///KEngine DropdownList constructor
    /** KEngine DropdownList is an object that makes you possible to
        choose one option from a list, DO NOT inherits form class
        GuiObject*/

    this->selected = std::make_unique<Button>(size, position, MIDDLE_MIDDLE, default_texture, default_text, default_character_size, default_text_position, default_object_color, default_text_color, default_outline_thickness, default_outline_color, 0, default_text_style, default_text_shift, default_font, active);

    this->expaned = expanded;

    this->m_pos_itr = 1;
    this->def_active = active;

    int j = m_pos_itr;
    if (members.size() >= member_pos.size())
        for (; m_pos_itr < j + 10; m_pos_itr++)
            member_pos.push_back(selected->getPosition().y + selected->getSize().y * m_pos_itr);

    this->def_pos = position;
    this->def_color = default_object_color;
    this->def_text_color = default_text_color;
    this->def_out_color = default_outline_color;
    this->def_out_thick = default_outline_thickness;
    this->def_text_style = default_text_style;
    this->def_font = default_font;
}


DropdownList::DropdownList( const sf::Vector2f& size,
                            const sf::Vector2f& position,
                            const std::string& default_texture_path,
                            const std::wstring& default_text,
                            unsigned int default_character_size,
                            int default_text_position,
                            const sf::Color& default_object_color,
                            const sf::Color& default_text_color,
                            float default_outline_thickness,
                            const sf::Color& default_outline_color,
                            unsigned int default_text_style,
                            const sf::Vector2f& default_text_shift,
                            int default_font,
                            bool expanded,
                            bool active )
{
    ///KEngine DropdownList constructor
    /** KEngine DropdownList is an object that makes you possible to
        choose one option from a list, DO NOT inherits form class
        GuiObject*/

    this->selected = std::make_unique<Button>(size, position, MIDDLE_MIDDLE, default_texture_path, default_text, default_character_size, default_text_position, default_object_color, default_text_color, default_outline_thickness, default_outline_color, 0, default_text_style, default_text_shift, default_font, active);

    this->expaned = expanded;

    this->m_pos_itr = 1;
    this->def_active = active;

    int j = m_pos_itr;
    if (members.size() >= member_pos.size())
        for (; m_pos_itr < j + 10; m_pos_itr++)
            member_pos.push_back(selected->getPosition().y + selected->getSize().y * m_pos_itr);

    this->def_pos = position;
    this->def_color = default_object_color;
    this->def_text_color = default_text_color;
    this->def_out_color = default_outline_color;
    this->def_out_thick = default_outline_thickness;
    this->def_text_style = default_text_style;
    this->def_font = default_font;
}


DropdownList::~DropdownList()
{
    ///KEngine DropdownList destructor
    /** KEngine DropdownList is an object that makes you possible to
        choose one option from a list, DO NOT inherits form class
        GuiObject*/
}



void DropdownList::create( const sf::Vector2f& size,
                           const sf::Vector2f& position,
                           const sf::Texture* default_texture,
                           const std::wstring& default_text,
                           unsigned int default_character_size,
                           int default_text_position,
                           const sf::Color& default_object_color,
                           const sf::Color& default_text_color,
                           float default_outline_thickness,
                           const sf::Color& default_outline_color,
                           unsigned int default_text_style,
                           const sf::Vector2f& default_text_shift,
                           int default_font,
                           bool expanded,
                           bool active )
{
    ///KEngine DropdownList create function <br>
    ///use with default constructor
    /** KEngine DropdownList is an object that makes you possible to
        choose one option from a list, DO NOT inherits form class
        GuiObject*/

    this->selected = std::make_unique<Button>(size, position, MIDDLE_MIDDLE, default_texture, default_text, default_character_size, default_text_position, default_object_color, default_text_color, default_outline_thickness, default_outline_color, 0, default_text_style, default_text_shift, default_font, active);

    this->expaned = expanded;

    this->def_active = active;

    int j = m_pos_itr;
    if (members.size() >= member_pos.size())
        for (; m_pos_itr < j + 10; m_pos_itr++)
            member_pos.push_back(selected->getPosition().y + selected->getSize().y * m_pos_itr);

    this->def_pos = position;
    this->def_color = default_object_color;
    this->def_text_color = default_text_color;
    this->def_out_color = default_outline_color;
    this->def_out_thick = default_outline_thickness;
    this->def_text_style = default_text_style;
    this->def_font = default_font;
}



void DropdownList::create( const sf::Vector2f& size,
                           const sf::Vector2f& position,
                           const std::string& default_texture_path,
                           const std::wstring& default_text,
                           unsigned int default_character_size,
                           int default_text_position,
                           const sf::Color& default_object_color,
                           const sf::Color& default_text_color,
                           float default_outline_thickness,
                           const sf::Color& default_outline_color,
                           unsigned int default_text_style,
                           const sf::Vector2f& default_text_shift,
                           int default_font,
                           bool expanded,
                           bool active )
{
    ///KEngine DropdownList create function <br>
    ///use with default constructor
    /** KEngine DropdownList is an object that makes you possible to
        choose one option from a list, DO NOT inherits form class
        GuiObject*/

    this->selected = std::make_unique<Button>(size, position, MIDDLE_MIDDLE, default_texture_path, default_text, default_character_size, default_text_position, default_object_color, default_text_color, default_outline_thickness, default_outline_color, 0, default_text_style, default_text_shift, default_font, active);

    this->expaned = expanded;

    this->def_active = active;

    int j = m_pos_itr;
    if (members.size() >= member_pos.size())
        for (; m_pos_itr < j + 10; m_pos_itr++)
            member_pos.push_back(selected->getPosition().y + selected->getSize().y * m_pos_itr);

    this->def_pos = position;
    this->def_color = default_object_color;
    this->def_text_color = default_text_color;
    this->def_out_color = default_outline_color;
    this->def_out_thick = default_outline_thickness;
    this->def_text_style = default_text_style;
    this->def_font = default_font;
}




void DropdownList::addMember( const sf::Texture* texture,
                              const std::wstring& text,
                              unsigned int character_size,
                              int text_position,
                              const sf::Color& object_color,
                              const sf::Color& text_color,
                              float outline_thickness,
                              const sf::Color& outline_color,
                              unsigned int text_style,
                              const sf::Vector2f& text_shift,
                              int font )
{
    ///adds member to the list

    int j = m_pos_itr;
    if (members.size() >= member_pos.size())
        for (; m_pos_itr < j + 10; m_pos_itr++)
            member_pos.push_back(selected->getPosition().y + selected->getSize().y * m_pos_itr);

    size_t i = members.size();
    members.push_back(std::make_unique<Button>(selected->getSize(), sf::Vector2f(selected->getPosition().x, member_pos[i]), MIDDLE_MIDDLE, texture, text, character_size, text_position, object_color, text_color, outline_thickness, outline_color, 0, text_style, text_shift, font, expaned));
}


void DropdownList::addMember( const std::string& texture_path,
                              const std::wstring& text,
                              unsigned int character_size,
                              int text_position,
                              const sf::Color& object_color,
                              const sf::Color& text_color,
                              float outline_thickness,
                              const sf::Color& outline_color,
                              unsigned int text_style,
                              const sf::Vector2f& text_shift,
                              int font )
{
    ///adds member to the list

    int j = m_pos_itr;
    if (members.size() >= member_pos.size())
        for (; m_pos_itr < j + 10; m_pos_itr++)
            member_pos.push_back(selected->getPosition().y + selected->getSize().y * m_pos_itr);

    size_t i = members.size();
    members.push_back(std::make_unique<Button>(selected->getSize(), sf::Vector2f(selected->getPosition().x, member_pos[i]), MIDDLE_MIDDLE, texture_path, text, character_size, text_position, object_color, text_color, outline_thickness, outline_color, 0, text_style, text_shift, font, expaned));
}



void DropdownList::deleteList()
{
    ///deletes list

    this->members.clear();
    //this->m_pos_itr = 1;
}


void DropdownList::removeMember(unsigned int member_number)
{
    ///removes a member form the list

    if (members.size() > 0)
    {
        if (member_number >+ members.size() - 1) member_number = members.size() - 1;

        members.erase(members.begin() + member_number);

        this->updateMembersPosition();
    }
}


void DropdownList::setMemberAsActive(unsigned int member_number)
{
    ///sets member as the chosen one

    if (member_number >+ members.size() - 1) member_number = members.size() - 1;

    *this->selected = *members.at(member_number);
    this->selected->setPosition(def_pos);
    this->selected->setFillColor(def_color);
    this->selected->setTextColor(def_text_color);
    this->selected->setOutlineColor(def_out_color);
    this->selected->setOutlineThickness(def_out_thick);
    this->selected->setTextStyle(def_text_style);
    this->selected->setFont(def_font);

    this->selected->setActiveStatus(def_active);
}


void DropdownList::swapMembers(unsigned int mn_1, unsigned int mn_2)
{
    ///swaps two list members

    if (members.size() > 0)
    {
        if (mn_1 >+ members.size() - 1) mn_1 = members.size() - 1;
        if (mn_2 >+ members.size() - 1) mn_2 = members.size() - 1;

        if (mn_1 != mn_2)
        {
            std::swap(members.at(mn_1), members.at(mn_2));
            this->updateMembersPosition();
        }
    }
}


std::vector<std::unique_ptr<Button>>* DropdownList::getMembers()
{
    ///returns pointer members vector
    /** use wisely, editing member list can cause damage*/

    return &members;
}

Button* DropdownList::getSelected()
{
    ///returns the chosen one

    return selected.get();
}


void DropdownList::updateMembersPosition()
{
    ///updates members position

    size_t i = 0;

    for (auto itr = members.begin(), eoi = members.end(); itr != eoi; ++itr, i++)
        (*itr)->setPosition((*itr)->getPosition().x, member_pos[i]);
}


bool DropdownList::isActive() const
{
    ///if KEngine DropdownList is displayed, returns true

    return this->selected->isActive();
}

void DropdownList::setActiveStatus(bool status)
{
    ///if KEngine DropdownList is active, it is displayed on the screen

    this->def_active = status;

    this->selected->setActiveStatus(status);

    if (!status) this->expaned = false;
}



bool DropdownList::isExpanded() const
{
    ///if the list is expanded, returns true

    return this->expaned;
}

void DropdownList::setExpandedStatus(bool status)
{
    ///sets if the list is expanded

    this->expaned = status;

    for (auto& i : members)
        i->setActiveStatus(this->expaned);
}



void DropdownList::update(const sf::Vector2f& mousePosition, sf::Event& event, sf::Mouse::Button button, sf::View* view)
{
    ///heart of the KEngine DropdownList, use in pollEvent loop

    if (this->selected->isClicked(button, mousePosition, event))
        this->expaned = ((expaned) ? false : true);

    for (auto& i : members)
        i->setActiveStatus(this->expaned);

    this->selected->update(mousePosition, event, button, view);

    if (this->expaned)
    {
        for (auto& i : members)
        {
            if (i->isClicked(button, mousePosition, event))
            {
                *this->selected = *i;
                this->selected->setPosition(def_pos);
                this->selected->setFillColor(def_color);
                this->selected->setTextColor(def_text_color);
                this->selected->setOutlineColor(def_out_color);
                this->selected->setOutlineThickness(def_out_thick);
                this->selected->setTextStyle(def_text_style);
                this->selected->setFont(def_font);

                this->selected->setActiveStatus(def_active);
            }

            i->update(mousePosition, event, button, view);
        }
    }
}




void DropdownList::render(sf::RenderWindow* window)
{
    ///renders KEngine DropdownList on the screen

    for (auto& i : this->members)
        i->render(window);

    this->selected->setActiveStatus(1);
    selected->render(window);
}

}
