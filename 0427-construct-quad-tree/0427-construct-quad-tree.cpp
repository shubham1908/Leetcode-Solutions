/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* helper(vector<vector<int>> &grid, int h1, int h2, int v1, int v2){
        if(h1 > h2 || v1 > v2){
            return NULL;
        }
        int isLeaf = true;
        int val = grid[h1][v1];
        for(int i=h1; i<=h2; i++){
            for(int j = v1; j<=v2; j++){
                if(grid[i][j] != val){
                    isLeaf = false;
                    break;
                }
            }
            if(!isLeaf){
                break;
            }
        }
        if(isLeaf){
            return new Node(val, true);
        }
        int midh = (h1+h2)/2, midv = (v1+v2)/2;
        Node *topL = helper(grid, h1, midh, v1, midv);
        Node *topR = helper(grid, h1, midh, midv+1, v2);
        Node *bottomL = helper(grid, midh+1, h2, v1, midv);
        Node *bottomR = helper(grid, midh+1, h2, midv+1, v2);
        return new Node(true, false, topL, topR, bottomL, bottomR);
    }
    
    Node* construct(vector<vector<int>>& grid) {
        return helper(grid, 0, grid.size()-1, 0, grid.size()-1);
    }
};