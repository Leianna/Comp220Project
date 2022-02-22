
//
// Created by leianna chen on 2019/10/15.
//
#include "ArrayLib.h"
#include "ArrayList.h"
ArrayList::ArrayList(int initialCapacity){
    if (initialCapacity<1){
        throw std::invalid_argument("invalid capacity");
    }
    this->array = new int[initialCapacity];
    this->currItemCount = 0;
    this->currCapacity = initialCapacity;
}
//Copy Constructor
ArrayList::ArrayList(const ArrayList& arrayListToCopy){

    array = new int[currCapacity];
    this->currCapacity = arrayListToCopy.currCapacity;
    this->currItemCount = arrayListToCopy.currItemCount;
    for(int i = 0; i < arrayListToCopy.currItemCount;i++){
        array[i] = arrayListToCopy.array[i];
    }
}

//Overloaded Assignment Operator
ArrayList& ArrayList::operator=(const ArrayList& arrayListToCopy){
        delete[] array;
        array = new int[arrayListToCopy.currCapacity];
        for(int i = 0; i < currItemCount;i++){
            this->array[i] = arrayListToCopy.array[i];
        }


    return *this;
}

//Destructor
ArrayList::~ArrayList(){
    delete[] array;
}
/**
     * replaces the old array with an array twice the size
     * private method only called within ArrayList when necessary
     * @post: array points to a new array of twice the size with values copied from the old one,
     * the old array is deleted.
     */
void ArrayList::doubleCapacity(){
    //make new dynamically allocated array with a size of currCapacity * 2
    this->currCapacity = currCapacity * 2;
    int* newArray = new int[currCapacity];
    //copy everything from array into newArray
    for(int i = 0; i < currItemCount;i++){
        newArray[i] = array[i];
    }
    //delete array
    delete[] array;
    //set array to newArray
    this->array = newArray;

}
/**
     * appends the new item to the end of the list
     * @post the list has an additional value in it, at the end
     */
void ArrayList::insertAtEnd(int itemToAdd){
    if(currItemCount>=currCapacity){
        doubleCapacity();
    }
    this->currItemCount = currItemCount + 1;
    array[currItemCount-1]=itemToAdd;

    //if there's not enough room in the array: doubleCapacity()
    //add 1 to currentItemCount
}

/**
 * gets a value from the list
 * @param index the location from which to get the value
 * @return a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
int ArrayList::getValueAt(int index){
//    return 0;
    if (index >= currItemCount || index < 0){
        throw std::out_of_range("invalid");
    }else{
        int result = array[index];
        return result;
    }

}

/**
 * gives a string representation of the current list
 * @returns a string representing the given list in the exact format shown below
 * {1, 2, 3, 4, 5}
 */
std::string ArrayList::toString(){
//    std::string result = ::toString(array,currItemCount);
//    return result;
    return ::toString(array,currItemCount);
}

/**
 * checks if there are any valid items in the list
 * @return true if there are no valid items in the list, false otherwise
 */
bool ArrayList::isEmpty(){
    if(currItemCount == 0){
        return true;
    }else{
        return false;
    }
}

/**
 * returns a count of valid items currently in the list
 * @returns the number of valid items in the list
 */
int ArrayList::itemCount(){
    int result = currItemCount;
    return result;
}

/**
 * makes the list empty of valid items
 * @post the list is empty, such that isEmpty() == true
 */
void ArrayList::clearList(){
    if(isEmpty()==false){
        int* newArray = new int[currCapacity];
        delete[] array;
        array = newArray;
        this->currItemCount = 0;
    }
}

/**
 * Searches an int array for a certain value
 * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
 */
int ArrayList::find(int numToFind){
    int num = 0;
    int result = ::find(array,currItemCount,numToFind,num);
    return result;
}

/**
 * Searches an int array for a certain value
 * @return the index of the last occurrence of numToFind if it is present, otherwise returns -1
 */
int ArrayList::findLast(int numToFind){
    int num = 0;
    int result = ::findLast(array,currItemCount,numToFind,num);
    return result;
}

/**
 * finds the largest value in the array
 * @return the first index of the maximum value
 * @throws out_of_range exception if there is no item to remove
 */
int ArrayList::findMaxIndex(){
    try{
        int num = 0;
        int result = ::findMaxIndex(array,currItemCount,num);
        return result;
    }catch(std::invalid_argument& e){
        throw std::out_of_range("invalid");
    }

}

/**
 * appends the new item to the beginning of the list
 * @post the list has an additional value in it, at the beginning
 *    all other items are shifted down by one index
 */
void ArrayList::insertAtFront(int itemToAdd){
    if(currItemCount>=currCapacity){
        doubleCapacity();
    }
    int* newArray = new int[currCapacity];
    newArray[0] = itemToAdd;
    currItemCount = currItemCount + 1;
    for(int i = 1; i < currItemCount; i++){
        newArray[i] = array[i-1];
    }
    delete[] array;
    array = newArray;
}

/**
 * inserts the item into the list so that it can be found with get(index)
 * @param index the location in which to insert this item
 * @post the list has an additional value in it at the specified index,
 *        all further values have been shifted down by one index
 * @throws out_of_range exception if index is invalid (< 0 or > currItemCount)
 */
void ArrayList::insertAt(int itemToAdd, int index){
    if(index>currItemCount || index<0){
        throw std::out_of_range("out of range");
    }else{
        if(currItemCount>=currCapacity){
            doubleCapacity();
        }
        int* newArray = new int[currCapacity];

        for(int i = 0 ; i < index ; i ++){
            newArray[i] = array[i];
        }
        for(int i = index ; i < (currItemCount) ; i ++){
            newArray[i+1] = array[i];
        }
        newArray[index]=itemToAdd;

        currItemCount = currItemCount + 1;
        delete[] array;
        array = newArray;


    }

}

/**
 * removes the item at the end of the list, and returns a copy of that item
 * @post the item at the end is removed from the list
 * @return a copy of the item at the end
 * @throws out_of_range exception if there is no item to remove
 */
int ArrayList::removeValueAtEnd(){
    if(currItemCount == 0) {
        throw std::out_of_range("no item");
    }else{
        int* newArray = new int[currCapacity];
        currItemCount = currItemCount -1;
        for(int i = 0; i < currItemCount; i++){
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
    }

}

/**
 * removes the item at the front of the list, and returns a copy of that item
 * @post the item at the front is removed from the list, everything else is shifted down one
 * @return a copy of the item at index
 * @throws out_of_range exception if there is no item to remove
 */
int ArrayList::removeValueAtFront(){
    if(currItemCount == 0) {
        throw std::out_of_range("no item");
    }else {
        int *newArray = new int[currCapacity];
        for (int i = 1; i < currItemCount; i++) {
            newArray[i-1] = array[i];
        }
        currItemCount=currItemCount-1;
        delete[] array;
        array = newArray;
    }
}

/**
 * removes the item at index from the list, and returns a copy of that item
 * @param index the location from which to get the value
 * @post the item at index is removed from the list, everything else is shifted down one
 * @return a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
int ArrayList::removeValueAt(int index){
    if(index > currCapacity) {
        throw std::out_of_range("out of range");
    }else{
        int* newArray = new int[currCapacity];
        for(int i = 0; i < index; i++){
            newArray[i]=array[i];
        }
        for(int i = index+1; i < currItemCount; i++){
            newArray[i-1]=array[i];
        }
        currItemCount=currItemCount-1;
        delete[] array;
        array = newArray;

    }

}