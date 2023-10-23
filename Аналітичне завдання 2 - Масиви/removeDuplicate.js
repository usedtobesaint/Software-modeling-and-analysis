function removeDuplicates(nums) {
    if (nums.length === 0) {
      console.log("[]");
      return 0;
    }
  
    let uniqueIndex = 0; 
  
    for (let i = 1; i < nums.length; i++) {
      if (nums[i] !== nums[uniqueIndex]) {
        uniqueIndex++;
        nums[uniqueIndex] = nums[i];
      } else {
        nums[i] = "_";
      }
    }
  
    const k = uniqueIndex + 1;
  
    const result = nums.slice(0, k); 
  
    for (let i = k; i < nums.length; i++) {
      result.push("_");
    }
  
    console.log(result);
  
    return k;
  }
 
  const nums1 = [1, 1, 2];
  const k1 = removeDuplicates(nums1);
  console.log(k1);
  
  const nums2 = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4];
  const k2 = removeDuplicates(nums2);
  console.log(k2); 
  