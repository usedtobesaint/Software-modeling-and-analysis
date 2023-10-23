function checkIfDoubleExists(arr) {
    for (let i = 0; i < arr.length; i++) {
      for (let j = 0; j < arr.length; j++) {
        if (i !== j && arr[i] === 2 * arr[j]) {
          return true;
        }
      }
    }
    return false;
  }

  const arr1 = [10, 2, 5, 3];
  const result1 = checkIfDoubleExists(arr1);
  console.log(result1); 
  
  const arr2 = [3, 1, 7, 11];
  const result2 = checkIfDoubleExists(arr2);
  console.log(result2); 
  