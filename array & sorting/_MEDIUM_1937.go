package main

import "fmt"

func maxPoints(points [][]int) int64 {
	rows := len(points)
	cols := len(points[0])
	previousRow := make([]int64, cols)

	// Initialize the first row
	for col := 0; col < cols; col++ {
		previousRow[col] = int64(points[0][col])
	}

	// Process each row
	for row := 1; row < rows; row++ {
		currentRow := make([]int64, cols)

		// Update from left to right
		currentRow[0] = previousRow[0] + int64(points[row][0])
		for col := 1; col < cols; col++ {
			currentRow[col] = max(currentRow[col-1]-1, previousRow[col]) + int64(points[row][col])
		}

		// Update from right to left
		for col := cols - 2; col >= 0; col-- {
			currentRow[col] = max(currentRow[col], currentRow[col+1]-1)
		}

		// Set previousRow to currentRow for the next iteration
		previousRow = currentRow
	}

	// Find the maximum value in the last processed row
	var maxPoints int64
	for col := 0; col < cols; col++ {
		maxPoints = max(maxPoints, previousRow[col])
	}

	return maxPoints
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func main() {
	points := [][]int{
		{1, 2, 3},
		{1, 5, 1},
		{3, 1, 1},
	}
	fmt.Println(maxPoints(points)) // Output should be 9
}
