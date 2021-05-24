#include <iostream>
#include "Node.h"
#include "Tree.h"

int main()
{
    Tree obj;
    obj.insert(5);
    obj.insert(3);
    obj.remove(5);
    obj.insert(7);
    obj.insert(9);
    obj.insert(1);
    obj.remove(7);
    obj.insert(6);
    obj.insert(4);
    obj.display();
    obj.countedNodes();
    obj.countedEdges();
}