#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "graphSearch.h"

int count;

static bool isCycle(int n, const int graph[][n], int v, bool *visited, int parent)
{
    visited[v] = true; 
    for(int i=0; i<n; ++i) {
        if(graph[v][i]) {
            if(!visited[i]) {
                if(isCycle(n, graph, i, visited, v)) {
                    return true;
                }
            } else if(i != parent) {
                return true;
            }
        }
    }
    return false;
}

bool isTree(int n, const int graph[][n])
{
    bool visited[n];
    for(int i=0; i<n; ++i) {
        visited[i] = false;
    }  
    
    if(isCycle(n, graph, 0, visited, -1)) return false;
    for(int i=0; i<n; ++i) {
        if(!visited[i]) {
            return false;
        }
    }
    return true;
}

static void dfs(int n, const int graph[][n], int v, bool *visited)
{
    count++;
    visited[v] = true;
    for(int i=0; i<n; ++i) {
        if(graph[v][i] && !visited[i]) {
            dfs(n, graph, i, visited);
        }
    }
}

static void dfs_with_k(int n, const int graph[][n], int v, bool *visited, int k)
{
    count++;
    visited[v] = true;
    for(int i=0; i<n; ++i) {
        if(graph[v][i] && !visited[i] && fabs(v-i) <= k) {
            dfs_with_k(n, graph, i, visited, k);
        }
    }
}

// In FrogLand, Pepe the Frog wants to build a food delivery app after being inspired by Swiggy.
// Frogs in FrogLand are not very friendly and don't allow frogs to jump from 
// HouseX to HouseY if they are enemies. Each house in FrogLand has a safeSequence 
// that mentions which houses are safe to jump onto, from the current house.
// No two frogs can cover the same house. Houses are numbered from 0 to n-1.
// Your task is to help Pepe find how many delivery frogs are required for his swamp,
// and to find the maximum number of houses any delivery agent has to visit.
// Note: Frogs can start at any house initially.
// Return a structure Result, with its members assigned.
Result pepesAnswers(int n, const int safeSeq[][n])
{
    bool visited[n];
    int componenets = 0;
    int max = 0;

    for(int i=0; i<n; ++i) {
        visited[i] = false;
    }
    
    for(int i=0; i<n; ++i) {
        if(!visited[i]) {
            count = 0;
            dfs(n, safeSeq, i, visited);
            componenets++;
            if(count > max) max = count;
        }
    }

    Result res;
    res.numDeliveryFrogs = componenets;
    res.maxHouses = max;

    return res;
}

// The swamp has now grown in population, and hence there are more frog houses.
// A delivery frog can only jump over 'k' houses at a time. 
// ie. A frog can jump from HouseX to HouseY only if abs(X-Y) <= k
// Hence modify your above solutions to account for this.
Result pepesAnswersWithK(int n, const int safeSeq[][n], int k)
{
    bool visited[n];
    int componenets = 0;
    int max = 0;

    for(int i=0; i<n; ++i) {
        visited[i] = false;
    }
    
    for(int i=0; i<n; ++i) {
        if(!visited[i]) {
            count = 0;
            dfs_with_k(n, safeSeq, i, visited, k);
            componenets++;
            if(count > max) max = count;
        }
    }

    Result res;
    res.numDeliveryFrogs = componenets;
    res.maxHouses = max;

    return res;
}
