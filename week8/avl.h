/*
AVL: self-balancing binary search tree 
*/
#ifndef AVL_H
#define AVL_H
#include<iostream>


class AVL {

    public:
        // constructor
        AVL(); 
        void insert(int x); 
        void remove(int x);
        void print(); 

    private:
        // node class 
        struct node {
            int data; 
            node* left; 
            node* right; 
            int height; 
        }; 
        
        // root 
        node* root; 


}










#endif