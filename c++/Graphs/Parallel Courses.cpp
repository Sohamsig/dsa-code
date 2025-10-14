#include <bits/stdc++.h>
using namespace std;

int minimumSemesters(int n, vector<vector<int>>& relations) {
    vector<vector<int>> graph(n + 1); // adjacency list for courses
    vector<int> indegree(n + 1, 0);   // indegree of each course

    // Build the graph
    for (auto &rel : relations) {
        int u = rel[0], v = rel[1];
        graph[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;

    // Push all courses with no prerequisites
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    int semesters = 0;  // count of semesters
    int takenCourses = 0; // count of courses taken

    // BFS Topological Sort
    while (!q.empty()) {
        int sz = q.size();
        semesters++; // new semester
        for (int i = 0; i < sz; i++) {
            int course = q.front(); q.pop();
            takenCourses++;
            // Reduce indegree of next courses
            for (int next : graph[course]) {
                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }
    }

    // If not all courses were taken, there's a cycle
    return (takenCourses == n) ? semesters : -1;
}

// Example usage
int main() {
    int n = 3;
    vector<vector<int>> relations = {{1,3},{2,3}};
    cout << minimumSemesters(n, relations) << endl; // Output: 2
    return 0;
}
