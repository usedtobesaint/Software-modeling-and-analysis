function sortedSquares(nums) {
    const squaredArray = nums.map(num => num * num); 
    squaredArray.sort((a, b) => a - b); 
    return squaredArray;
  }
  
  const nums1 = [-4, -1, 0, 3, 10];
  console.log(sortedSquares(nums1)); 
  
  const nums2 = [-7, -3, 2, 3, 11];
  console.log(sortedSquares(nums2)); 
  