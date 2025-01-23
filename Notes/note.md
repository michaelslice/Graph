Backtracking notes

Backtracking is just DFS on tree except there's no pre-defined tree. You have to build your own tree by passing the states through parameters.

For example, normally when you do pre-order traversal, you go root -> root.left -> root.right. In backtracking involving choosing a number, left tree will be choosing the number and right tree not choosing. So you go left first by adding the number to path, call dfs(root.left). Pop it out of path (un-choosing) then dfs(root.right).

# do the current operation

# try to finish the other operations

# undo the the current operation

COMMON MISTAKE WITH BACKTRACKING

Mixing index and i in for(int i{index}; i < nums.size(); ++i)

index : Represents the starting point of recursive logic
        ensures we don't visit previous elements

i: Represents the current element being processed in the loop


index: is used to initialize i so that each recursive call begins processing from the correct starting position (avoiding duplicates or redundant work).

The loop uses i to iterate over the remaining elements starting from index

What Happens If You Use i Instead of index???????????

1. Incorrect starting point

If you pass i instead of index to the next recursive call, the function would restart the loop at i (instead of the next valid starting position). This could cause:
- skipping valid elements
- revisiting elements that should be processed
- breaking the logic for handling duplicates