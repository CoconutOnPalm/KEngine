#include "Music.hpp"

namespace ke
{

Playlist::Playlist()
{
    ///KEngine Playlist constructor
    /** KEngine Playlist is a class that stores file names to music files
        and plays it automatically with its update() function*/
}

Playlist::~Playlist()
{
    ///KEngine Playlist destructor
    /** KEngine Playlist is a class that stores file names to music files
        and plays it automatically with its update() function*/

    music.stop();
}


void Playlist::addSong(const std::string& filename)
{
    ///adds new song to the playlist

    filenames.push_back(filename);
    current_playing = filenames.begin();
    music.setVolume(100);
}

void Playlist::play()
{
    ///manually starts playing the playlist

    if (!music.openFromFile(*current_playing))
        return;
    music.play();
}

void Playlist::pause()
{
    ///pauses the playlist

    music.pause();
}

void Playlist::resume()
{
    ///resumes paused playlist

    if (music.getStatus() == sf::Music::Paused)
        music.play();
}

void Playlist::restart()
{
    ///restarts the current song

    music.stop();
}

void Playlist::reset()
{
    ///plays the playlist form the beginning (Playlist::play to play)

    music.stop();
    current_playing = filenames.begin();
}


void Playlist::update()
{
    ///updates playlist, use to achieve automated track change

    if (music.getStatus() != sf::Music::Playing && music.getStatus() != sf::Music::Paused)
        this->skip();
}


void Playlist::skip()
{
    if (current_playing + 1 != filenames.end())
            current_playing++;
        else
            current_playing = filenames.begin();

    this->play();
}

void Playlist::playPrevious()
{
    if (current_playing != filenames.begin())
            current_playing--;
        else
            current_playing = filenames.end() - 1;

    this->play();
}


void Playlist::setVolume(float volume)
{
    ///sets music volume

    music.setVolume(volume);
}

void Playlist::setPitch(float pitch)
{
    ///sets music pitch

    music.setPitch(pitch);
}


void Playlist::shuffle()
{
    ///randomly changes the order of the songs

    int n = 0;

    for (auto& i : filenames)
    {
        int r = ke::Random::Int(n, filenames.size() - 1);
        swap(i, filenames[r]);
        n++;
    }
}


sf::Music* Playlist::getMusic()
{
    ///returns SFML music class

    return &music;
}

std::vector<std::string>* Playlist::getFilenames()
{
    ///returns vector of music filenames;

    return &filenames;
}


}
