//
//  Node.hpp
//  Balanced-tree
//
//  Created by jtkim on 2016. 9. 3..
//  Copyright © 2016년 jtkim. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>

#define MAX_DATA    2

typedef struct Node
{
    int data[MAX_DATA];
    int dataIndex;
    Node* child[MAX_DATA+1];
    int childIndex;
} Node;

Node* makeNode();

bool insertNode(Node* node, int data);

void printAllNode(Node* node);

#endif /* Node_hpp */
