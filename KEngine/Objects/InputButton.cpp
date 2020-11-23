#include "InputButton.hpp"

namespace ke
{

//-------------------------                                                         -------------------------//
//+++                                                                                                     +++//
//============== C O N S T R U C T O R S ,   D E S T R U C T O R S   A N D   O P E R A T O R S ==============//
//+++                                                                                                     +++//
//-------------------------                                                         -------------------------//



InputButton::InputButton()
{
    ///KEngine InputButton default constructor
    /** KEngine InputButton is an object where you can imput text, you
        can choose limits of entered text (for ex. letters only),
        inherits from class GuiObject */

    this->imp_text = L"";
    this->possible_to_ent = false;
    this->no_lines = 0;
}


InputButton::InputButton( const sf::Vector2f& size,
                          const sf::Vector2f& position,
                          int origin,
                          const sf::Texture* texture,
                          const std::wstring& default_text,
                          int text_scope,
                          unsigned int max_number_of_characters,
                          unsigned int max_number_of_lines,
                          unsigned int character_size,
                          int text_position,
                          const sf::Color& object_color,
                          const sf::Color& text_color,
                          const sf::Color& default_text_color,
                          float outline_thickness,
                          const sf::Color& outline_color,
                          unsigned int text_style,
                          const sf::Vector2f& text_shift,
                          int font,
                          bool acitve )
{
    ///KEngine InputButton constructor
    /** KEngine InputButton is an object where you can imput text, you
        can choose limits of entered text (for ex. letters only),
        inherits from class GuiObject */

    this->object = std::make_unique<Button>(size, position, origin, texture, default_text, character_size, text_position, object_color, default_text_color, outline_thickness, outline_color, 0, text_style, text_shift, font, acitve);

    this->text_scope = text_scope;
    this->imp_text = L"";
    this->def_text = default_text;
    this->text_color = text_color;
    this->def_text_color = default_text_color;

    this->possible_to_ent = false;
    this->no_lines = 0;
    this->max_char = max_number_of_characters;
    this->max_lines = max_number_of_lines;
}


InputButton::InputButton( const sf::Vector2f& size,
                          const sf::Vector2f& position,
                          int origin,
                          const std::string& texture_path,
                          const std::wstring& default_text,
                          int text_scope,
                          unsigned int max_number_of_characters,
                          unsigned int max_number_of_lines,
                          unsigned int character_size,
                          int text_position,
                          const sf::Color& object_color,
                          const sf::Color& text_color,
                          const sf::Color& default_text_color,
                          float outline_thickness,
                          const sf::Color& outline_color,
                          unsigned int text_style,
                          const sf::Vector2f& text_shift,
                          int font,
                          bool acitve )
{
    ///KEngine InputButton constructor
    /** KEngine InputButton is an object where you can imput text, you
        can choose limits of entered text (for ex. letters only),
        inherits from class GuiObject */

    this->object = std::make_unique<Button>(size, position, origin, texture_path, default_text, character_size, text_position, object_color, default_text_color, outline_thickness, outline_color, 0, text_style, text_shift, font, acitve);

    this->text_scope = text_scope;
    this->imp_text = L"";
    this->def_text = default_text;
    this->text_color = text_color;
    this->def_text_color = default_text_color;

    this->possible_to_ent = false;
    this->no_lines = 0;
    this->max_char = max_number_of_characters;
    this->max_lines = max_number_of_lines;
}


InputButton::~InputButton()
{
    ///KEngine InputButton destructor
    /** KEngine InputButton is an object where you can imput text, you
        can choose limits of entered text (for ex. letters only),
        inherits from class GuiObject */
}


InputButton::InputButton(InputButton& other)
{
    ///KEngine InputButton copy constructor
    /** KEngine InputButton is an object where you can imput text, you
        can choose limits of entered text (for ex. letters only),
        inherits from class GuiObject */

    this->object->operator = (*other.getObject());

    this->text_scope = other.getTextScope();
    this->imp_text = other.getText();
    this->def_text = other.getDefautText();
    this->text_color = other.getTextColor();
    this->def_text_color = other.getDefaultTextColor();

    this->possible_to_ent = false;
    this->no_lines = other.getLineNum();
    this->max_char = other.getMaxCharacterNum();
    this->max_lines = other.getMaxLineNum();
}


InputButton& InputButton::operator= (InputButton& other)
{
    ///KEngine Rectangle operator =
    /** KEngine InputButton is an object where you can imput text, you
        can choose limits of entered text (for ex. letters only),
        inherits from class GuiObject */

    this->object->operator = (*other.getObject());

    this->text_scope = other.getTextScope();
    this->imp_text = other.getText();
    this->def_text = other.getDefautText();
    this->text_color = other.getTextColor();
    this->def_text_color = other.getDefaultTextColor();

    this->possible_to_ent = false;
    this->no_lines = other.getLineNum();
    this->max_char = other.getMaxCharacterNum();
    this->max_lines = other.getMaxLineNum();

    return *this;
}



void InputButton::create( const sf::Vector2f& size,
                          const sf::Vector2f& position,
                          int origin,
                          const sf::Texture* texture,
                          const std::wstring& default_text,
                          int text_scope,
                          unsigned int max_number_of_characters,
                          unsigned int max_number_of_lines,
                          unsigned int character_size,
                          int text_position,
                          const sf::Color& object_color,
                          const sf::Color& text_color,
                          const sf::Color& default_text_color,
                          float outline_thickness,
                          const sf::Color& outline_color,
                          unsigned int text_style,
                          const sf::Vector2f& text_shift,
                          int font,
                          bool acitve )
{
    ///KEngine InputButton create function <br>
    ///use with default constructor
    /** KEngine InputButton is an object where you can imput text, you
        can choose limits of entered text (for ex. letters only),
        inherits from class GuiObject */

    this->object = std::make_unique<Button>(size, position, origin, texture, default_text, character_size, text_position, object_color, default_text_color, outline_thickness, outline_color, 0, text_style, text_shift, font, acitve);

    this->text_scope = text_scope;
    this->def_text = default_text;
    this->text_color = text_color;
    this->def_text_color = default_text_color;

    this->max_char = max_number_of_characters;
    this->max_lines = max_number_of_lines;
}


void InputButton::create( const sf::Vector2f& size,
                          const sf::Vector2f& position,
                          int origin,
                          const std::string& texture_path,
                          const std::wstring& default_text,
                          int text_scope,
                          unsigned int max_number_of_characters,
                          unsigned int max_number_of_lines,
                          unsigned int character_size,
                          int text_position,
                          const sf::Color& object_color,
                          const sf::Color& text_color,
                          const sf::Color& default_text_color,
                          float outline_thickness,
                          const sf::Color& outline_color,
                          unsigned int text_style,
                          const sf::Vector2f& text_shift,
                          int font,
                          bool acitve )
{
    ///KEngine InputButton create function <br>
    ///use with default constructor
    /** KEngine InputButton is an object where you can imput text, you
        can choose limits of entered text (for ex. letters only),
        inherits from class GuiObject */

    this->object = std::make_unique<Button>(size, position, origin, texture_path, default_text, character_size, text_position, object_color, default_text_color, outline_thickness, outline_color, 0, text_style, text_shift, font, acitve);

    this->text_scope = text_scope;
    this->def_text = default_text;
    this->text_color = text_color;
    this->def_text_color = default_text_color;

    this->max_char = max_number_of_characters;
    this->max_lines = max_number_of_lines;
}



//-------------------------                                                         -------------------------//
//+++                                                                                                     +++//
//==============                           M O D    F U N C T I O N S                          ==============//
//+++                                                                                                     +++//
//-------------------------                                                         -------------------------//



void InputButton::setPosition(const sf::Vector2f& position)
{
    ///sets KEngine Rectangle's position

    this->object->setPosition(position);
}

void InputButton::setPosition(float x, float y)
{
    ///sets KEngine Rectangle's position

    this->object->setPosition(x, y);
}

sf::Vector2f InputButton::getPosition() const
{
    ///returns KEngine Rectangle's position

    return object->getPosition();
}



void InputButton::setSize(const sf::Vector2f& size)
{
    ///sets KEngine Rectangle size

    this->object->setSize(size);
}

void InputButton::setSize(float size_x, float size_y)
{
    ///sets KEngine Rectangle size

    this->object->setSize(size_x, size_y);
}

sf::Vector2f InputButton::getSize() const
{
    ///returns KEngine Rectangle size

    return object->getSize();
}


void InputButton::move(const sf::Vector2f& offset)
{
    ///moves KEngine Rectangle by offset (px)

    this->object->move(offset);
}

void InputButton::move(float offset_x, float offset_y)
{
    ///moves KEngine Rectangle by offset (px)

    this->object->move(offset_x, offset_y);
}


void InputButton::setText(const std::wstring& text)
{
    ///changes String of KEngine Rectangle's text (std::wstring)

    this->imp_text = text;
}

std::wstring InputButton::getText() const
{
    ///returns String of KEngine Rectangle's text (std::wstring)

    return this->imp_text;
}


void InputButton::setDefautText(const std::wstring& default_text)
{
    ///changes default String of KEngine Rectangle's text (std::wstring)

    this->def_text = default_text;
}

std::wstring InputButton::getDefautText() const
{
    ///returns default String of KEngine Rectangle's text (std::wstring)

    return this->def_text;
}


void InputButton::setTextScope(int text_scope)
{
    ///changes limits of entered text

    this->text_scope = text_scope;
}

int InputButton::getTextScope() const
{
    ///returns limits of entered text

    return text_scope;
}


void InputButton::setOrigin(int origin)
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

    this->object->setOrigin(origin);
}

int InputButton::getOrigin() const
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

    return this->object->getOrigin();
}


void InputButton::setRotation(float angle)
{
    ///does nothing, not available here
}

void InputButton::Rotate(float angle)
{
    ///does nothing, not available here
}

float InputButton::getRotation() const
{
    ///does nothing, not available here

    return 0;
}


void InputButton::setPositionByCentre(const sf::Vector2f& postion)
{
    ///sets position by the centre of the object

    sf::Vector2f delta(this->object->getPosition().x - this->object->getShapeCentre().x, this->object->getPosition().y - this->object->getShapeCentre().y);

    this->setPosition(postion.x + delta.x, postion.y + delta.y);
}

sf::Vector2f InputButton::getShapeCentre() const
{
    ///returns centre of the shape

    return object->getShapeCentre();
}


void InputButton::setScale(const sf::Vector2f& factors)
{
    ///sets KEngine Rectangle's scale

    this->object->setScale(factors);
}

void InputButton::setScale(float factor_x, float factor_y)
{
    ///sets KEngine Rectangle's scale

    this->object->setScale(factor_x, factor_y);
}

void InputButton::scale(const sf::Vector2f& factors)
{
    ///scales KEngine Rectangle

    this->object->scale(factors);
}

sf::Vector2f InputButton::getScale() const
{
    ///returns KEngine Rectangle's scale

    return object->getScale();
}


void InputButton::setTexture(const sf::Texture* texture)
{
    ///changes KEngine Rectangle texture
    /// setting texture from other texture

    this->object->setTexture(texture);
}

void InputButton::setTexture(const std::string& texture_path)
{
    ///changes KEngine Rectangle texture
    /// setting texture directly from file

    this->object->setTexture(texture_path);
}

const sf::Texture* InputButton::getTexture() const
{
    ///returns pointer to KEngine Rectangle's texture
    /// if there's no texture, it returns nullptr

    return object->getTexture();
}

std::string InputButton::getTexturePath() const
{
    ///just don't use it

    return object->getTexturePath();
}


void InputButton::setFillColor(const sf::Color& color)
{
    ///sets KEngine Rectangle's fill color

    this->object->setFillColor(color);
}

const sf::Color& InputButton::getFillColor() const
{
    ///returns KEngine Rectangle's fill color

    return this->object->getFillColor();
}


void InputButton::setTextColor(const sf::Color& text_color)
{
    ///sets KEngine Rectangle's text fill color

    this->text_color = text_color;
}


const sf::Color& InputButton::getTextColor() const
{
    ///returns KEngine Rectangle's text fill color

    return this->text_color;
}


void InputButton::setDefaultTextColor(const sf::Color& text_color)
{
    ///sets KEngine Rectangle's default text fill color

    this->def_text_color = text_color;
}

const sf::Color& InputButton::getDefaultTextColor() const
{
    ///returns KEngine Rectangle's default text fill color

    return this->def_text_color;
}


void InputButton::setOutlineColor(const sf::Color& outline_color)
{
    ///sets KEngine Rectangle's outline color

    this->object->setOutlineColor(outline_color);
}

const sf::Color& InputButton::getOutlineColor() const
{
    ///returns KEngine Rectangle's outline color

    return object->getOutlineColor();
}


void InputButton::setOutlineThickness(float outline_thickness)
{
    ///sets KEngine Rectangle's outline thickness

    this->object->setOutlineThickness(outline_thickness);
}

float InputButton::getOutlineThickness() const
{
    ///returns KEngine Rectangle's outline thickness

    return object->getOutlineThickness();
}


void InputButton::setTextPosition(int position, const sf::Vector2f& text_shift)
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

    this->object->setTextPosition(position, text_shift);
}

int InputButton::getTextPosition() const
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

    return object->getTextPosition();
}


void InputButton::setTextStyle(int style)
{
    ///sets KEngine Rectangle's text style

    this->object->setTextStyle(style);
}

unsigned int InputButton::getTextStyle() const
{
    ///returns KEngine Rectangle's text style

    return object->getTextStyle();
}


void InputButton::setFont(int font)
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

    this->object->setFont(font);
}

int InputButton::getFont() const
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

    return object->getFont();
}


void InputButton::setCharacterSize(unsigned int char_size)
{
    ///sets KEngine Rectangle's text character size

    this->object->setCharacterSize(char_size);
}

unsigned int InputButton::getCharacterSize() const
{
    ///returns KEngine Rectangle's text character size

    return object->getCharacterSize();
}


Button* InputButton::getObject()
{
    ///returns pointer to KEngine Button that this object uses

    return object.get();
}



//-------------------------                                                         -------------------------//
//+++                                                                                                     +++//
//==============          R E N D E R   A N D   B E H A V I O U R   F U N C T I O N S          ==============//
//+++                                                                                                     +++//
//-------------------------                                                         -------------------------//



bool InputButton::isInvaded(const sf::Vector2f& mousePosition) const
{
    ///if mouse is on KEngine Rectangle, returns true

    return object->isInvaded(mousePosition);
}

bool InputButton::isClicked(sf::Mouse::Button button, const sf::Vector2f& mousePosition, sf::Event& event) const
{
    ///if mouse is on KEngine Rectangle and the right button is clicked, returns true (use in pollEvent loop)

    return object->isClicked(button, mousePosition, event);
}


bool InputButton::isActive() const
{
    ///if KEngine Rectangle is displayed, returns true

    return object->isActive();
}

void InputButton::setActiveStatus(bool status)
{
    ///if KEngine Rectangle is active, it is displayed on the screen

    this->object->setActiveStatus(status);
}



void InputButton::setEPS(bool status)
{
    ///changes if you can enter text

    this->possible_to_ent = status;
}

bool InputButton::getEPS() const
{
    ///returns if you can enter text

    return possible_to_ent;
}


size_t InputButton::getCharNum()
{
    ///returns text size

    return imp_text.size();
}

unsigned int InputButton::getLineNum()
{
    ///returns number of lines

    return no_lines;
}


void InputButton::setMaxCharacterNum(unsigned int max_char_num)
{
    ///sets maximum number of characters

    this->max_char = max_char_num;
}

unsigned int InputButton::getMaxCharacterNum() const
{
    ///returns maximum number of characters

    return max_char;
}


void InputButton::setMaxLineNum(unsigned int max_line_num)
{
    ///sets maximum number of lines
    /** better keep it as 1 */

    this->max_lines = max_line_num;
}

unsigned int InputButton::getMaxLineNum() const
{
    ///returns maximum number of lines
    /** better keep it as 1 */

    return max_lines;
}




float InputButton::update(const sf::Vector2f& mousePosition, sf::Event& event, sf::Mouse::Button button, sf::View* view)
{
    ///the heart of the KEngine Slider, it makes all the things work, use in pollEvent loop

    if (this->isClicked(button, mousePosition, event))
        possible_to_ent = ((possible_to_ent) ? false : true);
    if (!this->isInvaded(mousePosition) && event.type == sf::Event::MouseButtonPressed && event.key.code == button)
        possible_to_ent = false;


    if (possible_to_ent)
    {
        if (event.type == sf::Event::TextEntered)
        {
            switch (text_scope)
            {
            case Everything:
            {
                if (((event.text.unicode > 32) || event.text.unicode == '\b' || event.text.unicode == ' '))
                {
                    /*if (event.text.unicode == L'a' && sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                        imp_text += L"\u0104";
                    else if (event.text.unicode == L'c' && sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                        imp_text += L"\u0106";
                    else if (event.text.unicode == L'e' && sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                        imp_text += L"\u0118";
                    else if (event.text.unicode == L'l' && sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                        imp_text += L"\u0141";
                    else if (event.text.unicode == L'n' && sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                        imp_text += L"\u0143";
                    else if (event.text.unicode == L'o' && sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                        imp_text += L"\u00D3";
                    else if (event.text.unicode == L's' && sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                        imp_text += L"\u015A";
                    else if (event.text.unicode == L'x' && sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                        imp_text += L"\u0179";
                    else if (event.text.unicode == L'z' && sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                        imp_text += L"\u017B";

                    else if (event.text.unicode == L'a' && sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt))
                        imp_text += L"\u0105";
                    else if (event.text.unicode == L'c' && sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt))
                        imp_text += L"\u0107";
                    else if (event.text.unicode == L'e' && sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt))
                        imp_text += L"\u0119";
                    else if (event.text.unicode == L'l' && sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt))
                        imp_text += L"\u0142";
                    else if (event.text.unicode == L'n' && sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt))
                        imp_text += L"\u0144";
                    else if (event.text.unicode == L'o' && sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt))
                        imp_text += L"\u00F3";
                    else if (event.text.unicode == L's' && sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt))
                        imp_text += L"\u015B";
                    else if (event.text.unicode == L'x' && sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt))
                        imp_text += L"\u017A";
                    else if (event.text.unicode == L'z' && sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt))
                        imp_text += L"\u017C";*/

                    if (event.text.unicode == '\b')
                    {
                        if (!imp_text.empty())
                            imp_text.pop_back();
                    }
                    else if (imp_text.size() < max_char)
                    {
                        imp_text += event.text.unicode;
                    }

                    if (imp_text.empty())
                    {
                        this->object->setText(def_text);
                        this->object->setTextColor(def_text_color);
                    }
                    else
                    {
                        this->object->setText(imp_text);
                        this->object->setTextColor(text_color);
                    }

                    if (this->object->getSfText()->getLocalBounds().width > object->getSize().x - object->getTextShift().x * 2)
                    {
                        if (this->no_lines < max_lines - 1)
                        {
                            imp_text.insert(imp_text.size() - 1, 1, '\n');
                            no_lines++;
                            this->object->setText(imp_text);
                            this->object->setTextColor(text_color);

                            //while (this->object->getSfText()->getLocalBounds().height > object->getSize().y - object->getTextShift().y * 2)
                                //this->object->getSfText()->setCharacterSize(this->object->getSfText()->getCharacterSize() - 1);
                        }
                        else if (this->no_lines >= max_lines - 1)
                        {
                            imp_text.pop_back();
                        }
                    }
                }
            }
            break;
            case ASCII_Everything:
            {
                if (((event.text.unicode > 32 && event.text.unicode < 128) || event.text.unicode == '\b' || event.text.unicode == ' '))
                {
                    if (event.text.unicode == '\b')
                    {
                        if (!imp_text.empty())
                            imp_text.pop_back();
                    }
                    else if (imp_text.size() < max_char)
                    {
                        imp_text += event.text.unicode;
                    }

                    if (imp_text.empty())
                    {
                        this->object->setText(def_text);
                        this->object->setTextColor(def_text_color);
                    }
                    else
                    {
                        this->object->setText(imp_text);
                        this->object->setTextColor(text_color);
                    }

                    if (this->object->getSfText()->getLocalBounds().width > object->getSize().x - object->getTextShift().x * 2)
                    {
                        if (this->no_lines < max_lines - 1)
                        {
                            imp_text.insert(imp_text.size() - 1, 1, '\n');
                            no_lines++;
                            this->object->setText(imp_text);
                            this->object->setTextColor(text_color);

                            //while (this->object->getSfText()->getLocalBounds().height > object->getSize().y - object->getTextShift().y * 2)
                                //this->object->getSfText()->setCharacterSize(this->object->getSfText()->getCharacterSize() - 1);
                        }
                        else if (this->no_lines >= max_lines - 1)
                        {
                            imp_text.pop_back();
                        }
                    }
                }
            }
            break;

            case Letters_PMarks:
            {
                if ((((event.text.unicode > 32 && event.text.unicode < 48) || (event.text.unicode > 57 && event.text.unicode < 128)) || event.text.unicode == '\b' || event.text.unicode == ' '))
                {
                    if (event.text.unicode == '\b')
                    {
                        if (!imp_text.empty())
                            imp_text.pop_back();
                    }
                    else if (imp_text.size() < max_char)
                    {
                        imp_text += event.text.unicode;
                    }

                    if (imp_text.empty())
                    {
                        this->object->setText(def_text);
                        this->object->setTextColor(def_text_color);
                    }
                    else
                    {
                        this->object->setText(imp_text);
                        this->object->setTextColor(text_color);
                    }

                    if (this->object->getSfText()->getLocalBounds().width > object->getSize().x - object->getTextShift().x * 2)
                    {
                        if (this->no_lines < max_lines - 1)
                        {
                            imp_text.insert(imp_text.size() - 1, 1, '\n');
                            no_lines++;
                            this->object->setText(imp_text);
                            this->object->setTextColor(text_color);

                            //while (this->object->getSfText()->getLocalBounds().height > object->getSize().y - object->getTextShift().y * 2)
                                //this->object->getSfText()->setCharacterSize(this->object->getSfText()->getCharacterSize() - 1);
                        }
                        else if (this->no_lines >= max_lines - 1)
                        {
                            imp_text.pop_back();
                        }
                    }
                }
            }
            break;

            case Letters:
            {
                if ((((event.text.unicode > 64 && event.text.unicode < 91) || (event.text.unicode > 97 && event.text.unicode < 122)) || event.text.unicode == '\b' || event.text.unicode == ' '))
                {
                    if (event.text.unicode == '\b')
                    {
                        if (!imp_text.empty())
                            imp_text.pop_back();
                    }
                    else if (imp_text.size() < max_char)
                    {
                        imp_text += event.text.unicode;
                    }

                    if (imp_text.empty())
                    {
                        this->object->setText(def_text);
                        this->object->setTextColor(def_text_color);
                    }
                    else
                    {
                        this->object->setText(imp_text);
                        this->object->setTextColor(text_color);
                    }

                    if (this->object->getSfText()->getLocalBounds().width > object->getSize().x - object->getTextShift().x * 2)
                    {
                        if (this->no_lines < max_lines - 1)
                        {
                            imp_text.insert(imp_text.size() - 1, 1, '\n');
                            no_lines++;
                            this->object->setText(imp_text);
                            this->object->setTextColor(text_color);

                            //while (this->object->getSfText()->getLocalBounds().height > object->getSize().y - object->getTextShift().y * 2)
                                //this->object->getSfText()->setCharacterSize(this->object->getSfText()->getCharacterSize() - 1);
                        }
                        else if (this->no_lines >= max_lines - 1)
                        {
                            imp_text.pop_back();
                        }
                    }
                }
            }
            break;

            case Numbers:
            {
                if ((((event.text.unicode > 47 && event.text.unicode < 58)) || event.text.unicode == '\b' || event.text.unicode == ' '))
                {
                    if (event.text.unicode == '\b')
                    {
                        if (!imp_text.empty())
                            imp_text.pop_back();
                    }
                    else if (imp_text.size() < max_char)
                    {
                        imp_text += event.text.unicode;
                    }

                    if (imp_text.empty())
                    {
                        this->object->setText(def_text);
                        this->object->setTextColor(def_text_color);
                    }
                    else
                    {
                        this->object->setText(imp_text);
                        this->object->setTextColor(text_color);
                    }

                    if (this->object->getSfText()->getLocalBounds().width > object->getSize().x - object->getTextShift().x * 2)
                    {
                        if (this->no_lines < max_lines - 1)
                        {
                            imp_text.insert(imp_text.size() - 1, 1, '\n');
                            no_lines++;
                            this->object->setText(imp_text);
                            this->object->setTextColor(text_color);

                            //while (this->object->getSfText()->getLocalBounds().height > object->getSize().y - object->getTextShift().y * 2)
                                //this->object->getSfText()->setCharacterSize(this->object->getSfText()->getCharacterSize() - 1);
                        }
                        else if (this->no_lines >= max_lines - 1)
                        {
                            imp_text.pop_back();
                        }
                    }
                }
            }
            break;

            case Math:
            {
                if ((((event.text.unicode > 39 && event.text.unicode < 63)) || event.text.unicode == '\b' || event.text.unicode == ' '))
                {
                    if (event.text.unicode == '\b')
                    {
                        if (!imp_text.empty())
                            imp_text.pop_back();
                    }
                    else if (imp_text.size() < max_char)
                    {
                        imp_text += event.text.unicode;
                    }

                    if (imp_text.empty())
                    {
                        this->object->setText(def_text);
                        this->object->setTextColor(def_text_color);
                    }
                    else
                    {
                        this->object->setText(imp_text);
                        this->object->setTextColor(text_color);
                    }

                    if (this->object->getSfText()->getLocalBounds().width > object->getSize().x - object->getTextShift().x * 2)
                    {
                        if (this->no_lines < max_lines - 1)
                        {
                            imp_text.insert(imp_text.size() - 1, 1, '\n');
                            no_lines++;
                            this->object->setText(imp_text);
                            this->object->setTextColor(text_color);

                            //while (this->object->getSfText()->getLocalBounds().height > object->getSize().y - object->getTextShift().y * 2)
                                //this->object->getSfText()->setCharacterSize(this->object->getSfText()->getCharacterSize() - 1);
                        }
                        else if (this->no_lines >= max_lines - 1)
                        {
                            imp_text.pop_back();
                        }
                    }
                }
            }
            break;
            }
        }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
            {
                while(this->imp_text.back() != L' ' && this->imp_text.back() != L'\n' && this->imp_text.back() != L'.' && this->imp_text.back() != L',' && !this->imp_text.empty())
                    this->imp_text.pop_back();

                if (imp_text.empty())
                {
                    this->object->setText(def_text);
                    this->object->setTextColor(def_text_color);
                }
                else
                {
                    this->imp_text.pop_back();

                    this->object->setText(imp_text);
                    this->object->setTextColor(text_color);
                }
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && event.key.code == sf::Keyboard::V)
            {
                //sf::String temp(imp_text);
                //temp = sf::Clipboard::getString();
                this->imp_text = sf::Clipboard::getString().toWideString();
                while (imp_text.size() > max_char)
                    imp_text.pop_back();
                this->object->setText(imp_text);
                this->object->setTextColor(text_color);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && event.key.code == sf::Keyboard::C)
            {
                sf::Clipboard::setString(imp_text);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && event.key.code == sf::Keyboard::X)
            {
                sf::Clipboard::setString(imp_text);

                while(!imp_text.empty())
                    imp_text.pop_back();

                this->object->setText(def_text);
                this->object->setTextColor(def_text_color);
            }
    }


    return possible_to_ent;
}




void InputButton::render(sf::RenderWindow* window)
{
    ///displays KEngine Rectangle on the screen, if active of course

    this->object->render(window);
}

}
