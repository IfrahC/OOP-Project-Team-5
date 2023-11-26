#pragma once
#include <iostream>
#include "MazeRunner.hpp"
#include "GameManager.hpp"
#include "Maze.hpp"
#include "game.hpp"
#include "Player.hpp"




std::string makeMove(string direction,Maze* generator,Player& boy,Score& points,std::string gameState){
    
	if (direction == "East") //if the playe is to be moved in east direction
	{ 
       if (generator->grids[boy.curr_x][boy.curr_y].eastwalls==false){ //if there is no wall
           if (boy.curr_x==0 && boy.curr_y==0){ //if its the destination gamestate won
               gameState="WON";
           }
          else{ //otherwise player will be moved east
           boy.moveEast();
           boy.curr_x+=1;} //current x position of player will be incremented by 1
       }

      
      
        
	}	
	else if (direction == "West"){ //if the player is to be moved in west direction
        if (generator->grids[boy.curr_x][boy.curr_y].westwalls==false){ //if there is no wall
            if (boy.curr_x==0 && boy.curr_y==0){ //if its the destination gamestate won
               gameState="WON";
           }else{ //otherwise player will be moved west
           boy.moveWest();
           boy.curr_x-=1; //current x position of player will be decremented by 1
           
       }}
        
    }
	
	else if (direction == "North"){//if the player is to be moved in north direction
       if (generator->grids[boy.curr_x][boy.curr_y].northwalls==false){ //if there is no wall
        if (boy.curr_x==0 && boy.curr_y==0){ //if its the destination gamestate won
               gameState="WON";
           }else{  //otherwise player will be moved north
           boy.moveNorth();
           boy.curr_y-=1;} //current y position of player will be decremented by 1
       }
        
    }
	else if (direction == "South"){//if the player is to be moved in south direction
        if (generator->grids[boy.curr_x][boy.curr_y].southwalls==false){ //if there is no wall
            if (boy.curr_x==0 && boy.curr_y==0){ //if its the destination gamestate won
               gameState="WON";
           }else{  //otherwise player will be moved south
            boy.moveSouth();
           boy.curr_y+=1;} //current y position of player will be incremented by 1
       }}
       
    return gameState;   
}



