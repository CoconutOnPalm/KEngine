#ifndef SOUNDEFFECT_HPP_INCLUDED
#define SOUNDEFFECT_HPP_INCLUDED

#include <SFML/Audio.hpp>

#include <iostream>
#include <map>

namespace ke
{

    struct SEF
    {
        /// DO NOT USE THAT

        sf::SoundBuffer buffer;
        float volume;
        float pitch;
        float offset;
    };

class SoundEffects
{

public:

    SoundEffects();
    ~SoundEffects();

    void addEffect(const std::string& name, const std::string& file_path,
                   float volume = 100, float pitch = 1.0f, float offset = 0.0f);

    void removeEffect(const std::string& name);

    void play(const std::string& name);
    void pause();
    void resume();
    void stop();

    void setVolume(float volume, const std::string& name);
    void setPitch(float pitch, const std::string& name);
    void setOffset(float offset, const std::string& name);

    void setGeneralVolume(float volume);

    sf::Sound* getSound();
    std::map<std::string, SEF>* getEffects();

private:

    std::map<std::string, SEF> sound_effects;

    sf::Sound sound;
};


}

#endif // SOUNDEFFECT_HPP_INCLUDED
