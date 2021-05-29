// https://leetcode.com/problems/two-sum/

function twoSum(nums: number[], target: number): number[] {
  for (let first = 0; first < nums.length; first++) {
    for (let second = first + 1; second < nums.length; second++) {
      const sum = nums[first] + nums[second]
      if (sum === target) {
        return [first, second]
      }
    }
  }
  return [-1, -1]
};

console.log(twoSum([2, 7, 11, 15], 9))  // [0, 1]
console.log(twoSum([3, 2, 4], 6))       // [1, 2]
console.log(twoSum([3, 3], 6))          // [0, 1]