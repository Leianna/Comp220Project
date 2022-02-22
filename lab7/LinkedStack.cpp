//
// Created by Toby Dragon on 10/24/17.
//

#include "LinkedStack.h"

//Creates an empty stack
LinkedStack::LinkedStack(){
    top = nullptr;
}

//copy constructor
LinkedStack::LinkedStack(const LinkedStack& stackToCopy){
    //TODO
//    LinkedNode* newQueueToCopy = stackToCopy.top;
//    top = new LinkedNode(newQueueToCopy->getItem());
//    LinkedNode* newThis = this->top;
//    newQueueToCopy = newQueueToCopy->getNext();
//    while (newQueueToCopy != nullptr) {
//        LinkedNode *nextItem = new LinkedNode(newQueueToCopy->getItem());
//        newThis->setNext(nextItem);
//        newThis = nextItem;
//        newQueueToCopy = newQueueToCopy->getNext();
//    }
    // Copy the last item from stackToCopy
    this->top = stackToCopy.top;


}

LinkedStack& LinkedStack::operator=(const LinkedStack& stackToCopy){
    //TODO
    //Delete the top
    while(top != nullptr){
            LinkedNode* newNode = top;
            this -> top = top-> getNext();
            delete newNode;
    }


//    LinkedNode* newQueueToCopy = stackToCopy.top;
//    top = new LinkedNode(newQueueToCopy->getItem());
//    LinkedNode* newThis = this->top;
//    newQueueToCopy = newQueueToCopy->getNext();
//    while (newQueueToCopy != nullptr){
//        LinkedNode* nextItem = new LinkedNode(newQueueToCopy->getItem());
//        newThis->setNext(nextItem);
//        newThis = nextItem;
//        newQueueToCopy = newQueueToCopy->getNext();
//
//    }

    //set the new top to old top
    this->top = stackToCopy.top;
    return *this;
}

//destructor
LinkedStack::~LinkedStack(){
    //TODO
//    while(top->getNext() != nullptr){
//        LinkedNode* nodeNum = top;
//        delete nodeNum;
//        top = top->getNext();
//    }
    delete top;

}

//puts an item onto the top of the stack
void LinkedStack::push (std::string item){
    LinkedNode* newNode = new LinkedNode(item);
    newNode->setNext(top);
    top = newNode;
}

//takes the item off the top of the stack and returns it
//throws out_of_range exception if the stack is empty
std::string LinkedStack::pop(){
    //TODO
    if(top==nullptr){
        throw std::out_of_range("emptyStack");
    }else {
        //copy the last item
        std::string value = top->getItem();
        //change the pointer from last item to second last item
        top = top -> getNext();
        return value;
    }

}

//returns true if the stack has no items, false otherwise
bool LinkedStack::isEmpty(){
    return top == nullptr;
}
