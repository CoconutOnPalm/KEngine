#include "Circle.hpp"

namespace ke
{


//-------------------------                                                         -------------------------//
//+++                                                                                                     +++//
//============== C O N S T R U C T O R S ,   D E S T R U C T O R S   A N D   O P E R A T O R S ==============//
//+++                                                                                                     +++//
//-------------------------                                                         -------------------------//


Circle::Circle()
{
    ///KEngine Circle default constructor
    /** KEngine Circle is an object based on sf::CircleShape that can
        hold color or texture - basic object in the library, inherits from
        class GuiObject*/
}


Circle::Circle( float radius, const sf::Vector2f& position,
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
    ///KEngine Circle color constructor
    /** KEngine Circle is an object based on sf::CircleShape that can
        hold color or texture - basic object in the library, inherits from
        class GuiObject*/


    this->texture_path = "";
    this->texture_on = false;

    this->active = active;


    this->origin = origin;
    this->text_position = text_position;
    this->text_shift = text_shift;


    this->shape.setRadius(radius);
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

Circle::Circle( float radius,
                const sf::Vector2f& position,
                int origin,
                const sf::Texture* texture,
                bool active)
{
    ///KEngine Circle texture constructor <br>
    /// texture loading from other texture
    /** KEngine Circle is an object based on sf::CircleShape that can
        hold color or texture - basic object in the library, inherits from
        class GuiObject*/

    this->active = active;
    this->texture_on = true;
    this->texture_path = "";
    if (texture) this->texture = *texture;
    else this->texture.loadFromFile("");


    this->active = active;


    this->origin = origin;
    this->text_position = MIDDLE_MIDDLE;
    this->text_shift = sf::Vector2f(0, 0);


    this->shape.setRadius(radius);
    this->shape.setPosition(position);

    this->updateShape();

    this->shape.setTexture(&this->texture);
    this->shape.setFillColor(sf::Color::Black);
}

Circle::Circle( float radius,
                const sf::Vector2f& position,
                int origin,
                const std::string& texture_path,
                bool active)
{
    ///KEngine Circle texture constructor <br>
    /// texture loading directly from file
    /** KEngine Circle is an object based on sf::CircleShape that can
        hold color or texture - basic object in the library, inherits from
        class GuiObject*/

    this->active = active;
    this->texture_on = true;
    this->texture_path = texture_path;
    this->texture.loadFromFile(texture_path);


    this->active = active;


    this->origin = origin;
    this->text_position = MIDDLE_MIDDLE;
    this->text_shift = sf::Vector2f(0, 0);


    this->shape.setRadius(radius);
    this->shape.setPosition(position);

    this->updateShape();

    this->shape.setTexture(&this->texture);
    this->shape.setFillColor(sf::Color::Black);
}

Circle::~Circle()
{
    ///KEngine Circle destructor
    /** KEngine Circle is an object based on sf::CircleShape that can
        hold color or texture - basic object in the library, inherits from
        class GuiObject*/
}



Circle::Circle(Circle& other)
{
    ///KEngine Circle copy constructor
    /** KEngine Circle is an object based on sf::CircleShape that can
        hold color or texture - basic object in the library, inherits from
        class GuiObject*/

    this->texture_path = "";
    this->texture_on = false;

    this->active = other.isActive();


    this->origin = other.getOrigin();
    this->text_position = other.getTextPosition();
    this->text_shift = other.getTextShift();


    this->shape.setRadius(other.getRadius());
    this->shape.setPosition(other.getPosition());

    this->updateShape();

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



Circle& Circle::operator= (Circle& other)
{
    ///KEngine Circle operator =
    /** KEngine Circle is an object based on sf::CircleShape that can
        hold color or texture - basic object in the library, inherits from
        class GuiObject*/

    this->texture_path = "";
    this->texture_on = false;

    this->active = other.isActive();


    this->origin = other.getOrigin();
    this->text_position = other.getTextPosition();
    this->text_shift = other.getTextShift();


    this->shape.setRadius(other.getRadius());
    this->shape.setPosition(other.getPosition());

    this->updateShape();

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



void Circle::create( float radius, const sf::Vector2f& position,
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
    ///KEngine Circle color create function <br>
    ///use with default constructor
    /** KEngine Circle is an object based on sf::CircleShape that can
        hold color or texture - basic object in the library, inherits from
        class GuiObject*/


    this->texture_path = "";
    this->texture_on = false;

    this->active = active;


    this->origin = origin;
    this->text_position = text_position;
    this->text_shift = text_shift;


    this->shape.setRadius(radius);
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


void Circle::create( float radius,
                     const sf::Vector2f& position,
                     int origin,
                     const sf::Texture* texture,
                     bool active)
{
    ///KEngine Circle texture create function <br>
    ///use with default constructor <br>
    /// texture loading from other texture
    /** KEngine Circle is an object based on sf::CircleShape that can
        hold color or texture - basic object in the library, inherits from
        class GuiObject*/

    this->active = active;
    this->texture_on = true;
    this->texture_path = "";
    if (texture) this->texture = *texture;
    else this->texture.loadFromFile("");


    this->active = active;


    this->origin = origin;
    this->text_position = MIDDLE_MIDDLE;
    this->text_shift = sf::Vector2f(0, 0);


    this->shape.setRadius(radius);
    this->shape.setPosition(position);

    this->updateShape();

    this->shape.setTexture(&this->texture);
    this->shape.setFillColor(sf::Color::Black);
}


void Circle::create( float radius,
                     const sf::Vector2f& position,
                     int origin,
                     const std::string& texture_path,
                     bool active)
{
    ///KEngine Circle texture create function <br>
    ///use with default constructor <br>
    /// texture loading directly from file
    /** KEngine Circle is an object based on sf::CircleShape that can
        hold color or texture - basic object in the library, inherits from
        class GuiObject*/

    this->active = active;
    this->texture_on = true;
    this->texture_path = texture_path;
    this->texture.loadFromFile(texture_path);


    this->active = active;


    this->origin = origin;
    this->text_position = MIDDLE_MIDDLE;
    this->text_shift = sf::Vector2f(0, 0);


    this->shape.setRadius(radius);
    this->shape.setPosition(position);

    this->updateShape();

    this->shape.setTexture(&this->texture);
    this->shape.setFillColor(sf::Color::Black);
}



//-------------------------                                                         -------------------------//
//+++                                                                                                     +++//
//==============                       P R I V A T E   F U N C T I O N S                       ==============//
//+++                                                                                                     +++//
//-------------------------                                                         -------------------------//



void Circle::updateShape()
{
    ///KEngine Circle private function used automatically

    switch(this->origin)
    {
    case LEFT_TOP:
        {
            this->shapeCentre = sf::Vector2f(this->shape.getPosition().x + this->shape.getRadius(), this->shape.getPosition().y + this->shape.getRadius());
        }
        break;

    case MIDDLE_TOP:
        {
            this->shape.setOrigin(sf::Vector2f(this->shape.getRadius(), 0));
            this->shapeCentre = sf::Vector2f(this->shape.getPosition().x, this->shape.getPosition().y + this->shape.getRadius());
        }
        break;

    case RIGHT_TOP:
        {
            this->shape.setOrigin(sf::Vector2f(this->shape.getRadius() * 2, 0));
            this->shapeCentre = sf::Vector2f(this->shape.getPosition().x - this->shape.getRadius(), this->shape.getPosition().y + this->shape.getRadius());
        }
        break;

    case LEFT_MIDDLE:
        {
            this->shape.setOrigin(sf::Vector2f(0, this->shape.getRadius()));
            this->shapeCentre = sf::Vector2f(this->shape.getPosition().x + this->shape.getRadius(), this->shape.getPosition().y);
        }
        break;

    case MIDDLE_MIDDLE:
        {
            this->shape.setOrigin(sf::Vector2f(this->shape.getRadius(), this->shape.getRadius()));
            this->shapeCentre = this->shape.getPosition();
        }
        break;

    case RIGHT_MIDDLE:
        {
            this->shape.setOrigin(sf::Vector2f(this->shape.getRadius() * 2, this->shape.getRadius()));
            this->shapeCentre = sf::Vector2f(this->shape.getPosition().x - this->shape.getRadius(), this->shape.getPosition().y);
        }
        break;

    case LEFT_BOTTOM:
        {
            this->shape.setOrigin(sf::Vector2f(0, this->shape.getRadius() * 2));
            this->shapeCentre = sf::Vector2f(this->shape.getPosition().x + this->shape.getRadius(), this->shape.getPosition().y - this->shape.getRadius());
        }
        break;

    case MIDDLE_BOTTOM:
        {
            this->shape.setOrigin(sf::Vector2f(this->shape.getRadius(), this->shape.getRadius() * 2));
            this->shapeCentre = sf::Vector2f(this->shape.getPosition().x, this->shape.getPosition().y - this->shape.getRadius());
        }
        break;

    case RIGHT_BOTTOM:
        {
            this->shape.setOrigin(sf::Vector2f(this->shape.getRadius() * 2, this->shape.getRadius() * 2));
            this->shapeCentre = sf::Vector2f(this->shape.getPosition().x - this->shape.getRadius(), this->shape.getPosition().y - this->shape.getRadius());
        }
        break;

    default:
        {
            this->shapeCentre = sf::Vector2f(this->shape.getPosition().x + this->shape.getRadius(), this->shape.getPosition().y + this->shape.getRadius());
        }
        break;
    }
}


void Circle::updateText()
{
    ///KEngine Circle private function used automatically

    switch(this->text_position)
    {
    case MIDDLE_TOP:
        {
            this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().left + this->text.getLocalBounds().width / 2, this->text.getLocalBounds().top));
            this->text.setPosition(sf::Vector2f(this->shapeCentre.x + text_shift.x, this->shapeCentre.y - this->shape.getRadius() + text_shift.y));
        }
        break;

    case LEFT_MIDDLE:
        {
            this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().left, this->text.getLocalBounds().top + this->text.getLocalBounds().height / 2));
            this->text.setPosition(sf::Vector2f(this->shapeCentre.x - this->shape.getRadius() + text_shift.x, this->shapeCentre.y + text_shift.y));
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
            this->text.setPosition(sf::Vector2f(this->shapeCentre.x + this->shape.getRadius() + text_shift.x, this->shapeCentre.y + text_shift.y));
        }
        break;

    case MIDDLE_BOTTOM:
        {
            this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().left + this->text.getLocalBounds().width / 2, this->text.getLocalBounds().top + this->text.getLocalBounds().height));
            this->text.setPosition(sf::Vector2f(this->shapeCentre.x + text_shift.x, this->shapeCentre.y + this->shape.getRadius() + text_shift.y));
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



void Circle::setPosition(const sf::Vector2f& position)
{
    ///sets KEngine Circle's position

    this->shape.setPosition(position);

    this->updateShape();
    this->updateText();
}

void Circle::setPosition(float x, float y)
{
     ///sets KEngine Circle's position

    this->setPosition(sf::Vector2f(x, y));
}

sf::Vector2f Circle::getPosition() const
{
    ///returns KEngine Circle's position

    return this->shape.getPosition();
}


void Circle::setSize(const sf::Vector2f& size)
{
    ///sets KEngine Circle size

    this->shape.setRadius(size.x / 2);

    this->updateShape();
    this->updateText();
}

void Circle::setSize(float size_x, float size_y)
{
    ///sets KEngine Circle size

    this->shape.setRadius(size_x / 2);

    this->updateShape();
    this->updateText();
}

sf::Vector2f Circle::getSize() const
{
    ///returns KEngine Circle size

    sf::Vector2f temp(this->shape.getRadius() * 2, this->shape.getRadius() * 2);
    return temp;
}


void Circle::move(const sf::Vector2f& offset)
{
    ///moves KEngine Circle by offset (px)

    this->shape.move(offset);

    this->updateShape();
    this->updateText();
}


void Circle::move(float offset_x, float offset_y)
{
    ///moves KEngine Circle by offset (px)

    this->shape.move(offset_x, offset_y);

    this->updateShape();
    this->updateText();
}


void Circle::setRadius(float radius)
{
    ///sets KEngine Circle radius

    this->shape.setRadius(radius);

    this->updateShape();
    this->updateText();
}

float Circle::getRadius() const
{
    ///returns KEngine Circle radius

    return this->shape.getRadius();
}


void Circle::setText(const std::wstring& text)
{
    ///changes String of KEngine Circle's text (std::wstring)

    this->text.setString(text);
    this->updateText();
}

std::wstring Circle::getText() const
{
    ///returns String of KEngine Circle's text (std::wstring)

    return this->text.getString();
}


sf::CircleShape* Circle::getShape()
{
    ///returns pointer to sf::CircleShape that this KEngine Circle uses

    return &shape;
}

sf::Text* Circle::getSfText()
{
    ///returns pointer to sf::Text that this KEngine Circle uses

    return &text;
}


void Circle::setOrigin(int origin)
{
    ///changes origin of the KEngine Circle
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
    this->updateText();
}

int Circle::getOrigin() const
{
    ///returns origin of the KEngine Circle
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

void Circle::setRotation(float angle)
{
    ///rotates, don't really use it

    this->text.setRotation(angle);
}

void Circle::Rotate(float angle)
{
    ///rotates, don't really use it

    this->text.rotate(angle);
}

float Circle::getRotation() const
{
    ///returns KEngine Circle's rotation

    return this->text.getRotation();
}


void Circle::setPositionByCentre(const sf::Vector2f& postion)
{
    ///sets position by the centre of the object

    sf::Vector2f delta(this->shape.getPosition().x - this->shapeCentre.x, this->shape.getPosition().y - this->shapeCentre.y);

    this->setPosition(postion.x + delta.x, postion.y + delta.y);
}


sf::Vector2f Circle::getShapeCentre() const
{
    ///returns center of KEngine Circle

    return this->shapeCentre;
}


void Circle::setScale(const sf::Vector2f& factors)
{
    ///sets KEngine Circle's scale

    this->shape.setScale(factors);
    this->text.setScale(factors);
}

void Circle::setScale(float factor_x, float factor_y)
{
    ///sets KEngine Circle's scale

    this->setScale(sf::Vector2f(factor_x, factor_y));
}

void Circle::scale(const sf::Vector2f& factors)
{
    ///scales KEngine Circle's scale

    this->shape.scale(factors);
    this->text.scale(factors);
}

sf::Vector2f Circle::getScale() const
{
    ///returns scale of the KEngine Circle

    return this->shape.getScale();
}


void Circle::setTexture(const sf::Texture* texture)
{
    ///changes KEngine Circle texture, idk if that works
    /// setting texture from other texture

    this->texture = *texture;
    this->shape.setTexture(&this->texture);
    this->texture_on = true;
}

void Circle::setTexture(const std::string& texture_path)
{
    ///changes KEngine Circle texture, idk if that works
    /// setting texture directly from file

    this->texture_path = texture_path;
    this->texture.loadFromFile(texture_path);

    this->shape.setTexture(&this->texture);
    this->texture_on = true;
}

const sf::Texture* Circle::getTexture() const
{
    ///returns pointer to KEngine Circle's texture
    /// if there's no texture, it returns nullptr

    if (!this->texture_on)
        return nullptr;
    else
        return this->shape.getTexture();
}

std::string Circle::getTexturePath() const
{
    ///just don't use it

    return this->texture_path;
}


void Circle::setFillColor(const sf::Color& color)
{
    ///sets KEngine Circle's fill color

    this->shape.setFillColor(color);
}

const sf::Color &Circle::getFillColor() const
{
    ///returns KEngine Circle's fill color

    return this->shape.getFillColor();
}

void Circle::setTextColor(const sf::Color& text_color)
{
    ///sets KEngine Circle's text fill color

    this->text.setColor(text_color);
}

const sf::Color& Circle::getTextColor() const
{
    ///returns KEngine Circle's text fill color

    return this->text.getColor();
}

void Circle::setOutlineColor(const sf::Color& outline_color)
{
    ///sets KEngine Circle's outline color

    this->shape.setOutlineColor(outline_color);
}

const sf::Color& Circle::getOutlineColor() const
{
    ///returns KEngine Circle's outline color

    return this->shape.getOutlineColor();
}

void Circle::setOutlineThickness(float outline_thickness)
{
    ///sets KEngine Circle's outline thickness

    this->shape.setOutlineThickness(outline_thickness);
}

float Circle::getOutlineThickness() const
{
    ///returns KEngine Circle's outline thickness

    return this->shape.getOutlineThickness();
}

void Circle::setTextPosition(int position, const sf::Vector2f& text_shift)
{
    ///sets KEngine Circle's text position and text shift
    /**available origins: <br>
      * MIDDLE_TOP    = top <br>
      * RIGHT_MIDDLE  = right side <br>
      * MIDDLE_MIDDLE = center <br>
      * LEFT_MIDDLE   = left side <br>
      * MIDDLE_BOTTOM = bottom */

    this->text_position = position;
    this->text_shift = text_shift;

    updateText();
}

int Circle::getTextPosition() const
{
    ///returns KEngine Circle's text position
    /**available origins: <br>
      * MIDDLE_TOP    = top <br>
      * RIGHT_MIDDLE  = right side <br>
      * MIDDLE_MIDDLE = center <br>
      * LEFT_MIDDLE   = left side <br>
      * MIDDLE_BOTTOM = bottom */

    return this->text_position;
}

sf::Vector2f Circle::getTextShift() const
{
    ///returns KEngine Circle's text shift

    return text_shift;
}


void Circle::setTextStyle(int style)
{
    ///sets KEngine Circle's text style

    this->text.setStyle(style);
}

unsigned int Circle::getTextStyle() const
{
    ///returns \KEngine Circle's text style

    return this->text.getStyle();
}

void Circle::setFont(int font)
{
    ///sets KEngine Circle's font
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

int Circle::getFont() const
{
    ///returns KEngine Circle's font
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


void Circle::setCharacterSize(unsigned int char_size)
{
    ///sets KEngine Circle's text character size

    this->text.setCharacterSize(char_size);
}

unsigned int Circle::getCharacterSize() const
{
    ///returns KEngine Circle's text character size

    return text.getCharacterSize();
}



//-------------------------                                                         -------------------------//
//+++                                                                                                     +++//
//==============          R E N D E R   A N D   B E H A V I O U R   F U N C T I O N S          ==============//
//+++                                                                                                     +++//
//-------------------------                                                         -------------------------//



bool Circle::isInvaded(const sf::Vector2f& mousePosition) const
{
    ///if mouse is on KEngine Circle, returns true

    sf::Vector2f dbysc; // shapeCentre - mousePosition
    dbysc.x = shapeCentre.x - mousePosition.x;
    dbysc.y = shapeCentre.y - mousePosition.y;
    if (dbysc.x < 0) dbysc.x = -dbysc.x;
    if (dbysc.y < 0) dbysc.y = -dbysc.y;

    if (dbysc.x * dbysc.x + dbysc.y * dbysc.y < this->shape.getRadius() * this->shape.getRadius() * this->shape.getScale().x * this->shape.getScale().y)
            return true;
    else    return false;
}

bool Circle::isClicked(sf::Mouse::Button button, const sf::Vector2f& mousePosition, sf::Event& event) const
{
    ///if mouse is on KEngine Circle and the right button is clicked, returns true (use in pollEvent loop)

    if (this->isInvaded(mousePosition) && event.type == sf::Event::MouseButtonPressed && event.key.code == button)
            return true;
    else    return false;
}


bool Circle::isActive() const
{
    ///if KEngine Circle is displayed, returns true

    return this->active;
}

void  Circle::setActiveStatus(bool status)
{
    ///if KEngine Circle is active, it is displayed on the screen

    this->active = status;
}


float Circle::update(const sf::Vector2f& mousePosition, sf::Event& event, sf::Mouse::Button button, sf::View* view)
{
    ///rounds text position to integers

    this->text.setPosition(sf::Vector2f(static_cast<int>(this->text.getPosition().x), static_cast<int>(this->text.getPosition().y)));

    return 0;
}


void Circle::render(sf::RenderWindow *window)
{
    ///displays KEngine Circle on the screen, if active of course

    if (this->active)
    {
        window->draw(this->shape);
        window->draw(this->text);
    }
}



void Circle::initPhysics()
{
    ///initializes physics class

    m_physics = std::make_unique<Physics>(this);
}


void Circle::initPhysics(long double mass, float friction)
{
    ///initializes physics class

    m_physics = std::make_unique<Physics>(this, mass, friction);
}


void Circle::deletePhysics()
{
    ///deletes physics from the object

    m_physics.reset();
}


void Circle::updatePhysics(const float dt)
{
    ///updates physics

    if (this->m_physics != nullptr)
        this->m_physics->update(dt);
}


Physics* Circle::physics()
{
    ///returns physics class

    return m_physics.get();
}

}
