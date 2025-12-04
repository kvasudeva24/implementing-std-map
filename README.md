std map is a red black tree


The only reason we need to adjust colors and rotate if there are two adjacent reds (ie parent is red)


There are two main cases:

1. Parent of the inserted node is the left child of the grandparent
    a. If the uncle is also red 
        recolor both the parent and the uncle to black
        recolor the grandparent to red
        move to grandparent and repeat process
    
    b. if the uncle is black
        if the inserted node is the right child of the parent 
            perform a left rotation on the parent to correct the tree shape
        recolor the parent to black and the grandparent to red
        perform a right rotation on the grandparent to restore balance

2.  
    a. if the uncle is also red 
        recolor both the parent and the uncle to black 
        recolor the grandparent to red
        move upward to the grandparent and repeat

    b. if the uncle is black
        if the inserted node is the left child of the parent
            perform a right rotation on the parent
        recolor the parent to black and the grandparent to red
        perform a right rotation on the grandparent

At the end always set the root color to be black to make sure we have not violated anything
    