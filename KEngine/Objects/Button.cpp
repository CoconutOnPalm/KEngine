#include "Button.hpp"

namespace ke
{

//-------------------------                                                         -------------------------//
//+++                                                                                                     +++//
//============== C O N S T R U C T O R S ,   D E S T R U C T O R S   A N D   O P E R A T O R S ==============//
//+++                                                                                                     +++//
//-------------------------                                                         -------------------------//


Button::Button()
{
    ///KEngine Button default constructor
    /** KEngine Button is an object based on sf::RectangleShape that can
        hold color and texture at the same time, inherits from class
        GuiObject*/
}


Button::Button( const sf::Vector2f& size,
                const sf::Vector2f& position,
                int origin,
                const sf::Texture* texture,
                const std::wstring& text,
                unsigned int character_size,
                int text_position,
                const sf::Color& object_color,
                const sf::Color& text_color,
                float outline_thickness,
                const sf::Color& outline_color,
                float rotation,
                unsigned int text_style,
                const sf::Vector2f& text_shift,
                int font,
                bool active )
{
    ///KEngine Button constructor
    /** KEngine Button is an object based on sf::RectangleShape that can
        hold color and texture at the same time, inherits from class
        GuiObject*/

    this->texture_path = "";

    this->texture = *texture;

    this->active = active;


    this->origin = origin;
    this->text_position = text_position;
    this->text_shift = text_shift;


    this->t_shape.setSize(size);
    this->c_shape.setSize(size);
    this->c_shape.setPosition(position);
    this->t_shape.setPosition(position);

    this->updateShape();

    this->c_shape.setFillColor(object_color);
    this->c_shape.setOutlineColor(outline_color);
    this->c_shape.setOutlineThickness(outline_thickness);
    this->c_shape.setRotation(rotation);

    this->t_shape.setTexture(&this->texture);
    this->t_shape.setFillColor(sf::Color::Black);
    this->t_shape.setRotation(rotation);




    this->text.setCharacterSize(character_size);

    switch(font)
    {
    case Arial:
        {
            this->text.setFont(arial);
            this->text_font = Arial;
        }
        break;

    case Arial_Uni:
        {
            this->text.setFont(arial_uni);
            this->text_font = Arial_Uni;
        }
        break;

    case Calibri:
        {
            this->text.setFont(calibri);
            this->text_font = Calibri;
        }
        break;

    case ComicSans:
        {
            this->text.setFont(comic_sans);
            this->text_font = ComicSans;
        }
        break;

    case CourierNew:
        {
            this->text.setFont(courier_new);
            this->text_font = CourierNew;
        }
        break;

    case TimesNewRoman:
        {
            this->text.setFont(times_new_roman);
            this->text_font = TimesNewRoman;
        }
        break;

    case TrebuchetMS:
        {
            this->text.setFont(trebuchet_MS);
            this->text_font = TrebuchetMS;
        }
        break;

    case Verdana:
        {
            this->text.setFont(verdana);
            this->text_font = Verdana;
        }
        break;

    default:
        {
            this->text.setFont(arial);
            this->text_font = Arial;
        }
        break;
    }

    this->text.setStyle(text_style);
    this->text.setString(text);

    updateText();

    this->text.setColor(text_color);
}


Button::Button( const sf::Vector2f& size,
                const sf::Vector2f& position,
                int origin,
                const std::string& texture_path,
                const std::wstring& text,
                unsigned int character_size,
                int text_position,
                const sf::Color& object_color,
                const sf::Color& text_color,
                float outline_thickness,
                const sf::Color& outline_color,
                float rotation,
                unsigned int text_style,
                const sf::Vector2f& text_shift,
                int font,
                bool active )
{
    ///KEngine Button constructor
    /** KEngine Button is an object based on sf::RectangleShape that can
        hold color and texture at the same time, inherits from class
        GuiObject*/

    this->texture_path = texture_path;
    this->texture.loadFromFile(texture_path);

    this->active = active;


    this->origin = origin;
    this->text_position = text_position;
    this->text_shift = text_shift;


    this->t_shape.setSize(size);
    this->c_shape.setSize(size);
    this->t_shape.setPosition(position);
    this->c_shape.setPosition(position);

    updateShape();

    this->c_shape.setFillColor(object_color);
    this->c_shape.setOutlineColor(outline_color);
    this->c_shape.setOutlineThickness(outline_thickness);
    this->c_shape.setRotation(rotation);

    this->t_shape.setTexture(&this->texture);
    this->t_shape.setFillColor(sf::Color::Black);
    this->t_shape.setRotation(rotation);




    this->text.setCharacterSize(character_size);

    switch(font)
    {
    case Arial:
        {
            this->text.setFont(arial);
            this->text_font = Arial;
        }
        break;

    case Arial_Uni:
        {
            this->text.setFont(arial_uni);
            this->text_font = Arial_Uni;
        }
        break;

    case Calibri:
        {
            this->text.setFont(calibri);
            this->text_font = Calibri;
        }
        break;

    case ComicSans:
        {
            this->text.setFont(comic_sans);
            this->text_font = ComicSans;
        }
        break;

    case CourierNew:
        {
            this->text.setFont(courier_new);
            this->text_font = CourierNew;
        }
        break;

    case TimesNewRoman:
        {
            this->text.setFont(times_new_roman);
            this->text_font = TimesNewRoman;
        }
        break;

    case TrebuchetMS:
        {
            this->text.setFont(trebuchet_MS);
            this->text_font = TrebuchetMS;
        }
        break;

    case Verdana:
        {
            this->text.setFont(verdana);
            this->text_font = Verdana;
        }
        break;

    default:
        {
            this->text.setFont(arial);
            this->text_font = Arial;
        }
        break;
    }

    this->text.setStyle(text_style);
    this->text.setString(text);

    this->updateText();

    this->text.setColor(text_color);
}


Button::~Button()
{
    ///KEngine Button destructor
    /** KEngine Button is an object based on sf::RectangleShape that can
        hold color and texture at the same time, inherits from class
        GuiObject*/
}


Button::Button(Button& other)
{
    ///KEngine Button copy constructor
    /** KEngine Button is an object based on sf::RectangleShape that can
        hold color and texture at the same time, inherits from class
        GuiObject*/

    this->texture_path = "";

    this->texture = *other.getTexture();

    this->active = other.isActive();


    this->origin = other.getOrigin();
    this->text_position = other.getTextPosition();
    this->text_shift = other.getTextShift();


    this->t_shape.setSize(other.getSize());
    this->c_shape.setSize(other.getSize());

    updateShape();

    this->c_shape.setPosition(other.getPosition());
    this->c_shape.setFillColor(other.getFillColor());
    this->c_shape.setOutlineColor(other.getOutlineColor());
    this->c_shape.setOutlineThickness(other.getOutlineThickness());
    this->c_shape.setRotation(other.getRotation());


    this->t_shape.setPosition(other.getPosition());
    this->t_shape.setTexture(&this->texture);
    this->t_shape.setFillColor(sf::Color::Black);
    this->t_shape.setRotation(other.getRotation());





    this->text.setCharacterSize(other.getCharacterSize());

    switch(other.getFont())
    {
    case Arial:
        {
            this->text.setFont(arial);
            this->text_font = Arial;
        }
        break;

    case Arial_Uni:
        {
            this->text.setFont(arial_uni);
            this->text_font = Arial_Uni;
        }
        break;

    case Calibri:
        {
            this->text.setFont(calibri);
            this->text_font = Calibri;
        }
        break;

    case ComicSans:
        {
            this->text.setFont(comic_sans);
            this->text_font = ComicSans;
        }
        break;

    case CourierNew:
        {
            this->text.setFont(courier_new);
            this->text_font = CourierNew;
        }
        break;

    case TimesNewRoman:
        {
            this->text.setFont(times_new_roman);
            this->text_font = TimesNewRoman;
        }
        break;

    case TrebuchetMS:
        {
            this->text.setFont(trebuchet_MS);
            this->text_font = TrebuchetMS;
        }
        break;

    case Verdana:
        {
            this->text.setFont(verdana);
            this->text_font = Verdana;
        }
        break;

    default:
        {
            this->text.setFont(arial);
            this->text_font = Arial;
        }
        break;
    }

    this->text.setStyle(other.getTextStyle());
    this->text.setString(other.getText());

    updateText();

    this->text.setColor(other.getTextColor());
}


Button& Button::operator= (Button& other)
{
    ///KEngine Button operator =
    /** KEngine Button is an object based on sf::RectangleShape that can
        hold color and texture at the same time, inherits from class
        GuiObject*/

    this->texture_path = "";

    this->texture = *other.getTexture();

    this->active = other.isActive();


    this->origin = other.getOrigin();
    this->text_position = other.getTextPosition();
    this->text_shift = other.getTextShift();


    this->t_shape.setSize(other.getSize());
    this->c_shape.setSize(other.getSize());

    updateShape();

    this->c_shape.setPosition(other.getPosition());
    this->c_shape.setFillColor(other.getFillColor());
    this->c_shape.setOutlineColor(other.getOutlineColor());
    this->c_shape.setOutlineThickness(other.getOutlineThickness());
    this->c_shape.setRotation(other.getRotation());


    this->t_shape.setPosition(other.getPosition());
    this->t_shape.setTexture(&this->texture);
    this->t_shape.setFillColor(sf::Color::Black);
    this->t_shape.setRotation(other.getRotation());





    this->text.setCharacterSize(other.getCharacterSize());

    switch(other.getFont())
    {
    case Arial:
        {
            this->text.setFont(arial);
            this->text_font = Arial;
        }
        break;

    case Arial_Uni:
        {
            this->text.setFont(arial_uni);
            this->text_font = Arial_Uni;
        }
        break;

    case Calibri:
        {
            this->text.setFont(calibri);
            this->text_font = Calibri;
        }
        break;

    case ComicSans:
        {
            this->text.setFont(comic_sans);
            this->text_font = ComicSans;
        }
        break;

    case CourierNew:
        {
            this->text.setFont(courier_new);
            this->text_font = CourierNew;
        }
        break;

    case TimesNewRoman:
        {
            this->text.setFont(times_new_roman);
            this->text_font = TimesNewRoman;
        }
        break;

    case TrebuchetMS:
        {
            this->text.setFont(trebuchet_MS);
            this->text_font = TrebuchetMS;
        }
        break;

    case Verdana:
        {
            this->text.setFont(verdana);
            this->text_font = Verdana;
        }
        break;

    default:
        {
            this->text.setFont(arial);
            this->text_font = Arial;
        }
        break;
    }

    this->text.setStyle(other.getTextStyle());
    this->text.setString(other.getText());

    updateText();

    this->text.setColor(other.getTextColor());

    return *this;
}



void Button::create( const sf::Vector2f& size,
                     const sf::Vector2f& position,
                     int origin,
                     const sf::Texture* texture,
                     const std::wstring& text,
                     unsigned int character_size,
                     int text_position,
                     const sf::Color& object_color,
                     const sf::Color& text_color,
                     float outline_thickness,
                     const sf::Color& outline_color,
                     float rotation,
                     unsigned int text_style,
                     const sf::Vector2f& text_shift,
                     int font,
                     bool active )
{
    ///KEngine Button create function <br>
    ///use with default constructor
    /** KEngine Button is an object based on sf::RectangleShape that can
        hold color and texture at the same time, inherits from class
        GuiObject*/

    this->texture_path = "";

    this->texture = *texture;

    this->active = active;


    this->origin = origin;
    this->text_position = text_position;
    this->text_shift = text_shift;


    this->t_shape.setSize(size);
    this->c_shape.setSize(size);
    this->c_shape.setPosition(position);
    this->t_shape.setPosition(position);

    this->updateShape();

    this->c_shape.setFillColor(object_color);
    this->c_shape.setOutlineColor(outline_color);
    this->c_shape.setOutlineThickness(outline_thickness);
    this->c_shape.setRotation(rotation);

    this->t_shape.setTexture(&this->texture);
    this->t_shape.setFillColor(sf::Color::Black);
    this->t_shape.setRotation(rotation);




    this->text.setCharacterSize(character_size);

    switch(font)
    {
    case Arial:
        {
            this->text.setFont(arial);
            this->text_font = Arial;
        }
        break;

    case Arial_Uni:
        {
            this->text.setFont(arial_uni);
            this->text_font = Arial_Uni;
        }
        break;

    case Calibri:
        {
            this->text.setFont(calibri);
            this->text_font = Calibri;
        }
        break;

    case ComicSans:
        {
            this->text.setFont(comic_sans);
            this->text_font = ComicSans;
        }
        break;

    case CourierNew:
        {
            this->text.setFont(courier_new);
            this->text_font = CourierNew;
        }
        break;

    case TimesNewRoman:
        {
            this->text.setFont(times_new_roman);
            this->text_font = TimesNewRoman;
        }
        break;

    case TrebuchetMS:
        {
            this->text.setFont(trebuchet_MS);
            this->text_font = TrebuchetMS;
        }
        break;

    case Verdana:
        {
            this->text.setFont(verdana);
            this->text_font = Verdana;
        }
        break;

    default:
        {
            this->text.setFont(arial);
            this->text_font = Arial;
        }
        break;
    }

    this->text.setStyle(text_style);
    this->text.setString(text);

    updateText();

    this->text.setColor(text_color);
}



void Button::create( const sf::Vector2f& size,
                     const sf::Vector2f& position,
                     int origin,
                     const std::string& texture_path,
                     const std::wstring& text,
                     unsigned int character_size,
                     int text_position,
                     const sf::Color& object_color,
                     const sf::Color& text_color,
                     float outline_thickness,
                     const sf::Color& outline_color,
                     float rotation,
                     unsigned int text_style,
                     const sf::Vector2f& text_shift,
                     int font,
                     bool active )
{
    ///KEngine Button create function <br>
    ///use with default constructor
    /** KEngine Button is an object based on sf::RectangleShape that can
        hold color and texture at the same time, inherits from class
        GuiObject*/

    this->texture_path = texture_path;
    this->texture.loadFromFile(texture_path);

    this->active = active;


    this->origin = origin;
    this->text_position = text_position;
    this->text_shift = text_shift;


    this->t_shape.setSize(size);
    this->c_shape.setSize(size);
    this->t_shape.setPosition(position);
    this->c_shape.setPosition(position);

    updateShape();

    this->c_shape.setFillColor(object_color);
    this->c_shape.setOutlineColor(outline_color);
    this->c_shape.setOutlineThickness(outline_thickness);
    this->c_shape.setRotation(rotation);

    this->t_shape.setTexture(&this->texture);
    this->t_shape.setFillColor(sf::Color::Black);
    this->t_shape.setRotation(rotation);




    this->text.setCharacterSize(character_size);

    switch(font)
    {
    case Arial:
        {
            this->text.setFont(arial);
            this->text_font = Arial;
        }
        break;

    case Arial_Uni:
        {
            this->text.setFont(arial_uni);
            this->text_font = Arial_Uni;
        }
        break;

    case Calibri:
        {
            this->text.setFont(calibri);
            this->text_font = Calibri;
        }
        break;

    case ComicSans:
        {
            this->text.setFont(comic_sans);
            this->text_font = ComicSans;
        }
        break;

    case CourierNew:
        {
            this->text.setFont(courier_new);
            this->text_font = CourierNew;
        }
        break;

    case TimesNewRoman:
        {
            this->text.setFont(times_new_roman);
            this->text_font = TimesNewRoman;
        }
        break;

    case TrebuchetMS:
        {
            this->text.setFont(trebuchet_MS);
            this->text_font = TrebuchetMS;
        }
        break;

    case Verdana:
        {
            this->text.setFont(verdana);
            this->text_font = Verdana;
        }
        break;

    default:
        {
            this->text.setFont(arial);
            this->text_font = Arial;
        }
        break;
    }

    this->text.setStyle(text_style);
    this->text.setString(text);

    this->updateText();

    this->text.setColor(text_color);
}



//-------------------------                                                         -------------------------//
//+++                                                                                                     +++//
//==============                       P R I V A T E   F U N C T I O N S                       ==============//
//+++                                                                                                     +++//
//-------------------------                                                         -------------------------//



void Button::updateShape()
{
    ///KEngine Button private function used automatically

    switch(this->origin)
    {
    case LEFT_TOP:
        {
            this->shapeCentre = sf::Vector2f(this->t_shape.getPosition().x + this->t_shape.getSize().x / 2, this->t_shape.getPosition().y + this->t_shape.getSize().y / 2);
        }
        break;

    case MIDDLE_TOP:
        {
            this->t_shape.setOrigin(sf::Vector2f(this->t_shape.getSize().x / 2, 0));
            this->c_shape.setOrigin(sf::Vector2f(this->t_shape.getSize().x / 2, 0));
            this->shapeCentre = sf::Vector2f(this->t_shape.getPosition().x, this->t_shape.getPosition().y + this->t_shape.getSize().y / 2);
        }
        break;

    case RIGHT_TOP:
        {
            this->t_shape.setOrigin(sf::Vector2f(this->t_shape.getSize().x, 0));
            this->c_shape.setOrigin(sf::Vector2f(this->t_shape.getSize().x, 0));
            this->shapeCentre = sf::Vector2f(this->t_shape.getPosition().x - this->t_shape.getSize().x / 2, this->t_shape.getPosition().y + this->t_shape.getSize().y / 2);
        }
        break;

    case LEFT_MIDDLE:
        {
            this->t_shape.setOrigin(sf::Vector2f(0, this->t_shape.getSize().y / 2));
            this->c_shape.setOrigin(sf::Vector2f(0, this->t_shape.getSize().y / 2));
            this->shapeCentre = sf::Vector2f(this->t_shape.getPosition().x + this->t_shape.getSize().x / 2, this->t_shape.getPosition().y);
        }
        break;

    case MIDDLE_MIDDLE:
        {
            this->t_shape.setOrigin(sf::Vector2f(this->t_shape.getSize().x / 2, this->t_shape.getSize().y / 2));
            this->c_shape.setOrigin(sf::Vector2f(this->t_shape.getSize().x / 2, this->t_shape.getSize().y / 2));
            this->shapeCentre = this->t_shape.getPosition();
        }
        break;

    case RIGHT_MIDDLE:
        {
            this->t_shape.setOrigin(sf::Vector2f(this->t_shape.getSize().x, this->t_shape.getSize().y / 2));
            this->c_shape.setOrigin(sf::Vector2f(this->t_shape.getSize().x, this->t_shape.getSize().y / 2));
            this->shapeCentre = sf::Vector2f(this->t_shape.getPosition().x - this->t_shape.getSize().x / 2, this->t_shape.getPosition().y);
        }
        break;

    case LEFT_BOTTOM:
        {
            this->t_shape.setOrigin(sf::Vector2f(0, this->t_shape.getSize().y));
            this->c_shape.setOrigin(sf::Vector2f(0, this->t_shape.getSize().y));
            this->shapeCentre = sf::Vector2f(this->t_shape.getPosition().x + this->t_shape.getSize().x / 2, this->t_shape.getPosition().y - this->t_shape.getSize().y / 2);
        }
        break;

    case MIDDLE_BOTTOM:
        {
            this->t_shape.setOrigin(sf::Vector2f(this->t_shape.getSize().x / 2, this->t_shape.getSize().y));
            this->c_shape.setOrigin(sf::Vector2f(this->t_shape.getSize().x / 2, this->t_shape.getSize().y));
            this->shapeCentre = sf::Vector2f(this->t_shape.getPosition().x, this->t_shape.getPosition().y - this->t_shape.getSize().y / 2);
        }
        break;

    case RIGHT_BOTTOM:
        {
            this->t_shape.setOrigin(sf::Vector2f(this->t_shape.getSize().x, this->t_shape.getSize().y));
            this->c_shape.setOrigin(sf::Vector2f(this->t_shape.getSize().x, this->t_shape.getSize().y));
            this->shapeCentre = sf::Vector2f(this->t_shape.getPosition().x - this->t_shape.getSize().x / 2, this->t_shape.getPosition().y - this->t_shape.getSize().y / 2);
        }
        break;

    default:
        {
            this->shapeCentre = sf::Vector2f(this->t_shape.getPosition().x + this->t_shape.getSize().x / 2, this->t_shape.getPosition().y + this->t_shape.getSize().y / 2);
        }
        break;
    }
}


void Button::updateText()
{
    ///KEngine Button private function used automatically

    switch(this->text_position)
    {
    case LEFT_TOP:
        {
            this->text.setPosition(sf::Vector2f(this->shapeCentre.x - this->t_shape.getSize().x / 2 + text_shift.x, this->shapeCentre.y - this->t_shape.getSize().y / 2 + text_shift.y));
        }
        break;

    case MIDDLE_TOP:
        {
            this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().left + this->text.getLocalBounds().width / 2, this->text.getLocalBounds().top));
            this->text.setPosition(sf::Vector2f(this->shapeCentre.x + text_shift.x, this->shapeCentre.y - this->t_shape.getSize().y / 2 + text_shift.y));
        }
        break;

    case RIGHT_TOP:
        {
            this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().left + this->text.getLocalBounds().width, this->text.getLocalBounds().top));
            this->text.setPosition(sf::Vector2f(this->shapeCentre.x + this->t_shape.getSize().x / 2 + text_shift.x, this->shapeCentre.y - this->t_shape.getSize().y / 2 + text_shift.y));
        }
        break;

    case LEFT_MIDDLE:
        {
            this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().left, this->text.getLocalBounds().top + this->text.getLocalBounds().height / 2));
            this->text.setPosition(sf::Vector2f(this->shapeCentre.x - this->t_shape.getSize().x / 2 + text_shift.x, this->shapeCentre.y + text_shift.y));
        }
        break;

    case MIDDLE_MIDDLE:
        {
            this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().left + this->text.getLocalBounds().width / 2, this->text.getLocalBounds().top + this->text.getLocalBounds().height / 2));
            this->text.setPosition(sf::Vector2f(this->shapeCentre.x + text_shift.x, this->shapeCentre.y + text_shift.y));
        }
        break;

    case RIGHT_MIDDLE:
        {
            this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().left + this->text.getLocalBounds().width, this->text.getLocalBounds().top + this->text.getLocalBounds().height / 2));
            this->text.setPosition(sf::Vector2f(this->shapeCentre.x + this->t_shape.getSize().x / 2 + text_shift.x, this->shapeCentre.y + text_shift.y));
        }
        break;

    case LEFT_BOTTOM:
        {
            this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().left, this->text.getLocalBounds().top + this->text.getLocalBounds().height));
            this->text.setPosition(sf::Vector2f(this->shapeCentre.x - this->t_shape.getSize().x / 2 + text_shift.x, this->shapeCentre.y + this->t_shape.getSize().y / 2 + text_shift.y));
        }
        break;

    case MIDDLE_BOTTOM:
        {
            this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().left + this->text.getLocalBounds().width / 2, this->text.getLocalBounds().top + this->text.getLocalBounds().height));
            this->text.setPosition(sf::Vector2f(this->shapeCentre.x + text_shift.x, this->shapeCentre.y + this->t_shape.getSize().y / 2 + text_shift.y));
        }
        break;

    case RIGHT_BOTTOM:
        {
            this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().left + this->text.getLocalBounds().width, this->text.getLocalBounds().top + this->text.getLocalBounds().height));
            this->text.setPosition(sf::Vector2f(this->shapeCentre.x + this->t_shape.getSize().x / 2 + text_shift.x, this->shapeCentre.y + this->t_shape.getSize().y / 2 + text_shift.y));
        }
        break;

    default:
        {
            this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().left + this->text.getLocalBounds().width / 2, this->text.getLocalBounds().top));
            this->text.setPosition(sf::Vector2f(this->shapeCentre.x + text_shift.x, this->shapeCentre.y - this->t_shape.getSize().y / 2 + text_shift.y));
        }
        break;
    }
}



//-------------------------                                                         -------------------------//
//+++                                                                                                     +++//
//==============                           M O D    F U N C T I O N S                          ==============//
//+++                                                                                                     +++//
//-------------------------                                                         -------------------------//



void Button::setPosition(const sf::Vector2f& position)
{
    ///sets KEngine Button's position

    this->t_shape.setPosition(position);
    this->c_shape.setPosition(position);

    this->updateShape();
    this->updateText();
}

void Button::setPosition(float x, float y)
{
    ///sets KEngine Button's position

    this->setPosition(sf::Vector2f(x, y));
}

sf::Vector2f Button::getPosition() const
{
    ///returns KEngine Button's position

    return this->t_shape.getPosition();
}



void Button::move(const sf::Vector2f& offset)
{
    ///moves KEngine Button by offset (px)

    this->t_shape.move(offset);
    this->c_shape.move(offset);

    this->updateShape();
    this->updateText();
}


void Button::move(float offset_x, float offset_y)
{
    ///moves KEngine Button by offset (px)

    this->move(sf::Vector2f(offset_x, offset_y));
}


void Button::setSize(const sf::Vector2f& size)
{
    ///sets KEngine Button size

    this->t_shape.setSize(size);
    this->c_shape.setSize(size);
    this->setOrigin(this->origin);
}

void Button::setSize(float size_x, float size_y)
{
    ///sets KEngine Button size

    this->t_shape.setSize(sf::Vector2f(size_x, size_x));
    this->c_shape.setSize(sf::Vector2f(size_x, size_x));
    this->setOrigin(this->origin);
}

sf::Vector2f Button::getSize() const
{
    ///returns KEngine Button size

    return this->t_shape.getSize();
}


void Button::setText(const std::wstring& text)
{
    ///changes String of KEngine Button's text (std::wstring)

    this->text.setString(text);

    this->updateText();
}

std::wstring Button::getText() const
{
    ///returns String of KEngine Button's text (std::wstring)

    return this->text.getString();
}



sf::RectangleShape* Button::getTextureShape()
{
    ///returns pointer to sf::RectangleShape that this KEngine Button uses as texture holder

    return &t_shape;
}

sf::RectangleShape* Button::getColorShape()
{
    ///returns pointer to sf::RectangleShape that this KEngine Button uses as color holder

    return &c_shape;
}


sf::Text* Button::getSfText()
{
    ///returns pointer to sf::Text that this KEngine Button uses

    return &text;
}


void Button::setOrigin(int origin)
{
    ///changes origin of the KEngine Button
    /**available origins: <br>
      * RIGHT_TOP     = top right corner <br>
      * MIDDLE_TOP    = top <br>
      * LEFT_TOP      = top left corner <br>
      * RIGHT_MIDDLE  = right side <br>
      * MIDDLE_MIDDLE = center <br>
      * LEFT_MIDDLE   = left side <br>
      * RIGHT_BOTTOM  = bottom right corner <br>
      * MIDDLE_BOTTOM = bottom <br>
      * LEFT_BOTTOM   = bottom left corner*/

    this->origin = origin;

    this->updateShape();
}

int Button::getOrigin() const
{
    ///returns origin of the KEngine Button
    /**available origins: <br>
      * RIGHT_TOP     = top right corner <br>
      * MIDDLE_TOP    = top <br>
      * LEFT_TOP      = top left corner <br>
      * RIGHT_MIDDLE  = right side <br>
      * MIDDLE_MIDDLE = center <br>
      * LEFT_MIDDLE   = left side <br>
      * RIGHT_BOTTOM  = bottom right corner <br>
      * MIDDLE_BOTTOM = bottom <br>
      * LEFT_BOTTOM   = bottom left corner*/

    return this->origin;
}


void Button::setRotation(float angle)
{
    ///rotates, don't really use it

    this->t_shape.setRotation(angle);
    this->c_shape.setRotation(angle);
    this->text.setRotation(angle);
}

void Button::Rotate(float angle)
{
    ///rotates, don't really use it

    this->t_shape.rotate(angle);
    this->c_shape.rotate(angle);
    this->text.rotate(angle);
}

float Button::getRotation() const
{
    ///returns KEngine Button's rotation

    return this->t_shape.getRotation();
}


void Button::setPositionByCentre(const sf::Vector2f& postion)
{
    ///sets position by the centre of the object

    sf::Vector2f delta(this->t_shape.getPosition().x - this->shapeCentre.x, this->t_shape.getPosition().y - this->shapeCentre.y);

    this->setPosition(postion.x + delta.x, postion.y + delta.y);
}

sf::Vector2f Button::getShapeCentre() const
{
    ///returns center of KEngine Button

    return this->shapeCentre;
}

void Button::setScale(const sf::Vector2f& factors)
{
    ///sets KEngine Button's scale

    this->t_shape.setScale(factors);
    this->c_shape.setScale(factors);
    this->text.setScale(factors);
}

void Button::setScale(float factor_x, float factor_y)
{
    ///sets KEngine Button's scale

    this->t_shape.setScale(factor_x, factor_y);
    this->c_shape.setScale(factor_x, factor_y);
    this->text.setScale(factor_x, factor_y);
}

void Button::scale(const sf::Vector2f& factors)
{
    ///scales KEngine Button's scale

    this->t_shape.scale(factors);
    this->c_shape.scale(factors);
    this->text.scale(factors);
}

sf::Vector2f Button::getScale() const
{
    ///returns scale of the KEngine Button

    return this->t_shape.getScale();
}



void Button::setTexture(const sf::Texture *texture)
{
    ///changes KEngine Button texture, idk if that works
    /// setting texture from other texture

    this->texture = *texture;
    this->t_shape.setTexture(&this->texture);
}


void Button::setTexture(const std::string& texture_path)
{
    ///changes KEngine Button texture, idk if that works
    /// setting texture directly from file

    this->texture_path = texture_path;
    this->t_shape.setTexture(&this->texture);
}

const sf::Texture *Button::getTexture() const
{
    ///returns pointer to KEngine Button's texture
    /// if there's no texture, it returns nullptr

    return this->t_shape.getTexture();
}

std::string Button::getTexturePath() const
{
    ///just don't use it

    return this->texture_path;
}


void Button::setFillColor(const sf::Color& color)
{
    ///sets KEngine Button's fill color

    this->c_shape.setFillColor(color);
}

const sf::Color &Button::getFillColor() const
{
    ///returns KEngine Button's fill color

    return this->c_shape.getFillColor();
}


void Button::setTextColor(const sf::Color& text_color)
{
    ///sets KEngine Button's text fill color

    this->text.setColor(text_color);
}

const sf::Color &Button::getTextColor() const
{
    ///returns KEngine Button's text fill color

    return this->text.getColor();
}


void Button::setOutlineColor(const sf::Color& outline_color)
{
    ///sets KEngine Button's outline color

    this->c_shape.setOutlineColor(outline_color);
}

const sf::Color &Button::getOutlineColor() const
{
    ///returns KEngine Button's outline color

    return this->c_shape.getOutlineColor();
}


void Button::setOutlineThickness(float outline_thickness)
{
    ///sets KEngine Button's outline thickness

    this->c_shape.setOutlineThickness(outline_thickness);
}

float Button::getOutlineThickness() const
{
    ///returns KEngine Button's outline thickness

    return this->c_shape.getOutlineThickness();
}


void Button::setTextPosition(int position, const sf::Vector2f& text_shift)
{
    ///sets KEngine Button's text position and text shift
    /**available origins: <br>
      * RIGHT_TOP     = top right corner <br>
      * MIDDLE_TOP    = top <br>
      * LEFT_TOP      = top left corner <br>
      * RIGHT_MIDDLE  = right side <br>
      * MIDDLE_MIDDLE = center <br>
      * LEFT_MIDDLE   = left side <br>
      * RIGHT_BOTTOM  = bottom right corner <br>
      * MIDDLE_BOTTOM = bottom <br>
      * LEFT_BOTTOM   = bottom left corner*/

    this->text_position = position;
    this->text_shift = text_shift;

    this->updateText();
}

int Button::getTextPosition() const
{
    ///returns KEngine Button's text position
    /**available origins: <br>
      * RIGHT_TOP     = top right corner <br>
      * MIDDLE_TOP    = top <br>
      * LEFT_TOP      = top left corner <br>
      * RIGHT_MIDDLE  = right side <br>
      * MIDDLE_MIDDLE = center <br>
      * LEFT_MIDDLE   = left side <br>
      * RIGHT_BOTTOM  = bottom right corner <br>
      * MIDDLE_BOTTOM = bottom <br>
      * LEFT_BOTTOM   = bottom left corner*/

    return this->text_position;
}

sf::Vector2f Button::getTextShift() const
{
    ///returns KEngine Button's text shift

    return this->text_shift;
}


void Button::setTextStyle(int style)
{
    ///sets KEngine Button's text style

    this->text.setStyle(style);
}

unsigned int Button::getTextStyle() const
{
    ///returns KEngine Button's text style

    return this->text.getStyle();
}

void Button::setFont(int font)
{
    ///sets KEngine Button's font
    /**  available fonts <br>
      *  airal <br>
      *  airal unicode <br>
      *  calimbri <br>
      *  camic sans <br>
      *  courier new <br>
      *  times now roman <br>
      *  trebuchet MS <br>
      *  verdana */

    switch(font)
    {
    case Arial:
        {
            this->text.setFont(arial);
            this->text_font = Arial;
        }
        break;

    case Arial_Uni:
        {
            this->text.setFont(arial_uni);
            this->text_font = Arial_Uni;
        }
        break;

    case Calibri:
        {
            this->text.setFont(calibri);
            this->text_font = Calibri;
        }
        break;

    case ComicSans:
        {
            this->text.setFont(comic_sans);
            this->text_font = ComicSans;
        }
        break;

    case CourierNew:
        {
            this->text.setFont(courier_new);
            this->text_font = CourierNew;
        }
        break;

    case TimesNewRoman:
        {
            this->text.setFont(times_new_roman);
            this->text_font = TimesNewRoman;
        }
        break;

    case TrebuchetMS:
        {
            this->text.setFont(trebuchet_MS);
            this->text_font = TrebuchetMS;
        }
        break;

    case Verdana:
        {
            this->text.setFont(verdana);
            this->text_font = Verdana;
        }
        break;

    default:
        {
            this->text.setFont(arial);
            this->text_font = Arial;
        }
        break;
    }

    this->updateText();
}

int Button::getFont() const
{
    ///returns KEngine Button's font
    /**  available fonts <br>
      *  airal <br>
      *  airal unicode <br>
      *  calimbri <br>
      *  camic sans <br>
      *  courier new <br>
      *  times now roman <br>
      *  trebuchet MS <br>
      *  verdana */

    return this->text_font;
}


void Button::setCharacterSize(unsigned int char_size)
{
    ///sets KEngine Button's text character size

    this->text.setCharacterSize(char_size);
}

unsigned int Button::getCharacterSize() const
{
    ///returns KEngine Button's text character size

    return text.getCharacterSize();
}



//-------------------------                                                         -------------------------//
//+++                                                                                                     +++//
//==============          R E N D E R   A N D   B E H A V I O U R   F U N C T I O N S          ==============//
//+++                                                                                                     +++//
//-------------------------                                                         -------------------------//



bool Button::isInvaded(const sf::Vector2f& mousePosition) const
{
    ///if mouse is on KEngine Button, returns true

    if (this->t_shape.getRotation() == 0 || this->t_shape.getRotation() == 90 || this->t_shape.getRotation() == 180 || this->t_shape.getRotation() == 270)
    if (mousePosition.x > this->shapeCentre.x - this->t_shape.getSize().x / 2 * this->t_shape.getScale().x &&
        mousePosition.x < this->shapeCentre.x + this->t_shape.getSize().x / 2 * this->t_shape.getScale().x &&
        mousePosition.y > this->shapeCentre.y - this->t_shape.getSize().y / 2 * this->t_shape.getScale().y &&
        mousePosition.y < this->shapeCentre.y + this->t_shape.getSize().y / 2 * this->t_shape.getScale().y   )
                return true;
        else    return false;
    else        return false;
}

bool Button::isClicked(sf::Mouse::Button button, const sf::Vector2f& mousePosition, sf::Event& event) const
{
    ///if mouse is on KEngine Button and the right button is clicked, returns true (use in pollEvent loop)

    if (this->isInvaded(mousePosition) && event.type == sf::Event::MouseButtonPressed && event.key.code == button)
            return true;
    else    return false;
}


bool Button::isActive() const
{
    ///if KEngine Button is displayed, returns true

    return this->active;
}

void Button::setActiveStatus(bool status)
{
    ///if KEngine Button is active, it is displayed on the screen

    this->active = status;
}



float Button::update(const sf::Vector2f& mousePosition, sf::Event& event, sf::Mouse::Button button, sf::View* view)
{
    ///rounds text position to integers

    this->text.setPosition(static_cast<int>(this->text.getPosition().x), static_cast<int>(this->text.getPosition().y));

    return 0;
}


void Button::render(sf::RenderWindow *window)
{
    ///displays KEngine Button on the screen, if active of course

    if (this->active)
    {
        window->draw(this->c_shape);
        window->draw(this->t_shape);
        window->draw(this->text);
    }
}





void Button::initPhysics()
{
    ///initializes physics class

    m_physics = std::make_unique<Physics>(this);
}


void Button::initPhysics(long double mass, float friction)
{
    ///initializes physics class

    m_physics = std::make_unique<Physics>(this, mass, friction);
}


void Button::deletePhysics()
{
    ///deletes physics from the object

    m_physics.reset();
}


void Button::updatePhysics(const float dt)
{
    ///updates physics

    if (this->m_physics != nullptr)
        this->m_physics->update(dt);
}


Physics* Button::physics()
{
    ///returns physics class

    return m_physics.get();
}

}
