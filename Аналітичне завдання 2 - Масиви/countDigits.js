function countDigits(num) {
    let count = 0;
    while (num > 0) {
      count++;
      num = Math.floor(num / 10);
    }
    return count;
  }
  
  function countNumbersWithEvenDigits(nums) {
    let count = 0;
  
    for (const num of nums) {
      if (countDigits(num) % 2 === 0) {
        count++;
      }
    }
  
    return count;
  }
  
  const nums1 = [12, 345, 2, 6, 7896];
  console.log(countNumbersWithEvenDigits(nums1)); 
  
  const nums2 = [555, 901, 482, 1771];
  console.log(countNumbersWithEvenDigits(nums2));
  