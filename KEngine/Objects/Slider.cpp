#include "Slider.hpp"

namespace ke
{

//-------------------------                                                         -------------------------//
//+++                                                                                                     +++//
//============== C O N S T R U C T O R S ,   D E S T R U C T O R S   A N D   O P E R A T O R S ==============//
//+++                                                                                                     +++//
//-------------------------                                                         -------------------------//


Slider::Slider()
{
    ///KEngine Slider default constructor
    /** KEngine Slider is an object that scrolls your view or your
        other objects, it's just this bar on Google or other app
        on the right side and when you hold it something moves up
        or down, inherits from class GuiObject */

    this->holded = false;
    this->catchDiff = 0;
    this->shift = 0;
}


Slider::Slider( const sf::Vector2f& size,
                const sf::Vector2f& position,
                float field_height,
                int origin,
                const sf::Texture* slider_texture,
                const sf::Texture* slider_track_texture,
                const sf::Color& slider_color,
                const sf::Color& slider_track_color,
                float slider_outline_thickness,
                const sf::Color& slider_outline_color,
                float slider_track_outline_thickness,
                const sf::Color& slider_track_outline_color,
                bool active)
{
    ///KEngine Slider constructor
    /** KEngine Slider is an object that scrolls your view or your
        other objects, it's just this bar on Google or other app
        on the right side and when you hold it something moves up
        or down, inherits from class GuiObject */

    sf::Vector2f slider_start_pos;
    slider_start_pos.x = position.x;

    switch(origin)
    {
    case RIGHT_TOP:
        {
            slider_start_pos.y = position.y + (size.y * size.y / field_height) / 2;
        }
        break;

    case RIGHT_MIDDLE:
        {
            slider_start_pos.y = position.y - size.y / 2 + (size.y * size.y / field_height) / 2;
        }
        break;

    case RIGHT_BOTTOM:
        {
            slider_start_pos.y = position.y + size.y / 2 - (size.y * size.y / field_height) / 2;
        }
        break;

    default:
        {
            slider_start_pos.y = position.y + (size.y * size.y / field_height) / 2;
            origin = RIGHT_TOP;
        }
        break;
    }

    this->slider = std::make_unique<Button>(sf::Vector2f(size.x, size.y * size.y / field_height), sf::Vector2f(position.x, position.y + (size.y * size.y / field_height) / 2 ), RIGHT_MIDDLE, slider_texture, L"", 0, MIDDLE_MIDDLE, slider_color, sf::Color::Transparent, slider_outline_thickness, slider_outline_color);
    this->slider_track = std::make_unique<Button>(size, position, origin, slider_track_texture, L"", 0, MIDDLE_MIDDLE, slider_track_color, sf::Color::Transparent, slider_track_outline_thickness, slider_track_outline_color);

    this->holded = false;
    this->catchDiff = 0;
    this->shift = 0;
    this->field_height = field_height;
}


Slider::Slider( const sf::Vector2f& size,
                const sf::Vector2f& position,
                float field_height,
                int origin,
                const std::string& slider_texture_path,
                const std::string& slider_track_texture_path,
                const sf::Color& slider_color,
                const sf::Color& slider_track_color,
                float slider_outline_thickness,
                const sf::Color& slider_outline_color,
                float slider_track_outline_thickness,
                const sf::Color& slider_track_outline_color,
                bool active )
{
    ///KEngine Slider constructor
    /** KEngine Slider is an object that scrolls your view or your
        other objects, it's just this bar on Google or other app
        on the right side and when you hold it something moves up
        or down, inherits from class GuiObject */

    sf::Vector2f slider_start_pos;
    slider_start_pos.x = position.x;

    switch(origin)
    {
    case RIGHT_TOP:
        {
            slider_start_pos.y = position.y + (size.y * size.y / field_height) / 2;
        }
        break;

    case RIGHT_MIDDLE:
        {
            slider_start_pos.y = position.y - size.y / 2 + (size.y * size.y / field_height) / 2;
        }
        break;

    case RIGHT_BOTTOM:
        {
            slider_start_pos.y = position.y + size.y / 2 - (size.y * size.y / field_height) / 2;
        }
        break;

    default:
        {
            slider_start_pos.y = position.y + (size.y * size.y / field_height) / 2;
            origin = RIGHT_TOP;
        }
        break;
    }

    this->slider = std::make_unique<Button>(sf::Vector2f(size.x, size.y * size.y / field_height), sf::Vector2f(position.x, position.y + (size.y * size.y / field_height) / 2 ), RIGHT_MIDDLE, slider_texture_path, L"", 0, MIDDLE_MIDDLE, slider_color, sf::Color::Transparent, slider_outline_thickness, slider_outline_color);
    this->slider_track = std::make_unique<Button>(size, position, origin, slider_track_texture_path, L"", 0, MIDDLE_MIDDLE, slider_track_color, sf::Color::Transparent, slider_track_outline_thickness, slider_track_outline_color);

    this->holded = false;
    this->catchDiff = 0;
    this->shift = 0;
    this->field_height = field_height;
}

Slider::~Slider()
{
    ///KEngine Slider destructor
    /** KEngine Slider is an object that scrolls your view or your
        other objects, it's just this bar on Google or other app
        on the right side and when you hold it something moves up
        or down, inherits from class GuiObject */
}


Slider::Slider(Slider& other)
{
    ///KEngine Slider copy constructor
    /** KEngine Slider is an object that scrolls your view or your
        other objects, it's just this bar on Google or other app
        on the right side and when you hold it something moves up
        or down, inherits from class GuiObject */

    this->field_height = other.getFieldHeight();
    this->shift = other.getShift();

    sf::Texture temp_1 = *other.getTexture();
    sf::Texture temp_2 = *other.getTrackTexture();

    this->slider = std::make_unique<Button>(sf::Vector2f(other.getSize().x, other.getSize().y * other.getSize().y / this->field_height), sf::Vector2f(other.getPosition().x, other.getPosition().y + other.getShift() + (other.getSize().y * other.getSize().y / this->field_height) / 2 ), RIGHT_MIDDLE, &temp_1, L"", 0, MIDDLE_MIDDLE, other.getFillColor(), sf::Color::Transparent, other.getOutlineThickness(), other.getOutlineColor());
    this->slider_track = std::make_unique<Button>(other.getSize(), other.getPosition(), other.getOrigin(), &temp_2, L"", 0, MIDDLE_MIDDLE, other.getTrackColor(), sf::Color::Transparent, other.getTrackOutlineThickness(), other.getTrackColor());

    this->holded = false;
    this->catchDiff = 0;
}


Slider& Slider::operator= (Slider& other)
{
    ///KEngine Slider operator =
    /** KEngine Slider is an object that scrolls your view or your
        other objects, it's just this bar on Google or other app
        on the right side and when you hold it something moves up
        or down, inherits from class GuiObject */

    this->field_height = other.getFieldHeight();
    this->shift = other.getShift();

    sf::Texture temp_1 = *other.getTexture();
    sf::Texture temp_2 = *other.getTrackTexture();

    this->slider = std::make_unique<Button>(sf::Vector2f(other.getSize().x, other.getSize().y * other.getSize().y / this->field_height), sf::Vector2f(other.getPosition().x, other.getPosition().y + other.getShift() + (other.getSize().y * other.getSize().y / this->field_height) / 2 ), RIGHT_MIDDLE, &temp_1, L"", 0, MIDDLE_MIDDLE, other.getFillColor(), sf::Color::Transparent, other.getOutlineThickness(), other.getOutlineColor());
    this->slider_track = std::make_unique<Button>(other.getSize(), other.getPosition(), other.getOrigin(), &temp_2, L"", 0, MIDDLE_MIDDLE, other.getTrackColor(), sf::Color::Transparent, other.getTrackOutlineThickness(), other.getTrackColor());

    this->holded = false;
    this->catchDiff = 0;

    return *this;
}



void Slider::create( const sf::Vector2f& size,
                     const sf::Vector2f& position,
                     float field_height,
                     int origin,
                     const sf::Texture* slider_texture,
                     const sf::Texture* slider_track_texture,
                     const sf::Color& slider_color,
                     const sf::Color& slider_track_color,
                     float slider_outline_thickness,
                     const sf::Color& slider_outline_color,
                     float slider_track_outline_thickness,
                     const sf::Color& slider_track_outline_color,
                     bool active )
{
    ///KEngine Slider create function <br>
    ///use with default constructor
    /** KEngine Slider is an object that scrolls your view or your
        other objects, it's just this bar on Google or other app
        on the right side and when you hold it something moves up
        or down, inherits from class GuiObject */

    sf::Vector2f slider_start_pos;
    slider_start_pos.x = position.x;

    switch(origin)
    {
    case RIGHT_TOP:
        {
            slider_start_pos.y = position.y + (size.y * size.y / field_height) / 2;
        }
        break;

    case RIGHT_MIDDLE:
        {
            slider_start_pos.y = position.y - size.y / 2 + (size.y * size.y / field_height) / 2;
        }
        break;

    case RIGHT_BOTTOM:
        {
            slider_start_pos.y = position.y + size.y / 2 - (size.y * size.y / field_height) / 2;
        }
        break;

    default:
        {
            slider_start_pos.y = position.y + (size.y * size.y / field_height) / 2;
            origin = RIGHT_TOP;
        }
        break;
    }

    this->slider = std::make_unique<Button>(sf::Vector2f(size.x, size.y * size.y / field_height), sf::Vector2f(position.x, position.y + (size.y * size.y / field_height) / 2 ), RIGHT_MIDDLE, slider_texture, L"", 0, MIDDLE_MIDDLE, slider_color, sf::Color::Transparent, slider_outline_thickness, slider_outline_color);
    this->slider_track = std::make_unique<Button>(size, position, origin, slider_track_texture, L"", 0, MIDDLE_MIDDLE, slider_track_color, sf::Color::Transparent, slider_track_outline_thickness, slider_track_outline_color);

    this->field_height = field_height;
}


void Slider::create( const sf::Vector2f& size,
                     const sf::Vector2f& position,
                     float field_height,
                     int origin,
                     const std::string& slider_texture_path,
                     const std::string& slider_track_texture_path,
                     const sf::Color& slider_color,
                     const sf::Color& slider_track_color,
                     float slider_outline_thickness,
                     const sf::Color& slider_outline_color,
                     float slider_track_outline_thickness,
                     const sf::Color& slider_track_outline_color,
                     bool active )
{
    ///KEngine Slider create function <br>
    ///use with default constructor
    /** KEngine Slider is an object that scrolls your view or your
        other objects, it's just this bar on Google or other app
        on the right side and when you hold it something moves up
        or down, inherits from class GuiObject */

    sf::Vector2f slider_start_pos;
    slider_start_pos.x = position.x;

    switch(origin)
    {
    case RIGHT_TOP:
        {
            slider_start_pos.y = position.y + (size.y * size.y / field_height) / 2;
        }
        break;

    case RIGHT_MIDDLE:
        {
            slider_start_pos.y = position.y - size.y / 2 + (size.y * size.y / field_height) / 2;
        }
        break;

    case RIGHT_BOTTOM:
        {
            slider_start_pos.y = position.y + size.y / 2 - (size.y * size.y / field_height) / 2;
        }
        break;

    default:
        {
            slider_start_pos.y = position.y + (size.y * size.y / field_height) / 2;
            origin = RIGHT_TOP;
        }
        break;
    }

    this->slider = std::make_unique<Button>(sf::Vector2f(size.x, size.y * size.y / field_height), sf::Vector2f(position.x, position.y + (size.y * size.y / field_height) / 2 ), RIGHT_MIDDLE, slider_texture_path, L"", 0, MIDDLE_MIDDLE, slider_color, sf::Color::Transparent, slider_outline_thickness, slider_outline_color);
    this->slider_track = std::make_unique<Button>(size, position, origin, slider_track_texture_path, L"", 0, MIDDLE_MIDDLE, slider_track_color, sf::Color::Transparent, slider_track_outline_thickness, slider_track_outline_color);

    this->field_height = field_height;
}


//-------------------------                                                         -------------------------//
//+++                                                                                                     +++//
//==============                           M O D    F U N C T I O N S                          ==============//
//+++                                                                                                     +++//
//-------------------------                                                         -------------------------//



void Slider::setPosition(const sf::Vector2f& position)
{
    ///sets KEngine Slider's position

    this->slider_track->setPosition(position);

    switch(this->slider->getOrigin())
    {
    case RIGHT_TOP:
        {
            this->slider->setPosition(sf::Vector2f(position.x, position.y + (this->slider_track->getSize().y * this->slider_track->getSize().y / field_height) / 2 + shift));
        }
        break;

    case RIGHT_MIDDLE:
        {
            this->slider->setPosition(sf::Vector2f(position.x, position.y - this->slider_track->getSize().y / 2 + (this->slider_track->getSize().y * this->slider_track->getSize().y / field_height) / 2 + shift));
        }
        break;

    case RIGHT_BOTTOM:
        {
            this->slider->setPosition(sf::Vector2f(position.x, position.y + this->slider_track->getSize().y / 2 - (this->slider_track->getSize().y * this->slider_track->getSize().y / field_height) / 2 + shift));
        }
        break;

    default:
        {
            this->slider->setPosition(sf::Vector2f(position.x, position.y + (this->slider_track->getSize().y * this->slider_track->getSize().y / field_height) / 2 + shift));
        }
        break;
    }
}

void Slider::setPosition(float x, float y)
{
    ///sets KEngine Slider's position

    this->setPosition(sf::Vector2f(x, y));
}

sf::Vector2f Slider::getPosition() const
{
    ///returns KEngine Slider's position

    return this->slider->getPosition();
}

sf::Vector2f Slider::getSliderTrackPosition() const
{
    ///returns KEngine Slider's track position

    return this->slider_track->getPosition();
}


void Slider::setSize(const sf::Vector2f& size)
{
    ///sets KEngine Slider size

    this->slider->setSize(sf::Vector2f(size.x, size.y * size.y / field_height));
    this->slider_track->setSize(size);

    this->setPosition(this->slider_track->getPosition());
}

void Slider::setSize(float size_x, float size_y)
{
    ///sets KEngine Slider size

    this->slider->setSize(sf::Vector2f(size_x, size_y * size_y / field_height));
    this->slider_track->setSize(size_x, size_y);

    this->setPosition(this->slider_track->getPosition());
}

sf::Vector2f Slider::getSize() const
{
    ///returns KEngine Slider size

    return this->slider_track->getSize();
}

sf::Vector2f Slider::getSliderSize() const
{
    ///returns KEngine Slider's slider size

    return this->slider->getSize();
}


void Slider::move(const sf::Vector2f& offset)
{
    ///moves KEngine Slider by offset (px)

    this->slider->move(offset);
    this->slider_track->move(offset);
}

void Slider::move(float offset_x, float offset_y)
{
    ///moves KEngine Slider by offset (px)

    this->slider->move(offset_x, offset_y);
    this->slider_track->move(offset_x, offset_y);
}


void Slider::setScale(const sf::Vector2f& factors)
{
    ///sets KEngine Slider's scale

    this->slider->setScale(sf::Vector2f(factors.x, 1));
    this->slider_track->setScale(sf::Vector2f(factors.x, 1));

    this->setPosition(this->slider_track->getPosition());
}


void Slider::setScale(float factor_x, float factor_y)
{
    ///sets KEngine Slider's scale

    this->slider->setScale(factor_x, 1);
    this->slider_track->setScale(factor_x, 1);

    this->setPosition(this->slider_track->getPosition());
}

void Slider::scale(const sf::Vector2f& factors)
{
    ///scales KEngine Slider

    this->slider->scale(sf::Vector2f(factors.x, 1));
    this->slider_track->scale(sf::Vector2f(factors.x, 1));

    this->setPosition(this->slider_track->getPosition());
}

sf::Vector2f Slider::getScale() const
{
    ///returns KEngine Slider's scale

    return this->slider_track->getScale();
}


void Slider::setOrigin(int origin)
{
    ///changes origin of the KEngine Slider's track
    /**available origins: <br>
      * RIGHT_TOP     = top right corner <br>
      * RIGHT_MIDDLE  = right side <br>
      * RIGHT_BOTTOM  = bottom right corner */

    this->slider_track->setOrigin(origin);
}

int Slider::getOrigin() const
{
    ///returns origin of the KEngine Slider's track
    /**available origins: <br>
      * RIGHT_TOP     = top right corner <br>
      * RIGHT_MIDDLE  = right side <br>
      * RIGHT_BOTTOM  = bottom right corner */

    return slider_track->getOrigin();
}


void Slider::setPositionByCentre(const sf::Vector2f& postion)
{
    ///sets position by the centre of the object

    sf::Vector2f delta(this->slider_track->getPosition().x - this->slider_track->getShapeCentre().x, this->slider_track->getPosition().y - this->slider_track->getShapeCentre().y);

    this->setPosition(postion.x + delta.x, postion.y + delta.y);
}

sf::Vector2f Slider::getShapeCentre() const
{
    ///returns centre of the slider

    return slider->getShapeCentre();
}

sf::Vector2f Slider::getTrackCentre() const
{
    ///returns centre of the whole object

    return slider_track->getShapeCentre();
}


void Slider::setTexture(const sf::Texture* texture)
{
    ///changes KEngine Slider texture
    /// setting texture from other texture

    this->slider->setTexture(texture);
}

void Slider::setTrackTexture(const sf::Texture* texture)
{
    ///changes KEngine Slider's track texture
    /// setting texture from other texture

    this->slider_track->setTexture(texture);
}

void Slider::setTexture(const std::string& texture_path)
{
    ///changes KEngine Slider texture
    /// setting texture directly from file

    this->slider->setTexture(texture_path);
}

void Slider::setTrackTexture(const std::string& texture_path)
{
    ///changes KEngine Slider's track texture
    /// setting texture directly from file

    this->slider_track->setTexture(texture_path);
}

const sf::Texture* Slider::getTexture() const
{
    ///returns pointer to KEngine Slider's texture
    /// if there's no texture, it returns nullptr

    return this->slider->getTexture();
}

const sf::Texture* Slider::getTrackTexture() const
{
    ///returns pointer to KEngine Slider's's track texture
    /// if there's no texture, it returns nullptr

    return this->slider_track->getTexture();
}

std::string Slider::getTexturePath() const
{
    ///just don't use it

    return this->slider->getTexturePath();
}

std::string Slider::getTrackTexturePath() const
{
    ///just don't use it

    return this->slider_track->getTexturePath();
}


void Slider::setFillColor(const sf::Color& color)
{
    ///sets KEngine Slider's fill color

    this->slider->setFillColor(color);
}

void Slider::setTrackColor(const sf::Color& color)
{
    ///sets KEngine Slider's track fill color

    this->slider_track->setFillColor(color);
}

const sf::Color& Slider::getFillColor() const
{
    ///returns KEngine Slider's fill color

    return this->slider->getFillColor();
}

const sf::Color& Slider::getTrackColor() const
{
    ///returns KEngine Slider's track fill color

    return this->slider_track->getFillColor();
}


void Slider::setTextColor(const sf::Color& text_color)
{
    ///does nothing, not text in this object
}

const sf::Color& Slider::getTextColor() const
{
    ///does nothing, not text in this object

    return sf::Color::Transparent;
}


void Slider::setOutlineColor(const sf::Color& outline_color)
{
    ///sets KEngine Slider's outline color

    this->slider->setOutlineColor(outline_color);
}

void Slider::setTrackOutlineColor(const sf::Color& outline_color)
{
    ///sets KEngine Slider's track outline color

    this->slider_track->setOutlineColor(outline_color);
}

const sf::Color& Slider::getOutlineColor() const
{
    ///returns KEngine Slider's outline color

    return this->slider->getOutlineColor();
}

const sf::Color& Slider::getTrackOutlineColor() const
{
    ///returns KEngine Slider's track outline color

    return this->slider_track->getOutlineColor();
}


void Slider::setOutlineThickness(float outline_thickness)
{
    ///sets KEngine Slider's outline thickness

    this->slider->setOutlineThickness(outline_thickness);
}

void Slider::setTrackOutlineThickness(float outline_thickness)
{
    ///sets KEngine Slider's track outline thickness

    this->slider_track->setOutlineThickness(outline_thickness);
}

float Slider::getOutlineThickness() const
{
    ///returns KEngine Slider's outline thickness

    return this->slider->getOutlineThickness();
}

float Slider::getTrackOutlineThickness() const
{
    ///returns KEngine Slider's track outline thickness

    return this->slider_track->getOutlineThickness();
}



//-------------------------                                                         -------------------------//
//+++                                                                                                     +++//
//==============          R E N D E R   A N D   B E H A V I O U R   F U N C T I O N S          ==============//
//+++                                                                                                     +++//
//-------------------------                                                         -------------------------//



bool Slider::isInvaded(const sf::Vector2f& mousePoaition) const
{
    ///if mouse is on KEngine Slider, returns true

    //return this->slider->isInvaded(mousePoaition);

    if (this->slider->isInvaded(mousePoaition) || this->holded)
        return true;
    else return false;
}

bool Slider::isTrackInvaded(const sf::Vector2f& mousePosition) const
{
    ///if mouse is on KEngine Slider's track, returns true

    //return this->slider_track->isInvaded(mousePosition)

    if (this->slider_track->isInvaded(mousePosition) || this->holded)
        return true;
    else return false;
}

bool Slider::isClicked(sf::Mouse::Button button, const sf::Vector2f& mousePosition, sf::Event& event) const
{
    ///if mouse is on KEngine Slider and the right button is clicked, returns true (use in pollEvent loop)

    return this->slider->isClicked(button, mousePosition, event);
}

bool Slider::isTrackClicked(sf::Mouse::Button button, const sf::Vector2f& mousePosition, sf::Event& event) const
{
    ///if mouse is on KEngine Slider's track and the right button is clicked, returns true (use in pollEvent loop)

    return this->slider_track->isClicked(button, mousePosition, event);
}



bool Slider::isActive() const
{
    ///if KEngine Slider is displayed, returns true

    return this->slider->isActive();
}

void Slider::setActiveStatus(bool status)
{
    ///if KEngine Slider is active, it is displayed on the screen

    this->slider->setActiveStatus(status);
    this->slider_track->setActiveStatus(status);
}



bool Slider::isHolded() const
{
    ///if KEngine Slider's track is holded, returns true

    return holded;
}



Button* Slider::getSlider() const
{
    ///returns pointer to KEngine Button that this KEngine Slider uses as slider

    return this->slider.get();
}

Button* Slider::getSliderTrack() const
{
    ///returns pointer to KEngine Button that this KEngine Slider uses slider track

    return this->slider_track.get();
}



void Slider::setParameters(float field_height, float startPosition)
{
    /** \brief sets some variables values
     *
     * \param field_height  height of the view - border
     * \param startPosition well, this one doesn't work
     * \return void
     *
     */


    this->field_height = field_height;
    this->start_position = startPosition;
}

float Slider::getFieldHeight() const
{
    ///returns field height

    return this->field_height;
}

float Slider::getStartPosiiton() const
{
    ///returns start position, does not work pretty well I guess

    return this->start_position;
}


float Slider::getShift() const
{
    ///returns slider shift form top of the track (px)

    return this->shift;
}

void Slider::updateSize()
{
    ///KEngine Slider private function used automatically

    this->slider->setSize(sf::Vector2f(this->slider->getSize().x, this->slider_track->getSize().y * this->slider_track->getSize().y / field_height));
    this->slider->setOrigin(RIGHT_MIDDLE);
}


float Slider::update(const sf::Vector2f& mousePosition, sf::Event& event, sf::Mouse::Button button, sf::View* view)
{
    ///the heart of the KEngine Slider, it makes all the things work, use in pollEvent loop

    this->updateSize();

    //this->slider->setPosition(sf::Vector2f(this->slider->getPosition().x, (view->getCenter().y - view->getSize().y / 2) / (field_height / this->slider_track->getSize().y) + this->slider_track->getPosition().y + this->slider->getSize().y / 2));

    float top = this->slider_track->getShapeCentre().y - this->slider_track->getSize().y / 2;

    if (view)
        this->slider->setPosition(sf::Vector2f(this->slider->getPosition().x, this->slider->getSize().y / 2 + (view->getCenter().y - view->getSize().y / 2) * (slider_track->getSize().y - slider->getSize().y) / ((field_height - view->getSize().y))));
    if (this->slider->getPosition().y < this->slider_track->getPosition().y + this->slider->getSize().y / 2) this->slider->setPosition(sf::Vector2f(this->slider->getPosition().x, this->slider_track->getPosition().y + this->slider->getSize().y / 2));
    if (this->slider->getPosition().y > this->slider_track->getPosition().y + this->slider_track->getSize().y - this->slider->getSize().y / 2) this->slider->setPosition(sf::Vector2f(this->slider_track->getPosition().x, this->slider_track->getPosition().y + this->slider_track->getSize().y - this->slider->getSize().y / 2));

    if (this->slider->isClicked(button, mousePosition, event))
    {
        this->holded = true;
        this->catchDiff = mousePosition.y - this->slider->getPosition().y;
    }
    else if (!sf::Mouse::isButtonPressed(button)) this->holded = false;

    if (sf::Mouse::isButtonPressed(button) && this->holded && this->slider->getSize().y < this->slider_track->getSize().y)
    {
        this->slider->setPosition(sf::Vector2f(this->slider->getPosition().x, mousePosition.y - catchDiff));

        if (this->slider->getPosition().y < this->slider_track->getPosition().y + this->slider->getSize().y / 2) this->slider->setPosition(sf::Vector2f(this->slider->getPosition().x, this->slider_track->getPosition().y + this->slider->getSize().y / 2));
        if (this->slider->getPosition().y > this->slider_track->getPosition().y + this->slider_track->getSize().y - this->slider->getSize().y / 2) this->slider->setPosition(sf::Vector2f(this->slider_track->getPosition().x, this->slider_track->getPosition().y + this->slider_track->getSize().y - this->slider->getSize().y / 2));

        this->shift = this->slider->getPosition().y - (top + slider->getSize().y / 2);

        if (view)
            view->setCenter(view->getCenter().x, shift * ((field_height) - view->getSize().y) / ((slider_track->getSize().y - slider->getSize().y)) + view->getSize().y / 2);
    }
    else if (this->isTrackInvaded(mousePosition) && this->slider_track->isClicked(button, mousePosition, event) && !this->holded && this->slider->getSize().y < this->slider_track->getSize().y)
    {
        this->slider->setPosition(sf::Vector2f(this->slider->getPosition().x, mousePosition.y - catchDiff));

        this->shift = this->slider->getPosition().y - (top + slider->getSize().y / 2);

        if (this->slider->getPosition().y < this->slider_track->getPosition().y + this->slider->getSize().y / 2) this->slider->setPosition(sf::Vector2f(this->slider->getPosition().x, this->slider_track->getPosition().y + this->slider->getSize().y / 2));
        if (this->slider->getPosition().y > this->slider_track->getPosition().y + this->slider_track->getSize().y - this->slider->getSize().y / 2) this->slider->setPosition(sf::Vector2f(this->slider_track->getPosition().x, this->slider_track->getPosition().y + this->slider_track->getSize().y - this->slider->getSize().y / 2));

        if (view)
        {
            view->setCenter(sf::Vector2f(view->getCenter().x, shift * ((field_height) - view->getSize().y) / ((slider_track->getSize().y - slider->getSize().y)) + view->getSize().y / 2));

            if (view->getCenter().y < view->getSize().y / 2) view->setCenter(view->getCenter().x, view->getSize().y / 2);
            if (view->getCenter().y > field_height - view->getSize().y / 2) view->setCenter(view->getCenter().x, field_height - view->getSize().y / 2);
        }

        this->holded = true;
    }

    return shift * ((field_height)) / ((slider_track->getSize().y - slider->getSize().y));
}



void Slider::render(sf::RenderWindow* window)
{
    ///displays KEngine Slider on the screen, if active of course

    if (this->slider->isActive())
        if (this->slider->getSize().y < slider_track->getSize().y)
            slider->render(window);
    if (this->slider_track->isActive())
        slider_track->render(window);
}

}
