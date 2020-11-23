#include "Triangle.hpp"

namespace ke
{

//-------------------------                                                         -------------------------//
//+++                                                                                                     +++//
//============== C O N S T R U C T O R S ,   D E S T R U C T O R S   A N D   O P E R A T O R S ==============//
//+++                                                                                                     +++//
//-------------------------                                                         -------------------------//


EquilTraingle::EquilTraingle()
{
    ///KEngine Triangle default constructor
    /** KEngine Triangle is an object based on sf::CircleShape that can
        hold color or texture - basic object in the library, inherits from
        class GuiObject*/
}


EquilTraingle::EquilTraingle( float side_length,
                              const sf::Vector2f& position,
                              int origin,
                              const std::wstring& text,
                              unsigned int character_size,
                              int text_position,
                              const sf::Color& object_color,
                              const sf::Color& text_color,
                              float outline_thickness,
                              const sf::Color& outline_color,
                              unsigned int text_style,
                              const sf::Vector2f& text_shift,
                              int font,
                              bool active )
{
    ///KEngine Triangle color constructor
    /** KEngine Triangle is an object based on sf::CircleShape that can
        hold color or texture - basic object in the library, inherits from
        class GuiObject*/

    this->texture_path = "";
    this->texture_on = false;

    this->active = active;

    this->origin = origin;
    this->text_position = text_position;
    this->text_shift = text_shift;


    this->shape.setRadius(side_length * sqrt_3 / 3);
    this->shape.setPointCount(3);

    this-> a = side_length;
    this->shape.setPosition(position);

    this->updateShape();

    this->shape.setFillColor(object_color);
    this->shape.setOutlineColor(outline_color);
    this->shape.setOutlineThickness(outline_thickness);



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

EquilTraingle::EquilTraingle( float side_length,
                              const sf::Vector2f& position,
                              int origin,
                              const sf::Texture* texture,
                              bool acitve)
{
    ///KEngine Triangle texture constructor <br>
    /// texture loading from other texture
    /** KEngine Triangle is an object based on sf::CircleShape that can
        hold color or texture - basic object in the library, inherits from
        class GuiObject*/

    this->active = active;
    this->texture_on = true;
    this->texture_path = "";
    if (texture) this->texture = *texture;


    this->active = active;


    this->origin = origin;
    this->text_position = MIDDLE_MIDDLE;
    this->text_shift = sf::Vector2f(0, 0);


    this->shape.setRadius(side_length * sqrt_3 / 3);
    this->shape.setPointCount(3);

    this->a = side_length;
    this->shape.setPosition(position);

    this->updateShape();

    this->shape.setFillColor(sf::Color::Black);
    this->shape.setTexture(&this->texture);
}

EquilTraingle::EquilTraingle( float side_length,
                              const sf::Vector2f& position,
                              int origin,
                              const std::string& texture_path,
                              bool acitve)
{
    ///KEngine Triangle texture constructor <br>
    /// texture loading directly from file
    /** KEngine Triangle is an object based on sf::CircleShape that can
        hold color or texture - basic object in the library, inherits from
        class GuiObject*/

    this->active = active;
    this->texture_on = true;
    this->texture_path = "";
    this->texture.loadFromFile(texture_path);


    this->active = active;


    this->origin = origin;
    this->text_position = MIDDLE_MIDDLE;
    this->text_shift = sf::Vector2f(0, 0);


    this->shape.setRadius(side_length * sqrt_3 / 3);
    this->shape.setPointCount(3);

    this->a = side_length;
    this->shape.setPosition(position);

    this->updateShape();

    this->shape.setFillColor(sf::Color::Black);
    this->shape.setTexture(&this->texture);
}

EquilTraingle::~EquilTraingle()
{
    ///KEngine Triangle destructor
    /** KEngine Triangle is an object based on sf::CircleShape that can
        hold color or texture - basic object in the library, inherits from
        class GuiObject*/
}


EquilTraingle::EquilTraingle(EquilTraingle& other)
{
    ///KEngine Triangle copy constructor
    /** KEngine Triangle is an object based on sf::CircleShape that can
        hold color or texture - basic object in the library, inherits from
        class GuiObject*/

    this->texture_path = "";
    this->texture_on = false;

    this->active = other.isActive();

    this->origin = other.getOrigin();
    this->text_position = other.getTextPosition();
    this->text_shift = other.getTextShift();


    this->shape.setRadius(other.getRadius());
    this->shape.setPointCount(3);

    this-> a = other.getSideSize();

    this->updateShape();

    this->shape.setPosition(other.getPosition());
    this->shape.setFillColor(other.getFillColor());
    this->shape.setOutlineColor(other.getOutlineColor());
    this->shape.setOutlineThickness(other.getOutlineThickness());


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


EquilTraingle& EquilTraingle::operator= (EquilTraingle& other)
{
    ///KEngine Triangle operator =
    /** KEngine Triangle is an object based on sf::CircleShape that can
        hold color or texture - basic object in the library, inherits from
        class GuiObject*/

    this->texture_path = "";
    this->texture_on = false;

    this->active = other.isActive();

    this->origin = other.getOrigin();
    this->text_position = other.getTextPosition();
    this->text_shift = other.getTextShift();


    this->shape.setRadius(other.getRadius());
    this->shape.setPointCount(3);

    this-> a = other.getSideSize();

    this->updateShape();

    this->shape.setPosition(other.getPosition());
    this->shape.setFillColor(other.getFillColor());
    this->shape.setOutlineColor(other.getOutlineColor());
    this->shape.setOutlineThickness(other.getOutlineThickness());


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


void EquilTraingle::create( float side_length,
                              const sf::Vector2f& position,
                              int origin,
                              const std::wstring& text,
                              unsigned int character_size,
                              int text_position,
                              const sf::Color& object_color,
                              const sf::Color& text_color,
                              float outline_thickness,
                              const sf::Color& outline_color,
                              unsigned int text_style,
                              const sf::Vector2f& text_shift,
                              int font,
                              bool active )
{
    ///KEngine Triangle color create function <br>
    ///use with default constructor
    /** KEngine Triangle is an object based on sf::CircleShape that can
        hold color or texture - basic object in the library, inherits from
        class GuiObject*/

    this->texture_path = "";
    this->texture_on = false;

    this->active = active;

    this->origin = origin;
    this->text_position = text_position;
    this->text_shift = text_shift;


    this->shape.setRadius(side_length * sqrt_3 / 3);
    this->shape.setPointCount(3);

    this-> a = side_length;
    this->shape.setPosition(position);

    this->updateShape();

    this->shape.setFillColor(object_color);
    this->shape.setOutlineColor(outline_color);
    this->shape.setOutlineThickness(outline_thickness);



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


void EquilTraingle::create( float side_length,
                            const sf::Vector2f& position,
                            int origin,
                            const sf::Texture* texture,
                            bool acitve)
{
    ///KEngine Triangle texture create function <br>
    ///use with default constructor <br>
    /// texture loading from other texture
    /** KEngine Triangle is an object based on sf::CircleShape that can
        hold color or texture - basic object in the library, inherits from
        class GuiObject*/

    this->active = active;
    this->texture_on = true;
    this->texture_path = "";
    if (texture) this->texture = *texture;


    this->active = active;


    this->origin = origin;
    this->text_position = MIDDLE_MIDDLE;
    this->text_shift = sf::Vector2f(0, 0);


    this->shape.setRadius(side_length * sqrt_3 / 3);
    this->shape.setPointCount(3);

    this->a = side_length;
    this->shape.setPosition(position);

    this->updateShape();

    this->shape.setFillColor(sf::Color::Black);
    this->shape.setTexture(&this->texture);
}


void EquilTraingle::create( float side_length,
                            const sf::Vector2f& position,
                            int origin,
                            const std::string& texture_path,
                            bool acitve)
{
    ///KEngine Triangle texture create function <br>
    ///use with default constructor <br>
    /// texture loading directly from file
    /** KEngine Triangle is an object based on sf::CircleShape that can
        hold color or texture - basic object in the library, inherits from
        class GuiObject*/

    this->active = active;
    this->texture_on = true;
    this->texture_path = "";
    this->texture.loadFromFile(texture_path);


    this->active = active;


    this->origin = origin;
    this->text_position = MIDDLE_MIDDLE;
    this->text_shift = sf::Vector2f(0, 0);


    this->shape.setRadius(side_length * sqrt_3 / 3);
    this->shape.setPointCount(3);

    this->a = side_length;
    this->shape.setPosition(position);

    this->updateShape();

    this->shape.setFillColor(sf::Color::Black);
    this->shape.setTexture(&this->texture);
}



//-------------------------                                                         -------------------------//
//+++                                                                                                     +++//
//==============                       P R I V A T E   F U N C T I O N S                       ==============//
//+++                                                                                                     +++//
//-------------------------                                                         -------------------------//



void EquilTraingle::updateShape()
{
    ///KEngine Triangle private function used automatically

    switch(this->origin)
    {
    case MIDDLE_TOP:
        {
            this->shape.setOrigin(sf::Vector2f(this->shape.getRadius(), 0));
            this->shapeCentre = sf::Vector2f(this->shape.getPosition().x, this->shape.getPosition().y + this->shape.getRadius());
        }
        break;

    case MIDDLE_MIDDLE:
        {
            this->shape.setOrigin(sf::Vector2f(this->shape.getRadius(), this->shape.getRadius()));
            this->shapeCentre = this->shape.getPosition();
        }
        break;

    case LEFT_BOTTOM:
        {
            this->shape.setOrigin(sf::Vector2f(0, a * sqrt_3 / 2));
            this->shapeCentre = sf::Vector2f(this->shape.getPosition().x + this->shape.getRadius(), this->shape.getPosition().y - a * sqrt_3 / 6);
        }
        break;

    case MIDDLE_BOTTOM:
        {
            this->shape.setOrigin(sf::Vector2f(this->shape.getRadius(), a * sqrt_3 / 2));
            this->shapeCentre = sf::Vector2f(this->shape.getPosition().x, this->shape.getPosition().y - a * sqrt_3 / 6);
        }
        break;

    case RIGHT_BOTTOM:
        {
            this->shape.setOrigin(sf::Vector2f(this->shape.getRadius() * 2, a * sqrt_3 / 2));
            this->shapeCentre = sf::Vector2f(this->shape.getPosition().x - this->shape.getRadius(), this->shape.getPosition().y - shape.getRadius() / 2);
        }
        break;

    default:
        {
            this->shape.setOrigin(sf::Vector2f(a / 2, this->shape.getRadius()));
            this->shapeCentre = this->shape.getPosition();
        }
        break;
    }
}


void EquilTraingle::updateText()
{
    ///KEngine Triangle private function used automatically

    switch (text_position)
    {
    case MIDDLE_MIDDLE:
        {
            this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().left + this->text.getLocalBounds().width / 2, this->text.getLocalBounds().top + this->text.getLocalBounds().height / 2));
            this->text.setPosition(sf::Vector2f(this->shapeCentre.x + text_shift.x, this->shapeCentre.y + text_shift.y));
        }
        break;

    case MIDDLE_BOTTOM:
        {
            this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().left + this->text.getLocalBounds().width / 2, this->text.getLocalBounds().top + this->text.getLocalBounds().height));
            this->text.setPosition(sf::Vector2f(this->shapeCentre.x + text_shift.x, this->shapeCentre.y + a * sqrt_3 / 6 + text_shift.y));
        }
        break;

    default:
        {
            this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().left + this->text.getLocalBounds().width / 2, this->text.getLocalBounds().top + this->text.getLocalBounds().height / 2));
            this->text.setPosition(sf::Vector2f(this->shapeCentre.x + text_shift.x, this->shapeCentre.y + text_shift.y));
        }
        break;
    }
}




//-------------------------                                                         -------------------------//
//+++                                                                                                     +++//
//==============                           M O D    F U N C T I O N S                          ==============//
//+++                                                                                                     +++//
//-------------------------                                                         -------------------------//




void EquilTraingle::setPosition(const sf::Vector2f& position)
{
    ///sets KEngine Triangle's position

    this->shape.setPosition(position);

    this->updateShape();
    this->updateText();
}

void EquilTraingle::setPosition(float x, float y)
{
    ///sets KEngine Triangle's position

    this->setPosition(sf::Vector2f(x, y));
}

sf::Vector2f EquilTraingle::getPosition() const
{
    ///returns KEngine Triangle's position

    return this->shape.getPosition();
}


void EquilTraingle::setSize(const sf::Vector2f& size)
{
    ///sets KEngine Triangle size

    this->setSideSize(size.x);
    this->setOrigin(this->origin);
}

void EquilTraingle::setSize(float size_x, float size_y)
{
    ///sets KEngine Triangle size

    this->setSideSize(size_x);
    this->setOrigin(this->origin);
}

sf::Vector2f EquilTraingle::getSize() const
{
    ///returns KEngine Triangle size

    sf::Vector2f temp(this->a, this->a * sqrt_3 / 2);

    return temp;
}


void EquilTraingle::move(const sf::Vector2f& offset)
{
    ///moves KEngine Triangle by offset (px)

    this->shape.move(offset);

    this->updateShape();
    this->updateText();
}

void EquilTraingle::move(float offset_x, float offset_y)
{
    ///moves KEngine Triangle by offset (px)

    this->move(sf::Vector2f(offset_x, offset_y));
}


void EquilTraingle::setRadius(float radius)
{
    ///sets radius of KEngine Triangle

    this->shape.setRadius(radius);

    this->updateShape();
    this->updateText();
}

float EquilTraingle::getRadius() const
{
    ///returns radius of KEngine Triangle

    return this->shape.getRadius();
}

void EquilTraingle::setSideSize(float a)
{
    ///sets length of the KEngine Circle's side

    this->shape.setRadius(a * sqrt_3 / 3);

    this->updateShape();
    this->updateText();
}

float EquilTraingle::getSideSize() const
{
    ///returns length of the KEngine Circle's side

    return 3 * this->shape.getRadius() / sqrt_3;
}

void EquilTraingle::setText(const std::wstring& text)
{
    ///changes String of KEngine Triangle's text (std::wstring)

    this->text.setString(text);
    this->updateText();
}

std::wstring EquilTraingle::getText() const
{
    ///returns String of KEngine Triangle's text (std::wstring)

    return this->text.getString();
}

sf::CircleShape* EquilTraingle::getShape()
{
    ///returns pointer to sf::CircleShape that this KEngine Triangle uses

    return &shape;
}

sf::Text* EquilTraingle::getSfText()
{
    ///returns pointer to sf::Text that this KEngine Triangle uses

    return &text;
}

void EquilTraingle::setOrigin(int origin)
{
    ///changes origin of the KEngine Triangle
    /**available origins: <br>
      * MIDDLE_TOP    = top <br>
      * MIDDLE_MIDDLE = center <br>
      * RIGHT_BOTTOM  = bottom right corner <br>
      * MIDDLE_BOTTOM = bottom <br>
      * LEFT_BOTTOM   = bottom left corner*/

    this->origin = origin;

    this->updateShape();
    this->updateText();
}

int EquilTraingle::getOrigin() const
{
    ///returns origin of the KEngine Triangle
    /**available origins: <br>
      * MIDDLE_TOP    = top <br>
      * MIDDLE_MIDDLE = center <br>
      * RIGHT_BOTTOM  = bottom right corner <br>
      * MIDDLE_BOTTOM = bottom <br>
      * LEFT_BOTTOM   = bottom left corner*/

    return this->origin;
}

void EquilTraingle::setRotation(float angle)
{
    ///rotates, use it but only when you have to (not working well)

    this->shape.setRotation(angle);
    this->text.setRotation(angle);

    if (this->origin == MIDDLE_MIDDLE)
    {

        if (angle == 0)

            switch (text_position)
            {
            case MIDDLE_MIDDLE:
            {
                //this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().left + this->text.getLocalBounds().width / 2, this->text.getLocalBounds().top + this->text.getLocalBounds().height / 2));
                this->text.setPosition(sf::Vector2f(this->shapeCentre.x + text_shift.x, this->shapeCentre.y + text_shift.y));
            }
            break;

            case MIDDLE_BOTTOM:
            {
                //this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().left + this->text.getLocalBounds().width / 2, this->text.getLocalBounds().top + this->text.getLocalBounds().height));
                this->text.setPosition(sf::Vector2f(this->shapeCentre.x + text_shift.x, this->shapeCentre.y + a * sqrt_3 / 6 + text_shift.y));
            }
            break;

            default:
            {
                //this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().left + this->text.getLocalBounds().width / 2, this->text.getLocalBounds().top + this->text.getLocalBounds().height / 2));
                this->text.setPosition(sf::Vector2f(this->shapeCentre.x + text_shift.x, this->shapeCentre.y + text_shift.y));
            }
            break;
            }
    }
    else if (angle == 90)
    {

        switch (text_position)
        {
        case MIDDLE_MIDDLE:
        {
            //this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().left + this->text.getLocalBounds().width / 2, this->text.getLocalBounds().top + this->text.getLocalBounds().height / 2));
            this->text.setPosition(sf::Vector2f(this->shapeCentre.x + text_shift.x, this->shapeCentre.y + text_shift.y));
        }
        break;

        case MIDDLE_BOTTOM:
        {
            //this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().left + this->text.getLocalBounds().width / 2, this->text.getLocalBounds().top + this->text.getLocalBounds().height));
            this->text.setPosition(sf::Vector2f(this->shapeCentre.x - a * sqrt_3 / 6 + text_shift.x, this->shapeCentre.y + text_shift.y));
        }
        break;

        default:
        {
            //this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().left + this->text.getLocalBounds().width / 2, this->text.getLocalBounds().top + this->text.getLocalBounds().height / 2));
            this->text.setPosition(sf::Vector2f(this->shapeCentre.x + text_shift.x, this->shapeCentre.y + text_shift.y));
        }
        break;
        }
    }
    else if (angle == 180)
    {

        switch (text_position)
        {
        case MIDDLE_MIDDLE:
        {
            //this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().left + this->text.getLocalBounds().width / 2, this->text.getLocalBounds().top + this->text.getLocalBounds().height / 2));
            this->text.setPosition(sf::Vector2f(this->shapeCentre.x + text_shift.x, this->shapeCentre.y + text_shift.y));
        }
        break;

        case MIDDLE_BOTTOM:
        {
            //this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().left + this->text.getLocalBounds().width / 2, this->text.getLocalBounds().top + this->text.getLocalBounds().height));
            this->text.setPosition(sf::Vector2f(this->shapeCentre.x + text_shift.x, this->shapeCentre.y - a * sqrt_3 / 6 + text_shift.y));
        }
        break;

        default:
        {
            //this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().left + this->text.getLocalBounds().width / 2, this->text.getLocalBounds().top + this->text.getLocalBounds().height / 2));
            this->text.setPosition(sf::Vector2f(this->shapeCentre.x + text_shift.x, this->shapeCentre.y + text_shift.y));
        }
        break;
        }

    }
    else if (angle == 270)
    {

        switch (text_position)
        {
        case MIDDLE_MIDDLE:
        {
            //this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().left + this->text.getLocalBounds().width / 2, this->text.getLocalBounds().top + this->text.getLocalBounds().height / 2));
            this->text.setPosition(sf::Vector2f(this->shapeCentre.x + text_shift.x, this->shapeCentre.y + text_shift.y));
        }
        break;

        case MIDDLE_BOTTOM:
        {
            //this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().left + this->text.getLocalBounds().width / 2, this->text.getLocalBounds().top + this->text.getLocalBounds().height));
            this->text.setPosition(sf::Vector2f(this->shapeCentre.x + a * sqrt_3 / 6 + text_shift.x, this->shapeCentre.y + text_shift.y));
        }
        break;

        default:
        {
            //this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().left + this->text.getLocalBounds().width / 2, this->text.getLocalBounds().top + this->text.getLocalBounds().height / 2));
            this->text.setPosition(sf::Vector2f(this->shapeCentre.x + text_shift.x, this->shapeCentre.y + text_shift.y));
        }
        break;
        }
    }
}

void EquilTraingle::Rotate(float angle)
{
    ///rotates, don't really use it

    this->shape.rotate(angle);
    this->text.rotate(angle);
}

float EquilTraingle::getRotation() const
{
    ///returns KEngine Triangle's rotation

    return this->shape.getRotation();
}


void EquilTraingle::setPositionByCentre(const sf::Vector2f& postion)
{
    ///sets position by the centre of the object

    sf::Vector2f delta(this->shape.getPosition().x - this->shapeCentre.x, this->shape.getPosition().y - this->shapeCentre.y);

    this->setPosition(postion.x + delta.x, postion.y + delta.y);
}

sf::Vector2f EquilTraingle::getShapeCentre() const
{
    ///returns center of KEngine Triangle

    return shapeCentre;
}


void EquilTraingle::setScale(const sf::Vector2f& factors)
{
    ///sets KEngine Triangle's scale

    this->shape.setScale(factors);
    this->text.setScale(factors);
}

void EquilTraingle::setScale(float factor_x, float factor_y)
{
    ///sets KEngine Triangle's scale

    this->setScale(sf::Vector2f(factor_x, factor_y));
}

void EquilTraingle::scale(const sf::Vector2f& factors)
{
    ///scales KEngine Triangle's scale

    this->shape.scale(factors);
    this->text.scale(factors);
}

sf::Vector2f EquilTraingle::getScale() const
{
    ///returns scale of the KEngine Triangle

    return this->shape.getScale();
}

void EquilTraingle::setTexture(const sf::Texture* texture)
{
    ///changes KEngine Triangle texture, idk if that works
    /// setting texture from other texture

    this->texture = *texture;
    this->shape.setTexture(&this->texture);
    this->texture_on = true;
}

void EquilTraingle::setTexture(const std::string& texture_path)
{
    ///changes KEngine Triangle texture, idk if that works
    /// setting texture directly from file

    this->texture_path = texture_path;
    this->texture.loadFromFile(texture_path);
    this->shape.setTexture(&this->texture);
    this->texture_on = true;
}

const sf::Texture* EquilTraingle::getTexture() const
{
    ///returns pointer to KEngine Triangle's texture
    /// if there's no texture, it returns nullptr

    if (!this->texture_on)
        return nullptr;
    else
        return this->shape.getTexture();
}

std::string EquilTraingle::getTexturePath() const
{
    ///just don't use it

    return this->texture_path;
}


void EquilTraingle::setFillColor(const sf::Color& color)
{
    ///sets KEngine Triangle's fill color

    this->shape.setFillColor(color);
}

const sf::Color &EquilTraingle::getFillColor() const
{
    ///returns KEngine Triangle's fill color

    return this->shape.getFillColor();
}

void EquilTraingle::setTextColor(const sf::Color& text_color)
{
    ///sets KEngine Triangle's text fill color

    this->text.setColor(text_color);
}

const sf::Color& EquilTraingle::getTextColor() const
{
    ///returns KEngine Triangle's text fill color

    return this->text.getColor();
}

void EquilTraingle::setOutlineColor(const sf::Color& outline_color)
{
    ///sets KEngine Triangle's outline color

    this->shape.setOutlineColor(outline_color);
}

const sf::Color& EquilTraingle::getOutlineColor() const
{
    ///returns KEngine Triangle's outline color

    return this->shape.getOutlineColor();
}

void EquilTraingle::setOutlineThickness(float outline_thickness)
{
    ///sets KEngine Triangle's outline thickness

    this->shape.setOutlineThickness(outline_thickness);
}

float EquilTraingle::getOutlineThickness() const
{
    ///returns KEngine Triangle's outline thickness

    return this->shape.getOutlineThickness();
}

void EquilTraingle::setTextPosition(int position, const sf::Vector2f& text_shift)
{
    ///sets KEngine Triangle's text position and text shift
    /**available origins: <br>
      * MIDDLE_MIDDLE = center <br>
      * MIDDLE_BOTTOM = bottom <br> */

    this->text_position = text_position;
    this->text_shift = text_shift;

    this->updateText();
}

int EquilTraingle::getTextPosition() const
{
    ///returns KEngine Triangle's text position and text shift
    /**available origins: <br>
      * MIDDLE_MIDDLE = center <br>
      * MIDDLE_BOTTOM = bottom <br> */

    return this->text_position;
}

sf::Vector2f EquilTraingle::getTextShift() const
{
    ///returns KEngine Triangle's text shift

    return text_shift;
}



void EquilTraingle::setTextStyle(int style)
{
    ///sets KEngine Triangle's text style

    this->text.setStyle(style);
}

unsigned int EquilTraingle::getTextStyle() const
{
    ///returns KEngine Triangle's text style

    return this->text.getStyle();
}

void EquilTraingle::setFont(int font)
{
    ///sets KEngine Triangle's font
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

int EquilTraingle::getFont() const
{
    ///returns KEngine Triangle's font
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


void EquilTraingle::setCharacterSize(unsigned int char_size)
{
    ///sets KEngine Triangle's text character size

    this->text.setCharacterSize(char_size);
}

unsigned int EquilTraingle::getCharacterSize() const
{
    ///returns KEngine Triangle's text character size

    return text.getCharacterSize();
}



//-------------------------                                                         -------------------------//
//+++                                                                                                     +++//
//==============          R E N D E R   A N D   B E H A V I O U R   F U N C T I O N S          ==============//
//+++                                                                                                     +++//
//-------------------------                                                         -------------------------//



bool EquilTraingle::isInvaded(const sf::Vector2f& mousePosition) const
{
    ///if mouse is on KEngine Triangle, returns true (90, 180 and 270 degree angles also work!)

    if (this->shape.getRotation() == 0)
    {
        sf::Vector2f bottom;
        bottom.x = shapeCentre.x;
        bottom.y = shapeCentre.y + this->shape.getRadius() / 2 * this->shape.getScale().x;

        if ( mousePosition.y < bottom.y &&
             ((mousePosition.x - bottom.x) / tan(30 * (3.1415 / 180)) < (mousePosition.y - (shapeCentre.y - shape.getRadius() * shape.getScale().x)) &&
             -((mousePosition.x - bottom.x) / tan(30 * (3.1415 / 180))) < (mousePosition.y - (shapeCentre.y - shape.getRadius() * shape.getScale().x))))
                return true;
        else    return false;
    }

    else if (this->shape.getRotation() == 90)
    {
        sf::Vector2f bottom;
        bottom.x = shapeCentre.x - this->shape.getRadius() / 2 * this->shape.getScale().x;
        bottom.y = shapeCentre.y;

        if ( mousePosition.x > bottom.x &&
             ((mousePosition.y - bottom.y) / tan(30 * (3.1415 / 180)) < ((shapeCentre.x + shape.getRadius() * shape.getScale().x) - mousePosition.x) &&
             -((mousePosition.y - bottom.y) / tan(30 * (3.1415 / 180))) < ((shapeCentre.x + shape.getRadius() * shape.getScale().x)) - mousePosition.x))
                return true;
        else    return false;
    }

    else if (this->shape.getRotation() == 180)
    {
        sf::Vector2f bottom;
        bottom.x = shapeCentre.x;
        bottom.y = shapeCentre.y - this->shape.getRadius() / 2 * this->shape.getScale().x;

        if ( mousePosition.y > bottom.y &&
             ((mousePosition.x - bottom.x) / tan(30 * (3.1415 / 180)) < ((shapeCentre.y + shape.getRadius() * shape.getScale().x) - mousePosition.y) &&
             -((mousePosition.x - bottom.x) / tan(30 * (3.1415 / 180))) < ((shapeCentre.y + shape.getRadius() * shape.getScale().x) - mousePosition.y)))
                return true;
        else    return false;
    }

    else if (this->shape.getRotation() == 270)
    {
        sf::Vector2f bottom;
        bottom.x = shapeCentre.x + this->shape.getRadius() / 2 * this->shape.getScale().x;
        bottom.y = shapeCentre.y;

        if ( mousePosition.x < bottom.x &&
             ((mousePosition.y - bottom.y) / tan(30 * (3.1415 / 180)) < (mousePosition.x - (shapeCentre.x - shape.getRadius() * shape.getScale().x)) &&
             -((mousePosition.y - bottom.y) / tan(30 * (3.1415 / 180))) < (mousePosition.x - (shapeCentre.x - shape.getRadius() * shape.getScale().x))))
                return true;
        else    return false;
    }
    else return false;
}

bool EquilTraingle::isInvaded_rect(const sf::Vector2f& mousePosition) const
{
    ///if mouse is on KEngine Triangle, returns true, but it the hitboxes are like rectangle

    if (mousePosition.x > this->shapeCentre.x - this->shape.getRadius() * this->shape.getScale().x &&
        mousePosition.x < this->shapeCentre.x + this->shape.getRadius() * this->shape.getScale().x &&
        mousePosition.y > this->shapeCentre.y - this->shape.getRadius() * this->shape.getScale().y &&
        mousePosition.y < this->shapeCentre.y + this->shape.getRadius() / 2 * this->shape.getScale().y   )
                return true;
        else    return false;
}

bool EquilTraingle::isClicked(sf::Mouse::Button button, const sf::Vector2f& mousePosition, sf::Event& event) const
{
    ///if mouse is on KEngine Triangle and the right button is clicked, returns true (use in pollEvent loop)

    if (this->isInvaded(mousePosition) && event.type == sf::Event::MouseButtonPressed && event.key.code == button)
                return true;
        else    return false;
}

bool EquilTraingle::isActive() const
{
    ///if KEngine Triangle is displayed, returns true

    return this->active;
}

void EquilTraingle::setActiveStatus(bool status)
{
    ///if KEngine Triangle is active, it is displayed on the screen

    this->active = status;
}

float EquilTraingle::update(const sf::Vector2f& mousePosition, sf::Event& event, sf::Mouse::Button button, sf::View* view)
{
    ///rounds text position to integers

    this->text.setPosition(sf::Vector2f(static_cast<int>(this->text.getPosition().x), static_cast<int>(this->text.getPosition().y)));

    return 0;
}

void EquilTraingle::render(sf::RenderWindow* window)
{
    ///displays KEngine Triangle on the screen, if active of course

    if (this->active)
    {
        window->draw(this->shape);
        window->draw(this->text);
    }
}

}
