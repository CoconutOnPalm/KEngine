#ifndef SLIDER_HPP_INCLUDED
#define SLIDER_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "ObjectParent.hpp"
#include "../Data/Data.hpp"
#include "Button.hpp"

#include <iostream>
#include <cstdlib>

//class ke::Button;

namespace ke
{

class Slider : public GuiObject
{
public:

    Slider();

    Slider( const sf::Vector2f& size,
            const sf::Vector2f& position,
            float field_height,
            int origin,
            const sf::Texture* slider_texture,
            const sf::Texture* slider_track_texture,
            const sf::Color& slider_color = sf::Color::Black,
            const sf::Color& slider_track_color = sf::Color::Transparent,
            float slider_outline_thickness = 0,
            const sf::Color& slider_outline_color =  sf::Color::Transparent,
            float slider_track_outline_thickness = 0,
            const sf::Color& slider_track_outline_color =  sf::Color::Transparent,
            bool active = true );

    Slider( const sf::Vector2f& size,
            const sf::Vector2f& position,
            float field_height,
            int origin,
            const std::string& slider_texture_path,
            const std::string& slider_track_texture_path,
            const sf::Color& slider_color = sf::Color::Black,
            const sf::Color& slider_track_color = sf::Color::Transparent,
            float slider_outline_thickness = 0,
            const sf::Color& slider_outline_color =  sf::Color::Transparent,
            float slider_track_outline_thickness = 0,
            const sf::Color& slider_track_outline_color =  sf::Color::Transparent,
            bool active = true );

    virtual ~Slider();

    Slider(Slider& other);
    Slider& operator= (Slider& other);

    void create( const sf::Vector2f& size,
                 const sf::Vector2f& position,
                 float field_height,
                 int origin,
                 const sf::Texture* slider_texture,
                 const sf::Texture* slider_track_texture,
                 const sf::Color& slider_color = sf::Color::Black,
                 const sf::Color& slider_track_color = sf::Color::Transparent,
                 float slider_outline_thickness = 0,
                 const sf::Color& slider_outline_color =  sf::Color::Transparent,
                 float slider_track_outline_thickness = 0,
                 const sf::Color& slider_track_outline_color =  sf::Color::Transparent,
                 bool active = true );

    void create( const sf::Vector2f& size,
                 const sf::Vector2f& position,
                 float field_height,
                 int origin,
                 const std::string& slider_texture_path,
                 const std::string& slider_track_texture_path,
                 const sf::Color& slider_color = sf::Color::Black,
                 const sf::Color& slider_track_color = sf::Color::Transparent,
                 float slider_outline_thickness = 0,
                 const sf::Color& slider_outline_color =  sf::Color::Transparent,
                 float slider_track_outline_thickness = 0,
                 const sf::Color& slider_track_outline_color =  sf::Color::Transparent,
                 bool active = true );


    void setPosition(const sf::Vector2f& position);
    void setPosition(float x, float y);
    sf::Vector2f getPosition() const;
    sf::Vector2f getSliderTrackPosition() const;

    void setSize(const sf::Vector2f& size);
    void setSize(float size_x, float size_y);
    sf::Vector2f getSize() const;
    sf::Vector2f getSliderSize() const;

    void move(const sf::Vector2f& offset);
    void move(float offset_x, float offset_y);

    void setScale(const sf::Vector2f& factors);
    void setScale(float factor_x, float factor_y);
    void scale(const sf::Vector2f& factors);
    sf::Vector2f getScale() const;

    void setOrigin(int origin);
    int getOrigin() const;

    void setPositionByCentre(const sf::Vector2f& position);
    sf::Vector2f getShapeCentre() const;
    sf::Vector2f getTrackCentre() const;

    void setTexture(const sf::Texture *texture);
    void setTrackTexture(const sf::Texture* texture);
    void setTexture(const std::string& texture_path);
    void setTrackTexture(const std::string& texture_path);
    const sf::Texture* getTexture() const;
    const sf::Texture* getTrackTexture() const;
    std::string getTexturePath() const;
    std::string getTrackTexturePath() const;

    void setFillColor(const sf::Color& color = sf::Color::Transparent);
    void setTrackColor(const sf::Color& color = sf::Color::Transparent);
    const sf::Color& getFillColor() const;
    const sf::Color& getTrackColor() const;

    void setTextColor(const sf::Color& text_color = sf::Color::White);
    const sf::Color& getTextColor() const;

    void setOutlineColor(const sf::Color& outline_color = sf::Color::Transparent);
    void setTrackOutlineColor(const sf::Color& outline_color = sf::Color::Transparent);
    const sf::Color& getOutlineColor() const;
    const sf::Color& getTrackOutlineColor() const;

    void setOutlineThickness(float outline_thickness = 0);
    void setTrackOutlineThickness(float outline_thickness = 0);
    float getOutlineThickness() const;
    float getTrackOutlineThickness() const;


    bool isInvaded(const sf::Vector2f& mousePosition) const;
    bool isTrackInvaded(const sf::Vector2f& mousePosition) const;
    bool isClicked(sf::Mouse::Button button, const sf::Vector2f& mousePosition, sf::Event& event) const;
    bool isTrackClicked(sf::Mouse::Button button, const sf::Vector2f& mousePosition, sf::Event& event) const;

    bool isActive() const;
    void setActiveStatus(bool status = true);


    bool isHolded() const;


    Button* getSlider() const;
    Button* getSliderTrack() const;


    void setParameters(float field_height, float startPosition);
    float getFieldHeight() const;
    float getStartPosiiton() const;

    float getShift() const;


    float update(const sf::Vector2f& mousePosition, sf::Event& event, sf::Mouse::Button button, sf::View* view);

    void render(sf::RenderWindow *window);


private:

    void updateSize();

    std::unique_ptr<Button> slider;
    std::unique_ptr<Button> slider_track;

    bool holded;
    float catchDiff; // difference between mouse position and slider centre

    float field_height;
    float start_position;
    float shift;
};

}

#endif // SLIDER_HPP_INCLUDED
