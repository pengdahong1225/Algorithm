package main

import "sort"

// 贪心算法

// 分配饼干
func FindContentChildren(children []int, cookies []int) int {
	// 预处理
	sort.Ints(children)
	sort.Ints(cookies)

	var child, cookie = 0, 0
	for child < len(children) && cookie < len(cookies) {
		if children[child] <= cookies[cookie] {
			child++
		}
		cookie++
	}
	return child
}
