#include "SoundEffect.hpp"

namespace ke
{

SoundEffects::SoundEffects()
{
    ///KEngine SoundEffects constructor
    /** Kengine SoundEffects is a class that stores a map of
        sound effects which can be called in any time */

}

SoundEffects::~SoundEffects()
{
    ///KEngine SoundEffects destructor
    /** KEngine SoundEffects is a class that stores a map of
        sound effects which can be called in any time */
    sound.stop();
}


void SoundEffects::addEffect(const std::string& name, const std::string& file_path,
                             float volume, float pitch, float offset)
{
    /** \brief adds an sound effect to the sound map
     *
     * \param name          name of the effect
     * \param file_path     file path to the effect
     * \param volume        volume
     * \param pitch         pitch
     * \param offset        offset in seconds
     * \return void
     *
     */


    sound_effects[name].volume = volume;
    sound_effects[name].pitch = pitch;
    sound_effects[name].offset = offset;
    sound_effects[name].buffer.loadFromFile(file_path);
}

void SoundEffects::removeEffect(const std::string& name)
{
    ///removes specific sound effect

    if (sound_effects.find(name) == sound_effects.end())
    {
        std::cout << "[SoundEffect.removeEffect(..)]: effect not found\n";
        return;
    }

    if (&sound_effects[name].buffer == (sound.getBuffer()))
    {
        sound.stop();
        sound.resetBuffer();
    }

    sound_effects.erase(name);
}


void SoundEffects::play(const std::string& name)
{
    ///plays specific sound effect

    this->sound.setVolume(sound_effects[name].volume);
    this->sound.setPitch(sound_effects[name].pitch);
    this->sound.setPlayingOffset(sf::seconds(sound_effects[name].offset));

    sound.setBuffer(sound_effects[name].buffer);
    sound.play();
}

void SoundEffects::pause()
{
    ///pauses currently playing sound effect, don't really use it

    if (!sound.Paused)
        sound.pause();
}

void SoundEffects::resume()
{
    ///resumes currently playing sound effect, don't really use it

    if (sound.Paused)
        sound.play();
}

void SoundEffects::stop()
{
    ///stops currently playing sound effect, don't really use it

    if (!sound.Stopped)
        sound.stop();
}


void SoundEffects::setVolume(float volume, const std::string& name)
{
    ///sets volume of the given effect

    if (sound_effects.find(name) != sound_effects.end())
        sound_effects[name].volume = volume;
}

void SoundEffects::setPitch(float pitch, const std::string& name)
{
    ///sets pitch of the given effect

    if (sound_effects.find(name) != sound_effects.end())
        sound_effects[name].pitch = pitch;
}

void SoundEffects::setOffset(float offset, const std::string& name)
{
    ///sets offset (seconds) of the given effect

    if (sound_effects.find(name) != sound_effects.end())
        sound_effects[name].offset = offset;
}


void SoundEffects::setGeneralVolume(float volume)
{
    ///sets volume of the currently playing sound effect (probably)

    sound.setVolume(volume);
}


sf::Sound* SoundEffects::getSound()
{
    ///returns sound effect

    return &sound;
}

std::map<std::string, SEF>* SoundEffects::getEffects()
{
    ///returns effects map

    return &sound_effects;
}

}
