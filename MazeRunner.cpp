#pragma once
#include <iostream>
#include "MazeRunner.hpp"
#include "mover.hpp"
#include "Maze.h"
#include "game.hpp"
#include "Player.hpp"




std::string makeMove(string direction,Maze* generator,Player& boy,Score& points,std::string gameState){
	if (direction == "East")
	{ 
       if (generator->grids[boy.curr_x][boy.curr_y].eastwalls==false){
           if (boy.curr_x==0 && boy.curr_y==0){
               gameState="WON";
           }
          else{
           boy.moveEast();
           boy.curr_x+=1;}
       }

      
      
        
	}	
	else if (direction == "West"){
        if (generator->grids[boy.curr_x][boy.curr_y].westwalls==false){
            if (boy.curr_x==0 && boy.curr_y==0){
               gameState="WON";
           }else{
           boy.moveWest();
           boy.curr_x-=1;}
       }
        
    }
	
	else if (direction == "North"){
       if (generator->grids[boy.curr_x][boy.curr_y].northwalls==false){
        if (boy.curr_x==0 && boy.curr_y==0){
               gameState="WON";
           }else{
           boy.moveNorth();
           boy.curr_y-=1;}
       }
        
    }
	else if (direction == "South"){
        if (generator->grids[boy.curr_x][boy.curr_y].southwalls==false){
            if (boy.curr_x==0 && boy.curr_y==0){
               gameState="WON";
           }else{
            boy.moveSouth();
           boy.curr_y+=1;}
       }}
    return gameState;   
}



