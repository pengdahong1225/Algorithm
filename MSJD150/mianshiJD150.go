package mianshiJD150

// 数组、字符串

import (
	"fmt"
)

// 88.合并两个有序数组
func merge(nums1 []int, m int, nums2 []int, n int) {
	// 双指针
	p1, p2 := 0, 0
	var sortNums = make([]int, 0, m+n)
	for {
		// 先处理边界
		if p1 == m {
			sortNums = append(sortNums, nums2[p2:]...)
			break
		}
		if p2 == n {
			sortNums = append(sortNums, nums1[p1:]...)
			break
		}
		if nums1[p1] <= nums2[p2] {
			sortNums = append(sortNums, nums1[p1])
			p1++
		} else {
			sortNums = append(sortNums, nums2[p2])
			p2++
		}
	}
	copy(nums1, sortNums)
}

// 27.移除元素
func removeElement(nums []int, val int) int {
	// 双指针，头尾交换
	left, right := 0, len(nums)-1
	for left <= right {
		if nums[left] == val {
			nums[left], nums[right] = nums[right], nums[left]
			right--
		} else {
			left++
		}
	}
	nums = nums[0:left]
	return len(nums)
}

// 26.删除有序数组中的重复项
func removeDuplicates(nums []int) int {
	// 双指针，相同right++，不同left++
	left, right := 0, 1
	for right < len(nums) {
		if nums[left] == nums[right] {
			right++
		} else {
			// 出现了不同的元素
			if right-left > 1 {
				// 去掉中间，只留一个，将前后连接起来 注意切片是左闭右开
				nums = append(nums[:left+1], nums[right:]...)
				// 重置
				left, right = 0, 1
			} else {
				left++
			}
		}
	}
	// 结束的时候还要判断left和right的间隔
	if right-left > 1 {
		// 有间隔，说明中间还有重复值
		nums = append(nums[:left+1], nums[right:]...)
	}
	return len(nums)
}

// 80.删除有序数组中的重复项 II
func removeDuplicates2(nums []int) int {
	// 双指针，相同right++，不同left++
	left, right := 0, 1
	for right < len(nums) {
		if nums[left] == nums[right] {
			right++
		} else {
			// 出现了不同的元素
			if right-left > 2 {
				// 去掉中间，只留一个，将前后连接起来 注意切片是左闭右开
				nums = append(nums[:left+2], nums[right:]...)
				// 重置
				left, right = 0, 1
			} else {
				left++
			}
		}
	}
	// 结束的时候还要判断left和right的间隔
	if right-left > 2 {
		// 有间隔，说明中间还有重复值
		nums = append(nums[:left+1], nums[right-1:]...)
	}
	return len(nums)
}

// 169.多数元素
func majorityElement(nums []int) int {
	var count = make(map[int]int)
	var ret = nums[0]
	for _, num := range nums {
		count[num]++
		if count[num] > count[ret] {
			ret = num
		}
	}
	return ret
}

// 189. 轮转数组
func rotate(nums []int, k int) {
	// 循环队列类型的-->>模运算
	var temp []int = make([]int, len(nums))
	copy(temp, nums)
	length := len(nums)
	for i := 0; i < length; i++ {
		nums[(i+k)%length] = temp[i]
	}
}

// 121. 买卖股票的最佳时机
func maxProfit(prices []int) int {
	// 遍历一遍数组，计算每次 到当天为止 的最小股票价格和最大利润。
	var minPri, maxPro = prices[0], 0
	for _, price := range prices {
		// 记录最小价格
		if price < minPri {
			minPri = price
			fmt.Println("min = ", minPri)
		}
		// 记录最大利润[当天价格减去最小价格]
		if price-minPri > maxPro {
			maxPro = price - minPri
		}
	}
	return maxPro
}

// 122. 买卖股票的最佳时机 II
func maxProfit_II(prices []int) int {

}

// 双指针

// 125. 验证回文串
func isPalindrome(s string) bool {
	str := []rune(s)
	// 转小写
	for i, ch := range str {
		if unicode.IsUpper(ch) {
			str[i] = unicode.ToLower(ch)
		}
	}
	left, right := 0, len(str)-1
	for left <= len(str)/2 && right >= len(str)/2 {
		if left > right {
			return false
		}
		// 非字母和数字就移动
		for left < len(str)/2 && !isAlphaNumeric(str[left]) {
			left++
		}
		for right > len(str)/2 && !isAlphaNumeric(str[right]) {
			right--
		}
		// 是否一致
		if str[left] != str[right] {
			return false
		} else {
			left++
			right--
		}
	}
	return true
}
func isAlphaNumeric(char rune) bool {
	if unicode.IsLetter(char) || unicode.IsDigit(char) {
		return true
	}
	return false
}
func main() {
	s := ":;"
	println(isPalindrome(s))
}
