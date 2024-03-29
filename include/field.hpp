#pragma once
#include <iostream>
#include <cmath>
#include <set>
#include <list>
#include <stack>
#include <cstdlib>
#include <ctime>
#include "cell.hpp"
#include "node.hpp"



// Consider the field border as non available space to access.

class Field{

  private:

      float cellSize;
      std::vector< std::vector<Cell> > vectorOfCells;
      std::pair<int,int> fieldDimension;


    public:

        // Constructors
        Field(int width, int height, float cellSize);
        Field(std::pair<int,int> fieldDimension, float cellSize);

        // Getters
        Cell getCell(int posX, int posY);
        int getWidth();
        int getHeight();

        void reset();

        void changeCellState(int posX, int posY, CellObjects cellObject);
        std::vector<Node> calculateChilds(Node* targetNode);
        int calculateHeuristic(Node targetNode, std::pair<int,int> finalPos, Heuristic heuristicFunction);

        /* This function contains PATHFINDING method using the A* algorithm */
        int calculateFunction(Node targetNode, std::pair<int,int> finalPos, Heuristic heuristicFunction);


        std::list<Node> calculateOptimalRoute(std::pair<int,int> initialPos, std::pair<int,int> finalPos, int& generatedNodes, Heuristic heuristicFunction);
        bool nodesAreEqual(Node* nodeA, Node* nodeB);
        void eliminateDuplicates(std::list<Node*>& nodeQueue);
        Node* findMinimumNode(std::list<Node*>& openList);
        bool lowerEqualExist(std::list<Node*> openList, Node node);
        bool lowerEqualExist(std::list<Node> openList, Node node);

        std::pair<int,int> uniToBidimensional(int rangePos);
        void generateRandomTerrain(int percentage);
        std::pair<int,int> generateRandomGoal();








};
