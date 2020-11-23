#include "Switch.hpp"

namespace ke
{

//-------------------------                                                         -------------------------//
//+++                                                                                                     +++//
//============== C O N S T R U C T O R S ,   D E S T R U C T O R S   A N D   O P E R A T O R S ==============//
//+++                                                                                                     +++//
//-------------------------                                                         -------------------------//



Switch::Switch()
{
    ///KEngine Switch default constructor
    /** KEngine Switch is a on / off object based on KEngine Circle
        and KEngine CurvedButton that allows you to make signal true
        or false, similar to the on / off buttons on your phone,
        inherits from class GuiObject*/

    this->signal = false;
    this->moving = false;
}



Switch::Switch( const sf::Vector2f& size,
                float button_radius,
                const sf::Vector2f& position,
                const sf::Texture* button_texture,
                const sf::Texture* object_texture,
                const sf::Color& button_color,
                const sf::Color& object_color,
                float button_outline_thickness,
                const sf::Color& button_outline_color,
                float object_outline_thickness,
                const sf::Color& object_outline_color,
                bool active )
{
    ///KEngine Switch constructor
    /** KEngine Switch is a on / off object based on KEngine Circle
        and KEngine CurvedButton that allows you to make signal true
        or false, similar to the on / off buttons on your phone,
        inherits from class GuiObject*/

    this->t_button = std::make_unique<Circle>(button_radius, sf::Vector2f(position.x - (size.x - size.y) / 2, position.y), MIDDLE_MIDDLE, button_texture, active);
    this->c_button = std::make_unique<Circle>(button_radius, sf::Vector2f(position.x - (size.x - size.y) / 2, position.y), MIDDLE_MIDDLE, L"", 0, MIDDLE_MIDDLE, button_color, sf::Color::Transparent, button_outline_thickness, button_outline_color, sf::Text::Regular, sf::Vector2f(0, 0), Arial, active);
    this->object = std::make_unique<CurvedButton>(size, position, object_texture, L"", 0, MIDDLE_MIDDLE, object_color, sf::Color::Transparent, object_outline_thickness, object_outline_color, 0, sf::Text::Regular, sf::Vector2f(0, 0), Arial, active);

    this->signal = false;
    this->moving = false;
}

Switch::Switch( const sf::Vector2f& size,
                float button_radius,
                const sf::Vector2f& position,
                const std::string& button_texture_path,
                const std::string& object_texture_path,
                const sf::Color& button_color,
                const sf::Color& object_color,
                float button_outline_thickness,
                const sf::Color& button_outline_color,
                float object_outline_thickness,
                const sf::Color& object_outline_color,
                bool active )
{
    ///KEngine Switch constructor
    /** KEngine Switch is a on / off object based on KEngine Circle
        and KEngine CurvedButton that allows you to make signal true
        or false, similar to the on / off buttons on your phone,
        inherits from class GuiObject*/

    this->t_button = std::make_unique<Circle>(button_radius, sf::Vector2f(position.x - (size.x - size.y) / 2, position.y), MIDDLE_MIDDLE, button_texture_path, active);
    this->c_button = std::make_unique<Circle>(button_radius, sf::Vector2f(position.x - (size.x - size.y) / 2, position.y), MIDDLE_MIDDLE, L"", 0, MIDDLE_MIDDLE, button_color, sf::Color::Transparent, button_outline_thickness, button_outline_color, sf::Text::Regular, sf::Vector2f(0, 0), Arial, active);
    this->object = std::make_unique<CurvedButton>(size, position, object_texture_path, L"", 0, MIDDLE_MIDDLE, object_color, sf::Color::Transparent, object_outline_thickness, object_outline_color, 0, sf::Text::Regular, sf::Vector2f(0, 0), Arial, active);

    this->signal = false;
    this->moving = false;
}



Switch::~Switch()
{
    ///KEngine Switch destructor
    /** KEngine Switch is a on / off object based on KEngine Circle
        and KEngine CurvedButton that allows you to make signal true
        or false, similar to the on / off buttons on your phone,
        inherits from class GuiObject*/
}


Switch::Switch(Switch& other)
{
    ///KEngine Switch copy constructor
    /** KEngine Switch is a on / off object based on KEngine Circle
        and KEngine CurvedButton that allows you to make signal true
        or false, similar to the on / off buttons on your phone,
        inherits from class GuiObject*/

    this->t_button->operator = (*other.getTextureButton());
    this->c_button->operator = (*other.getColorButton());
    this->object->operator = (*other.getObject());

    this->signal = other.getSignal();
    this->moving = false;
}


Switch& Switch::operator= (Switch& other)
{
    ///KEngine Rectangle operator =
    /** KEngine Switch is a on / off object based on KEngine Circle
        and KEngine CurvedButton that allows you to make signal true
        or false, similar to the on / off buttons on your phone,
        inherits from class GuiObject*/

    this->t_button->operator = (*other.getTextureButton());
    this->c_button->operator = (*other.getColorButton());
    this->object->operator = (*other.getObject());

    this->signal = other.getSignal();
    this->moving = false;

    return *this;
}


void Switch::create( const sf::Vector2f& size,
                     float button_radius,
                     const sf::Vector2f& position,
                     const sf::Texture* button_texture,
                     const sf::Texture* object_texture,
                     const sf::Color& button_color,
                     const sf::Color& object_color,
                     float button_outline_thickness,
                     const sf::Color& button_outline_color,
                     float object_outline_thickness,
                     const sf::Color& object_outline_color,
                     bool active )
{
    ///KEngine Switch create function <br>
    ///use with default constructor
    /** KEngine Switch is a on / off object based on KEngine Circle
        and KEngine CurvedButton that allows you to make signal true
        or false, similar to the on / off buttons on your phone,
        inherits from class GuiObject*/

    this->t_button = std::make_unique<Circle>(button_radius, sf::Vector2f(position.x - (size.x - size.y) / 2, position.y), MIDDLE_MIDDLE, button_texture, active);
    this->c_button = std::make_unique<Circle>(button_radius, sf::Vector2f(position.x - (size.x - size.y) / 2, position.y), MIDDLE_MIDDLE, L"", 0, MIDDLE_MIDDLE, button_color, sf::Color::Transparent, button_outline_thickness, button_outline_color, sf::Text::Regular, sf::Vector2f(0, 0), Arial, active);
    this->object = std::make_unique<CurvedButton>(size, position, object_texture, L"", 0, MIDDLE_MIDDLE, object_color, sf::Color::Transparent, object_outline_thickness, object_outline_color, 0, sf::Text::Regular, sf::Vector2f(0, 0), Arial, active);
}


void Switch::create( const sf::Vector2f& size,
                     float button_radius,
                     const sf::Vector2f& position,
                     const std::string& button_texture_path,
                     const std::string& object_texture_path,
                     const sf::Color& button_color,
                     const sf::Color& object_color,
                     float button_outline_thickness,
                     const sf::Color& button_outline_color,
                     float object_outline_thickness,
                     const sf::Color& object_outline_color,
                     bool active )
{
    ///KEngine Switch create function <br>
    ///use with default constructor
    /** KEngine Switch is a on / off object based on KEngine Circle
        and KEngine CurvedButton that allows you to make signal true
        or false, similar to the on / off buttons on your phone,
        inherits from class GuiObject*/

    this->t_button = std::make_unique<Circle>(button_radius, sf::Vector2f(position.x - (size.x - size.y) / 2, position.y), MIDDLE_MIDDLE, button_texture_path, active);
    this->c_button = std::make_unique<Circle>(button_radius, sf::Vector2f(position.x - (size.x - size.y) / 2, position.y), MIDDLE_MIDDLE, L"", 0, MIDDLE_MIDDLE, button_color, sf::Color::Transparent, button_outline_thickness, button_outline_color, sf::Text::Regular, sf::Vector2f(0, 0), Arial, active);
    this->object = std::make_unique<CurvedButton>(size, position, object_texture_path, L"", 0, MIDDLE_MIDDLE, object_color, sf::Color::Transparent, object_outline_thickness, object_outline_color, 0, sf::Text::Regular, sf::Vector2f(0, 0), Arial, active);
}



//-------------------------                                                         -------------------------//
//+++                                                                                                     +++//
//==============                           M O D    F U N C T I O N S                          ==============//
//+++                                                                                                     +++//
//-------------------------                                                         -------------------------//



void Switch::setPosition(const sf::Vector2f& position)
{
    ///sets KEngine Rectangle's position

    this->object->setPosition(position);
    this->t_button->setPosition(sf::Vector2f(this->object->getPosition().x - (this->object->getSize().x * this->object->getScale().x) / 2, position.y));
    this->c_button->setPosition(sf::Vector2f(this->object->getPosition().x - (this->object->getSize().x * this->object->getScale().x) / 2, position.y));
}

void Switch::setPosition(float x, float y)
{
    ///sets KEngine Rectangle's position

    this->setPosition(sf::Vector2f(x, y));
}

sf::Vector2f Switch::getPosition() const
{
    ///returns KEngine Rectangle's position

    return this->object->getPosition();
}


void Switch::setSize(const sf::Vector2f& size)
{
    ///sets KEngine Rectangle size

    this->object->setSize(size);
    this->c_button->setPosition(this->object->getPosition().x - (size.x * object->getScale().x) / 2, this->object->getPosition().y);
    this->t_button->setPosition(this->object->getPosition().x - (size.x * object->getScale().x) / 2, this->object->getPosition().y);
}

void Switch::setSize(float size_x, float size_y)
{
    ///sets KEngine Rectangle size

    this->setSize(sf::Vector2f(size_x, size_y));
}

sf::Vector2f Switch::getSize() const
{
    ///returns KEngine Rectangle size

    return this->object->getSize();
}

void Switch::setButtonRadius(float radius)
{
    ///sets radius of the button

    this->t_button->setRadius(radius);
    this->c_button->setRadius(radius);

    this->t_button->setPosition((this->object->getPosition().x - this->object->getSize().y) / 2, this->object->getPosition().y);
    this->c_button->setPosition((this->object->getPosition().x - this->object->getSize().y) / 2, this->object->getPosition().y);
}

float Switch::getButtonRadius() const
{
    ///returns radius of the button

    return this->c_button->getRadius();
}


void Switch::move(const sf::Vector2f& offset)
{
    ///moves KEngine Rectangle by offset (px)

    this->object->move(offset);
    this->t_button->move(offset);
    this->c_button->move(offset);
}

void Switch::move(float offset_x, float offset_y)
{
    ///moves KEngine Rectangle by offset (px)

    this->object->move(offset_x, offset_y);
    this->t_button->move(offset_x, offset_y);
    this->c_button->move(offset_x, offset_y);
}


void Switch::setScale(const sf::Vector2f& factors)
{
    ///sets KEngine Rectangle's scale

    this->object->setScale(factors);
    this->setPosition(this->object->getPosition());
}

void Switch::setScale(float factor_x, float factor_y)
{
    ///sets KEngine Rectangle's scale

    this->object->setScale(factor_x, factor_y);
    this->setPosition(this->object->getPosition());
}

void Switch::setButtonScale(const sf::Vector2f& factors)
{
    ///sets KEngine Rectangle's button scale

    this->c_button->setScale(factors);
    this->t_button->setScale(factors);
}

void Switch::setButtonScale(float factor_x, float factor_y)
{
    ///sets KEngine Rectangle's button scale

    this->c_button->setScale(factor_x, factor_y);
    this->t_button->setScale(factor_x, factor_y);
    this->setPosition(this->object->getPosition());
}

void Switch::scale(const sf::Vector2f& factors)
{
    ///scales KEngine Rectangle

    this->object->scale(factors);
    this->setPosition(this->object->getPosition());
}

void Switch::scaleButton(const sf::Vector2f& factors)
{
    ///scales KEngine Rectangle's button

    this->c_button->scale(factors);
    this->t_button->scale(factors);
    this->setPosition(this->object->getPosition());
}

sf::Vector2f Switch::getScale() const
{
    ///returns scale of the KEngine Rectangle

    return this->object->getScale();
}

sf::Vector2f Switch::getButtonScale() const
{
    ///returns scale of the KEngine Rectangle's button

    return this->t_button->getScale();
}


void Switch::setPositionByCentre(const sf::Vector2f& postion)
{
    ///sets position by the centre of the object

    sf::Vector2f delta(this->object->getPosition().x - this->object->getShapeCentre().x, this->object->getPosition().y - this->object->getShapeCentre().y);

    this->setPosition(postion.x + delta.x, postion.y + delta.y);
}

sf::Vector2f Switch::getShapeCentre() const
{
    ///returns centre of the object

    return object->getShapeCentre();
}

sf::Vector2f Switch::getButtonCentre() const
{
    ///returns centre of the button

    return t_button->getShapeCentre();
}


void Switch::setTexture(const sf::Texture* texture)
{
    ///changes KEngine Rectangle texture
    /// setting texture from other texture

    this->object->setTexture(texture);
}

void Switch::setButtonTexture(const sf::Texture* texture)
{
    ///changes KEngine Rectangle's button texture
    /// setting texture from other texture

    this->t_button->setTexture(texture);
}

void Switch::setTexture(const std::string& texture_path)
{
    ///changes KEngine Rectangle texture
    /// setting texture directly from file

    this->object->setTexture(texture_path);
}

void Switch::setButtonTexture(const std::string& texture_path)
{
    ///changes KEngine Rectangle's button texture
    /// setting texture directly from file

    this->t_button->setTexture(texture_path);
}

const sf::Texture* Switch::getTexture() const
{
    ///returns pointer to KEngine Rectangle's texture
    /// if there's no texture, it returns nullptr

    return this->object->getTexture();
}

const sf::Texture* Switch::getButtonTexture() const
{
    ///returns pointer to KEngine Rectangle's button texture
    /// if there's no texture, it returns nullptr

    return this->t_button->getTexture();
}


void Switch::setFillColor(const sf::Color& color)
{
    ///sets KEngine Rectangle's fill color

    this->object->setFillColor(color);
}

void Switch::setButtonColor(const sf::Color& color)
{
    ///sets KEngine Rectangle's button fill color

    c_button->setFillColor(color);
}

const sf::Color& Switch::getFillColor() const
{
    ///returns KEngine Rectangle's fill color

    return this->object->getFillColor();
}

const sf::Color& Switch::getButtonColor() const
{
    ///returns KEngine Rectangle's button fill color

    return this->c_button->getFillColor();
}


void Switch::setTextColor(const sf::Color& text_color)
{
    ///does nothing, no text in this object
}

const sf::Color& Switch::getTextColor() const
{
    ///does nothing, no text in this object

    return sf::Color::Transparent;
}


void Switch::setOutlineColor(const sf::Color& outline_color)
{
    ///sets KEngine Rectangle's outline color

    this->object->setOutlineColor(outline_color);
}

void Switch::setOutlineButtonColor(const sf::Color& outline_color)
{
    ///sets KEngine Rectangle's button outline color

    this->c_button->setOutlineColor(outline_color);
}

const sf::Color& Switch::getOutlineColor() const
{
    ///returns KEngine Rectangle's outline color

    return this->object->getOutlineColor();
}

const sf::Color& Switch::getOutlineButtonColor() const
{
    ///returns KEngine Rectangle's button outline color

    return this->c_button->getOutlineColor();
}


void Switch::setOutlineThickness(float outline_thickness)
{
    ///sets KEngine Rectangle's outline thickness

    this->object->setOutlineThickness(outline_thickness);
}

void Switch::setOutlineButtonThickness(float outline_thickness)
{
    ///sets KEngine Rectangle's button outline thickness

    this->c_button->setOutlineThickness(outline_thickness);
}

float Switch::getOutlineThickness() const
{
    ///returns KEngine Rectangle's outline thickness

    return this->object->getOutlineThickness();
}

float Switch::getOutlineButtonThickness() const
{
    ///returns KEngine Rectangle's button outline thickness

    return this->c_button->getOutlineThickness();
}



//-------------------------                                                         -------------------------//
//+++                                                                                                     +++//
//==============          R E N D E R   A N D   B E H A V I O U R   F U N C T I O N S          ==============//
//+++                                                                                                     +++//
//-------------------------                                                         -------------------------//



bool Switch::isInvaded(const sf::Vector2f& mousePosition) const
{
    ///if mouse is on KEngine Rectangle, returns true

    return this->object->isInvaded(mousePosition);
}

bool Switch::isButtonInvaded(const sf::Vector2f& mousePosition) const
{
    ///if mouse is on KEngine Rectangle's button, returns true

    return this->t_button->isInvaded(mousePosition);
}

bool Switch::isClicked(sf::Mouse::Button button, const sf::Vector2f& mousePosition, sf::Event& event) const
{
    ///if mouse is on KEngine Rectangle and the right button is clicked, returns true (use in pollEvent loop)

    return this->object->isClicked(button, mousePosition, event);
}

bool Switch::isButtonClicked(sf::Mouse::Button button, const sf::Vector2f& mousePosition, sf::Event& event) const
{
    ///if mouse is on KEngine Rectangle's button and the right button is clicked, returns true (use in pollEvent loop)

    return this->t_button->isClicked(button, mousePosition, event);
}



bool Switch::isActive() const
{
    ///if KEngine Rectangle is displayed, returns true

    return this->object->isActive();
}

void Switch::setActiveStatus(bool status)
{
    ///if KEngine Rectangle is active, it is displayed on the screen

    this->c_button->setActiveStatus(status);
    this->t_button->setActiveStatus(status);
    this->object->setActiveStatus(status);
}



Circle* Switch::getColorButton()
{
    return this->c_button.get();
}

Circle* Switch::getTextureButton()
{
    return this->t_button.get();
}

CurvedButton* Switch::getObject()
{
    return this->object.get();
}



void Switch::setSignal(bool signal)
{
    ///sets the signal
    /** <br> on - true <br> off - false*/

    this->signal = signal;

    if (signal)
    {
        t_button->setPosition(object->getPosition().x + object->getSize().x / 2, object->getPosition().y);
        c_button->setPosition(object->getPosition().x + object->getSize().x / 2, object->getPosition().y);
    }
    else
    {
        t_button->setPosition(object->getPosition().x - object->getSize().x / 2, object->getPosition().y);
        c_button->setPosition(object->getPosition().x - object->getSize().x / 2, object->getPosition().y);
    }
}

bool Switch::getSignal() const
{
    ///returns the signal
    /** <br> on - true <br> off - false*/

    return this->signal;
}



bool Switch::isMoving() const
{
    ///if button is moving, return true
    /** used in SmoothSignalChange */

    return this->moving;
}



float Switch::update(const sf::Vector2f& mousePosition, sf::Event& event, sf::Mouse::Button button, sf::View* view)
{
    ///1/2 heart of the KEngine Switch, use if you don't want the smooth change

    if (this->isClicked(button, mousePosition, event))
    {
        if (signal) signal = false;
        else        signal = true;

        if (signal)
        {
            t_button->setPosition(object->getPosition().x + object->getSize().x / 2, object->getPosition().y);
            c_button->setPosition(object->getPosition().x + object->getSize().x / 2, object->getPosition().y);
        }
        else
        {
            t_button->setPosition(object->getPosition().x - object->getSize().x / 2, object->getPosition().y);
            c_button->setPosition(object->getPosition().x - object->getSize().x / 2, object->getPosition().y);
        }

        return 1;
    }
    else return 0;
}

void Switch::SSC_click_update(const sf::Vector2f& mousePosition, sf::Event& event, sf::Mouse::Button button)
{
    ///!!! required to run KEngine Switch SmoothSignalChange properly !!!

    if (this->isClicked(button, mousePosition, event) && !moving)
    {
        this->moving = true;
        if (signal) signal = false;
        else        signal = true;
    }
}

float Switch::SmoothSignalChange(const sf::Vector2f& mousePosition, sf::Mouse::Button button, float speed, float dt)
{
    ///!!! SSC_click_update(...) in sf::Window::pollEvent required to run this function properly !!!
    ///<br>2/2 heart of the KEngine Switch, use if you want the smooth change

    if (this->moving)
    {
        if (signal)
        {
            this->t_button->move(speed * dt, 0);
            this->c_button->move(speed * dt, 0);
        }
        else
        {
            this->t_button->move(-speed * dt, 0);
            this->c_button->move(-speed * dt, 0);
        }

        if (t_button->getPosition().x < object->getPosition().x - object->getSize().x / 2)
        {
            t_button->setPosition(object->getPosition().x - object->getSize().x / 2, object->getPosition().y);
            c_button->setPosition(object->getPosition().x - object->getSize().x / 2, object->getPosition().y);

            this->moving = false;
        }
        else if (t_button->getPosition().x > object->getPosition().x + object->getSize().x / 2)
        {
            t_button->setPosition(object->getPosition().x + object->getSize().x / 2, object->getPosition().y);
            c_button->setPosition(object->getPosition().x + object->getSize().x / 2, object->getPosition().y);

            this->moving = false;
        }

        return 1;
    }
    else return 0;
}


void Switch::render(sf::RenderWindow* window)
{
    ///displays KEngine Rectangle on the screen, if active of course

    this->object->render(window);

    this->c_button->render(window);
    this->t_button->render(window);
}

}
