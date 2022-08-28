#include <stdio.h> 
#include<limits.h>
#include<stdbool.h>

#define V 16 
   
int minDistance(float dist[], bool sptSet[]) 
{ 
   int min = INT_MAX, min_index;
   
   for (int v = 0; v < V; v++) 
   {
      if (sptSet[v] == false && dist[v] <= min) 
      {
         min = dist[v], min_index = v; 
      }
   }
   
   return min_index; 
} 
  
void printcost(float dist[]) 
{ 
   /*for (int i = 0; i < V; i++) 
   {
      printf("%d --> %.1f\n", i, dist[i]); 
   }*/

   printf("Its Cost: %.1f\n", dist[V-1]);
} 
   
void dijkstra(float graph[V][V], int src) 
{ 
   int save_direction_rev[16];
   for (size_t i = 0; i < 10; i++)
   {
      save_direction_rev[i] = -1;
   }
   
   float dist[V];     
   bool sptSet[V]; 
   
   for (int i = 0; i < V; i++) 
   {
      dist[i] = INT_MAX;
      sptSet[i] = false; 
   }

   dist[src] = 0; 

   for (int count = 0; count < V-1; count++) 
   { 
      int u = minDistance(dist, sptSet); 
      sptSet[u] = true; 

      for (int v = 0; v < V; v++) 
      {
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
         {  
            dist[v] = dist[u] + graph[u][v];
            save_direction_rev[v] = u;
         }
            
      }

   } 

   
   printcost(dist); 

   printf("The best route:   (right to left)\n");
   
   int destination = 15;
   printf("15 <----- ");
   while (destination > 0)
   {
      if (save_direction_rev[destination] == 0)
      {
         printf("%d\n", save_direction_rev[destination]);
         break;
      }
      
      printf("%d <----- ", save_direction_rev[destination]);
      destination = save_direction_rev[destination];
   }
   
} 
   

int main() 
{ 
                     
   float graph[V][V] = {{0, 0.2, 0,   0.6, 0.2,   0,   0,   0,  0,  0,   0,   0,   0,   0,   0,   0}, 
                      {0.2, 0,   0,   3.9, 2.8,   0,   0,   0,  0,  0,   0,   0,   0,   0,   0,   0}, 
                      {0,   0,   0,   3.8, 0,     2,   0,   0,  0,  0,   0,   0,   0,   0,   0,   0}, 
                      {0.6, 3.9, 3.8, 0,   0.4,   6.3, 0,   0,  0,  0,   0,   0,   0,   0,   0,   0}, 
                      {0.2, 2.8, 0,   0.4, 0,     0,   4.8, 0,  0,  0,   0,   0,   0,   0,   0,   0}, 
                      {0,   0,   2,   6.3, 0,     0,   3.8, 0,  0,  0.3, 0,   0,   0,   0,   0,   0}, 
                      {0,   0,   0,   0,   4.8,   3.8, 0,   0,  0,  0,   9,   0,   0,   0,   0,   0}, 
                      {0,   0,   0,   0,   0,     0.2, 9,   0,  1.1,0,   0,   3.6, 0,   0,   0,   0}, 
                     
                      {0,   0,   0,   0,   0,     0,   0,   1.1,0,  0.2, 0,   0,   2,   0,   0,   0},
                      {0,   0,   0,   0,   0,     0,   0,   0,  0.2,0,   0.1, 0,   0,   7,   0,   0},
                      {0,   0,   0,   0,   0,     0,   0,   0,  0,  0.1, 0,   0,   0,   0,   8.2, 0},
                      {0,   0,   0,   0,   0,     0,   0,   3.6,0,  0,   0,   0,   1.8, 0,   0,   0},
                      {0,   0,   0,   0,   0,     0,   0,   0,  2,  0,   0,   1.8, 0,   2.4, 0,   0.2},
                      {0,   0,   0,   0,   0,     0,   0,   0,  0,  7,   0,   0,   2.4, 0,   3.6, 0},
                      {0,   0,   0,   0,   0,     0,   0,   0,  0,  0,   4.1, 0,   0,   3.6, 0,   0},
                      {0,   0,   0,   0,   0,     0,   0,   0,  0,  0,   0,   0,   0.2, 0,   0,   0},
                     };

   
   dijkstra(graph, 0); 
   
   return 0; 
}