/*
 * File:   hashtable.h
 * Author: ipchelsea, guinek
 */
#include <list>
#include "customer.h"

#ifndef HASHTABLE_H
#define	HASHTABLE_H

class HashTable 
{
    public:

            //default constructor
            HashTable();
            //destructor
            ~HashTable();
            //idk what's this
            HashTable(int buckets);

            virtual int getHashIndex(&customer) const;
            
            bool contains(&customer) const;
            //destructor
            ///~HashTable();

            customer& find(&customer) const;

            bool insert(&customer);

            void remove(&customer);

    private:

            struct Node 
            {
                Customer* data;
                Node* next;
                int key;
            };

            struct HashTableNode 
            {
                int count;
                Node* nodeData;
            };

            //int hash(&customer);
            int customerID;
            int bucketNum;
            list<customer> *table;

};

#endif	/* BUSINESS_H */