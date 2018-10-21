int depthOfTree(struct Node *ptr) 
{ 
    // Base case 
    if (!ptr) 
        return 0; 
  
    // Check for all children and find 
    // the maximum depth 
    int maxdepth = 0; 
    for (vector<Node*>::iterator it = ptr->child.begin(); 
                              it != ptr->child.end(); it++) 
        maxdepth = max(maxdepth, depthOfTree(*it)); 
  
    return maxdepth + 1 ; 
} 
