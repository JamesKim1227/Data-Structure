//
//  main.cpp
//  Balanced-tree
//
//  Created by jtkim on 2016. 9. 3..
//  Copyright © 2016년 jtkim. All rights reserved.
//

#include <iostream>
#include "Node.hpp"

int main(int argc, const char * argv[])
{
    Node* nd1 = makeNode();
    
    insertNode(nd1, 1);
    insertNode(nd1, 2);
    insertNode(nd1, 3);
    insertNode(nd1, 4);
    //insertNode(nd1, 5);
    
   
    printAllNode(nd1);
   
    return 0;
}
