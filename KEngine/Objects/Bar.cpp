#include "Bar.hpp"

namespace ke
{

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// \ \ \ \ \ \ \
//
//  P  E  R  C  E  N  T  A  G  E    %
//
// / / / / / / /
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =


//-------------------------                                                         -------------------------//
//+++                                                                                                     +++//
//============== C O N S T R U C T O R S ,   D E S T R U C T O R S   A N D   O P E R A T O R S ==============//
//+++                                                                                                     +++//
//-------------------------                                                         -------------------------//


PercentageBar::PercentageBar()
{
    ///KEngine PercentageBar default constructor
    /** KEngine PercentageBar is an object based on KEngine Circle and
        KEngine CurvedButton - it works like a volume bar, for ex. it
        can give % of sound volume, user can modify it by sliding the
        button form right (0%) to left (100%), inherits from class
        GuiObject*/


    this->shift = 0;
    this->holded = false;
    this->catchDiff = 0;
}


PercentageBar::PercentageBar( const sf::Vector2f& size,
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
    ///KEngine PercentageBar constructor
    /** KEngine PercentageBar is an object based on KEngine Circle and
        KEngine CurvedButton - it works like a volume bar, for ex. it
        can give % of sound volume, user can modify it by sliding the
        button form right (0%) to left (100%), inherits from class
        GuiObject*/

    this->t_button = std::make_unique<Circle>(button_radius, sf::Vector2f(position.x - (size.x - size.y) / 2, position.y), MIDDLE_MIDDLE, button_texture, active);
    this->c_button = std::make_unique<Circle>(button_radius, sf::Vector2f(position.x - (size.x - size.y) / 2, position.y), MIDDLE_MIDDLE, L"", 0, MIDDLE_MIDDLE, button_color, sf::Color::Transparent, button_outline_thickness, button_outline_color, sf::Text::Regular, sf::Vector2f(0, 0), Arial, active);
    this->object = std::make_unique<CurvedButton>(size, position, object_texture, L"", 0, MIDDLE_MIDDLE, object_color, sf::Color::Transparent, object_outline_thickness, object_outline_color, 0, sf::Text::Regular, sf::Vector2f(0, 0), Arial, active);

    this->shift = 0;
    this->holded = false;
    this->catchDiff = 0;
}

PercentageBar::PercentageBar( const sf::Vector2f& size,
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
    ///KEngine PercentageBar constructor
    /** KEngine PercentageBar is an object based on KEngine Circle and
        KEngine CurvedButton - it works like a volume bar, for ex. it
        can give % of sound volume, user can modify it by sliding the
        button form right (0%) to left (100%), inherits from class
        GuiObject*/

    this->t_button = std::make_unique<Circle>(button_radius, sf::Vector2f(position.x - (size.x - size.y) / 2, position.y), MIDDLE_MIDDLE, button_texture_path, active);
    this->c_button = std::make_unique<Circle>(button_radius, sf::Vector2f(position.x - (size.x - size.y) / 2, position.y), MIDDLE_MIDDLE, L"", 0, MIDDLE_MIDDLE, button_color, sf::Color::Transparent, button_outline_thickness, button_outline_color, sf::Text::Regular, sf::Vector2f(0, 0), Arial, active);
    this->object = std::make_unique<CurvedButton>(size, position, object_texture_path, L"", 0, MIDDLE_MIDDLE, object_color, sf::Color::Transparent, object_outline_thickness, object_outline_color, 0, sf::Text::Regular, sf::Vector2f(0, 0), Arial, active);

    this->shift = 0;
    this->holded = false;
    this->catchDiff = 0;
}


PercentageBar::~PercentageBar()
{
    ///KEngine PercentageBar destructor
    /** KEngine PercentageBar is an object based on KEngine Circle and
        KEngine CurvedButton - it works like a volume bar, for ex. it
        can give % of sound volume, user can modify it by sliding the
        button form right (0%) to left (100%), inherits from class
        GuiObject*/
}


PercentageBar::PercentageBar(PercentageBar& other)
{
    ///KEngine PercentageBar copy constructor
    /** KEngine PercentageBar is an object based on KEngine Circle and
        KEngine CurvedButton - it works like a volume bar, for ex. it
        can give % of sound volume, user can modify it by sliding the
        button form right (0%) to left (100%), inherits from class
        GuiObject*/

    this->t_button->operator = (*other.getTextureButton()); // WTF
    this->c_button->operator = (*other.getColorButton()); // WTF
    this->object->operator = (*other.getObject()); // WTF

    this->shift = other.getShift();
    this->holded = false;
    this->catchDiff = 0;
}


PercentageBar& PercentageBar::operator= (PercentageBar& other)
{
    ///KEngine PercentageBar operator =
    /** KEngine PercentageBar is an object based on KEngine Circle and
        KEngine CurvedButton - it works like a volume bar, for ex. it
        can give % of sound volume, user can modify it by sliding the
        button form right (0%) to left (100%), inherits from class
        GuiObject*/

    this->t_button->operator = (*other.getTextureButton()); // WTF
    this->c_button->operator = (*other.getColorButton()); // WTF
    this->object->operator = (*other.getObject()); // WTF

    this->shift = other.getShift();
    this->holded = false;
    this->catchDiff = 0;

    return *this;
}



void PercentageBar::create( const sf::Vector2f& size,
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
    ///KEngine PercentageBar create function <br>
    ///use with default constructor
    /** KEngine PercentageBar is an object based on KEngine Circle and
        KEngine CurvedButton - it works like a volume bar, for ex. it
        can give % of sound volume, user can modify it by sliding the
        button form right (0%) to left (100%), inherits from class
        GuiObject*/

    this->t_button = std::make_unique<Circle>(button_radius, sf::Vector2f(position.x - (size.x - size.y) / 2, position.y), MIDDLE_MIDDLE, button_texture, active);
    this->c_button = std::make_unique<Circle>(button_radius, sf::Vector2f(position.x - (size.x - size.y) / 2, position.y), MIDDLE_MIDDLE, L"", 0, MIDDLE_MIDDLE, button_color, sf::Color::Transparent, button_outline_thickness, button_outline_color, sf::Text::Regular, sf::Vector2f(0, 0), Arial, active);
    this->object = std::make_unique<CurvedButton>(size, position, object_texture, L"", 0, MIDDLE_MIDDLE, object_color, sf::Color::Transparent, object_outline_thickness, object_outline_color, 0, sf::Text::Regular, sf::Vector2f(0, 0), Arial, active);
}


void PercentageBar::create( const sf::Vector2f& size,
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
    ///KEngine PercentageBar create function <br>
    ///use with default constructor
    /** KEngine PercentageBar is an object based on KEngine Circle and
        KEngine CurvedButton - it works like a volume bar, for ex. it
        can give % of sound volume, user can modify it by sliding the
        button form right (0%) to left (100%), inherits from class
        GuiObject*/

    this->t_button = std::make_unique<Circle>(button_radius, sf::Vector2f(position.x - (size.x - size.y) / 2, position.y), MIDDLE_MIDDLE, button_texture_path, active);
    this->c_button = std::make_unique<Circle>(button_radius, sf::Vector2f(position.x - (size.x - size.y) / 2, position.y), MIDDLE_MIDDLE, L"", 0, MIDDLE_MIDDLE, button_color, sf::Color::Transparent, button_outline_thickness, button_outline_color, sf::Text::Regular, sf::Vector2f(0, 0), Arial, active);
    this->object = std::make_unique<CurvedButton>(size, position, object_texture_path, L"", 0, MIDDLE_MIDDLE, object_color, sf::Color::Transparent, object_outline_thickness, object_outline_color, 0, sf::Text::Regular, sf::Vector2f(0, 0), Arial, active);
}



//-------------------------                                                         -------------------------//
//+++                                                                                                     +++//
//==============                           M O D    F U N C T I O N S                          ==============//
//+++                                                                                                     +++//
//-------------------------                                                         -------------------------//



void PercentageBar::setPosition(const sf::Vector2f& position)
{
    ///sets KEngine PercentageBar's position

    this->object->setPosition(position);
    this->t_button->setPosition(sf::Vector2f(this->object->getPosition().x - (this->object->getSize().x * this->object->getScale().x) / 2, position.y));
    this->c_button->setPosition(sf::Vector2f(this->object->getPosition().x - (this->object->getSize().x * this->object->getScale().x) / 2, position.y));
}

void PercentageBar::setPosition(float x, float y)
{
    ///sets KEngine PercentageBar's position

    this->setPosition(sf::Vector2f(x, y));
}

sf::Vector2f PercentageBar::getPosition() const
{
    ///returns KEngine PercentageBar's position

    return this->object->getPosition();
}


void PercentageBar::setSize(const sf::Vector2f& size)
{
    ///sets KEngine PercentageBar size

    this->object->setSize(size);
    this->c_button->setPosition(this->object->getPosition().x - (size.x * object->getScale().x) / 2, this->object->getPosition().y);
    this->t_button->setPosition(this->object->getPosition().x - (size.x * object->getScale().x) / 2, this->object->getPosition().y);
}

void PercentageBar::setSize(float size_x, float size_y)
{
    ///sets KEngine PercentageBar size

    this->setSize(sf::Vector2f(size_x, size_y));
}

sf::Vector2f PercentageBar::getSize() const
{
    ///returns KEngine PercentageBar size

    return this->object->getSize();
}

void PercentageBar::setButtonRadius(float radius)
{
    ///sets KEngine PercentageBar button radius

    this->t_button->setRadius(radius);
    this->c_button->setRadius(radius);

    this->t_button->setPosition((this->object->getPosition().x - this->object->getSize().y) / 2, this->object->getPosition().y);
    this->c_button->setPosition((this->object->getPosition().x - this->object->getSize().y) / 2, this->object->getPosition().y);
}

float PercentageBar::getButtonRadius() const
{
    ///returns KEngine PercentageBar button radius

    return this->c_button->getRadius();
}


void PercentageBar::move(const sf::Vector2f& offset)
{
    ///moves KEngine PercentageBar by offset (px)

    this->object->move(offset);
    this->t_button->move(offset);
    this->c_button->move(offset);
}

void PercentageBar::move(float offset_x, float offset_y)
{
    ///moves KEngine PercentageBar by offset (px)

    this->object->move(offset_x, offset_y);
    this->t_button->move(offset_x, offset_y);
    this->c_button->move(offset_x, offset_y);
}


void PercentageBar::setScale(const sf::Vector2f& factors)
{
    ///sets KEngine PercentageBar's scale

    this->object->setScale(factors);
    this->setPosition(this->object->getPosition());
}

void PercentageBar::setScale(float factor_x, float factor_y)
{
    ///sets KEngine PercentageBar's scale

    this->object->setScale(factor_x, factor_y);
    this->setPosition(this->object->getPosition());
}

void PercentageBar::setButtonScale(const sf::Vector2f& factors)
{
    ///sets KEngine PercentageBar's button scale

    this->c_button->setScale(factors);
    this->t_button->setScale(factors);
}

void PercentageBar::setButtonScale(float factor_x, float factor_y)
{
    ///sets KEngine PercentageBar's button scale

    this->c_button->setScale(factor_x, factor_y);
    this->t_button->setScale(factor_x, factor_y);
    this->setPosition(this->object->getPosition());
}

void PercentageBar::scale(const sf::Vector2f& factors)
{
    ///scales KEngine PercentageBar

    this->object->scale(factors);
    this->setPosition(this->object->getPosition());
}

void PercentageBar::scaleButton(const sf::Vector2f& factors)
{
    ///scales KEngine PercentageBar's button

    this->c_button->scale(factors);
    this->t_button->scale(factors);
    this->setPosition(this->object->getPosition());
}

sf::Vector2f PercentageBar::getScale() const
{
    ///returns KEngine PercentageBar's scale

    return this->object->getScale();
}

sf::Vector2f PercentageBar::getButtonScale() const
{
    ///returns KEngine PercentageBar's button scale

    return this->t_button->getScale();
}


void PercentageBar::setPositionByCentre(const sf::Vector2f& postion)
{
    ///sets position by the centre of the object

    sf::Vector2f delta(this->object->getPosition().x - this->object->getShapeCentre().x, this->object->getPosition().y - this->object->getShapeCentre().y);

    this->setPosition(postion.x + delta.x, postion.y + delta.y);
}

sf::Vector2f PercentageBar::getShapeCentre() const
{
    ///returns centre of the object

    return object->getShapeCentre();
}

sf::Vector2f PercentageBar::getButtonCentre() const
{
    ///returns centre of the button

    return t_button->getShapeCentre();
}


void PercentageBar::setTexture(const sf::Texture* texture)
{
    ///changes KEngine PercentageBar texture
    /// setting texture from other texture

    this->object->setTexture(texture);
}

void PercentageBar::setButtonTexture(const sf::Texture* texture)
{
    ///changes KEngine PercentageBar's button texture
    /// setting texture from other texture

    this->t_button->setTexture(texture);
}

void PercentageBar::setTexture(const std::string& texture_path)
{
    ///changes KEngine PercentageBar texture
    /// setting texture directly from file

    this->object->setTexture(texture_path);
}

void PercentageBar::setButtonTexture(const std::string& texture_path)
{
    ///changes KEngine PercentageBar's button texture
    /// setting texture directly from file

    this->t_button->setTexture(texture_path);
}

const sf::Texture* PercentageBar::getTexture() const
{
    ///returns pointer to KEngine PercentageBar's texture
    /// if there's no texture, it returns nullptr

    return this->object->getTexture();
}

const sf::Texture* PercentageBar::getButtonTexture() const
{
    ///returns pointer to KEngine PercentageBar's button texture
    /// if there's no texture, it returns nullptr

    return this->t_button->getTexture();
}


void PercentageBar::setFillColor(const sf::Color& color)
{
    ///sets KEngine PercentageBar's fill color

    this->object->setFillColor(color);
}

void PercentageBar::setButtonColor(const sf::Color& color)
{
    ///sets KEngine PercentageBar's button fill color

    c_button->setFillColor(color);
}

const sf::Color& PercentageBar::getFillColor() const
{
    ///returns KEngine PercentageBar's fill color

    return this->object->getFillColor();
}

const sf::Color& PercentageBar::getButtonColor() const
{
    ///returns KEngine PercentageBar's button fill color

    return this->c_button->getFillColor();
}


void PercentageBar::setTextColor(const sf::Color& text_color)
{
    /// does nothing - not text in this object
}

const sf::Color& PercentageBar::getTextColor() const
{
    /// does nothing - not text in this object

    return sf::Color::Transparent;
}


void PercentageBar::setOutlineColor(const sf::Color& outline_color)
{
    ///sets KEngine PercentageBar's outline color

    this->object->setOutlineColor(outline_color);
}

void PercentageBar::setOutlineButtonColor(const sf::Color& outline_color)
{
    ///sets KEngine PercentageBar's button outline color

    this->c_button->setOutlineColor(outline_color);
}

const sf::Color& PercentageBar::getOutlineColor() const
{
    ///returns KEngine PercentageBar's outline color

    return this->object->getOutlineColor();
}

const sf::Color& PercentageBar::getOutlineButtonColor() const
{
    ///returns KEngine PercentageBar's button outline color

    return this->c_button->getOutlineColor();
}


void PercentageBar::setOutlineThickness(float outline_thickness)
{
    ///sets KEngine PercentageBar's outline thickness

    this->object->setOutlineThickness(outline_thickness);
}

void PercentageBar::setOutlineButtonThickness(float outline_thickness)
{
    ///sets KEngine PercentageBar's button outline thickness

    this->c_button->setOutlineThickness(outline_thickness);
}

float PercentageBar::getOutlineThickness() const
{
    ///returns KEngine PercentageBar's outline thickness

    return this->object->getOutlineThickness();
}

float PercentageBar::getOutlineButtonThickness() const
{
    ///returns KEngine PercentageBar's button outline thickness

    return this->c_button->getOutlineThickness();
}



//-------------------------                                                         -------------------------//
//+++                                                                                                     +++//
//==============          R E N D E R   A N D   B E H A V I O U R   F U N C T I O N S          ==============//
//+++                                                                                                     +++//
//-------------------------                                                         -------------------------//



bool PercentageBar::isInvaded(const sf::Vector2f& mousePosition) const
{
    ///if mouse is on KEngine PercentageBar, returns true

    return this->object->isInvaded(mousePosition);
}

bool PercentageBar::isButtonInvaded(const sf::Vector2f& mousePosition) const
{
    ///if mouse is on KEngine PercentageBar's button, returns true

    return this->t_button->isInvaded(mousePosition);
}

bool PercentageBar::isClicked(sf::Mouse::Button button, const sf::Vector2f& mousePosition, sf::Event& event) const
{
    ///if mouse is on KEngine PercentageBar and the right button is clicked, returns true (use in pollEvent loop)

    return this->object->isClicked(button, mousePosition, event);
}

bool PercentageBar::isButtonClicked(sf::Mouse::Button button, const sf::Vector2f& mousePosition, sf::Event& event) const
{
    ///if mouse is on KEngine PercentageBar's button and the right button is clicked, returns true (use in pollEvent loop)

    return this->t_button->isClicked(button, mousePosition, event);
}



bool PercentageBar::isActive() const
{
    ///if KEngine PercentageBar is displayed, returns true

    return this->object->isActive();
}

void PercentageBar::setActiveStatus(bool status)
{
    ///if KEngine PercentageBar is active, it is displayed on the screen

    this->c_button->setActiveStatus(status);
    this->t_button->setActiveStatus(status);
    this->object->setActiveStatus(status);
}



Circle* PercentageBar::getColorButton()
{
    return this->c_button.get();
}

Circle* PercentageBar::getTextureButton()
{
    return this->t_button.get();
}

CurvedButton* PercentageBar::getObject()
{
    return this->object.get();
}



void PercentageBar::setPercent(float percent)
{
    ///sets the percent of KEngine PercentageBar's shift

    this->t_button->setPosition(sf::Vector2f(this->object->getPosition().x - (this->object->getSize().x * this->object->getScale().x) / 2 + this->object->getSize().x * this->object->getScale().x * (percent / 100), this->object->getPosition().y));
    this->c_button->setPosition(sf::Vector2f(this->object->getPosition().x - (this->object->getSize().x * this->object->getScale().x) / 2 + this->object->getSize().x * this->object->getScale().x * (percent / 100), this->object->getPosition().y));

    this->shift = this->object->getSize().x * (percent / 100);
}


float PercentageBar::getPercent() const
{
    ///returns the percent of KEngine PercentageBar's shift

    return this->shift * 100 / this->object->getSize().x;
}



bool PercentageBar::isHolded() const
{
    ///if KEngine PercentageBar is holded by the mouse, returns true

    return holded;
}

float PercentageBar::getShift() const
{
    ///returns KEngine PercentageBar's button shift in pixels

    return shift;
}



float PercentageBar::update(const sf::Vector2f& mousePosition, sf::Event& event, sf::Mouse::Button button, sf::View* view)
{
    ///KEngine PercentageBar heart, use it in pollEvent loop to make it work

    if (this->isButtonClicked(button, mousePosition, event))
    {
        this->holded = true;
        this->catchDiff = mousePosition.x - t_button->getPosition().x;
    }
    else if (!sf::Mouse::isButtonPressed(button))
        this->holded = false;

    if (holded)
    {
        this->c_button->setPosition(mousePosition.x - catchDiff, this->object->getPosition().y);
        this->t_button->setPosition(mousePosition.x - catchDiff, this->object->getPosition().y);

        sf::Vector2f temp = mousePosition;
        if (temp.x < object->getPosition().x - object->getSize().x / 2) temp.x = object->getPosition().x - object->getSize().x / 2;
        if (temp.x > object->getPosition().x + object->getSize().x / 2) temp.x = object->getPosition().x + object->getSize().x / 2;
        this->shift = temp.x - (this->object->getPosition().x - this->object->getSize().x / 2);

        if (t_button->getPosition().x < object->getPosition().x - object->getSize().x / 2)
        {
            t_button->setPosition(object->getPosition().x - object->getSize().x / 2, object->getPosition().y);
            c_button->setPosition(object->getPosition().x - object->getSize().x / 2, object->getPosition().y);
        }
        else if (t_button->getPosition().x > object->getPosition().x + object->getSize().x / 2)
        {
            t_button->setPosition(object->getPosition().x + object->getSize().x / 2, object->getPosition().y);
            c_button->setPosition(object->getPosition().x + object->getSize().x / 2, object->getPosition().y);
        }

        return 1.f;
    }
    else return 0;
}


void PercentageBar::render(sf::RenderWindow* window)
{
    ///displays KEngine PercentageBar on the screen, if active of course

    this->object->render(window);

    this->c_button->render(window);
    this->t_button->render(window);
}




// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// \ \ \ \ \ \ \
//
//  P  O  I  N  T    .f
//
// / / / / / / /
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =



//-------------------------                                                         -------------------------//
//+++                                                                                                     +++//
//============== C O N S T R U C T O R S ,   D E S T R U C T O R S   A N D   O P E R A T O R S ==============//
//+++                                                                                                     +++//
//-------------------------                                                         -------------------------//



PointBar::PointBar()
{

}


PointBar::PointBar( const sf::Vector2f& size,
                    const sf::Vector2f& position,
                    const sf::Texture* texture,
                    float points,
                    float max_points,
                    int origin,
                    const sf::Color& object_color,
                    const sf::Color& bar_color,
                    float object_outline_thickness,
                    float bar_outline_thickness,
                    const sf::Color& object_outline_color,
                    const sf::Color& bar_outline_color,
                    bool active )
{
    ///KEngine PointBar constructor
    /** KEngine PointBar is an object based on KEngine Rectangle and
        KEngine Button - it works like a loading bar, you can manage
        the number of points and max points, inherits from class
        GuiObject */

    this->object = std::make_unique<Button>(size, position, origin, texture, L"", 0, MIDDLE_MIDDLE, object_color, sf::Color::Transparent, object_outline_thickness, object_outline_color, 0, sf::Text::Regular, sf::Vector2f(0, 0), Arial, active);
    this->bar = std::make_unique<Rectangle>(sf::Vector2f(size.x * (points / max_points), size.y), sf::Vector2f(this->object->getShapeCentre().x - this->object->getSize().x / 2, this->object->getShapeCentre().y), LEFT_MIDDLE, L"", 0, MIDDLE_MIDDLE, bar_color, sf::Color::Transparent, bar_outline_thickness, bar_outline_color, 0, sf::Text::Regular, sf::Vector2f(0, 0), Arial, active);

    this->pts = points;
    this->max_pts = max_points;
}


PointBar::PointBar( const sf::Vector2f& size,
                    const sf::Vector2f& position,
                    const std::string& texture_path,
                    float points,
                    float max_points,
                    int origin,
                    const sf::Color& object_color,
                    const sf::Color& bar_color,
                    float object_outline_thickness,
                    float bar_outline_thickness,
                    const sf::Color& object_outline_color,
                    const sf::Color& bar_outline_color,
                    bool active )
{
    ///KEngine PointBar constructor
    /** KEngine PointBar is an object based on KEngine Rectangle and
        KEngine Button - it works like a loading bar, you can manage
        the number of points and max points, inherits from class
        GuiObject */

    this->object = std::make_unique<Button>(size, position, origin, texture_path, L"", 0, MIDDLE_MIDDLE, object_color, sf::Color::Transparent, object_outline_thickness, object_outline_color, 0, sf::Text::Regular, sf::Vector2f(0, 0), Arial, active);
    this->bar = std::make_unique<Rectangle>(sf::Vector2f(size.x * (points / max_points), size.y), sf::Vector2f(this->object->getShapeCentre().x - this->object->getSize().x / 2, this->object->getShapeCentre().y), LEFT_MIDDLE, L"", 0, MIDDLE_MIDDLE, bar_color, sf::Color::Transparent, bar_outline_thickness, bar_outline_color, 0, sf::Text::Regular, sf::Vector2f(0, 0), Arial, active);

    this->pts = points;
    this->max_pts = max_points;
}


PointBar::~PointBar()
{
    ///KEngine PointBar destructor
    /** KEngine PointBar is an object based on KEngine Rectangle and
        KEngine Button - it works like a loading bar, you can manage
        the number of points and max points, inherits from class
        GuiObject */
}


PointBar::PointBar(PointBar& other)
{
    ///KEngine PointBar copy constructor
    /** KEngine PointBar is an object based on KEngine Rectangle and
        KEngine Button - it works like a loading bar, you can manage
        the number of points and max points, inherits from class
        GuiObject */

    this->bar->operator = (*other.getBar());
    this->object->operator = (*other.getObject());

    this->pts = other.getPointCount();
    this->max_pts = other.getMaxPointCount();
}


PointBar& PointBar::operator= (PointBar& other)
{
    ///KEngine Rectangle operator =
    /** KEngine PointBar is an object based on KEngine Rectangle and
        KEngine Button - it works like a loading bar, you can manage
        the number of points and max points, inherits from class
        GuiObject */

    this->bar->operator = (*other.getBar());
    this->object->operator = (*other.getObject());

    this->pts = other.getPointCount();
    this->max_pts = other.getMaxPointCount();

    return *this;
}



void PointBar::create( const sf::Vector2f& size,
                       const sf::Vector2f& position,
                       const sf::Texture* texture,
                       float points,
                       float max_points,
                       int origin,
                       const sf::Color& object_color,
                       const sf::Color& bar_color,
                       float object_outline_thickness,
                       float bar_outline_thickness,
                       const sf::Color& object_outline_color,
                       const sf::Color& bar_outline_color,
                       bool active )
{
    ///KEngine PointBar create function <br>
    ///use with default constructor
    /** KEngine PointBar is an object based on KEngine Rectangle and
        KEngine Button - it works like a loading bar, you can manage
        the number of points and max points, inherits from class
        GuiObject */

    this->object = std::make_unique<Button>(size, position, origin, texture, L"", 0, MIDDLE_MIDDLE, object_color, sf::Color::Transparent, object_outline_thickness, object_outline_color, 0, sf::Text::Regular, sf::Vector2f(0, 0), Arial, active);
    this->bar = std::make_unique<Rectangle>(sf::Vector2f(size.x * (points / max_points), size.y), sf::Vector2f(this->object->getShapeCentre().x - this->object->getSize().x / 2, this->object->getShapeCentre().y), LEFT_MIDDLE, L"", 0, MIDDLE_MIDDLE, bar_color, sf::Color::Transparent, bar_outline_thickness, bar_outline_color, 0, sf::Text::Regular, sf::Vector2f(0, 0), Arial, active);

    this->pts = points;
    this->max_pts = max_points;
}



void PointBar::create( const sf::Vector2f& size,
                       const sf::Vector2f& position,
                       const std::string& texture_path,
                       float points,
                       float max_points,
                       int origin,
                       const sf::Color& object_color,
                       const sf::Color& bar_color,
                       float object_outline_thickness,
                       float bar_outline_thickness,
                       const sf::Color& object_outline_color,
                       const sf::Color& bar_outline_color,
                       bool active )
{
    ///KEngine PointBar create function <br>
    ///use with default constructor
    /** KEngine PointBar is an object based on KEngine Rectangle and
        KEngine Button - it works like a loading bar, you can manage
        the number of points and max points, inherits from class
        GuiObject */

    this->object = std::make_unique<Button>(size, position, origin, texture_path, L"", 0, MIDDLE_MIDDLE, object_color, sf::Color::Transparent, object_outline_thickness, object_outline_color, 0, sf::Text::Regular, sf::Vector2f(0, 0), Arial, active);
    this->bar = std::make_unique<Rectangle>(sf::Vector2f(size.x * (points / max_points), size.y), sf::Vector2f(this->object->getShapeCentre().x - this->object->getSize().x / 2, this->object->getShapeCentre().y), LEFT_MIDDLE, L"", 0, MIDDLE_MIDDLE, bar_color, sf::Color::Transparent, bar_outline_thickness, bar_outline_color, 0, sf::Text::Regular, sf::Vector2f(0, 0), Arial, active);

    this->pts = points;
    this->max_pts = max_points;
}



//-------------------------                                                         -------------------------//
//+++                                                                                                     +++//
//==============                           M O D    F U N C T I O N S                          ==============//
//+++                                                                                                     +++//
//-------------------------                                                         -------------------------//



void PointBar::setPosition(const sf::Vector2f& position)
{
    ///sets KEngine Rectangle's position

    this->object->setPosition(position);
    this->bar->setPosition(sf::Vector2f(this->object->getShapeCentre().x - this->object->getSize().x / 2, this->object->getShapeCentre().y));
}

void PointBar::setPosition(float x, float y)
{
    ///sets KEngine Rectangle's position

    this->setPosition(sf::Vector2f(x, y));
}

sf::Vector2f PointBar::getPosition() const
{
    ///returns KEngine Rectangle's position

    return this->object->getPosition();
}


void PointBar::setSize(const sf::Vector2f& size)
{
    ///sets KEngine Rectangle size

    this->object->setSize(size);
    this->bar->setSize(sf::Vector2f(size.x * (pts / max_pts), size.y));
}

void PointBar::setSize(float size_x, float size_y)
{
    ///sets KEngine Rectangle size

    this->object->setSize(size_x, size_y);
    this->bar->setSize(sf::Vector2f(size_x * (pts / max_pts), size_y));
}

sf::Vector2f PointBar::getSize() const
{
    ///returns KEngine Rectangle size

    return this->object->getSize();
}

sf::Vector2f PointBar::getBarSize() const
{
    ///sets KEngine Rectangle's bar size

    return this->bar->getSize();
}


void PointBar::move(const sf::Vector2f& offset)
{
    ///moves KEngine Rectangle by offset (px)

    this->object->move(offset);
    this->bar->move(offset);
}

void PointBar::move(float offset_x, float offset_y)
{
    ///moves KEngine Rectangle by offset (px)

    this->object->move(offset_x, offset_y);
    this->bar->move(offset_x, offset_y);
}


void PointBar::setScale(const sf::Vector2f& factors)
{
    ///sets KEngine Rectangle's scale

    this->object->setScale(factors);
    this->bar->setScale(factors);
}

void PointBar::setScale(float factor_x, float factor_y)
{
    ///sets KEngine Rectangle's scale

    this->object->setScale(factor_x, factor_y);
    this->bar->setScale(factor_x, factor_y);
}

void PointBar::scale(const sf::Vector2f& factors)
{
    ///scales KEngine Rectangle

    this->object->scale(factors);
    this->bar->scale(factors);
}

sf::Vector2f PointBar::getScale() const
{
    ///returns scale of the KEngine Rectangle

    return this->object->getScale();
}


void PointBar::setPositionByCentre(const sf::Vector2f& postion)
{
    ///sets position by the centre of the object

    sf::Vector2f delta(this->object->getPosition().x - this->object->getShapeCentre().x, this->object->getPosition().y - this->object->getShapeCentre().y);

    this->setPosition(postion.x + delta.x, postion.y + delta.y);
}

sf::Vector2f PointBar::getShapeCentre() const
{
    ///returns centre of the object

    return object->getShapeCentre();
}


void PointBar::setTexture(const sf::Texture* texture)
{
    ///changes KEngine Rectangle texture
    /// setting texture from other texture

    this->object->setTexture(texture);
}

void PointBar::setTexture(const std::string& texture_path)
{
    ///changes KEngine Rectangle texture
    /// setting texture directly from file

    this->object->setTexture(texture_path);
}

const sf::Texture* PointBar::getTexture() const
{
    ///returns pointer to KEngine Rectangle's texture
    /// if there's no texture, it returns nullptr

    return this->object->getTexture();
}


void PointBar::setFillColor(const sf::Color& color)
{
    ///sets KEngine Rectangle's fill color

    this->object->setFillColor(color);
}

void PointBar::setBarFillColor(const sf::Color& color)
{
    ///sets KEngine Rectangle's bar fill color

    this->bar->setFillColor(color);
}

const sf::Color& PointBar::getFillColor() const
{
    ///returns KEngine Rectangle's fill color

    return object->getFillColor();
}

const sf::Color& PointBar::getBarFillColor() const
{
    ///returns KEngine Rectangle's bar fill color

    return bar->getFillColor();
}


void PointBar::setTextColor(const sf::Color& text_color)
{
    ///does nothing, no text in this object
}

const sf::Color& PointBar::getTextColor() const
{
    ///does nothing, no text in this object

    return sf::Color::Transparent;
}



void PointBar::setOutlineColor(const sf::Color& outline_color)
{
    ///sets KEngine Rectangle's outline color

    this->object->setOutlineColor(outline_color);
}

void PointBar::setBarOutlineColor(const sf::Color& outline_color)
{
    ///sets KEngine Rectangle's bar outline color

    this->bar->setOutlineColor(outline_color);
}

const sf::Color& PointBar::getOutlineColor() const
{
    ///returns KEngine Rectangle's outline color

    return object->getOutlineColor();
}

const sf::Color& PointBar::getBarOutlineColor() const
{
    ///returns KEngine Rectangle's bar outline color

    return bar->getOutlineColor();
}


void PointBar::setOutlineThickness(float outline_thickness)
{
    ///sets KEngine Rectangle's outline thickness

    this->object->setOutlineThickness(outline_thickness);
}

void PointBar::setBarOutlineThickness(float outline_thickness)
{
    ///sets KEngine Rectangle's bar outline thickness

    this->bar->setOutlineThickness(outline_thickness);
}

float PointBar::getOutlineThickness() const
{
    ///returns KEngine Rectangle's outline thickness

    return object->getOutlineThickness();
}

float PointBar::getBarOutlineThickness() const
{
    ///returns KEngine Rectangle's bar outline thickness

    return bar->getOutlineThickness();
}



//-------------------------                                                         -------------------------//
//+++                                                                                                     +++//
//==============          R E N D E R   A N D   B E H A V I O U R   F U N C T I O N S          ==============//
//+++                                                                                                     +++//
//-------------------------                                                         -------------------------//



bool PointBar::isInvaded(const sf::Vector2f& mousePosition) const
{
    ///if mouse is on KEngine Rectangle, returns true

    return object->isInvaded(mousePosition);
}

bool PointBar::isBarInvaded(const sf::Vector2f& mousePosition) const
{
    ///if mouse is on KEngine Rectangle's bar, returns true

    return bar->isInvaded(mousePosition);
}


bool PointBar::isClicked(sf::Mouse::Button button, const sf::Vector2f& mousePosition, sf::Event& event) const
{
    ///if mouse is on KEngine Rectangle and the right button is clicked, returns true (use in pollEvent loop)

    return object->isClicked(button, mousePosition, event);
}

bool PointBar::isBarClicked(sf::Mouse::Button button, const sf::Vector2f& mousePosition, sf::Event& event) const
{
    ///if mouse is on KEngine Rectangle's bar and the right button is clicked, returns true (use in pollEvent loop)

    return bar->isClicked(button, mousePosition, event);
}


bool PointBar::isActive() const
{
    ///if KEngine Rectangle is displayed, returns true

    return object->isActive();
}

void PointBar::setActiveStatus(bool status)
{
    ///if KEngine Rectangle is active, it is displayed on the screen

    this->object->setActiveStatus(status);
    this->bar->setActiveStatus(status);
}


Rectangle* PointBar::getBar()
{
    ///returns pointer to KEngine PointBar's rectangle

    return bar.get();
}

Button* PointBar::getObject()
{
    ///returns pointer to KEngine PointBar's button

    return object.get();
}


void PointBar::addPoint()
{
    ///adds one point

    if (pts + 1 <= max_pts)
        pts++;
    else pts = max_pts;

    this->bar->setSize(sf::Vector2f(object->getSize().x * (pts / max_pts), object->getSize().y));
}

void PointBar::subtractPoint()
{
    ///subtracts one point

    if (pts - 1 >= 0)
        pts--;
    else pts = 0;

    this->bar->setSize(sf::Vector2f(object->getSize().x * (pts / max_pts), object->getSize().y));
}


void PointBar::addPoints(float count)
{
    ///adds given amount of points

    if (pts + count <= max_pts)
        pts += count;
    else pts = max_pts;

    this->bar->setSize(sf::Vector2f(object->getSize().x * (pts / max_pts), object->getSize().y));
}

void PointBar::subtractPoints(float count)
{
    ///subtracts given amount of points

    if (pts - count >= 0)
        pts -= count;
    else pts = 0;

    this->bar->setSize(sf::Vector2f(object->getSize().x * (pts / max_pts), object->getSize().y));
}


void PointBar::setPointCount(float count)
{
    ///sets point count to "count"

    this->pts = count;

    if (pts > max_pts) pts = max_pts;
    else if (pts < 0)  pts = 0;

    this->bar->setSize(sf::Vector2f(object->getSize().x * (pts / max_pts), object->getSize().y));
}

float PointBar::getPointCount() const
{
    ///returns number of points

    return pts;
}


void PointBar::setMaxPointCount(float max_count)
{
    ///sets maximum point count

    this->max_pts = max_count;

    this->bar->setSize(sf::Vector2f(object->getSize().x * (pts / max_pts), object->getSize().y));
}

float PointBar::getMaxPointCount() const
{
    ///returns maximum point count

    return max_pts;
}



float PointBar::update(const sf::Vector2f& mousePosition, sf::Event& event, sf::Mouse::Button button, sf::View* view)
{
    ///does nothing

    return 0;
}


void PointBar::render(sf::RenderWindow* window)
{
    ///displays KEngine Rectangle on the screen, if active of course

    if (object->isActive())
    {
        this->object->render(window);
        this->bar->render(window);
    }
}

}
