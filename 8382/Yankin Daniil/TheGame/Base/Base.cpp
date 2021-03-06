#include "Base.h"
#include "Game/Game.h"
#include "Player/Player.h"
#include "Field/Field.h"


Base::Base(Point point, Player* player) : point(point), player(player), health(Health(250, 250)),
    strength(Strength(30, 0)), armor(Armor(40)), maxUnitCount(4) {
    player->addBase(this);
}

Base::~Base() {
    player->removeBase(this);

    Game& game = Game::getInstance();
    for (auto iter = unitSet.begin(); iter != unitSet.end(); iter++) {
        game.objectWasDestructed(static_cast <Object*> (*iter));
        delete *iter;
    }
    game.objectWasDestructed(static_cast <Object*> (this));
}



uint8_t Base::getGroupType() {
    return BASE;
}

uint8_t Base::getObjectType() {
    return BASE;
}

Point Base::getPoint() {
    return point;
}



Player* Base::getPlayer() {
    return player;
}



uint16_t Base::getMaxHealth() {
    return health.getMaxHealth();
}

uint16_t Base::getHealth() {
    return health.getHealth();
}

uint16_t Base::getAttack() {
    return strength.getStrength();
}

uint16_t Base::getArmor() {
    return armor.getArmor();
}



uint16_t Base::giveDamage(IUnit *enemy) {
    uint16_t damage = strength.getStrength();
    if (enemy->getGroupType() == UNIT_SIEGE_ENGINE)
        damage *= 0.5;
    return damage;
}

bool Base::takeDamage(uint16_t damage) {
    health.setHealth(std::max(health.getHealth() - damage, 0));
    if (health.getHealth() == 0) {
        delete this;
        return false;
    }
    return true;

    // Выжил - true, помер - false
}



void Base::produceUnit(uint8_t unitType) {
    if (!Game::getInstance().getGameMediator().baseProductionAccess(this))
        return;

    UnitFactory factory;
    Unit* unit = factory.produce(unitType, point, this);
    Game::getInstance().objectWasCreated(unit);
}



bool Base::isBelowUnitMax() {
    if (unitSet.size() < maxUnitCount)
        return true;
    return false;
}

void Base::addUnit(IUnit* unit) {
    if (this->isBelowUnitMax()) {
        unitSet.insert(unit);
        player->addUnit(unit);
    }
}

void Base::removeUnit(IUnit* unit) {
    player->removeUnit(unit);
    unitSet.erase(unit);
}



uint8_t Base::getUnitCount() {
    return unitSet.size();
}

uint8_t Base::getMaxUnitCount() {
    return maxUnitCount;
}
