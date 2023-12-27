// Header file for Camera Class

#ifndef CUSTOM_CAMERA_HPP
#define CUSTOM_CAMERA_HPP

#include "raylib.h"


class CustomCamera {
    public:
        CustomCamera(Vector2 size, Vector2 location, float roation, float zoom = 1.0);
        ~CustomCamera();
        void update(Vector2 newLocation);
        void begin();
        void end();
    private:
        Camera2D m_oCustomCamera;
};

#endif