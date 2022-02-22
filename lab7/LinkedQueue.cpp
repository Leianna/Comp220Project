//
// Created by Toby Dragon on 10/24/17.
//
#include "LinkedQueue.h"

//Creates an empty queue
LinkedQueue::LinkedQueue(){
    front = nullptr;
    end = nullptr;
}

//Copy Constructor
LinkedQueue::LinkedQueue(const LinkedQueue& queueToCopy){
    //TODO
//    this->front= queueToCopy.front;
//    this->end=queueToCopy.end;

    //copy the address of queueToCopy.front
    LinkedNode* newQueueToCopy = queueToCopy.front;
    //create a new node and store item form queueToCopy.front, and set it equal to new front
    this->front = new LinkedNode(queueToCopy.front->getItem());
    //copy the address from new front, newThis will be the last item with a null pointer
    LinkedNode* newThis = this->front;
    //store next pointer address form queueToCopy
    newQueueToCopy = newQueueToCopy->getNext();
    //while the address is not nullptr (not the last)
    while (newQueueToCopy != nullptr){
        //creat a new node and store the item from newQueueToCopy, store this address in nextItem
        LinkedNode* nextItem = new LinkedNode(newQueueToCopy->getItem());
        //connect the node above to newThis(copy address of front), newThis will point to node above
        newThis->setNext(nextItem);
        //set the nextItem become the last item with a null pinter
        newThis = nextItem;
        end = nextItem;
        //get next node from queueToCopy until it point to a null pointer
        newQueueToCopy = newQueueToCopy->getNext();

    }
//    LinkedNode* nodeNum = front->getNext();
//    while(nodeNum != nullptr){
//        LinkedNode* newNode = nodeNum;
//        end->setNext(newNode);
//        end = nodeNum;
//        nodeNum = nodeNum->getNext();
//    }


}

LinkedQueue& LinkedQueue::operator=(const LinkedQueue& queueToCopy){
    //TODO
    if(front != nullptr){
        while(end != front){
            LinkedNode* newNode = front;
            this -> front = front-> getNext();
            delete newNode;
        }
    }

    LinkedNode* newQueueToCopy = queueToCopy.front;
    front = new LinkedNode(newQueueToCopy->getItem());
    LinkedNode* newThis = this->front;
    newQueueToCopy = newQueueToCopy->getNext();
    while (newQueueToCopy != nullptr){
        LinkedNode* nextItem = new LinkedNode(newQueueToCopy->getItem());
        newThis->setNext(nextItem);
        newThis = nextItem;
        end = nextItem;
        newQueueToCopy = newQueueToCopy->getNext();

    }
    return *this;
}

//Destructor
LinkedQueue::~LinkedQueue(){
    //TODO
    if(front != nullptr){
        while(front != end){
            LinkedNode* newNode = front;
            this -> front = front-> getNext();
            delete newNode;
        }
        delete end;
    }
}


//adds an item to the end of the queue
void LinkedQueue::enqueue(std::string item){
    LinkedNode* newNode = new LinkedNode(item);
    //if front is nullptr, end should be nullptr too
    if (front == nullptr){
        front = newNode;
        end = newNode;
    }else {
        end->setNext(newNode);
        end = newNode;
    }
}

//takes an item off the front of the queue and returns it
//throws out_of_range exception if the queue is empty
std::string LinkedQueue::dequeue(){
    //TODO

    if(front== nullptr){
        throw std::out_of_range("empty queue");
    }else{
        //copy the first item
        std::string result = front->getItem();
        //change the pointer from first item to second item
        front = front->getNext();
        return result;
    }
}

//returns true if the queue has no items, false otherwise
bool LinkedQueue::isEmpty(){
    if(this->front== nullptr){
        return true;
    }else{
        return false;
    }
}