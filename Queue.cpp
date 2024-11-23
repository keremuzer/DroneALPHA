#include "Queue.h"
#include <iostream>

// Constructor to initialize an empty queue
Queue::Queue()
{
    // TODO: Your code here
    front = rear = -1;
}

// Adds a province to the end of the queue
void Queue::enqueue(int province)
{
    // TODO: Your code here
    // Implement circular structure
    // Add the province
    if ((rear + 1) % MAX_QUEUE_SIZE == front)
    {
        return;
    }
    rear = (rear + 1) % MAX_QUEUE_SIZE;
    data[rear] = province;
    if (front == -1)
    {
        front = rear;
    }
}

// Removes and returns the front province from the queue
int Queue::dequeue()
{
    // TODO: Your code here
    if (!isEmpty())
    {
        int temp = data[front];
        if (front == rear)
        {
            front = rear = -1;
            return temp;
        }
        front = (front + 1) % MAX_QUEUE_SIZE;
    }
    return -1;
}

// Returns the front province without removing it
int Queue::peek() const
{
    // TODO: Your code here
    if (front == -1)
    {
        return -1;
    }
    return data[front];
}

// Checks if the queue is empty
bool Queue::isEmpty() const
{
    // TODO: Your code here
    return front == -1;
}

// Add a priority neighboring province in a way that will be dequeued and explored before other non-priority neighbors
void Queue::enqueuePriority(int province)
{
    // TODO: Your code here
    if (isEmpty())
    {
        enqueue(province);
        return;
    }
    if ((front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE == rear)
    {
        return;
    }
    front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    data[front] = province;
}
