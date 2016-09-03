//
//  Node.cpp
//  Balanced-tree
//
//  Created by jtkim on 2016. 9. 3..
//  Copyright © 2016년 jtkim. All rights reserved.
//

#include "Node.hpp"
#include <stdlib.h>
#include <string.h>
//typedef struct Node
//{
//    int data[MAX_DATA];
//    Node* child[MAX_DATA+1];
//    int childIndex;
//} Node;

Node* makeNode()
{
    Node* node = (Node*)malloc(sizeof(struct Node));
    node->childIndex = 0;
    node->dataIndex = 0;
    memset(node->data, 0, sizeof(node->data));
    memset(node->child, 0, sizeof(node->child));
    
    return node;
}

bool insertNode(Node* node, int data)
{
    if ( !node ) return false;
    
    if ( node->data[0] > data )
        {
            insertNode(node->child[0], data);
        }
        else
        {
            insertNode(node->child[1], data);
        }
    
    // if there is room for the new data, then insert the new one in the node.
    if ( node->dataIndex < MAX_DATA+1 )
    {
        node->data[node->dataIndex++] = data;
    }
    else
    {
        // if the node is full, evenly split into two nodes.
        // 1. find the median
        node->data[0] = 2;
        node->dataIndex = 2;
        // 2. make left sub tree
        Node* left = makeNode();
        left->data[0] = 1;
        left->dataIndex = 2;
        node->child[0] = left;
        
        // 3. make right sub tree
        Node* right = makeNode();
        right->data[0] = 3;
        right->dataIndex = 2;
        node->child[1] = right;
    }
    
    return true;
}

void makeLeftSubTree(Node* root, Node* child, int index)
{
    root->child[index] = child;
}

void makeRightSubTree(Node* root, Node* child, int index)
{
    root->child[index] = child;
}

void printAllNode(Node* root)
{
    if ( !root ) return;
    
    for ( int i=0; i<MAX_DATA; i++ )
    {
        printf("%d ", root->data[i]);
    }
    printf("\n");

    for ( int i=0; i<MAX_DATA+1; i++ )
    {
        printAllNode(root->child[i]);
    }
}



