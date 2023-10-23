function sortArrayByParity(nums) {
    const even = nums.filter(num => num % 2 === 0);
    const odd = nums.filter(num => num % 2 !== 0);
    return even.concat(odd);
  }

  const nums1 = [3, 1, 2, 4];
  const result1 = sortArrayByParity(nums1);
  console.log(result1); 
  
  const nums2 = [0];
  const result2 = sortArrayByParity(nums2);
  console.log(result2); 
  