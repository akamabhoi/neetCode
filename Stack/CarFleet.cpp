// This function calculates the number of car fleets that can reach the target without overlapping.
// It takes three parameters: the target position, a vector of positions of cars, and a vector of their speeds.
// It returns an integer representing the number of car fleets.
class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        // Create a vector of pairs to store the positions and the time it takes for each car to reach the target.
        vector<pair<int, double>> cars;

        // Get the number of cars.
        int n = position.size();

        // Iterate through each car's position and speed.
        for (int i = 0; i < n; i++)
        {
            // Calculate the time it takes for the car to reach the target and store it as a pair with the position.
            cars.push_back({position[i], (double)(target - position[i]) / speed[i]});
        }

        // Sort the cars based on their positions in descending order.
        sort(cars.begin(), cars.end(), greater<pair<int, double>>());

        // Initialize variables to track the number of fleets and the time of the current fleet.
        int fleets = 0;
        double curr_fleet_time = 0;

        // Iterate through each car.
        for (int i = 0; i < n; i++)
        {
            // Check if the current car's time to reach the target is greater than the current fleet time.
            if (cars[i].second > curr_fleet_time)
            {
                // If so, update the current fleet time and increment the fleet count.
                curr_fleet_time = cars[i].second;
                fleets++;
            }
        }

        // Return the total number of car fleets.
        return fleets;
    }
};
