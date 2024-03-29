#include "Map.h"

//virtual destructor to allow child destructor to be called
virtual Map::~Map(){

}

/*
 * @post if the key is new, the key-value pair is added to the map
 *       if the key was already present, the new value overwrites the old value
 *       (i.e., the new value will be returned by get instead of the old value)
 */
virtual void put(std::string key, const Car& value){

}

/*
 * @return the value associated with the given key
 * @throws std::invalid_argument if the key is not present
 */
virtual Car get(std::string key){

}

/*
 * @return true if the given key is associated with a value in the map, false otherwise
 */
virtual bool containsKey(std::string key){

}