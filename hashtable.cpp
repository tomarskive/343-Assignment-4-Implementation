#include "hashtable.h"

static const int MAX_SIZE = 999;

using namespace std;

// ---------------------Default Constructor -----------------------------------------
// Changed the size of the table to 999, just in case she inserts something greater
// than 8.
//
HashTable::HashTable() 
{
    bucketNum = MAX_SIZE;
    Table = new list<customer>[MAX_SIZE];
    
    for(int i = 0; i < bucketNum; i++)
    {
        Table[i] = NULL;
    }
}

// ---------------------Destructor -----------------------------------------
// Constructs the first name, last name and the month of the actor.
//
HashTable::~HashTable() 
{
    remove();
}

// ---------------------Destructor -----------------------------------------
// Constructs the first name, last name and the month of the actor.
//
int HashTable::getHashIndex(&customer person) const
{
    int index = person.customerID % bucketNum;
    return index;
}

// ---------------------Insert() -----------------------------------------
// Constructs the first name, last name and the month of the actor.
//
bool HashTable::insert(&customer newPerson) 
{
    Node* newNode = new Node;
    newNode->data = newPerson;
    newNode->next = NULL;
    
    
    HashTNode* newHashNode = new HashTNode;
    int index = getHashIndex(person);
    newHashNode->key = index;
    
    newHashNode->nodeData = newNode;
    Table[index] = new newHashNode;
    
    return true;
}

// ---------------------Contains() -----------------------------------------
// Returns true if hashkey is present
//
bool HashTable::contains(&customer target) const
{
    int hashKey = getHashIndex(target);
    return Table[hashKey] != NULL;
}

// ---------------------find() -----------------------------------------
// Checks whether targeted customer is present in the hashtable, calls
// the getHashIndex function.
//
HashTable Hashtable::find(&customer target) const
{
    
    if(contains(target))
    {
        return Table[getHashIndex(target)]->nodeData->data;
    }
    else
    {
        cout << "This person does not exist" <<endl;
        return NULL;
    }
}

void HashTable::remove(&customer newPerson) 
{
    for(int i = 0; i < bucketNum; i++)
    {
        if(Table[i])
        {
            delete Table[i]->nodeData->data;
            delete Table[i]->nodeData;
            delete Table[i];
        }
    }
}

/*
// ---------------------Destructor -----------------------------------------
// Constructs the first name, last name and the month of the actor.
//
HashTable::HashTable(int buckets) 
{
    bucketNum = buckets;
    table = new list<customer>[buckets];
}
*/


