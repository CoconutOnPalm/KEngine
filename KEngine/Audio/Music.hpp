#ifndef MUSIC_HPP_INCLUDED
#define MUSIC_HPP_INCLUDED

#include "SFML/Audio.hpp"
#include "../Algorithms/RandomGenerator.hpp"

#include <iostream>
#include <cstdlib>
#include <vector>

namespace ke
{

class Playlist
{
public:

    Playlist();
    ~Playlist();

    void addSong(const std::string& filename);

    void play();
    void pause();
    void resume();
    void restart();
    void reset();

    void update();

    void skip();
    void playPrevious();

    void setVolume(float volume);
    void setPitch(float pitch);

    void shuffle();

    sf::Music* getMusic();
    std::vector<std::string>* getFilenames();

private:

    std::vector<std::string> filenames;
    std::vector<std::string>::iterator current_playing;

    sf::Music music;
};

}

#endif // MUSIC_HPP_INCLUDED
