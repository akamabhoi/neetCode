class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
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

        // If the number of courses in topological order is equal to numCourses, return topo
        if (numCourses == topo.size())
            return topo;
        return {}; // Otherwise, return an empty vector indicating it is impossible to complete all courses
    }
};