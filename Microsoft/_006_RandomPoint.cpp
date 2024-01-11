class Solution {
private:
    vector<vector<int>> rects;
public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        srand(time(0));
    }

    vector<int> pick() {
        int totalPoints = 0;
        vector<int> chosenRect;

        for (const auto& rect : rects) {
            int rectPoints = (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            if (rand() % (totalPoints + rectPoints) < rectPoints) {
                chosenRect = rect;
            }

            totalPoints += rectPoints;
        }

        int x = rand() % (chosenRect[2] - chosenRect[0] + 1) + chosenRect[0];
        int y = rand() % (chosenRect[3] - chosenRect[1] + 1) + chosenRect[1];

        return {x, y};
    }
};