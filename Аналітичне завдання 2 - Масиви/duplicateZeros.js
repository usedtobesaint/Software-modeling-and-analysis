function duplicateZeros(arr) {
    let zerosCount = 0;
    for (const num of arr) {
      if (num === 0) {
        zerosCount++;
      }
    }
  
    const n = arr.length; 
    let i = n - 1; 
  
    while (i >= 0) {
      if (arr[i] === 0) {
        if (i + zerosCount < n) {
          arr[i + zerosCount] = 0;
        }
        zerosCount--;
      }
  
      if (i + zerosCount < n) {
        arr[i + zerosCount] = arr[i];
      }
  
      i--;
    }
  }
  
 
  const arr1 = [1, 0, 2, 3, 0, 4, 5, 0];
  duplicateZeros(arr1);
  console.log(arr1);
  
  const arr2 = [1, 2, 3];
  duplicateZeros(arr2);
  console.log(arr2); 
  