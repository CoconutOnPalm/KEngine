#include "CurvedButton.hpp"

namespace ke
{

//-------------------------                                                         -------------------------//
//+++                                                                                                     +++//
//============== C O N S T R U C T O R S ,   D E S T R U C T O R S   A N D   O P E R A T O R S ==============//
//+++                                                                                                     +++//
//-------------------------                                                         -------------------------//


CurvedButton::CurvedButton()
{
    ///KEngine CurvedButton default constructor
    /** KEngine CurvedButton is an object based on sf::RectangleShape and
        sf::CircleShape that can hold color and texture at the same
        time and is curved like Google search button, inherits from
        class GuiObject*/
}


CurvedButton::CurvedButton( const sf::Vector2f& size,
                            const sf::Vector2f& position,
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
    ///KEngine CurvedButton constructor
    /** KEngine CurvedButton is an object based on sf::RectangleShape and
        sf::CircleShape that can hold color and texture at the same
        time and is curved like Google search button, inherits from
        class GuiObject*/

    this->texture_path = "";

    this->texture = *texture;

    this->active = active;


    this->origin = MIDDLE_MIDDLE;
    this->text_position = text_position;
    this->text_shift = text_shift;


    this->t_shape.setSize(sf::Vector2f(size.x - size.y, size.y));
    this->c_shape.setSize(sf::Vector2f(size.x - size.y, size.y));
    this->c_circle_L.setRadius(size.y / 2);
    this->c_circle_R.setRadius(size.y / 2);

    this->t_shape.setOrigin(sf::Vector2f((size.x - size.y) / 2, size.y / 2));
    this->c_shape.setOrigin(sf::Vector2f((size.x - size.y) / 2, size.y / 2));
    this->c_circle_L.setOrigin(c_circle_L.getRadius(), c_circle_L.getRadius());
    this->c_circle_R.setOrigin(c_circle_R.getRadius(), c_circle_R.getRadius());

    this->t_shape.setPosition(position);
    this->c_shape.setPosition(position);

    this->updateShape();

    this->c_shape.setFillColor(object_color);
    this->c_shape.setOutlineColor(outline_color);
    this->c_shape.setOutlineThickness(outline_thickness);
    this->c_shape.setRotation(rotation);


    this->t_shape.setTexture(&this->texture);
    this->t_shape.setFillColor(sf::Color::Black);
    this->t_shape.setRotation(rotation);

    this->c_circle_L.setFillColor(object_color);
    this->c_circle_R.setFillColor(object_color);
    this->c_circle_L.setOutlineColor(outline_color);
    this->c_circle_R.setOutlineColor(outline_color);
    this->c_circle_L.setOutlineThickness(outline_thickness);
    this->c_circle_R.setOutlineThickness(outline_thickness);



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


CurvedButton::CurvedButton( const sf::Vector2f& size,
                            const sf::Vector2f& position,
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
    ///KEngine CurvedButton create function <br>
    ///use with default constructor
    /** KEngine CurvedButton is an object based on sf::RectangleShape and
        sf::CircleShape that can hold color and texture at the same
        time and is curved like Google search button, inherits from
        class GuiObject*/

    this->texture_path = texture_path;

    this->texture.loadFromFile(texture_path);

    this->active = active;


    this->origin = origin;
    this->text_position = text_position;
    this->text_shift = text_shift;


    this->t_shape.setSize(sf::Vector2f(size.x - size.y, size.y));
    this->c_shape.setSize(sf::Vector2f(size.x - size.y, size.y));
    this->c_circle_L.setRadius(size.y / 2);
    this->c_circle_R.setRadius(size.y / 2);

    this->t_shape.setOrigin(sf::Vector2f((size.x - size.y) / 2, size.y / 2));
    this->c_shape.setOrigin(sf::Vector2f((size.x - size.y) / 2, size.y / 2));
    this->c_circle_L.setOrigin(c_circle_L.getRadius(), c_circle_L.getRadius());
    this->c_circle_R.setOrigin(c_circle_R.getRadius(), c_circle_R.getRadius());

    this->t_shape.setPosition(position);
    this->c_shape.setPosition(position);

    this->updateShape();

    this->c_shape.setFillColor(object_color);
    this->c_shape.setOutlineColor(outline_color);
    this->c_shape.setOutlineThickness(outline_thickness);
    this->c_shape.setRotation(rotation);


    this->t_shape.setTexture(&this->texture);
    this->t_shape.setFillColor(sf::Color::Black);
    this->t_shape.setRotation(rotation);

    this->c_circle_L.setFillColor(object_color);
    this->c_circle_R.setFillColor(object_color);
    this->c_circle_L.setOutlineColor(outline_color);
    this->c_circle_R.setOutlineColor(outline_color);
    this->c_circle_L.setOutlineThickness(outline_thickness);
    this->c_circle_R.setOutlineThickness(outline_thickness);



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


CurvedButton::~CurvedButton()
{
    ///KEngine CurvedButton destructor
    /** KEngine CurvedButton is an object based on sf::RectangleShape and
        sf::CircleShape that can hold color and texture at the same
        time and is curved like Google search button, inherits from
        class GuiObject*/
}



CurvedButton::CurvedButton(CurvedButton& other)
{
    ///KEngine CurvedButton copy constructor
    /** KEngine CurvedButton is an object based on sf::RectangleShape and
        sf::CircleShape that can hold color and texture at the same
        time and is curved like Google search button, inherits from
        class GuiObject*/

    this->texture_path = "";

    this->texture = *other.getTexture();

    this->active = other.isActive();


    this->origin = MIDDLE_MIDDLE;
    this->text_position = other.getTextPosition();
    this->text_shift = other.getTextShift();


    this->t_shape.setSize(sf::Vector2f(other.getSize().x - other.getSize().y, other.getSize().y));
    this->c_shape.setSize(sf::Vector2f(other.getSize().x - other.getSize().y, other.getSize().y));
    this->c_circle_L.setRadius(other.getSize().y / 2);
    this->c_circle_R.setRadius(other.getSize().y / 2);

    this->t_shape.setOrigin(sf::Vector2f((other.getSize().x - other.getSize().y) / 2, other.getSize().y / 2));
    this->c_shape.setOrigin(sf::Vector2f((other.getSize().x - other.getSize().y) / 2, other.getSize().y / 2));
    this->c_circle_L.setOrigin(c_circle_L.getRadius(), c_circle_L.getRadius());
    this->c_circle_R.setOrigin(c_circle_R.getRadius(), c_circle_R.getRadius());

    this->t_shape.setPosition(other.getPosition());
    this->c_shape.setPosition(other.getPosition());

    this->updateShape();

    this->c_shape.setFillColor(other.getFillColor());
    this->c_shape.setOutlineColor(other.getOutlineColor());
    this->c_shape.setOutlineThickness(other.getOutlineThickness());
    this->c_shape.setRotation(other.getRotation());


    this->t_shape.setTexture(&this->texture);
    this->t_shape.setFillColor(sf::Color::Black);
    this->t_shape.setRotation(other.getRotation());

    this->c_circle_L.setFillColor(other.getFillColor());
    this->c_circle_R.setFillColor(other.getFillColor());
    this->c_circle_L.setOutlineColor(other.getOutlineColor());
    this->c_circle_R.setOutlineColor(other.getOutlineColor());
    this->c_circle_L.setOutlineThickness(other.getOutlineThickness());
    this->c_circle_R.setOutlineThickness(other.getOutlineThickness());



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

    this->updateText();

    this->text.setColor(other.getTextColor());
}



CurvedButton& CurvedButton::operator= (CurvedButton& other)
{
    ///KEngine CurvedButton operator =
    /** KEngine CurvedButton is an object based on sf::RectangleShape and
        sf::CircleShape that can hold color and texture at the same
        time and is curved like Google search button, inherits from
        class GuiObject*/

    this->texture_path = "";

    this->texture = *other.getTexture();

    this->active = other.isActive();


    this->origin = MIDDLE_MIDDLE;
    this->text_position = other.getTextPosition();
    this->text_shift = other.getTextShift();


    this->t_shape.setSize(sf::Vector2f(other.getSize().x - other.getSize().y, other.getSize().y));
    this->c_shape.setSize(sf::Vector2f(other.getSize().x - other.getSize().y, other.getSize().y));
    this->c_circle_L.setRadius(other.getSize().y / 2);
    this->c_circle_R.setRadius(other.getSize().y / 2);

    this->t_shape.setOrigin(sf::Vector2f((other.getSize().x - other.getSize().y) / 2, other.getSize().y / 2));
    this->c_shape.setOrigin(sf::Vector2f((other.getSize().x - other.getSize().y) / 2, other.getSize().y / 2));
    this->c_circle_L.setOrigin(c_circle_L.getRadius(), c_circle_L.getRadius());
    this->c_circle_R.setOrigin(c_circle_R.getRadius(), c_circle_R.getRadius());

    this->t_shape.setPosition(other.getPosition());
    this->c_shape.setPosition(other.getPosition());

    this->updateShape();

    this->c_shape.setFillColor(other.getFillColor());
    this->c_shape.setOutlineColor(other.getOutlineColor());
    this->c_shape.setOutlineThickness(other.getOutlineThickness());
    this->c_shape.setRotation(other.getRotation());


    this->t_shape.setTexture(&this->texture);
    this->t_shape.setFillColor(sf::Color::Black);
    this->t_shape.setRotation(other.getRotation());

    this->c_circle_L.setFillColor(other.getFillColor());
    this->c_circle_R.setFillColor(other.getFillColor());
    this->c_circle_L.setOutlineColor(other.getOutlineColor());
    this->c_circle_R.setOutlineColor(other.getOutlineColor());
    this->c_circle_L.setOutlineThickness(other.getOutlineThickness());
    this->c_circle_R.setOutlineThickness(other.getOutlineThickness());



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

    this->updateText();

    this->text.setColor(other.getTextColor());

    return *this;
}



void CurvedButton::create( const sf::Vector2f& size,
                           const sf::Vector2f& position,
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
    ///KEngine CurvedButton constructor
    /** KEngine CurvedButton is an object based on sf::RectangleShape and
        sf::CircleShape that can hold color and texture at the same
        time and is curved like Google search button, inherits from
        class GuiObject*/

    this->texture_path = "";

    this->texture = *texture;

    this->active = active;


    this->origin = MIDDLE_MIDDLE;
    this->text_position = text_position;
    this->text_shift = text_shift;


    this->t_shape.setSize(sf::Vector2f(size.x - size.y, size.y));
    this->c_shape.setSize(sf::Vector2f(size.x - size.y, size.y));
    this->c_circle_L.setRadius(size.y / 2);
    this->c_circle_R.setRadius(size.y / 2);

    this->t_shape.setOrigin(sf::Vector2f((size.x - size.y) / 2, size.y / 2));
    this->c_shape.setOrigin(sf::Vector2f((size.x - size.y) / 2, size.y / 2));
    this->c_circle_L.setOrigin(c_circle_L.getRadius(), c_circle_L.getRadius());
    this->c_circle_R.setOrigin(c_circle_R.getRadius(), c_circle_R.getRadius());

    this->t_shape.setPosition(position);
    this->c_shape.setPosition(position);

    this->updateShape();

    this->c_shape.setFillColor(object_color);
    this->c_shape.setOutlineColor(outline_color);
    this->c_shape.setOutlineThickness(outline_thickness);
    this->c_shape.setRotation(rotation);


    this->t_shape.setTexture(&this->texture);
    this->t_shape.setFillColor(sf::Color::Black);
    this->t_shape.setRotation(rotation);

    this->c_circle_L.setFillColor(object_color);
    this->c_circle_R.setFillColor(object_color);
    this->c_circle_L.setOutlineColor(outline_color);
    this->c_circle_R.setOutlineColor(outline_color);
    this->c_circle_L.setOutlineThickness(outline_thickness);
    this->c_circle_R.setOutlineThickness(outline_thickness);



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



void CurvedButton::create( const sf::Vector2f& size,
                           const sf::Vector2f& position,
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
    ///KEngine CurvedButton create function <br>
    ///use with default constructor
    /** KEngine CurvedButton is an object based on sf::RectangleShape and
        sf::CircleShape that can hold color and texture at the same
        time and is curved like Google search button, inherits from
        class GuiObject*/

    this->texture_path = texture_path;

    this->texture.loadFromFile(texture_path);

    this->active = active;


    this->origin = origin;
    this->text_position = text_position;
    this->text_shift = text_shift;


    this->t_shape.setSize(sf::Vector2f(size.x - size.y, size.y));
    this->c_shape.setSize(sf::Vector2f(size.x - size.y, size.y));
    this->c_circle_L.setRadius(size.y / 2);
    this->c_circle_R.setRadius(size.y / 2);

    this->t_shape.setOrigin(sf::Vector2f((size.x - size.y) / 2, size.y / 2));
    this->c_shape.setOrigin(sf::Vector2f((size.x - size.y) / 2, size.y / 2));
    this->c_circle_L.setOrigin(c_circle_L.getRadius(), c_circle_L.getRadius());
    this->c_circle_R.setOrigin(c_circle_R.getRadius(), c_circle_R.getRadius());

    this->t_shape.setPosition(position);
    this->c_shape.setPosition(position);

    this->updateShape();

    this->c_shape.setFillColor(object_color);
    this->c_shape.setOutlineColor(outline_color);
    this->c_shape.setOutlineThickness(outline_thickness);
    this->c_shape.setRotation(rotation);


    this->t_shape.setTexture(&this->texture);
    this->t_shape.setFillColor(sf::Color::Black);
    this->t_shape.setRotation(rotation);

    this->c_circle_L.setFillColor(object_color);
    this->c_circle_R.setFillColor(object_color);
    this->c_circle_L.setOutlineColor(outline_color);
    this->c_circle_R.setOutlineColor(outline_color);
    this->c_circle_L.setOutlineThickness(outline_thickness);
    this->c_circle_R.setOutlineThickness(outline_thickness);



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



void CurvedButton::updateShape()
{
    ///KEngine CurvedButton private function used automatically

    this->c_circle_L.setPosition(this->t_shape.getPosition().x - this->t_shape.getSize().x * this->t_shape.getScale().x / 2, this->t_shape.getPosition().y);
    this->c_circle_R.setPosition(this->t_shape.getPosition().x + this->t_shape.getSize().x * this->t_shape.getScale().x / 2, this->t_shape.getPosition().y);
    this->shapeCentre = this->t_shape.getPosition();
}


void CurvedButton::updateText()
{
    ///KEngine CurvedButton private function used automatically

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



void CurvedButton::setPosition(const sf::Vector2f& position)
{
    ///sets KEngine CurvedButton's position

    this->t_shape.setPosition(position);
    this->c_shape.setPosition(position);

    this->updateShape();
    this->updateText();
}

void CurvedButton::setPosition(float x, float y)
{
    ///sets KEngine CurvedButton's position

    this->setPosition(sf::Vector2f(x, y));
}

sf::Vector2f CurvedButton::getPosition() const
{
    ///returns KEngine CurvedButton's position

    return this->t_shape.getPosition();
}



void CurvedButton::move(const sf::Vector2f& offset)
{
    ///moves KEngine CurvedButton by offset (px)

    this->t_shape.move(offset);
    this->c_shape.move(offset);
    this->c_circle_L.move(offset);
    this->c_circle_R.move(offset);
    this->shapeCentre = this->t_shape.getPosition();

    this->updateText();
}


void CurvedButton::move(float offset_x, float offset_y)
{
    ///moves KEngine CurvedButton by offset (px)

    this->move(sf::Vector2f(offset_x, offset_y));
}



void CurvedButton::setSize(const sf::Vector2f& size)
{
    ///sets KEngine CurvedButton size

    this->t_shape.setSize(sf::Vector2f(size.x - size.y, size.y));
    this->c_shape.setSize(sf::Vector2f(size.x - size.y, size.y));
    this->c_circle_L.setRadius(size.y / 2);
    this->c_circle_R.setRadius(size.y / 2);
    this->shapeCentre = t_shape.getPosition();

    this->t_shape.setOrigin(sf::Vector2f((size.x - size.y) / 2, size.y / 2));
    this->c_shape.setOrigin(sf::Vector2f((size.x - size.y) / 2, size.y / 2));
    this->c_circle_L.setOrigin(c_circle_L.getRadius(), c_circle_L.getRadius());
    this->c_circle_R.setOrigin(c_circle_R.getRadius(), c_circle_R.getRadius());

    this->updateShape();
}

void CurvedButton::setSize(float size_x, float size_y)
{
    ///sets KEngine CurvedButton size

    this->setSize(sf::Vector2f(size_x, size_x));
}

sf::Vector2f CurvedButton::getSize() const
{
    ///returns KEngine CurvedButton size

    return this->t_shape.getSize();
}


void CurvedButton::setText(const std::wstring& text)
{
    ///changes String of KEngine CurvedButton's text (std::wstring)

    this->text.setString(text);

    this->updateText();
}

std::wstring CurvedButton::getText() const
{
    ///returns String of KEngine CurvedButton's text (std::wstring)

    return this->text.getString();
}



sf::RectangleShape* CurvedButton::getTextureShape()
{
    ///returns pointer to sf::RectangleShape that this KEngine CurvedButton uses as texture holder

    return &t_shape;
}

sf::RectangleShape* CurvedButton::getColorShape()
{
    ///returns pointer to sf::RectangleShape that this KEngine CurvedButton uses as color holder

    return &c_shape;
}

sf::CircleShape* CurvedButton::getLeftCircle()
{
    ///returns pointer to Left sf::CircleShape that this KEngine CurvedButton uses as color holder

    return &c_circle_L;
}

sf::CircleShape* CurvedButton::getRightCircle()
{
    ///returns pointer to Right sf::CircleShape that this KEngine CurvedButton uses as color holder

    return &c_circle_R;
}

sf::Text* CurvedButton::getSfText()
{
    ///returns pointer to sf::Text that this KEngine CurvedButton uses

    return &text;
}



void CurvedButton::setOrigin(int origin)
{
    ///doing nothing, the origin of KEngine CurvedButton is always MIDDLE_MIDDLE right now

    std::cout << "changing origin is not available for CurvedButton right now\n";
}

int CurvedButton::getOrigin() const
{
    ///returns MIDDLE_MIDDLE, the origin of KEngine CurvedButton is always MIDDLE_MIDDLE right now

    return MIDDLE_MIDDLE;
}


void CurvedButton::setRotation(float angle)
{
    ///rotates, don't really use it

    this->t_shape.setRotation(angle);
    this->c_shape.setRotation(angle);
    this->text.setRotation(angle);

    std::cout << "Yeah, rotation in CurvedButton is not the best option...\n";
}

void CurvedButton::Rotate(float angle)
{
    ///rotates, don't really use it

    this->t_shape.rotate(angle);
    this->c_shape.rotate(angle);
    this->text.rotate(angle);

    std::cout << "Yeah, rotation in CurvedButton is not the best option...\n";
}

float CurvedButton::getRotation() const
{
    ///returns KEngine CurvedButton's rotation

    return this->t_shape.getRotation();
}


void CurvedButton::setPositionByCentre(const sf::Vector2f& postion)
{
    ///sets position by the centre of the object

    sf::Vector2f delta(this->t_shape.getPosition().x - this->shapeCentre.x, this->t_shape.getPosition().y - this->shapeCentre.y);

    this->setPosition(postion.x + delta.x, postion.y + delta.y);
}

sf::Vector2f CurvedButton::getShapeCentre() const
{
    ///returns center of KEngine CurvedButton

    return this->shapeCentre;
}

void CurvedButton::setScale(const sf::Vector2f& factors)
{
    ///sets KEngine CurvedButton's scale

    this->t_shape.setScale(factors);
    this->c_shape.setScale(factors);
    this->c_circle_L.setScale(factors);
    this->c_circle_R.setScale(factors);
    this->text.setScale(factors);

    this->setPosition(this->t_shape.getPosition());
}

void CurvedButton::setScale(float factor_x, float factor_y)
{
    ///sets KEngine CurvedButton's scale

    this->t_shape.setScale(factor_x, factor_y);
    this->c_shape.setScale(factor_x, factor_y);
    this->c_circle_L.setScale(factor_x, factor_y);
    this->c_circle_R.setScale(factor_x, factor_y);
    this->text.setScale(factor_x, factor_y);

    this->setPosition(this->t_shape.getPosition());
}

void CurvedButton::scale(const sf::Vector2f& factors)
{
    ///scales KEngine CurvedButton's scale

    this->t_shape.scale(factors);
    this->c_shape.scale(factors);
    this->c_circle_L.scale(factors);
    this->c_circle_R.scale(factors);
    this->text.scale(factors);

    this->setPosition(this->t_shape.getPosition());
}

sf::Vector2f CurvedButton::getScale() const
{
    ///returns scale of the KEngine CurvedButton

    return this->t_shape.getScale();
}



void CurvedButton::setTexture(const sf::Texture *texture)
{
    ///changes KEngine CurvedButton texture
    /// setting texture from other texture

    this->texture = *texture;
    this->t_shape.setTexture(&this->texture);
}


void CurvedButton::setTexture(const std::string& texture_path)
{
    ///changes KEngine CurvedButton texture
    /// setting texture directly from file

    this->texture_path = texture_path;
    this->t_shape.setTexture(&this->texture);
}

const sf::Texture *CurvedButton::getTexture() const
{
    ///returns pointer to KEngine CurvedButton's texture
    /// if there's no texture, it returns nullptr

    return this->t_shape.getTexture();
}

std::string CurvedButton::getTexturePath() const
{
    ///just don't use it

    return this->texture_path;
}


void CurvedButton::setFillColor(const sf::Color& color)
{
    ///sets KEngine CurvedButton's fill color

    this->c_shape.setFillColor(color);
    this->c_circle_L.setFillColor(color);
    this->c_circle_R.setFillColor(color);
}

const sf::Color &CurvedButton::getFillColor() const
{
    ///returns KEngine CurvedButton's fill color

    return this->c_shape.getFillColor();
}


void CurvedButton::setTextColor(const sf::Color& text_color)
{
    ///sets KEngine CurvedButton's text fill color

    this->text.setColor(text_color);
}

const sf::Color &CurvedButton::getTextColor() const
{
    ///returns KEngine CurvedButton's text fill color

    return this->text.getColor();
}


void CurvedButton::setOutlineColor(const sf::Color& outline_color)
{
    ///sets KEngine CurvedButton's outline color

    this->c_shape.setOutlineColor(outline_color);
    this->c_circle_L.setOutlineColor(outline_color);
    this->c_circle_R.setOutlineColor(outline_color);
}

const sf::Color &CurvedButton::getOutlineColor() const
{
    ///returns KEngine CurvedButton's outline color

    return this->c_shape.getOutlineColor();
}


void CurvedButton::setOutlineThickness(float outline_thickness)
{
    ///sets KEngine CurvedButton's outline thickness

    this->c_shape.setOutlineThickness(outline_thickness);
    this->c_circle_L.setOutlineThickness(outline_thickness);
    this->c_circle_R.setOutlineThickness(outline_thickness);
}

float CurvedButton::getOutlineThickness() const
{
    ///returns KEngine CurvedButton's outline thickness

    return this->c_shape.getOutlineThickness();
}


void CurvedButton::setTextPosition(int position, const sf::Vector2f& text_shift)
{
    ///sets KEngine CurvedButton's text position and text shift
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

int CurvedButton::getTextPosition() const
{
    ///returns KEngine CurvedButton's text position
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

sf::Vector2f CurvedButton::getTextShift() const
{
    ///returns KEngine CurvedButton's text shift

    return text_shift;
}


void CurvedButton::setTextStyle(int style)
{
    ///sets KEngine CurvedButton's text style

    this->text.setStyle(style);
}

unsigned int CurvedButton::getTextStyle() const
{
    ///returns KEngine CurvedButton's text style

    return this->text.getStyle();
}

void CurvedButton::setFont(int font)
{
    ///sets KEngine CurvedButton's font
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

int CurvedButton::getFont() const
{
    ///returns KEngine CurvedButton's font
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


void CurvedButton::setCharacterSize(unsigned int char_size)
{
    ///sets KEngine CurvedButton's text character size

    this->text.setCharacterSize(char_size);
}

unsigned int CurvedButton::getCharacterSize() const
{
    ///returns KEngine CurvedButton's text character size

    return text.getCharacterSize();
}



//-------------------------                                                         -------------------------//
//+++                                                                                                     +++//
//==============          R E N D E R   A N D   B E H A V I O U R   F U N C T I O N S          ==============//
//+++                                                                                                     +++//
//-------------------------                                                         -------------------------//



bool CurvedButton::isInvaded(const sf::Vector2f& mousePosition) const
{
    ///if mouse is on KEngine CurvedButton, returns true

    sf::Vector2f cirCentre_L(this->t_shape.getPosition().x - this->t_shape.getSize().x * this->t_shape.getScale().x / 2, this->t_shape.getPosition().y);
    sf::Vector2f cirCentre_R(this->t_shape.getPosition().x + this->t_shape.getSize().x * this->t_shape.getScale().x / 2, this->t_shape.getPosition().y);

    sf::Vector2f dbysc_L; // cirCentre_L - mousePosition
    dbysc_L.x = cirCentre_L.x - mousePosition.x;
    dbysc_L.y = cirCentre_L.y - mousePosition.y;
    if (dbysc_L.x < 0) dbysc_L.x = -dbysc_L.x;
    if (dbysc_L.y < 0) dbysc_L.y = -dbysc_L.y;

    sf::Vector2f dbysc_R; // cirCentre_R - mousePosition
    dbysc_R.x = cirCentre_R.x - mousePosition.x;
    dbysc_R.y = cirCentre_R.y - mousePosition.y;
    if (dbysc_R.x < 0) dbysc_R.x = -dbysc_R.x;
    if (dbysc_R.y < 0) dbysc_R.y = -dbysc_R.y;



    if (this->t_shape.getRotation() == 0 || this->t_shape.getRotation() == 90 || this->t_shape.getRotation() == 180 || this->t_shape.getRotation() == 270)
    if((mousePosition.x > this->shapeCentre.x - this->t_shape.getSize().x / 2 * this->t_shape.getScale().x &&
        mousePosition.x < this->shapeCentre.x + this->t_shape.getSize().x / 2 * this->t_shape.getScale().x &&
        mousePosition.y > this->shapeCentre.y - this->t_shape.getSize().y / 2 * this->t_shape.getScale().y &&
        mousePosition.y < this->shapeCentre.y + this->t_shape.getSize().y / 2 * this->t_shape.getScale().y)||
        (dbysc_L.x * dbysc_L.x + dbysc_L.y * dbysc_L.y < this->c_circle_L.getRadius() * this->c_circle_L.getRadius() * this->c_circle_L.getScale().x * this->c_circle_L.getScale().y) ||
        (dbysc_R.x * dbysc_R.x + dbysc_R.y * dbysc_R.y < this->c_circle_R.getRadius() * this->c_circle_R.getRadius() * this->c_circle_R.getScale().x * this->c_circle_R.getScale().y)    )

                return true;
        else    return false;
    else        return false;
}

bool CurvedButton::isClicked(sf::Mouse::Button button, const sf::Vector2f& mousePosition, sf::Event& event) const
{
    ///if mouse is on KEngine CurvedButton and the right button is clicked, returns true (use in pollEvent loop)

    if (this->isInvaded(mousePosition) && event.type == sf::Event::MouseButtonPressed && event.key.code == button)
            return true;
    else    return false;
}


bool CurvedButton::isActive() const
{
    ///if KEngine CurvedButton is displayed, returns true

    return this->active;
}

void CurvedButton::setActiveStatus(bool status)
{
    ///if KEngine CurvedButton is active, it is displayed on the screen

    this->active = status;
}




float CurvedButton::update(const sf::Vector2f& mousePosition, sf::Event& event, sf::Mouse::Button button, sf::View* view)
{
    ///rounds text position to integers

    this->text.setPosition(sf::Vector2f(static_cast<int>(this->text.getPosition().x), static_cast<int>(this->text.getPosition().y)));

    return 0;
}


void CurvedButton::render(sf::RenderWindow *window)
{
    ///displays KEngine CurvedButton on the screen, if active of course

    if (this->active)
    {
        window->draw(this->c_circle_L);
        window->draw(this->c_circle_R);
        window->draw(this->c_shape);
        window->draw(this->t_shape);
        window->draw(this->text);
    }
}

}
