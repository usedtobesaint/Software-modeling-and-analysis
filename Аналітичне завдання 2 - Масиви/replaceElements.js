function replaceElements(arr) {
    const n = arr.length;
  
    if (n === 1) {
      return [-1]; 
    }
  
    let max = arr[n - 1]; 
  
    for (let i = n - 2; i >= 0; i--) {
      const current = arr[i];
      arr[i] = max;
      max = Math.max(max, current);
    }
  
    arr[n - 1] = -1; 
  
    return arr;
  }
  
  const arr1 = [17, 18, 5, 4, 6, 1];
  const result1 = replaceElements(arr1);
  console.log(result1); 
  
  const arr2 = [400];
  const result2 = replaceElements(arr2);
  console.log(result2); 
  