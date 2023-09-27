#pragma once

#include "../../raylib/include/raylib.h"

namespace Audio {
    class ToneGenerator {
    private:
        static float frequency;
        static float tanhIdx;

        static AudioStream stream;

        static void wave_generator_callback(void *buffer, unsigned int frames);

    public:
        static void Initialize();

        static float GetFrequency();
        static void SetFrequency(float frequency);

        static void Play();
        static void Stop();

        static void Dispose();
    };
}

