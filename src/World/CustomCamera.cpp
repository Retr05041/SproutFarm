#include "CustomCamera.hpp"

/**
 * @brief Camera constructor
*/
CustomCamera::CustomCamera(Vector2 size, Vector2 location, float rotation, float zoom) {
    m_oCustomCamera = {size, location, rotation, zoom};
}

/**
 * @brief Camera destructor
*/
CustomCamera::~CustomCamera() {

}

/**
 * @brief Updates camera location
 * 
 * @param newLocation New location of camera
*/
void CustomCamera::update(Vector2 newLocation) {
    m_oCustomCamera.target = newLocation;
}

/**
 * @brief Begins camera
*/
void CustomCamera::begin() {
    BeginMode2D(m_oCustomCamera);
}

/**
 * @brief Ends camera
*/
void CustomCamera::end() {
    EndMode2D();
}