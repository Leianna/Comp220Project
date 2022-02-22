//
// Created by Toby Dragon on 11/6/18.
//

#include <iostream>
#include "Map.h"
#include "TestLib.h"
#include "Car.h"

void mapTest(Map* mapToTest){

    printAssertEquals(false, mapToTest->containsKey("x"));

    mapToTest->put("car01", Car( 1995, "Chevy", "Blazer", 300, 85));
    mapToTest->put("car02", Car( 1995, "Chevy", "Camaro", 800, 400));
    mapToTest->put("car03", Car( 1995, "Pontiac", "Firebird", 1000, 500));

    printAssertEquals(800, mapToTest->get("car02").getAskingPrice(), 0.0001);
    printAssertEquals(300, mapToTest->get("car01").getAskingPrice(), 0.0001);
    printAssertEquals(1000, mapToTest->get("car03").getAskingPrice(), 0.0001);

    printAssertEquals(false, mapToTest->containsKey("x"));
    printAssertEquals(true, mapToTest->containsKey("car03"));
    printAssertEquals(true, mapToTest->containsKey("car01"));
    printAssertEquals(true, mapToTest->containsKey("car02"));

    mapToTest->put("car02", Car( 2008, "Honda", "Civic", 4000, 1000));
    printAssertEquals(true, mapToTest->containsKey("car02"));
    printAssertEquals(4000, mapToTest->get("car02").getAskingPrice(), 0.0001);

    try{
        mapToTest->get("nothing");
        std::cout << "FAIL: get did not throw exception" << std::endl;
    }
    catch(std::invalid_argument& e){
        printAssertEquals("Key not present", e.what());
    }
}

void testLargeCarMap(Map* mapToTest){
    for (int i=0; i<10000; i++){
        mapToTest->put("car"+std::to_string(i), Car(i, "unkown", "unknown", i, 0));
    }
    int failCount = 0;
    for (int i=9999; i>=0; i--){
        try {
            if (mapToTest->get("car"+std::to_string(i)).getAskingPrice() != i) {
                failCount++;
            }
        }
        catch (std::invalid_argument e){
            std::cout << e.what() << std::endl;
            failCount++;
        }
    }
    printAssertEquals(0, failCount);
}

Map* createMap(){
    //TODO: create an instance of your map and return it
}

int main(){
    Map* map = createMap();
    mapTest(map);
    delete map;

    return 0;
}
