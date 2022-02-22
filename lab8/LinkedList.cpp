//
// Created by Toby Dragon on 10/30/18.
//

#include "LinkedList.h"
#include "ArrayLib.h"

/**
    * Constructor
*/
LinkedList::LinkedList(){
    this->front = nullptr;
    this->currCount=0;

}

//Destructor
LinkedList::~LinkedList(){
    delete front;
}

/**
 * appends the new item to the end of the list
 * @post the list has an additional value in it, at the end
 */
void LinkedList::insertAtEnd(int itemToAdd){
    LinkedNode* newNode=new LinkedNode(itemToAdd);
    if(isEmpty()){
        this->front=newNode;
    }
    else{
        LinkedNode* tempNode=this->front;
        while(tempNode->getNext()!= nullptr){
            tempNode=tempNode->getNext();
        }
        tempNode->setNext(newNode);
    }
    this->currCount+=1;
}

/**
 * gets a value from the list
 * @param index the location from which to get the value
 * @return a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
int LinkedList::getValueAt(int index){
    LinkedNode* node=front;
    if(index<0) {
        throw std::out_of_range("getValueAt");
    }
    if(!isEmpty()) {
        for (int i = 0; i < index; i++) {
            if (node->getNext()== nullptr){
                throw std::out_of_range("getValueAt");
            }
            node = node->getNext();
        }
        return node->getItem();
    }
    else{
        throw std::out_of_range("getValueAt");
    }
}

/**
 * gives a string representation of the current list
 * @returns a string representing the given list in the exact format shown below
 * {1, 2, 3, 4, 5}
 */
std::string LinkedList::toString(){
    std::string result = "{";
    LinkedNode* tempNode=front;
    if(itemCount()<1){
        result="{}";
        return result;
    }
    else{
        while(tempNode->getNext()!= nullptr){
            result+=std::to_string(tempNode->getItem())+", ";
            tempNode=tempNode->getNext();
        }
        result+=std::to_string(tempNode->getItem());
        result+="}";
        return result;
    }

}

/**
 * checks if there are any valid items in the list
 * @return true if there are no valid items in the list, false otherwise
 */
bool LinkedList::isEmpty(){
    if(itemCount()==0){
        return true;
    }else{
        return false;
    }
}

/**
 * returns a count of valid items currently in the list
 * @returns the number of valid items in the list
 */
int LinkedList::itemCount(){
    return currCount;
}

/**
 * makes the list empty of valid items
 * @post the list is empty, such that isEmpty() == true
 */
void LinkedList::clearList(){
    if(front!=nullptr){
        LinkedNode* tempNode=front;
        LinkedNode* nextNode=front->getNext();

        while(tempNode->getNext()!= nullptr){
            delete tempNode;
            tempNode=nextNode;
            nextNode=tempNode->getNext();
        }
        delete tempNode;
        front= nullptr;
    }
    currCount=0;
}

/**
 * Searches an int array for a certain value
 * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
 */
int LinkedList::find(int numToFind){
//TODO
    int result = -1;
    LinkedNode* tempNode = front;
    if (front != nullptr){
        result = result+1;
        while(tempNode->getNext() != nullptr){
            if(tempNode->getItem() == numToFind){
                return result;
            }
            result +=1;
            tempNode = tempNode->getNext();
        }
        if(tempNode->getItem() == numToFind){
            return result;
        }
        return -1;
    }
    return result;
}

/**
 * Searches an int array for a certain value
 * @return the index of the last occurrence of numToFind if it is present, otherwise returns -1
 */
int LinkedList::findLast(int numToFind){
//TODO
    int result = -1;
    if(front != nullptr){
        LinkedNode* tempNode = front;
        int indexOfItem = 0;
        while(tempNode->getNext() != nullptr){
            if(tempNode->getItem() == numToFind){
                result = indexOfItem;
            }
            tempNode= tempNode->getNext();
            indexOfItem +=1;
        }
        if(tempNode->getItem() == numToFind){
            result = indexOfItem;
        }
        return result;
    }
}

/**
 * finds the largest value in the array
 * @return the first index of the maximum value
 * @throws out_of_range exception if there is no item to remove
 */
int LinkedList::findMaxIndex(){
    if(front == nullptr){
        throw std::out_of_range("findMaxIndex");
    }else{
        LinkedNode* tempNode = front;
        int itemIndex = 0;
        int maxIndex = 0;
        int maxValue = this->front->getItem();
        while(tempNode->getNext() != nullptr){
            if(tempNode->getItem() > maxValue){
                maxValue = tempNode->getItem();
                maxIndex = itemIndex;
            }
            tempNode = tempNode->getNext();
            itemIndex +=1;
        }
        if(tempNode->getItem() > maxValue){
            maxIndex = itemIndex;
        }
        return maxIndex;

    }

}

/**
 * appends the new item to the beginning of the list
 * @post the list has an additional value in it, at the beginning
 *    all other items are shifted down by one index
 */
void LinkedList::insertAtFront(int itemToAdd){
    LinkedNode *aNode = new LinkedNode(itemToAdd);
    if(itemCount()==0){
        front=aNode;
    }else{
        aNode->setNext(front);
        front=aNode;
    }
    this->currCount+=1;
}

/**
 * inserts the item into the list so that it can be found with get(index)
 * @param index the location in which to insert this item
 * @post the list has an additional value in it at the specified index,
 *        all further values have been shifted down by one index
 * @throws out_of_range exception if index is invalid (< 0 or > currItemCount)
 */
void LinkedList::insertAt(int itemToAdd, int index){
    if(index>itemCount() || index<0){
        throw std::out_of_range("insertAt");
    }else if(index==0){
        insertAtFront(itemToAdd);
    }else if(index==itemCount()){
        insertAtEnd(itemToAdd);
    }else{
        LinkedNode* tempNode = this->front;
        LinkedNode* tempNodeBefore = this->front;
        LinkedNode* tempNodeToAdd = new LinkedNode(itemToAdd);
        for(int i=0; i<index; i++){
            tempNodeBefore = tempNode;
            tempNode = tempNode->getNext();
        }
        tempNodeBefore->setNext(tempNodeToAdd);
        tempNodeToAdd->setNext(tempNode);
        this->currCount+=1;
    }
}

/**
 * removes the item at the end of the list, and returns a copy of that item
 * @post the item at the end is removed from the list
 * @return a copy of the item at the end
 * @throws out_of_range exception if there is no item to remove
 */
int LinkedList::removeValueAtEnd(){
    if(isEmpty()){
        throw std::out_of_range("No items to remove");
    }else {
        if (currCount == 1) {
            return removeValueAtFront();
        } else {
            LinkedNode* tempNode = this->front;
            LinkedNode* nodeBefore = this->front;
            while (tempNode->getNext() != nullptr) {
                nodeBefore = tempNode;
                tempNode = tempNode->getNext();
            }
            int endValue = tempNode->getItem();
            nodeBefore->setNext(nullptr);
            this->currCount -= 1;
            return endValue;
        }
    }
}

/**
 * removes the item at the front of the list, and returns a copy of that item
 * @post the item at the front is removed from the list, everything else is shifted down one
 * @return a copy of the item at index
 * @throws out_of_range exception if there is no item to remove
 */
int LinkedList::removeValueAtFront(){
    if(itemCount()<1){
        throw std::out_of_range("removeValueAtFront");
    } else{
        int result = front->getItem();
        front=front->getNext();
        this->currCount-=1;
        return result;

    }

}

/**
 * removes the item at index from the list, and returns a copy of that item
 * @param index the location from which to get the value
 * @post the item at index is removed from the list, everything else is shifted down one
 * @return a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
int LinkedList::removeValueAt(int index){
//TODO
    LinkedNode *tempNode = this->front;
    LinkedNode *tempNodeBefore = this->front;
    if (index < 0 || index > currCount || isEmpty()) {
        throw std::out_of_range("Index Invalid");
    }
    if (index == 0) {
        return removeValueAtFront();
    } else {
        for (int i = 0; i < index; i++) {
            tempNodeBefore = tempNode;
            tempNode = tempNode->getNext();
        }
        int itemReturn = tempNode->getItem();
        tempNodeBefore->setNext(tempNode->getNext());
        this->currCount -= 1;
        return itemReturn;
    }
}