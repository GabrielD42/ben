import info.gridworld.actor.Bug; 
import info.gridworld.grid.Location; 
import java.awt.Color; 
import java.lang.*; 

// parent for all algorithmically pathfinding bugs
public abstract class PathBug extends Bug 
{ 
     private int step; // counter for map[]
     private int map[]; // holds facing of each step before bug moves
      
     public PathBug(Location destination)
     { 
          setColor(new Color(210, 100, 210)); 
          step = 0; 
          map = new int[10000]; 
          for (int i = 0; i < map.length; i++) 
               map[i] = 0;
          map = getPath(destination);
     } 
      
     public void turn() 
     {
          setDirection(map[step]); 
          step++; 
     } 
      
     public void act() 
     { 
       if(step < map.length) {
          turn(); 
          if (canMove()) 
                
               move(); 
       }
 
     }
     
     // override this method with desired algorithm. should return a list directions that the bug should turn to before moving each step
     // for directions, only use static constants NORTH, EAST, SOUTH, WEST, NORTHEAST, SOUTHEAST, SOUTHWEST and NORTHWEST of class Location
     protected abstract int[] getPath(Location destination);
}