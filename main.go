package main

import (
	"fmt"
	"math"
	"strconv"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

// 2.两数相加
// x y暂存法
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var ret = new(ListNode)
	cur := ret
	carry := 0
	for l1 != nil || l2 != nil {
		x, y := 0, 0
		if l1 != nil {
			x = l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			y = l2.Val
			l2 = l2.Next
		}
		sum := x + y + carry
		cur.Next = &ListNode{Val: sum % 10}
		cur = cur.Next
		carry = sum / 10
	}
	if carry > 0 {
		cur.Next = &ListNode{Val: carry}
	}
	return ret.Next
}

// 3.无重复字符的最长子串
// hash + 滑动窗口
func lengthOfLongestSubstring(s string) int {
	if len(s) == 0 {
		return 0
	}
	var maxLength = 0
	str := []rune(s)
	var hash = make(map[rune]int)
	left, right := 0, 0
	for right < len(str) {
		hash[str[right]]++
		// 出现了重复字符，左边的边界往右滑[同时把左边的字符数--]，直到滑到过了重复字符为止
		for hash[str[right]] > 1 {
			hash[str[left]]--
			left++
		}
		if right-left+1 > maxLength {
			maxLength = right - left + 1
			fmt.Println(maxLength)
		}
		right++
	}
	return maxLength
}

// 字符串转换整数 (atoi)
func myAtoi(s string) int {
	var num []rune
	str := []rune(s)
	begin, prefix := 0, 1
	// 去前导空格
	for i, ch := range str {
		if ch != ' ' {
			begin = i
			break
		}
	}
	// 重置
	str = str[begin:]
	begin = 0
	// 符号
	if len(str) > 0 && str[begin] == '-' {
		prefix = -1
		begin++
	} else if len(str) > 0 && str[begin] == '+' {
		begin++
	}
	str = str[begin:]
	// 开始数字
	for _, ch := range str {
		if ch >= 48 && ch <= 57 {
			num = append(num, ch)
		} else {
			break
		}
	}
	ret, _ := strconv.Atoi(string(num))
	ret *= prefix
	if ret >= math.MaxInt32 {
		ret = math.MaxInt32
	} else if ret <= math.MinInt32 {
		ret = math.MinInt32
	}
	return ret
}

func main() {
	var s = "   +1"
	ret := myAtoi(s)
	fmt.Println(ret)
}
