package main

import "fmt"

func mergeAlternately(word1 string, word2 string) string {
	var res string
	i, j := 0, 0

	for i < len(word1) || j < len(word2) {
		if i < len(word1) {
			res += string(word1[i])
			i++
		}
		if j < len(word2) {
			res += string(word2[j])
			j++
		}
	}

	return res
}

func main() {
	fmt.Println(mergeAlternately("abc", "def")) // Output: "adbecf"
}
