// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

function removeDuplicates(nums: number[]): number {
  const originalLength = nums.length
  var actual = 0
  for (let i = 0; i < originalLength; i++) {
    if (nums[actual] === nums[actual + 1]) {
      nums.splice(actual, 1)
    } else {
      actual += 1
    }
  }
  return nums.length
}

var nums = [1, 1, 2]
console.log(removeDuplicates(nums), nums) // 2, nums = [1, 2]
nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
console.log(removeDuplicates(nums), nums) // 5, nums = [0, 1, 2, 3, 4]