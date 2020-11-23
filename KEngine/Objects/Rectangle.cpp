#include "Rectangle.hpp"

namespace ke
{


//-------------------------                                                         -------------------------//
//+++                                                                                                     +++//
//============== C O N S T R U C T O R S ,   D E S T R U C T O R S   A N D   O P E R A T O R S ==============//
//+++                                                                                                     +++//
//-------------------------                                                         -------------------------//


Rectangle::Rectangle()
{
    ///KEngine Rectangle default constructor
    /** KEngine Rectangle is an object based on sf::RectangleShape that can
        hold color or texture - basic object in the library, inherits from
        class GuiObject*/
}


Rectangle::Rectangle( const sf::Vector2f& size,
                      const sf::Vector2f& position,
                      int origin,
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
    ///KEngine Rectangle color constructor
    /** KEngine Rectangle is an object based on sf::RectangleShape that can
        hold color or texture - basic object in the library, inherits from
        class GuiObject*/

    this->texture_path = "";
    this->texture_on = false;

    this->active = active;


    this->origin = origin;
    this->text_position = text_position;
    this->text_shift = text_shift;


    this->shape.setSize(size);
    this->shape.setPosition(position);

    this->updateShape();

    this->shape.setFillColor(object_color);
    this->shape.setOutlineColor(outline_color);
    this->shape.setOutlineThickness(outline_thickness);
    this->shape.setRotation(rotation);



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

Rectangle::Rectangle( const sf::Vector2f& size,
                      const sf::Vector2f& position,
                      int origin,
                      const sf::Texture* texture,
                      float rotation,
                      bool active )
{
    ///KEngine Rectangle texture constructor <br>
    /// texture loading from other texture
    /** KEngine Rectangle is an object based on sf::RectangleShape that can
        hold color or texture - basic object in the library, inherits from
        class GuiObject*/

    this->active = active;

    if (texture) this->texture = *texture;
    else this->texture.loadFromFile("");
    this->texture_path = "";
    this->texture_on = true;

    this->origin = origin;
    this->text_position = MIDDLE_MIDDLE;
    this->text_shift = sf::Vector2f(0, 0);


    this->shape.setSize(size);
    this->shape.setPosition(position);

    this->updateShape();

    this->shape.setTexture(&this->texture);
    this->shape.setFillColor(sf::Color::Black);
    this->shape.setRotation(rotation);
}

Rectangle::Rectangle( const sf::Vector2f& size,
                      const sf::Vector2f& position,
                      int origin,
                      const std::string& texture_path,
                      float rotation,
                      bool active )
{
    ///KEngine Rectangle texture constructor <br>
    /// texture loading directly from file
    /** KEngine Rectangle is an object based on sf::RectangleShape that can
        hold color or texture - basic object in the library, inherits from
        class GuiObject*/

    this->active = active;


    this->texture_path = texture_path;
    this->texture.loadFromFile(this->texture_path);
    this->texture_on = true;


    this->origin = origin;
    this->text_position = MIDDLE_MIDDLE;
    this->text_shift = sf::Vector2f(0, 0);


    this->shape.setSize(size);
    this->shape.setPosition(position);

    this->updateShape();

    this->shape.setTexture(&this->texture);
    this->shape.setFillColor(sf::Color::Black);
    this->shape.setRotation(rotation);
}


Rectangle::~Rectangle()
{
    ///KEngine Rectangle destructor
    /** KEngine Rectangle is an object based on sf::RectangleShape that can
        hold color or texture - basic object in the library, inherits from
        class GuiObject*/
}


Rectangle::Rectangle(Rectangle& other)
{
    ///KEngine Rectangle copy constructor
    /** KEngine Rectangle is an object based on sf::RectangleShape that can
        hold color or texture - basic object in the library, inherits from
        class GuiObject*/

    this->texture_path = "";
    this->texture_on = false;

    this->active = other.isActive();


    this->origin = other.getOrigin();
    this->text_position = other.getTextPosition();
    this->text_shift = other.getTextShift();

    if (other.getTexture())
        this->texture = *other.getTexture();


    this->shape.setSize(other.getSize());
    this->shape.setPosition(other.getPosition());

    this->updateShape();

    this->shape.setFillColor(other.getFillColor());
    this->shape.setOutlineColor(other.getOutlineColor());
    this->shape.setOutlineThickness(other.getOutlineThickness());
    this->shape.setRotation(other.getRotation());



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

    this->m_physics->setTarget(this);

    for (auto& i : *other.physics()->getForceList())
        this->m_physics->addForce(i.first, i.second.x * i.second.x + i.second.y * i.second.y, acos(i.second.x / (i.second.x * i.second.x + i.second.y * i.second.y)));

    this->m_physics->setSpeed(other.physics()->getSpeed().x * other.physics()->getSpeed().x + other.physics()->getSpeed().y * other.physics()->getSpeed().y, acos(other.physics()->getSpeed().x / (other.physics()->getSpeed().x * other.physics()->getSpeed().x + other.physics()->getSpeed().y * other.physics()->getSpeed().y)));
    this->m_physics->setMass(other.physics()->getMass());
    this->m_physics->setFriction(other.physics()->getFriction());
}


Rectangle& Rectangle::operator= (Rectangle& other)
{
    ///KEngine Rectangle operator =
    /** KEngine Rectangle is an object based on sf::RectangleShape that can
        hold color or texture - basic object in the library, inherits from
        class GuiObject*/

    this->texture_path = "";
    this->texture_on = false;

    this->active = other.isActive();


    this->origin = other.getOrigin();
    this->text_position = other.getTextPosition();
    this->text_shift = other.getTextShift();

    if (other.getTexture())
        this->texture = *other.getTexture();


    this->shape.setSize(other.getSize());
    this->shape.setPosition(other.getPosition());

    this->updateShape();

    this->shape.setFillColor(other.getFillColor());
    this->shape.setOutlineColor(other.getOutlineColor());
    this->shape.setOutlineThickness(other.getOutlineThickness());
    this->shape.setRotation(other.getRotation());



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

    this->m_physics->setTarget(this);

    for (auto& i : *other.physics()->getForceList())
        this->m_physics->addForce(i.first, i.second.x * i.second.x + i.second.y * i.second.y, acos(i.second.x / (i.second.x * i.second.x + i.second.y * i.second.y)));

    this->m_physics->setSpeed(other.physics()->getSpeed().x * other.physics()->getSpeed().x + other.physics()->getSpeed().y * other.physics()->getSpeed().y, acos(other.physics()->getSpeed().x / (other.physics()->getSpeed().x * other.physics()->getSpeed().x + other.physics()->getSpeed().y * other.physics()->getSpeed().y)));
    this->m_physics->setMass(other.physics()->getMass());
    this->m_physics->setFriction(other.physics()->getFriction());

    return *this;
}



void Rectangle::create( const sf::Vector2f& size,
                        const sf::Vector2f& position,
                        int origin,
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
    ///KEngine Rectangle color create function <br>
    ///use with default constructor
    /** KEngine Rectangle is an object based on sf::RectangleShape that can
        hold color or texture - basic object in the library, inherits from
        class GuiObject*/

    this->texture_path = "";
    this->texture_on = false;

    this->active = active;


    this->origin = origin;
    this->text_position = text_position;
    this->text_shift = text_shift;


    this->shape.setSize(size);
    this->shape.setPosition(position);

    this->updateShape();

    this->shape.setFillColor(object_color);
    this->shape.setOutlineColor(outline_color);
    this->shape.setOutlineThickness(outline_thickness);
    this->shape.setRotation(rotation);



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


void Rectangle::create( const sf::Vector2f& size,
                        const sf::Vector2f& position,
                        int origin,
                        const sf::Texture* texture,
                        float rotation,
                        bool active )
{
    ///KEngine Rectangle texture create function <br>
    ///use with default constructor <br>
    /// texture loading from other texture
    /** KEngine Rectangle is an object based on sf::RectangleShape that can
        hold color or texture - basic object in the library, inherits from
        class GuiObject*/

    this->active = active;

    if (texture) this->texture = *texture;
    else this->texture.loadFromFile("");
    this->texture_path = "";
    this->texture_on = true;

    this->origin = origin;
    this->text_position = MIDDLE_MIDDLE;
    this->text_shift = sf::Vector2f(0, 0);


    this->shape.setSize(size);
    this->shape.setPosition(position);

    this->updateShape();

    this->shape.setTexture(&this->texture);
    this->shape.setFillColor(sf::Color::Black);
    this->shape.setRotation(rotation);
}


void Rectangle::create( const sf::Vector2f& size,
                        const sf::Vector2f& position,
                        int origin,
                        const std::string& texture_path,
                        float rotation,
                        bool active )
{
    ///KEngine Rectangle texture constructor <br>
    ///use with default constructor <br>
    /// texture loading directly from file
    /** KEngine Rectangle is an object based on sf::RectangleShape that can
        hold color or texture - basic object in the library, inherits from
        class GuiObject*/

    this->active = active;


    this->texture_path = texture_path;
    this->texture.loadFromFile(this->texture_path);
    this->texture_on = true;


    this->origin = origin;
    this->text_position = MIDDLE_MIDDLE;
    this->text_shift = sf::Vector2f(0, 0);


    this->shape.setSize(size);
    this->shape.setPosition(position);

    this->updateShape();

    this->shape.setTexture(&this->texture);
    this->shape.setFillColor(sf::Color::Black);
    this->shape.setRotation(rotation);
}



//-------------------------                                                         -------------------------//
//+++                                                                                                     +++//
//==============                       P R I V A T E   F U N C T I O N S                       ==============//
//+++                                                                                                     +++//
//-------------------------                                                         -------------------------//



void Rectangle::updateShape()
{
    ///KEngine Rectangle private function used automatically

    switch(this->origin)
    {
    case LEFT_TOP:
        {
            this->shapeCentre = sf::Vector2f(this->shape.getPosition().x + this->shape.getSize().x / 2, this->shape.getPosition().y + this->shape.getSize().y / 2);
        }
        break;

    case MIDDLE_TOP:
        {
            this->shape.setOrigin(sf::Vector2f(this->shape.getSize().x / 2, 0));
            this->shapeCentre = sf::Vector2f(this->shape.getPosition().x, this->shape.getPosition().y + this->shape.getSize().y / 2);
        }
        break;

    case RIGHT_TOP:
        {
            this->shape.setOrigin(sf::Vector2f(this->shape.getSize().x, 0));
            this->shapeCentre = sf::Vector2f(this->shape.getPosition().x - this->shape.getSize().x / 2, this->shape.getPosition().y + this->shape.getSize().y / 2);
        }
        break;

    case LEFT_MIDDLE:
        {
            this->shape.setOrigin(sf::Vector2f(0, this->shape.getSize().y / 2));
            this->shapeCentre = sf::Vector2f(this->shape.getPosition().x + this->shape.getSize().x / 2, this->shape.getPosition().y);
        }
        break;

    case MIDDLE_MIDDLE:
        {
            this->shape.setOrigin(sf::Vector2f(this->shape.getSize().x / 2, this->shape.getSize().y / 2));
            this->shapeCentre = this->shape.getPosition();
        }
        break;

    case RIGHT_MIDDLE:
        {
            this->shape.setOrigin(sf::Vector2f(this->shape.getSize().x, this->shape.getSize().y / 2));
            this->shapeCentre = sf::Vector2f(this->shape.getPosition().x - this->shape.getSize().x / 2, this->shape.getPosition().y);
        }
        break;

    case LEFT_BOTTOM:
        {
            this->shape.setOrigin(sf::Vector2f(0, this->shape.getSize().y));
            this->shapeCentre = sf::Vector2f(this->shape.getPosition().x + this->shape.getSize().x / 2, this->shape.getPosition().y - this->shape.getSize().y / 2);
        }
        break;

    case MIDDLE_BOTTOM:
        {
            this->shape.setOrigin(sf::Vector2f(this->shape.getSize().x / 2, this->shape.getSize().y));
            this->shapeCentre = sf::Vector2f(this->shape.getPosition().x, this->shape.getPosition().y - this->shape.getSize().y / 2);
        }
        break;

    case RIGHT_BOTTOM:
        {
            this->shape.setOrigin(sf::Vector2f(this->shape.getSize().x, this->shape.getSize().y));
            this->shapeCentre = sf::Vector2f(this->shape.getPosition().x - this->shape.getSize().x / 2, this->shape.getPosition().y - this->shape.getSize().y / 2);
        }
        break;

    default:
        {
            this->shapeCentre = sf::Vector2f(this->shape.getPosition().x + this->shape.getSize().x / 2, this->shape.getPosition().y + this->shape.getSize().y / 2);
        }
        break;
    }
}


void Rectangle::updateText()
{
    ///KEngine Rectangle private function used automatically

    switch(text_position)
    {
    case LEFT_TOP:
        {
            this->text.setPosition(sf::Vector2f(this->shapeCentre.x - this->shape.getSize().x / 2 + text_shift.x, this->shapeCentre.y - this->shape.getSize().y / 2 + text_shift.y));
        }
        break;

    case MIDDLE_TOP:
        {
            this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().left + this->text.getLocalBounds().width / 2, this->text.getLocalBounds().top));
            this->text.setPosition(sf::Vector2f(this->shapeCentre.x + text_shift.x, this->shapeCentre.y - this->shape.getSize().y / 2 + text_shift.y));
        }
        break;

    case RIGHT_TOP:
        {
            this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().left + this->text.getLocalBounds().width, this->text.getLocalBounds().top));
            this->text.setPosition(sf::Vector2f(this->shapeCentre.x + this->shape.getSize().x / 2 + text_shift.x, this->shapeCentre.y - this->shape.getSize().y / 2 + text_shift.y));
        }
        break;

    case LEFT_MIDDLE:
        {
            this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().left, this->text.getLocalBounds().top + this->text.getLocalBounds().height / 2));
            this->text.setPosition(sf::Vector2f(this->shapeCentre.x - this->shape.getSize().x / 2 + text_shift.x, this->shapeCentre.y + text_shift.y));
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
            this->text.setPosition(sf::Vector2f(this->shapeCentre.x + this->shape.getSize().x / 2 + text_shift.x, this->shapeCentre.y + text_shift.y));
        }
        break;

    case LEFT_BOTTOM:
        {
            this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().left, this->text.getLocalBounds().top + this->text.getLocalBounds().height));
            this->text.setPosition(sf::Vector2f(this->shapeCentre.x - this->shape.getSize().x / 2 + text_shift.x, this->shapeCentre.y + this->shape.getSize().y / 2 + text_shift.y));
        }
        break;

    case MIDDLE_BOTTOM:
        {
            this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().left + this->text.getLocalBounds().width / 2, this->text.getLocalBounds().top + this->text.getLocalBounds().height));
            this->text.setPosition(sf::Vector2f(this->shapeCentre.x + text_shift.x, this->shapeCentre.y + this->shape.getSize().y / 2 + text_shift.y));
        }
        break;

    case RIGHT_BOTTOM:
        {
            this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().left + this->text.getLocalBounds().width, this->text.getLocalBounds().top + this->text.getLocalBounds().height));
            this->text.setPosition(sf::Vector2f(this->shapeCentre.x + this->shape.getSize().x / 2 + text_shift.x, this->shapeCentre.y + this->shape.getSize().y / 2 + text_shift.y));
        }
        break;

    default:
        {
            this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().left + this->text.getLocalBounds().width / 2, this->text.getLocalBounds().top));
            this->text.setPosition(sf::Vector2f(this->shapeCentre.x + text_shift.x, this->shapeCentre.y - this->shape.getSize().y / 2 + text_shift.y));
        }
        break;
    }
}



//-------------------------                                                         -------------------------//
//+++                                                                                                     +++//
//==============                           M O D    F U N C T I O N S                          ==============//
//+++                                                                                                     +++//
//-------------------------                                                         -------------------------//



void Rectangle::setPosition(const sf::Vector2f& position)
{
    ///sets KEngine Rectangle's position

    this->shape.setPosition(position);

    this->updateShape();
    this->updateText();
}

void Rectangle::setPosition(float x, float y)
{
    ///sets KEngine Rectangle's position

    this->setPosition(sf::Vector2f(x, y));
}

sf::Vector2f Rectangle::getPosition() const
{
    ///returns KEngine Rectangle's position

    return this->shape.getPosition();
}




void Rectangle::move(const sf::Vector2f& offset)
{
    ///moves KEngine Rectangle by offset (px)

    this->shape.move(offset);

    this->updateShape();
    this->updateText();
}


void Rectangle::move(float offset_x, float offset_y)
{
    ///moves KEngine Rectangle by offset (px)

    this->shape.move(offset_x, offset_y);

    this->updateShape();
    this->updateText();
}


void Rectangle::setSize(const sf::Vector2f& size)
{
    ///sets KEngine Rectangle size

    this->shape.setSize(size);
    this->setOrigin(this->origin);
}

void Rectangle::setSize(float size_x, float size_y)
{
    ///sets KEngine Rectangle size

    this->shape.setSize(sf::Vector2f(size_x, size_y));
    this->setOrigin(this->origin);
}

sf::Vector2f Rectangle::getSize() const
{
    ///returns KEngine Rectangle size

    return this->shape.getSize();
}

void Rectangle::setText(const std::wstring& text)
{
    ///changes String of KEngine Rectangle's text (std::wstring)

    this->text.setString(text);
    this->updateText();
}

std::wstring Rectangle::getText() const
{
    ///returns String of KEngine Rectangle's text (std::wstring)

    return this->text.getString();
}



sf::RectangleShape* Rectangle::getShape()
{
    ///returns pointer to sf::RectangleShape that this KEngine Rectangle uses

    return &shape;
}

sf::Text* Rectangle::getSfText()
{
    ///returns pointer to sf::Text that this KEngine Rectangle uses

    return &text;
}


void Rectangle::setOrigin(int origin)
{
    ///changes origin of the KEngine Rectangle
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

int Rectangle::getOrigin() const
{
    ///returns origin of the KEngine Rectangle
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


void Rectangle::setRotation(float angle)
{
    ///rotates, don't really use it

    this->shape.setRotation(angle);
    this->text.setRotation(angle);
}

void Rectangle::Rotate(float angle)
{
    ///rotates, don't really use it

    this->shape.rotate(angle);
    this->text.rotate(angle);
}

float Rectangle::getRotation() const
{
    ///returns KEngine Rectangle's rotation

    return this->shape.getRotation();
}


void Rectangle::setPositionByCentre(const sf::Vector2f& postion)
{
    ///sets position by the centre of the object

    sf::Vector2f delta(this->shape.getPosition().x - this->shapeCentre.x, this->shape.getPosition().y - this->shapeCentre.y);

    this->setPosition(postion.x + delta.x, postion.y + delta.y);
}

sf::Vector2f Rectangle::getShapeCentre() const
{
    ///returns center of KEngine Rectangle

    return this->shapeCentre;
}

void Rectangle::setScale(const sf::Vector2f& factors)
{
    ///sets KEngine Rectangle's scale

    this->shape.setScale(factors);
    this->text.setScale(factors);
}

void Rectangle::setScale(float factor_x, float factor_y)
{
    ///sets KEngine Rectangle's scale

    this->shape.setScale(factor_x, factor_y);
}

void Rectangle::scale(const sf::Vector2f& factors)
{
    ///scales KEngine Rectangle

    this->shape.scale(factors);
    this->text.scale(factors);
}

sf::Vector2f Rectangle::getScale() const
{
    ///returns scale of the KEngine Rectangle

    return this->shape.getScale();
}



void Rectangle::setTexture(const sf::Texture *texture)
{
    ///changes KEngine Rectangle texture
    /// setting texture from other texture

    this->texture = *texture;
    this->shape.setTexture(&this->texture);

    this->texture_on = true;
}


void Rectangle::setTexture(const std::string& texture_path)
{
    ///changes KEngine Rectangle texture
    /// setting texture directly from file

    this->texture.loadFromFile(texture_path);
    this->texture_path = texture_path;

    this->shape.setTexture(&this->texture);
    this->texture_on = true;
}

const sf::Texture *Rectangle::getTexture() const
{
    ///returns pointer to KEngine Rectangle's texture
    /// if there's no texture, it returns nullptr

    if (!this->texture_on)
        return nullptr;
    else
        return this->shape.getTexture();
}

std::string Rectangle::getTexturePath() const
{
    ///just don't use it

    return this->texture_path;
}


void Rectangle::setFillColor(const sf::Color& color)
{
    ///sets KEngine Rectangle's fill color

    this->shape.setFillColor(color);
}

const sf::Color &Rectangle::getFillColor() const
{
    ///returns KEngine Rectangle's fill color

    return this->shape.getFillColor();
}


void Rectangle::setTextColor(const sf::Color& text_color)
{
    ///sets KEngine Rectangle's text fill color

    this->text.setColor(text_color);
}

const sf::Color &Rectangle::getTextColor() const
{
    ///returns KEngine Rectangle's text fill color

    return this->text.getColor();
}


void Rectangle::setOutlineColor(const sf::Color& outline_color)
{
    ///sets KEngine Rectangle's outline color

    this->shape.setOutlineColor(outline_color);
}

const sf::Color &Rectangle::getOutlineColor() const
{
    ///returns KEngine Rectangle's outline color

    return this->shape.getOutlineColor();
}


void Rectangle::setOutlineThickness(float outline_thickness)
{
    ///sets KEngine Rectangle's outline thickness

    this->shape.setOutlineThickness(outline_thickness);
}

float Rectangle::getOutlineThickness() const
{
    ///returns KEngine Rectangle's outline thickness

    return this->shape.getOutlineThickness();
}


void Rectangle::setTextPosition(int position, const sf::Vector2f& text_shift)
{
    ///sets KEngine Rectangle's text position and text shift
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

int Rectangle::getTextPosition() const
{
    ///returns KEngine Rectangle's text position
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

sf::Vector2f Rectangle::getTextShift() const
{
    ///returns KEngine Rectangle's text shift

    return text_shift;
}


void Rectangle::setTextStyle(int style)
{
    ///sets KEngine Rectangle's text style

    this->text.setStyle(style);
}

unsigned int Rectangle::getTextStyle() const
{
    ///returns KEngine Rectangle's text style

    return this->text.getStyle();
}

void Rectangle::setFont(int font)
{
    ///sets KEngine Rectangle's font
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

int Rectangle::getFont() const
{
    ///returns KEngine Rectangle's font
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


void Rectangle::setCharacterSize(unsigned int char_size)
{
    ///sets KEngine Rectangle's text character size

    this->text.setCharacterSize(char_size);
}

unsigned int Rectangle::getCharacterSize() const
{
    ///returns KEngine Rectangle's text character size

    return text.getCharacterSize();
}



//-------------------------                                                         -------------------------//
//+++                                                                                                     +++//
//==============          R E N D E R   A N D   B E H A V I O U R   F U N C T I O N S          ==============//
//+++                                                                                                     +++//
//-------------------------                                                         -------------------------//



bool Rectangle::isInvaded(const sf::Vector2f& mousePosition) const
{
    ///if mouse is on KEngine Rectangle, returns true

    if (this->shape.getRotation() == 0 || this->shape.getRotation() == 90 || this->shape.getRotation() == 180 || this->shape.getRotation() == 270)
    if (mousePosition.x > this->shapeCentre.x - this->shape.getSize().x / 2 * this->shape.getScale().x &&
        mousePosition.x < this->shapeCentre.x + this->shape.getSize().x / 2 * this->shape.getScale().x &&
        mousePosition.y > this->shapeCentre.y - this->shape.getSize().y / 2 * this->shape.getScale().y &&
        mousePosition.y < this->shapeCentre.y + this->shape.getSize().y / 2 * this->shape.getScale().y   )
                return true;
        else    return false;
    else        return false;
}

bool Rectangle::isClicked(sf::Mouse::Button button, const sf::Vector2f& mousePosition, sf::Event& event) const
{
    ///if mouse is on KEngine Rectangle and the right button is clicked, returns true (use in pollEvent loop)

    if (this->isInvaded(mousePosition) && event.type == sf::Event::MouseButtonPressed && event.key.code == button)
            return true;
    else    return false;
}


bool Rectangle::isActive() const
{
    ///if KEngine Rectangle is displayed, returns true

    return this->active;
}

void Rectangle::setActiveStatus(bool status)
{
    ///if KEngine Rectangle is active, it is displayed on the screen

    this->active = status;
}




float Rectangle::update(const sf::Vector2f& mousePosition, sf::Event& event, sf::Mouse::Button button, sf::View* view)
{
    ///rounds text position to integers

    this->text.setPosition(sf::Vector2f(static_cast<int>(this->text.getPosition().x), static_cast<int>(this->text.getPosition().y)));

    return 0;
}


void Rectangle::render(sf::RenderWindow *window)
{
    ///displays KEngine Rectangle on the screen, if active of course

    if (this->active)
    {
        window->draw(this->shape);
        window->draw(this->text);
    }
}




void Rectangle::initPhysics()
{
    ///initializes physics class

    m_physics = std::make_unique<Physics>(this);
}


void Rectangle::initPhysics(long double mass, float friction)
{
    ///initializes physics class

    m_physics = std::make_unique<Physics>(this, mass, friction);
}


void Rectangle::deletePhysics()
{
    ///deletes physics from the object

    m_physics.reset();
}


void Rectangle::updatePhysics(const float dt)
{
    ///updates physics

    if (this->m_physics != nullptr)
        this->m_physics->update(dt);
}


Physics* Rectangle::physics()
{
    ///returns physics class

    return m_physics.get();
}

}
