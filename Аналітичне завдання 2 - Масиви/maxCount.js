function findMaxConsecutiveOnes(nums) {
    let maxCount = 0; 
    let currentCount = 0; 
  
    for (const num of nums) {
      if (num === 1) {
        currentCount++; 
        maxCount = currentCount; // Оновлюємо максимальний лічильник.
      } else {
        currentCount = 0; 
      }
    }
  
    return maxCount;
  }
 
  const nums = [1, 1, 0, 1, 1, 1, 0, 1, 1, 1];
  const maxOnes = findMaxConsecutiveOnes(nums);
  console.log(`Максимальна кількість повторень 1-ць: ${maxOnes}`);
  