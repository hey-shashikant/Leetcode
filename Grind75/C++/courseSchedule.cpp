class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Create an adjacency list to represent the graph
        std::vector<std::vector<int>> adjList(numCourses);
        for (const auto& prerequisite : prerequisites) {
            int course = prerequisite[0];
            int prerequisiteForCourse = prerequisite[1];
            adjList[prerequisiteForCourse].push_back(course);
        }

        // Calculate indegrees for each course
        std::vector<int> indegrees(numCourses);
        for (int course = 0; course < numCourses; ++course) {
            for (int neighbor : adjList[course]) {
                indegrees[neighbor]++;
            }
        }

        // Find courses with no prerequisites to start with
        std::queue<int> coursesWithNoPrerequisites;
        for (int course = 0; course < numCourses; ++course) {
            if (indegrees[course] == 0) {
                coursesWithNoPrerequisites.push(course);
            }
        }

        // Perform topological sort using BFS
        int countVisitedCourses = 0;
        while (!coursesWithNoPrerequisites.empty()) {
            int course = coursesWithNoPrerequisites.front();
            coursesWithNoPrerequisites.pop();
            countVisitedCourses++;
            for (int neighbor : adjList[course]) {
                indegrees[neighbor]--;
                if (indegrees[neighbor] == 0) {
                    coursesWithNoPrerequisites.push(neighbor);
                }
            }
        }

        // If all courses can be visited, return true
        return countVisitedCourses == numCourses;
    }
};