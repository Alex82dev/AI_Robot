#ifndef VOICE_ENGINE_H
#define VOICE_ENGINE_H

#include <string>

class VoiceEngine {
public:
    // Constructor
    VoiceEngine();

    // Destructor
    ~VoiceEngine();

    // Initialize the voice engine
    void initialize();

    // Start listening for voice commands
    void startListening();

    // Stop listening for voice commands
    void stopListening();

    // Get the recognized voice command
    std::string getRecognizedCommand();
};

#endif  // VOICE_ENGINE_H
