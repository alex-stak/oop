#include "Attributes.h"


Strength::Strength() {
    this->strength = 0;
    this->radius = 0;
}

Strength::Strength(uint16_t strength, uint8_t radius) {
    this->strength = strength;
    this->radius = radius;
}

void Strength::setStrength(uint16_t strength) {
    this->strength = strength;
}

void Strength::setRadius(uint8_t radius) {
    this->radius = radius;
}

uint16_t Strength::getStrength() {
    return strength;
}

uint8_t Strength::getRadius() {
    return radius;
}


Armor::Armor() {
    this->armor = 0;
}

Armor::Armor(uint16_t armor) {
    this->armor = armor;
}

void Armor::setArmor(uint16_t armor) {
    this->armor = armor;
}

uint16_t Armor::getArmor() {
    return armor;
}



Health::Health() {
    this->maxHealth = 100;
    this->health = 100;
}

Health::Health(uint16_t maxHealth, uint16_t health) {
    this->maxHealth = maxHealth;
    this->health = health;
}

void Health::setMaxHealth(uint16_t maxHealth) {
    this->maxHealth = maxHealth;
}

void Health::setHealth(uint16_t health) {
    this->health = health;
}

uint16_t Health::getMaxHealth() {
    return maxHealth;
}

uint16_t Health::getHealth() {
    return health;
}



MovePoints::MovePoints() {
    this->maxMovePoints = 100;
    this->movePoints = 100;
}

MovePoints::MovePoints(uint8_t maxMovePoints, uint8_t movePoints) {
    this->maxMovePoints = maxMovePoints;
    this->movePoints = movePoints;
}

void MovePoints::setMaxMovePoints(uint8_t maxMovePoints) {
    this->maxMovePoints = maxMovePoints;
}

void MovePoints::setMovePoints(uint8_t movePoints) {
    this->movePoints = movePoints;
}

uint8_t MovePoints::getMaxMovePoints() {
    return maxMovePoints;
}

uint8_t MovePoints::getMovePoints() {
    return movePoints;
}
