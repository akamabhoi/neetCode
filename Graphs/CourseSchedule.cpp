class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // Create an adjacency list for the graph
        unordered_map<int, vector<int>> graph;
        for (auto course : prerequisites)
        {
            int u = course[1];     // Prerequisite course
            int v = course[0];     // Course that depends on the prerequisite
            graph[u].push_back(v); // Add edge from prerequisite to course
        }

        // Initialize the indegree vector to count prerequisites for each course
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++)
        {
            for (auto course : graph[i])
            {
                indegree[course]++; // Increment indegree for each dependent course
            }
        }

        // Queue to process courses with no prerequisites
        queue<int> q;
        // Vector to store the topological order
        vector<int> topo;

        // Add courses with no prerequisites to the queue
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // Process the courses in topological order
        while (!q.empty())
        {
            int node = q.front(); // Get the front course from the queue
            q.pop();
            topo.push_back(node); // Add the course to the topological order

            // Reduce the indegree of the dependent courses
            for (auto course : graph[node])
            {
                indegree[course]--; // Decrease the indegree by 1
                if (indegree[course] == 0)
                { // If indegree becomes 0, add to the queue
                    q.push(course);
                }
            }
        }

        // If the number of courses in topological order is equal to numCourses, return true
        if (numCourses == topo.size())
            return true;
        return false; // Otherwise, return false
    }
};

/*

Explanation:
Graph Construction:
    The graph is an adjacency list representing the course prerequisites.
    For each prerequisite pair [u, v], it adds an edge from u to v in the graph (graph[u].push_back(v)).

Indegree Calculation:
    The indegree vector counts the number of prerequisites (incoming edges) for each course.
    For each course in the graph, it increments the indegree for its dependent courses.

Queue Initialization:
    A queue q is used to process courses with no prerequisites (indegree[i] == 0).
    It adds all such courses to the queue initially.

Topological Sort:
    The while loop processes the queue to generate a topological order (topo vector).
    For each course processed, it reduces the indegree of its dependent courses.
    If any dependent course's indegree becomes 0, it adds it to the queue.

Cycle Detection:
    After processing all courses, if the number of courses in the topological order is equal to numCourses, it means all courses can be finished (no cycle).
    If not, it returns false indicating a cycle in the graph (some courses cannot be finished).

This solution uses Kahn's algorithm for topological sorting, which is effective for detecting cycles in directed graphs and checking if a valid ordering of courses is possible.

*/