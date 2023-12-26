#include "CustomCamera.hpp"

CustomCamera::CustomCamera(Vector2 size, Vector2 location, float rotation, float zoom) {
    m_oCustomCamera = {size, location, rotation, zoom};
}

CustomCamera::~CustomCamera() {

}

void CustomCamera::update(Vector2 newLocation) {
    m_oCustomCamera.target = newLocation;
}

void CustomCamera::begin() {
    BeginMode2D(m_oCustomCamera);
}

void CustomCamera::end() {
    EndMode2D();
}