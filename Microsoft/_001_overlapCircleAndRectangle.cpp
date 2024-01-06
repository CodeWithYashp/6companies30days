class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Find the closest point on the rectangle to the circle's center
        int closestX = clamp(xCenter, x1, x2);
        int closestY = clamp(yCenter, y1, y2);

        // Calculate the distance between the center of the circle and the closest point on the rectangle
        int distanceX = xCenter - closestX;
        int distanceY = yCenter - closestY;

        // Use Pythagorean theorem to calculate the distance
        double distance = sqrt(distanceX * distanceX + distanceY * distanceY);

        // Check if the distance is less than or equal to the radius
        return distance <= radius;
    }
};