import info.gridworld.actor.Bug; 
import info.gridworld.grid.Location; 
import java.awt.Color; 
import java.lang.*; 

// A* Search Algorithm
public class AStarBug extends PathBug 
{ 
     private int step; // counter for map[]
     private int map[]; // holds facing of each step before bug moves
     
     // needs to be varient of this in every descendent of PathBug
     public AStarBug(Location destination)
     {
       super(destination);
     }
     
     protected int[] getPath(Location destination)
     {
       int array[] = {Location.NORTH, Location.EAST, Location.SOUTH, Location.WEST};
       return array;
     }
}